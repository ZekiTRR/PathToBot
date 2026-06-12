use std::sync::OnceLock;

// Подключаем константы из модуля offsets
use crate::utility::offsets::*;
use crate::client;

#[derive(Debug)]
struct FOV {
    fov_address: usize,
}

// Статический кеш для хранения вычисленных адресов.
static FOV_CACHE: OnceLock<FOV> = OnceLock::new();

// Делаем функцию публичной, чтобы ее можно было вызвать из других модулей
pub unsafe fn change_fov(new_fov_value: f32) {
    let fov_memory = FOV_CACHE.get_or_init(|| {
        println!("[PathToBot] Первое выполнение: вычисление указателей FOV...");

        let client_info = match client::CLIENT.get() {
            Some(info) => info,
            None => panic!("Клиент не инициализирован!"),
        };

        let game_base = client_info.game_base_address;

        let lvl1_ptr = (game_base + OFFSET_CAMERA_BASE) as *const usize;
        if lvl1_ptr.is_null() { panic!("lvl1_ptr is null"); }
        let lvl1_address = *lvl1_ptr;
        if lvl1_address == 0 { panic!("Камера еще не создана (lvl1 == 0)"); }

        let lvl2_ptr = (lvl1_address + OFFSET_CAMERA_LVL1) as *const usize;
        let lvl2_address = *lvl2_ptr;
        if lvl2_address == 0 { panic!("Камера еще не создана (lvl2 == 0)"); }

        let fov_address = lvl2_address + OFFSET_CAMERA_FOV;

        FOV { fov_address }
    });

    let fov_ptr = fov_memory.fov_address as *mut f32;
    *fov_ptr = new_fov_value;

    println!("[PathToBot] FOV успешно изменен на: {}", new_fov_value);
}