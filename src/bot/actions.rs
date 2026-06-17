use std::sync::OnceLock;

use super::{MoveRequest, Vector2D};

/// Наша целевая точка — статическая переменная, на которую перенаправляем указатель.
/// Не затирает внутреннюю память игры — мы только переключаем p_target_pos на этот адрес.
static MY_CUSTOM_TARGET: OnceLock<Vector2D> = OnceLock::new();

/// Смещения внутри pMovementController для чтения текущих координат персонажа (из IDA)
const OFFSET_CURRENT_X: usize = 660;
const OFFSET_CURRENT_Y: usize = 664;

/// Порог расстояния: если персонаж уже рядом с целью — не подменяем,
/// даём оригинальной игре обработать запрос.
const DISTANCE_THRESHOLD: i32 = 15;

/// Вызывается из detour-функции, когда pMovementController принадлежит локальному игроку.
///
/// Подменяет указатель `p_target_pos` на статическую переменную `MY_CUSTOM_TARGET`,
/// задавая новые координаты назначения. Оригинальная память игры не затирается.
pub unsafe fn on_process_move_request(
    p_movement_controller: i64,
    request: &mut MoveRequest,
) {
    // Инициализируем целевую точку один раз
    let target = MY_CUSTOM_TARGET.get_or_init(|| Vector2D { x: 2157, y: 1722 });
    let position_ptr_address = unsafe {
        *( (p_movement_controller + 0x660) as *const usize )
    };
    // Читаем текущие координаты персонажа из контроллера
    let current_x = unsafe {
        *((p_movement_controller + OFFSET_CURRENT_X as i64) as *const i32)
    };
    let current_y = unsafe {
        *((p_movement_controller + OFFSET_CURRENT_Y as i64) as *const i32)
    };

    // Если персонаж уже в радиусе цели — не подменяем, даём игре самой дойти
    if (current_x - target.x).abs() < DISTANCE_THRESHOLD
        && (current_y - target.y).abs() < DISTANCE_THRESHOLD
    {
        return;
    }

    // Перенаправляем указатель на нашу статическую точку
    // Оригинальная память игры НЕ изменяется — мы просто меняем, куда смотрит указатель
    request.p_target_pos = target as *const Vector2D as *mut Vector2D;

    // Параметры запроса
    request.tolerance = 5.0;
    //request.interrupt_flag = 1;
}
