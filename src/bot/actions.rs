use std::sync::OnceLock;

use super::{MoveRequest, Vector2D};

static MY_CUSTOM_TARGET: OnceLock<Vector2D> = OnceLock::new();

const OFFSET_CURRENT_X: usize = 660;
const OFFSET_CURRENT_Y: usize = 664;
const DISTANCE_THRESHOLD: i32 = 15;

pub unsafe fn on_process_move_request(
    p_movement_controller: i64,
    request: &mut MoveRequest,
) {
    let target = MY_CUSTOM_TARGET.get_or_init(|| Vector2D { x: 2157, y: 1722 });

    let current_x = unsafe {
        *((p_movement_controller + OFFSET_CURRENT_X as i64) as *const i32)
    };
    let current_y = unsafe {
        *((p_movement_controller + OFFSET_CURRENT_Y as i64) as *const i32)
    };

    if (current_x - target.x).abs() < DISTANCE_THRESHOLD
        && (current_y - target.y).abs() < DISTANCE_THRESHOLD
    {
        return;
    }

    request.p_target_pos = target as *const Vector2D as *mut Vector2D;
    request.tolerance = 5.0;
}
