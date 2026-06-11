use std::ffi::c_void;
use std::thread;

// Имортируем родные типы и константы Windows
use windows_sys::Win32::Foundation::{HMODULE, TRUE, FALSE};
use windows_sys::core::BOOL; // BOOL
use windows_sys::Win32::System::SystemServices::{DLL_PROCESS_ATTACH, DLL_PROCESS_DETACH};
use windows_sys::Win32::System::Console::{AllocConsole, FreeConsole};

// Создадим псевдоним для LPVOID
type LPVOID = *mut c_void;

#[unsafe(no_mangle)]
#[allow(non_snake_case)]
pub unsafe extern "system" fn DllMain(
    _h_module: HMODULE,
    dw_reason: u32,         // В WinAPI это DWORD (u32 в Rust)
    _lp_reserved: LPVOID,
) -> BOOL {
    match dw_reason { // switch
        DLL_PROCESS_ATTACH => {
            thread::spawn(|| {
                unsafe { my_inside_logic(); }
            });
        }
        DLL_PROCESS_DETACH => {}
        _ => {} // Дефолтный кейс. _ означает "любое другое значение". Тут можно ничего не делать
    }
    TRUE // (равна 1)
}


unsafe fn my_inside_logic() {
    // Открываем консоль внутри чужого процесса, чтобы видеть наш println!
    unsafe {
    AllocConsole();
    println!("[Rust DLL] Успешно внедрились в процесс!");


    // Бесконечный цикл, чтобы поток не умирал #placeholder
    // В реальном проекте здесь будет ваш цикл обработки
    loop {
        thread::sleep(std::time::Duration::from_millis(100));
    }
}

}