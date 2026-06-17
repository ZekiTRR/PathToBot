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

/// Смещения координат персонажа внутри entity struct (из IDA)
const OFFSET_POS_X: usize = 0x2B8;
const OFFSET_POS_Y: usize = 0x2BC;

unsafe fn init_game_hooks() {
    unsafe {
        install_hook(crate::config::PLAYER_AOB, 7, hook_player, addr_of_mut!(PLAYER_RET));
        install_hook(crate::config::RADAR_AOB, 9, hook_radar, addr_of_mut!(RADAR_RET));
        install_hook(crate::config::FOV_AOB, 8, hook_fov, addr_of_mut!(FOV_RET));
        install_hook(crate::config::MOUSE_AOB, 7, hook_mouse, addr_of_mut!(MOUSE_RET));
        install_hook(crate::config::MOVEMENT_CTRL_AOB, 6, hook_movement, addr_of_mut!(MOVEMENT_RET));
        install_hook(crate::config::ENTITY_TEST_AOB, 8, hook_player_struct, addr_of_mut!(PLAYER_STRUCT_RET));
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

    // Mid-function хуки
    println!("[hooks] Установка mid-function хуков...");
    unsafe { init_game_hooks(); }
    println!("[hooks] Mid-function хуки установлены");

    // MinHook хук — перехват ProcessMoveRequest + подмена аргументов
    println!("[bot] Установка MinHook для ProcessMoveRequest...");
    unsafe { crate::bot::install(); }
    println!("[bot] ProcessMoveRequest хук установлен");

    // Ожидание 2 сек, пока хуки подхватят данные
    println!("[client] Ожидание 2 сек...");
    thread::sleep(std::time::Duration::from_secs(2));

    // Основной цикл — вывод координат в реальном времени
    println!("[client] Координаты персонажа:");
    loop {
        thread::sleep(std::time::Duration::from_millis(500));

        if let Some(player_struct_ptr) = get_player_struct() {
            unsafe {
                let x = *((player_struct_ptr + OFFSET_POS_X) as *const f32);
                let y = *((player_struct_ptr + OFFSET_POS_Y) as *const f32);
                println!("Cord, Cord | {:.1}, {:.1}", x, y);
            }
        }
    }
}
