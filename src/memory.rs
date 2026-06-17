use minhook::{MinHook, MH_STATUS};
use std::sync::atomic::{AtomicUsize, Ordering};

use windows_sys::Win32::System::LibraryLoader::GetModuleHandleA;
use windows_sys::Win32::System::ProcessStatus::{K32GetModuleInformation, MODULEINFO};
use windows_sys::Win32::System::Threading::GetCurrentProcess;

use windows_sys::Win32::System::Memory::{
    VirtualQuery, MEMORY_BASIC_INFORMATION, MEM_COMMIT, PAGE_EXECUTE_READ, PAGE_EXECUTE_READWRITE,
    PAGE_GUARD, PAGE_NOACCESS, PAGE_READONLY, PAGE_READWRITE, VirtualAlloc, MEM_RESERVE
};


use std::ops::Range;
use std::arch::asm;

/// Функция переводит строку паттерна вида "48 8B 05 ?? ?? ?? ??" в вектор Опций
fn parse_pattern(pattern: &str) -> Vec<Option<u8>> {
    println!("[DEBUG] parse_pattern: Парсинг паттерна '{}'", pattern);
    let parsed: Vec<Option<u8>> = pattern
        .split_whitespace() // Разбивает по пробелам
        .map(|b| {
            if b == "?" || b == "??" {
                None
            } else {
                Some(u8::from_str_radix(b, 16).unwrap_or(0)) // Парсим число как шестнадцатеричное
            }
        })
        .collect(); // Собирает результаты итератора в финальный контейнер Vec<Option<u8>>

    println!("[DEBUG] parse_pattern: Длина спарсенного паттерна: {} байт", parsed.len());
    parsed
}

/// Получает диапазон адресов (начало..конец) главного модуля текущего процесса
unsafe fn get_module_range() -> Range<usize> {
    println!("[DEBUG] get_module_range: Запрос информации о модуле...");
    let process = GetCurrentProcess();
    let module = GetModuleHandleA(std::ptr::null()); // null означает главный .exe модуля

    let mut module_info = MODULEINFO {
        lpBaseOfDll: std::ptr::null_mut(),
        SizeOfImage: 0,
        EntryPoint: std::ptr::null_mut(),
    };

    K32GetModuleInformation(
        process,
        module,
        &mut module_info,
        std::mem::size_of::<MODULEINFO>() as u32,
    );

    let start = module_info.lpBaseOfDll as usize;
    let end = start + module_info.SizeOfImage as usize;

    println!("[DEBUG] get_module_range: База модуля: 0x{:X}, Конец: 0x{:X}, Размер: 0x{:X} ({} байт)", start, end, module_info.SizeOfImage, module_info.SizeOfImage);

    start..end
}

/// Основная функция АОБ-скана. Возвращает адрес начала совпадения.
pub unsafe fn find_pattern(pattern: &str) -> Option<usize> {
    println!("[DEBUG] find_pattern: Старт AOB скана для '{}'", pattern);
    let parsed = parse_pattern(pattern);
    let range = get_module_range();

    println!("[DEBUG] find_pattern: Ищем совпадение в диапазоне 0x{:X} - 0x{:X}...", range.start, range.end);

    let mut current_addr = range.start;

    // Идем по памяти модуля блоками, проверяя права доступа
    while current_addr < range.end {
        let mut mbi: MEMORY_BASIC_INFORMATION = std::mem::zeroed();

        // Запрашиваем информацию о странице памяти
        let res = VirtualQuery(
            current_addr as *const _,
            &mut mbi,
            std::mem::size_of::<MEMORY_BASIC_INFORMATION>(),
        );

        if res == 0 {
            break; // Не удалось получить инфу, прерываем сканирование
        }

        // Проверяем, что память физически выделена
        let is_committed = mbi.State == MEM_COMMIT;
        println!("Проверяем, что память физически выделена");

        // Проверяем, что страница имеет права на чтение
        let is_readable = (mbi.Protect & (PAGE_READONLY | PAGE_READWRITE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE)) != 0;
        println!("Проверяем, что страница имеет права на чтение");

        // Проверяем, что нет защиты от доступа
        let is_guarded_or_noaccess = (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) != 0;
        println!("Проверяем, что нет защиты от доступа");

        // Если память можно читать - сканируем этот конкретный регион
        if is_committed && is_readable && !is_guarded_or_noaccess {
            let region_start = current_addr;
            let region_end = (current_addr + mbi.RegionSize).min(range.end);
            println!("Если память можно читать - сканируем этот конкретный регион");


            // Если размер региона меньше размера паттерна, искать нет смысла
            if region_end - region_start >= parsed.len() {
                let memory_slice = std::slice::from_raw_parts(region_start as *const u8, region_end - region_start);
            println!("Если размер региона меньше размера паттерна, искать нет смысла");
                'outer: for i in 0..=(memory_slice.len() - parsed.len()) {
                    for j in 0..parsed.len() {
                        if let Some(pattern_byte) = parsed[j] {
                            if memory_slice[i + j] != pattern_byte {
                                continue 'outer;
                            }
                        }
                    }
                    // Паттерн совпал
                    let found_addr = region_start + i;
                    println!("[DEBUG] find_pattern: [+] ПАТТЕРН НАЙДЕН по адресу: 0x{:X}", found_addr);
                    return Some(found_addr);
                }
            }
        }

        // Прыгаем к следующему региону памяти
        current_addr += mbi.RegionSize;
    }

    println!("[DEBUG] find_pattern: [-] Паттерн НЕ НАЙДЕН!");
    None
}

