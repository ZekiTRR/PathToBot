use windows_sys::Win32::System::LibraryLoader::GetModuleHandleA;
use windows_sys::Win32::System::ProcessStatus::{K32GetModuleInformation, MODULEINFO};
use windows_sys::Win32::System::Threading::GetCurrentProcess;
use windows_sys::Win32::System::Memory::{
    VirtualQuery, MEMORY_BASIC_INFORMATION, MEM_COMMIT, PAGE_EXECUTE_READ,
    PAGE_EXECUTE_READWRITE, PAGE_GUARD, PAGE_NOACCESS, PAGE_READONLY, PAGE_READWRITE,
    VirtualAlloc, MEM_RESERVE,
};

use std::ops::Range;

/// Переводит строку паттерна "48 8B 05 ?? ?? ?? ??" в Vec<Option<u8>>
fn parse_pattern(pattern: &str) -> Vec<Option<u8>> {
    pattern
        .split_whitespace()
        .map(|b| {
            if b == "?" || b == "??" {
                None
            } else {
                Some(u8::from_str_radix(b, 16).unwrap_or(0))
            }
        })
        .collect()
}

/// Диапазон адресов главного модуля текущего процесса
unsafe fn get_module_range() -> Range<usize> {
    let process = GetCurrentProcess();
    let module = GetModuleHandleA(std::ptr::null());

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

/// AOB-сканер. Возвращает адрес начала совпадения.
pub unsafe fn find_pattern(pattern: &str) -> Option<usize> {
    let parsed = parse_pattern(pattern);
    let range = get_module_range();
    let mut current_addr = range.start;

    while current_addr < range.end {
        let mut mbi: MEMORY_BASIC_INFORMATION = std::mem::zeroed();

        let res = VirtualQuery(
            current_addr as *const _,
            &mut mbi,
            std::mem::size_of::<MEMORY_BASIC_INFORMATION>(),
        );

        if res == 0 {
            break;
        }

        let is_committed = mbi.State == MEM_COMMIT;
        let is_readable = (mbi.Protect
            & (PAGE_READONLY | PAGE_READWRITE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE))
            != 0;
        let is_guarded_or_noaccess = (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) != 0;

        if is_committed && is_readable && !is_guarded_or_noaccess {
            let region_start = current_addr;
            let region_end = (current_addr + mbi.RegionSize).min(range.end);

            if region_end - region_start >= parsed.len() {
                let memory_slice =
                    std::slice::from_raw_parts(region_start as *const u8, region_end - region_start);

                'outer: for i in 0..=(memory_slice.len() - parsed.len()) {
                    for j in 0..parsed.len() {
                        if let Some(pattern_byte) = parsed[j] {
                            if memory_slice[i + j] != pattern_byte {
                                continue 'outer;
                            }
                        }
                    }
                    return Some(region_start + i);
                }
            }
        }

        current_addr += mbi.RegionSize;
    }

    None
}

/// Разрешает RIP-относительные адреса (x64)
pub unsafe fn resolve_rip(
    instruction_addr: usize,
    offset_in_instruction: usize,
    instruction_len: usize,
) -> usize {
    let displacement_addr = instruction_addr + offset_in_instruction;
    let displacement = *(displacement_addr as *const i32) as i64;
    let rip = (instruction_addr + instruction_len) as i64;
    (rip + displacement) as usize
}

/// Выделяет страницу памяти в радиусе ±2 ГБ от целевого адреса
unsafe fn allocate_relay_cave(target_addr: usize) -> Option<usize> {
    let min_addr = target_addr.saturating_sub(0x7FFF0000);
    let max_addr = target_addr.saturating_add(0x7FFF0000);

    let mut search_addr = (target_addr & !0xFFFF) - 0x10000;
    while search_addr > min_addr {
        let alloc = VirtualAlloc(
            search_addr as _,
            4096,
            MEM_COMMIT | MEM_RESERVE,
            PAGE_EXECUTE_READWRITE,
        );
        if !alloc.is_null() {
            return Some(alloc as usize);
        }
        search_addr -= 0x10000;
    }

    let mut search_addr = (target_addr & !0xFFFF) + 0x10000;
    while search_addr < max_addr {
        let alloc = VirtualAlloc(
            search_addr as _,
            4096,
            MEM_COMMIT | MEM_RESERVE,
            PAGE_EXECUTE_READWRITE,
        );
        if !alloc.is_null() {
            return Some(alloc as usize);
        }
        search_addr += 0x10000;
    }

    None
}

/// Установка mid-function хука через Relay Cave
pub unsafe fn install_hook(
    pattern: &str,
    hook_len: usize,
    naked_fn: unsafe extern "C" fn(),
    return_addr: *mut usize,
) {
    assert!(hook_len >= 5, "Длина инструкции должна быть не менее 5 байт для JMP");

    let inject_addr = find_pattern(pattern).expect("Паттерн не найден!");
    *return_addr = inject_addr + hook_len;

    let cave_addr = allocate_relay_cave(inject_addr)
        .expect("Не удалось выделить Relay Cave в радиусе 2 ГБ!");

    // Заполняем Relay Cave: FF 25 00 00 00 00 [8 байт абсолютного адреса]
    let cave_slice = std::slice::from_raw_parts_mut(cave_addr as *mut u8, 14);
    cave_slice[0] = 0xFF;
    cave_slice[1] = 0x25;
    cave_slice[2..6].copy_from_slice(&[0x00, 0x00, 0x00, 0x00]);
    cave_slice[6..14].copy_from_slice(&(naked_fn as usize).to_le_bytes());

    // Пишем 5-байтовый относительный JMP в игру
    let mut old_protect = 0;
    windows_sys::Win32::System::Memory::VirtualProtect(
        inject_addr as _,
        hook_len,
        PAGE_EXECUTE_READWRITE,
        &mut old_protect,
    );

    let jmp_offset = cave_addr.wrapping_sub(inject_addr + 5) as u32;
    let game_slice = std::slice::from_raw_parts_mut(inject_addr as *mut u8, hook_len);
    game_slice[0] = 0xE9;
    game_slice[1..5].copy_from_slice(&jmp_offset.to_le_bytes());

    if hook_len > 5 {
        for i in 5..hook_len {
            game_slice[i] = 0x90;
        }
    }

    windows_sys::Win32::System::Memory::VirtualProtect(
        inject_addr as _,
        hook_len,
        old_protect,
        &mut old_protect,
    );
}
