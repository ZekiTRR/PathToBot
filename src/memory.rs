use minhook::{MinHook, MH_STATUS};
use std::sync::atomic::{AtomicUsize, Ordering};

use windows_sys::Win32::System::LibraryLoader::GetModuleHandleA;
use windows_sys::Win32::System::ProcessStatus::{K32GetModuleInformation, MODULEINFO};
use windows_sys::Win32::System::Threading::GetCurrentProcess;

use std::ops::Range;
use std::arch::asm;

/// Функция переводит строку паттерна вида "48 8B 05 ?? ?? ?? ??" в вектор Опций
fn parse_pattern(pattern: &str) -> Vec<Option<u8>> {
    pattern
        .split_whitespace() // Разбивает по пробелам
        .map(|b| {
            if b == "?" || b == "??" {
                None
            } else {
                Some(u8::from_str_radix(b, 16).unwrap_or(0)) // Парсим число как шестнадцатеричное
            }
        })
        .collect() // Собирает результаты итератора в финальный контейнер Vec<Option<u8>>
}

/// Получает диапазон адресов (начало..конец) главного модуля текущего процесса
unsafe fn get_module_range() -> Range<usize> {
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

    start..end
}

/// Основная функция АОБ-скана. Возвращает адрес начала совпадения.
pub unsafe fn find_pattern(pattern: &str) -> Option<usize> {
    let parsed = parse_pattern(pattern);
    let range = get_module_range();

    let memory_slice = std::slice::from_raw_parts(range.start as *const u8, range.end - range.start);

    'outer: for i in 0..(memory_slice.len() - parsed.len()) { // Что бы не выйти за массив
        for j in 0..parsed.len() {
            if let Some(pattern_byte) = parsed[j] {
                if memory_slice[i + j] != pattern_byte {
                    continue 'outer;
                }
            }
        }
        // Если дошли сюда — паттерн совпал
        return Some(range.start + i);
    }
    None
}

/// Специальная функция для x64. Разрешает RIP-относительные адреса (например, в инструкциях MOV)
/// `instruction_addr` — адрес найденной инструкции
/// `offset_in_instruction` — через сколько байт от начала инструкции лежит 4-байтовое смещение
/// `instruction_len` — полная длина инструкции в байтах
pub unsafe fn resolve_rip(instruction_addr: usize, offset_in_instruction: usize, instruction_len: usize) -> usize {
    // Читаем 4-байтовое смещение из тела инструкции
    let displacement = *( (instruction_addr + offset_in_instruction) as *const i32 ) as i64;
    // В x64 RIP указывает на СЛЕДУЮЩУЮ инструкцию, поэтому прибавляем её длину
    let rip = (instruction_addr + instruction_len) as i64;

    (rip + displacement) as usize
}


// Универсальная функция установки Mid-Function хука
pub unsafe fn install_hook(
    pattern: &str,
    hook_len: usize,                       // Длина оригинальной инструкции (сколько байт затираем)
    naked_fn: unsafe extern "sysv64" fn(), // Функция-капкан
    return_addr: *mut usize,               // Ссылка на переменную, куда запишется адрес возврата
) {
    // 1. Ищем адрес
    let inject_addr = find_pattern(pattern).expect("Один из паттернов не найден!");

    // 2. Считаем и сохраняем адрес возврата
    *return_addr = inject_addr + hook_len;

    // 3. Открываем память для записи
    let mut old_protect = 0;
    windows_sys::Win32::System::Memory::VirtualProtect(
        inject_addr as _,
        hook_len,
        windows_sys::Win32::System::Memory::PAGE_EXECUTE_READWRITE,
        &mut old_protect,
    );

    // 4. Математика прыжка: Target - (Inject + 5)
    let jmp_offset = (naked_fn as usize).wrapping_sub(inject_addr + 5) as u32;

    // 5. Пишем JMP и дистанцию
    let slice = std::slice::from_raw_parts_mut(inject_addr as *mut u8, hook_len);
    slice[0] = 0xE9; // JMP
    slice[1..5].copy_from_slice(&jmp_offset.to_le_bytes());

    // 6. Добиваем остаток NOP-ами (динамически, в зависимости от hook_len)
    for i in 5..hook_len {
        slice[i] = 0x90;
    }

    // 7. Закрываем память
    windows_sys::Win32::System::Memory::VirtualProtect(
        inject_addr as _,
        hook_len,
        old_protect,
        &mut old_protect,
    );
}