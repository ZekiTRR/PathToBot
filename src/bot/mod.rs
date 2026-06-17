pub mod actions;

use std::ffi::c_void;
use std::sync::atomic::{AtomicUsize, Ordering};

use crate::game::hooks::get_movement;
use crate::memory::find_pattern;
use minhook::MinHook;

// ==========================================
// Структуры данных (Единый источник правды)
// ==========================================

/// Координаты сетки (grid coordinates) — целочисленные значения.
#[derive(Debug, Copy, Clone)]
#[repr(C)]
pub struct Vector2D {
    pub x: i32,
    pub y: i32,
}

/// Запрос на перемещение персонажа.
#[repr(C)]
pub struct MoveRequest {
    pub p_target_pos: *mut Vector2D,     // 0x00 — указатель на координаты назначения
    pub tolerance: f32,                   // 0x08 — радиус погрешности
    pub target_entity_id: u32,            // 0x0C — ID целевой сущности
    pub _pad_0010: [u8; 56],             // 0x10
    pub p_callback1: *mut c_void,        // 0x48
    pub _pad_0050: [u8; 56],             // 0x50
    pub p_callback2: *mut c_void,        // 0x88
    pub state_byte1: u8,                  // 0x90
    pub has_state_byte1: u8,              // 0x91
    pub state_byte2: u8,                  // 0x92
    pub state_byte3: u8,                  // 0x93
    pub has_state_byte3: u8,              // 0x94
    pub interrupt_flag: u8,               // 0x95
}

// ==========================================
// Сигнатура оригинальной функции
// ==========================================
type ProcessMoveRequestFn = unsafe extern "system" fn(i64, *mut MoveRequest) -> *mut c_void;
static ORIGINAL_FN: AtomicUsize = AtomicUsize::new(0);

// ==========================================
// Detour-функция (хук)
// ==========================================
#[unsafe(no_mangle)]
pub unsafe extern "system" fn hook_process_move_request(
    p_movement_controller: i64,
    p_move_request: *mut MoveRequest,
) -> *mut c_void {
    if let Some(local_movement) = get_movement() {
        if p_movement_controller as usize == local_movement {
            // Передаем ссылку на ту же самую структуру MoveRequest
            actions::on_process_move_request(p_movement_controller, &mut *p_move_request);
        }
    }

    let original: ProcessMoveRequestFn = std::mem::transmute(ORIGINAL_FN.load(Ordering::Relaxed));
    original(p_movement_controller, p_move_request)
}

// ==========================================
// Установка хука через MinHook
// ==========================================
pub unsafe fn install() {
    let addr = unsafe { find_pattern(crate::config::PROCESS_MOVE_REQUEST_AOB) }
        .expect("[bot] AOB-паттерн ProcessMoveRequest не найден!");

    println!("[bot] ProcessMoveRequest найден по адресу: 0x{:X}", addr);

    let original_addr = MinHook::create_hook(
        addr as *mut c_void,
        hook_process_move_request as *mut c_void,
    )
        .expect("[bot] MinHook::create_hook() провалился!");

    ORIGINAL_FN.store(original_addr as usize, Ordering::Relaxed);

    MinHook::enable_all_hooks().expect("[bot] MinHook::enable_all_hooks() провалился!");
    println!("[bot] Хук ProcessMoveRequest установлен, original: 0x{:X}", original_addr as usize);
}