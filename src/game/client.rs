// Получить базовый адрес игры и сохранить в контейнер

use std::ptr::{null, null_mut};
use windows_sys::Win32::System::Console::AllocConsole;
use windows_sys::Win32::System::LibraryLoader::GetModuleHandleA;
use windows_sys::Win32::Foundation::HMODULE;
use std::sync::OnceLock;
use std::thread;

use std::ptr::addr_of_mut;

use crate::memory::*;
use crate::game::hooks::*;



#[derive(Debug)]
#[repr(C)]
pub struct Client {
    pub game_base_address: usize,
}

pub static CLIENT: OnceLock<Client> = OnceLock::new();


unsafe fn init_game_hooks()
{
    // Обращение к static mut переменной должно быть в unsafe блоке
    unsafe {
        install_hook(crate::config::PLAYER_AOB, 7, crate::game::hooks::hook_player, addr_of_mut!(crate::game::hooks::PLAYER_RET));
        install_hook(crate::config::RADAR_AOB, 9, crate::game::hooks::hook_radar, addr_of_mut!(crate::game::hooks::RADAR_RET));
        install_hook(crate::config::FOV_AOB, 8, crate::game::hooks::hook_fov, addr_of_mut!(crate::game::hooks::FOV_RET));
        install_hook(crate::config::MOUSE_AOB, 7, crate::game::hooks::hook_mouse, addr_of_mut!(crate::game::hooks::MOUSE_RET));
        install_hook(crate::config::MOVEMENT_CTRL_AOB, 6, crate::game::hooks::hook_movement, addr_of_mut!(crate::game::hooks::MOVEMENT_RET));
    }
}
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

    println!("[hooks] Попытка установки хуков");
    init_game_hooks();
    println!("[hooks] Хуки установлены");


    loop {
        thread::sleep(std::time::Duration::from_millis(1000));
    }

    true
}