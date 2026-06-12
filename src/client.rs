// Убираем некорректное объявление `mod fov;`
// Добавляем правильный импорт функции
use crate::utility::fov::change_fov;

use std::ptr::{null, null_mut};
use windows_sys::Win32::System::Console::AllocConsole;
use windows_sys::Win32::System::LibraryLoader::GetModuleHandleA;
use windows_sys::Win32::Foundation::HMODULE;
use std::sync::OnceLock;

#[derive(Debug)]
#[repr(C)]
pub struct Client {
    pub game_base_address: usize,
}

pub static CLIENT: OnceLock<Client> = OnceLock::new();

pub unsafe fn client_initialization() -> bool {
    AllocConsole();
    println!("[Rust DLL] Успешно внедрились в процесс!");

    let game_handle: HMODULE = GetModuleHandleA(null());

    if game_handle == null_mut() {
        println!("[PathToBot] Не удалось получить базовый адрес процесса!");
        return false;
    }

    let client_instance = Client { game_base_address: game_handle as usize };
    println!("[Rust DLL] Создан объект: {:?}", client_instance);

    CLIENT.set(client_instance)
        .expect("Ошибка инициализации CLIENT");

    // Теперь мы можем вызывать функцию из другого модуля
    let mut fov_value = 2.0;
    loop {
        change_fov(fov_value);

        std::thread::sleep(std::time::Duration::from_millis(10));
    }

    true
}