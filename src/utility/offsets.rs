use std::ffi::c_void;

#[repr(C)] // Нужен для точного воссоздания структуры в памяти
pub struct Hud {
    pub _unused: u8, // sizeof=0x1 (Rust не разрешает пустые repr(C) структуры размера 0)
}

#[repr(C)]
pub struct Player {
    pub pad_000: [u8; 52],
    pub speed: f32,
    pub pad_038: [u8; 536],
    pub start_position_x: f32,
    pub start_position_y: f32,
    pub pad_258: [u8; 96],
    pub player_pos_x: f32,
    pub player_pos_y: f32,
}

#[repr(C)]
pub struct Render {
    pub pad0: [u8; 68],
    pub b_is_fov_locked: u8, // std::byte эквивалентен u8
    pub pad1: [u8; 59],
    pub p_renderer: *mut RendererBackend,
    pub pad2: [u8; 16],
    pub p_camera: *mut Camera,
    pub pad3: [u8; 1024],
    pub viewport_x: i32,
    pub viewport_width: i32,
    pub process_fov: f32,
    pub pad4: [u8; 4],
    pub fov: f32,
    pub pad_end: [u8; 4],
}

#[repr(C)]
pub struct Camera {
    pub _unused: u8, // sizeof=0x1
}

#[repr(C)]
pub struct RendererBackend {
    pub _unused: u8, // sizeof=0x1
}

// Опережающее объявление (Opaque struct)
#[repr(C)]
pub struct UiSettingWidget {
    _private: [u8; 0],
}

#[repr(C)]
pub struct OptionsUiController {
    pub p_base_panel_context: *mut c_void,
    pub pad_base: [u8; 96],
    pub p_options_context: *mut UiSettingWidget,
    pub pad_070: [u8; 56],
    pub p_show_corner_map_widget: *mut UiSettingWidget,
    pub p_auto_recenter_map_widget: *mut UiSettingWidget,
    pub p_always_show_sockets: *mut UiSettingWidget,
    pub p_always_attack_in_place: *mut UiSettingWidget,
    pub p_attack_in_place_stops_move: *mut UiSettingWidget,
    pub p_show_full_ground_descs: *mut UiSettingWidget,
    pub p_show_life_levels: *mut UiSettingWidget,
    pub p_hide_reservation_levels: *mut UiSettingWidget,
    pub p_show_flask_buffs: *mut UiSettingWidget,
    pub p_show_aura_icons: *mut UiSettingWidget,
    pub p_show_global_chat: *mut UiSettingWidget,
    pub p_show_trade_chat: *mut UiSettingWidget,
    pub p_show_guild_chat: *mut UiSettingWidget,
    pub p_show_chat_timestamps: *mut UiSettingWidget,
    pub p_screen_shake_v2: *mut UiSettingWidget,
    pub p_unknown_vtable848: *mut UiSettingWidget,
    pub pad_128: [u8; 8],
    pub p_camera_z_rotation: *mut UiSettingWidget,
    pub p_minimap_geometry_alpha: *mut UiSettingWidget,
    pub p_minimap_walk_alpha: *mut UiSettingWidget,
    pub p_minimap_zoom: *mut UiSettingWidget,
    pub p_show_ally_mini_life_bars: *mut UiSettingWidget,
    pub p_show_enemy_mini_life_bars: *mut UiSettingWidget,
    pub p_show_player_mini_life_bar: *mut UiSettingWidget,
    pub p_show_ally_names_on_map: *mut UiSettingWidget,
    pub p_map_overlay_mods_hidden: *mut UiSettingWidget,
    pub pad_178: [u8; 16],
    pub p_show_clock: *mut UiSettingWidget,
    pub p_hide_remove_only_tabs: *mut UiSettingWidget,
    pub p_output_dialogue_to_chat: *mut UiSettingWidget,
    pub p_quest_tracking: *mut UiSettingWidget,
    pub p_add_support_gem_popup1: *mut UiSettingWidget,
    pub p_add_support_gem_popup2: *mut UiSettingWidget,
    pub p_chat_box_font_size: *mut UiSettingWidget,
    pub p_always_highlight: *mut UiSettingWidget,
    pub p_always_highlight_gamepad: *mut UiSettingWidget,
    pub p_language_dropdown: *mut UiSettingWidget,
    pub p_chat_lang_dropdown: *mut UiSettingWidget,
    pub p_enable_profanity_filter: *mut UiSettingWidget,
    pub p_reduce_ui_animations: *mut UiSettingWidget,
    pub p_cursor_manager: *mut c_void,
    pub p_cursor_hover_image: *mut UiSettingWidget,
    pub p_cursor_pressed_image: *mut UiSettingWidget,
    pub pad_208: [u8; 8],
    pub p_confine_mouse_to_window: *mut UiSettingWidget,
    pub p_always_highlight2: *mut UiSettingWidget,
    pub p_mouse_wheel_zoom: *mut UiSettingWidget,
    pub p_hide_email: *mut UiSettingWidget,
    pub p_unknown_setting1: *mut UiSettingWidget,
    pub pad_238: [u8; 8],
    pub p_show_resistance_icons: *mut UiSettingWidget,
}





pub const OFFSET_CAMERA_BASE: usize = 0x04382DE8; // Базовый указатель на камеру
pub const OFFSET_CAMERA_LVL1: usize = 0x1F8;      // Первый оффсет
pub const OFFSET_CAMERA_FOV: usize = 0x4B0;       // Финальный оффсет до FOV