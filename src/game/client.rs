use std::ptr::{null, null_mut};
use std::sync::OnceLock;
use std::thread;

use windows_sys::Win32::Foundation::HMODULE;
use windows_sys::Win32::System::Console::AllocConsole;
use windows_sys::Win32::System::LibraryLoader::GetModuleHandleA;

use std::ptr::addr_of_mut;

use crate::memory::*;
use crate::game::hooks::*;

#[derive(Debug)]
#[repr(C)]
pub struct Client {
    pub game_base_address: usize,
}

pub static CLIENT: OnceLock<Client> = OnceLock::new();



unsafe fn init_game_hooks() {
    unsafe {
        install_hook(crate::config::PLAYER_AOB, 7, crate::game::hooks::hook_player, addr_of_mut!(crate::game::hooks::PLAYER_RET));
        install_hook(crate::config::RADAR_AOB, 9, crate::game::hooks::hook_radar, addr_of_mut!(crate::game::hooks::RADAR_RET));
        install_hook(crate::config::FOV_AOB, 8, crate::game::hooks::hook_fov, addr_of_mut!(crate::game::hooks::FOV_RET));
        install_hook(crate::config::MOUSE_AOB, 7, crate::game::hooks::hook_mouse, addr_of_mut!(crate::game::hooks::MOUSE_RET));
        install_hook(crate::config::MOVEMENT_CTRL_AOB, 6, crate::game::hooks::hook_movement, addr_of_mut!(crate::game::hooks::MOVEMENT_RET));
        install_hook(crate::config::ENTITY_TEST_AOB, 8, crate::game::hooks::hook_player_struct, addr_of_mut!(crate::game::hooks::PLAYER_STRUCT_RET));
    }
}

pub unsafe fn client_initialization() -> bool {
    unsafe { AllocConsole(); }
    println!("[Rust DLL] Успешно внедрились в процесс!");

    let game_handle: HMODULE = unsafe { GetModuleHandleA(null()) };

    if game_handle == null_mut() {
        println!("[PathToBot] Не удалось получить базовый адрес процесса!");
        return false;
    }

    let client_instance = Client { game_base_address: game_handle as usize };
    println!("[Rust DLL] Создан объект: {:?}", client_instance);

    CLIENT.set(client_instance)
        .expect("Ошибка инициализации CLIENT");

    // 1. Mid-function хуки
    println!("[hooks] Установка mid-function хуков...");
    unsafe { init_game_hooks(); }
    println!("[hooks] Mid-function хуки установлены");

    // 2. MinHook хук — перехват ProcessMoveRequest + подмена аргументов
    println!("[bot] Установка MinHook для ProcessMoveRequest...");
    unsafe { crate::bot::install(); }
    println!("[bot] ProcessMoveRequest хук установлен");

    // 3. Ждём 2 секунды, пока хуки подхватят данные
    println!("[client] Ожидание 2 сек...");
    thread::sleep(std::time::Duration::from_secs(2));

    // 4. Основной цикл — вывод координат в реальном времени
    println!("[client] Координаты персонажа:");
    loop {
        thread::sleep(std::time::Duration::from_millis(500));

        if let Some(player_struct_ptr) = get_player_struct() {
            unsafe {
                let x = *((player_struct_ptr + 0x2B8) as *const f32);
                let y = *((player_struct_ptr + 0x2BC) as *const f32);
                println!("Cord, Cord | {:.1}, {:.1}", x, y);
            }
        }
    }
}