/// Специальная функция для x64. Разрешает RIP-относительные адреса (например, в инструкциях MOV)
pub unsafe fn resolve_rip(instruction_addr: usize, offset_in_instruction: usize, instruction_len: usize) -> usize {
    println!("[DEBUG] resolve_rip: Разрешение RIP для инструкции по адресу 0x{:X}", instruction_addr);

    // Читаем 4-байтовое смещение из тела инструкции
    let displacement_addr = instruction_addr + offset_in_instruction;
    let displacement = *( displacement_addr as *const i32 ) as i64;
    println!("[DEBUG] resolve_rip: Прочитано смещение (displacement): 0x{:X} по адресу 0x{:X}", displacement, displacement_addr);

    // В x64 RIP указывает на СЛЕДУЮЩУЮ инструкцию, поэтому прибавляем её длину
    let rip = (instruction_addr + instruction_len) as i64;
    println!("[DEBUG] resolve_rip: Значение регистра RIP (адрес следующей инструкции): 0x{:X}", rip);

    let resolved = (rip + displacement) as usize;
    println!("[DEBUG] resolve_rip: Итоговый абсолютный адрес: 0x{:X}", resolved);

    resolved
}

// Универсальная функция установки Mid-Function хука
/// Ищет и выделяет страницу памяти в радиусе +-2 ГБ от целевого адреса
unsafe fn allocate_relay_cave(target_addr: usize) -> Option<usize> {
    let min_addr = target_addr.saturating_sub(0x7FFF0000);
    let max_addr = target_addr.saturating_add(0x7FFF0000);

    // Идем назад от адреса инъекции с шагом в 64 КБ (гранулярность выделения Windows)
    let mut search_addr = (target_addr & !0xFFFF) - 0x10000;
    while search_addr > min_addr {
        let alloc = VirtualAlloc(search_addr as _, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        if !alloc.is_null() {
            return Some(alloc as usize);
        }
        search_addr -= 0x10000;
    }

    // Если назад не получилось, идем вперед
    let mut search_addr = (target_addr & !0xFFFF) + 0x10000;
    while search_addr < max_addr {
        let alloc = VirtualAlloc(search_addr as _, 4096, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        if !alloc.is_null() {
            return Some(alloc as usize);
        }
        search_addr += 0x10000;
    }

    None
}

// Модифицированная функция установки хука "от А до Я"
pub unsafe fn install_hook(
    pattern: &str,
    hook_len: usize,
    naked_fn: unsafe extern "C" fn(), // Лучше использовать стандартный "C" или "win64" для Windows
    return_addr: *mut usize,
) {
    assert!(hook_len >= 5, "Длина оригинальной инструкции должна быть не менее 5 байт для JMP!");

    // 1. Ищем адрес в игре
    let inject_addr = find_pattern(pattern).expect("Паттерн не найден!");

    // 2. Считаем адрес возврата в игру
    *return_addr = inject_addr + hook_len;

    // 3. Создаем Relay Cave в радиусе 2 ГБ от игры
    let cave_addr = allocate_relay_cave(inject_addr).expect("Не удалось выделить Relay Cave в радиусе 2 ГБ!");
    println!("[DEBUG] Выделен Relay Cave по адресу: 0x{:X}", cave_addr);

    // 4. Заполняем Relay Cave абсолютным 14-байтовым прыжком на нашу Rust DLL функцию
    // Инструкция: jmp [rip + 0] -> FF 25 00 00 00 00 [8 байт абсолютного адреса]
    let cave_slice = std::slice::from_raw_parts_mut(cave_addr as *mut u8, 14);
    cave_slice[0] = 0xFF;
    cave_slice[1] = 0x25;
    cave_slice[2] = 0x00;
    cave_slice[3] = 0x00;
    cave_slice[4] = 0x00;
    cave_slice[5] = 0x00;
    let naked_fn_addr = naked_fn as usize;
    cave_slice[6..14].copy_from_slice(&naked_fn_addr.to_le_bytes());

    // 5. Открываем память игры для записи хука
    let mut old_protect = 0;
    windows_sys::Win32::System::Memory::VirtualProtect(
        inject_addr as _,
        hook_len,
        windows_sys::Win32::System::Memory::PAGE_EXECUTE_READWRITE,
        &mut old_protect,
    );

    // 6. Считаем относительное смещение от игры до нашего Relay Cave (для 5-байтового JMP)
    // Формула: Cave - (Inject + 5)
    let jmp_offset = cave_addr.wrapping_sub(inject_addr + 5) as u32;

    // 7. Пишем 5-байтовый относительный JMP в игру
    let game_slice = std::slice::from_raw_parts_mut(inject_addr as *mut u8, hook_len);
    game_slice[0] = 0xE9; // Относительный JMP
    game_slice[1..5].copy_from_slice(&jmp_offset.to_le_bytes());

    // 8. Забиваем NOP-ами оставшиеся байты оригинальной инструкции игры
    if hook_len > 5 {
        for i in 5..hook_len {
            game_slice[i] = 0x90; // NOP
        }
    }

    // 9. Восстанавливаем права на память игры
    windows_sys::Win32::System::Memory::VirtualProtect(
        inject_addr as _,
        hook_len,
        old_protect,
        &mut old_protect,
    );

    println!("[DEBUG] Хук успешно установлен через Relay Cave!\n");
}