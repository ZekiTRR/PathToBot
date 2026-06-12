use crate::utility::offsets::*;
use std::sync::OnceLock;
use crate::client;


#[derive(Debug)]
struct Bool_enable_disable_parser_shor_Corner_map {
    bool_enable_disable_parser_shor_Corner_map_address: usize,
}

// Статический лок для хранения адреса функции-парсера
static Setting: OnceLock<Bool_enable_disable_parser_shor_Corner_map> = OnceLock::new();

pub unsafe fn toggle_corner_map(options_ui_controller_: *mut OptionsUiController) {
    if options_ui_controller_.is_null() {
        println!("[PathToBot] toggle_corner_map: options_ui_controller is null");
        return;
    }

    // Получаем pShowCornerMap_Widget
    let p_show_corner_map_widget = (*options_ui_controller_).p_show_corner_map_widget;
    if p_show_corner_map_widget.is_null() {
        println!("[PathToBot] toggle_corner_map: p_show_corner_map_widget is null");
        return;
    }

    // Читаем адрес vtable (первые 8 байт объекта)
    let vtable = *(p_show_corner_map_widget as *mut usize);

    // Сдвигаемся на 0x340 байт внутри vtable и читаем адрес функции-сеттера
    let func_address = *((vtable + 0x340) as *mut usize);

    // Превращаем голый адрес сеттера в вызываемую функцию
    let setter: unsafe extern "C" fn(*mut UiSettingWidget, u64, u64) = std::mem::transmute(func_address);

    // Получаем или инициализируем адрес парсера игры
    let parser_info = Setting.get_or_init(|| {
        println!("[PathToBot] Вычисление адреса Bool_enable_disable_parser_shor_Corner_map...");

        let client_info = match client::CLIENT.get() {
            Some(info) => info,
            None => panic!("Клиент не инициализирован!"),
        };

        let game_base = client_info.game_base_address;
        Bool_enable_disable_parser_shor_Corner_map {
            bool_enable_disable_parser_shor_Corner_map_address: game_base + 0x17E4F40
        }
    });

    let parser_addr = parser_info.bool_enable_disable_parser_shor_Corner_map_address;

    let bool_parser: unsafe extern "C" fn() -> bool = std::mem::transmute(parser_addr);

    // Вызываем парсер игры (получаем тот самый v9 из IDA)
    /*
    v9 = bool_enable_disable_parser_shor_Corner_map();
    setter(pShowCornerMap_Widget, v9, 0);
     */
    let v9 = bool_parser();

    // 9. Передаем результат парсера (v9 как u64) в сеттер виджета
    setter(p_show_corner_map_widget, v9 as u64, 0);
}

/*
    ФУНКЦИЯ НЕ ИСПОЛЬЗУЕТСЯ
    ОНА ЗДЕСЬ ДЛЯ НАГЛЯДНОГО ПРИМЕРА И КОРЕКТНОГО ВЫЗОВА
 */
pub unsafe fn setter_method(a1: *mut u8, a2: u8, a3: i8) -> i64 {
    // В IDA переменная `result` не инициализируется, если условие if не выполняется.
    // В Rust мы должны вернуть хоть какое-то дефолтное значение в таком случае.
    let mut result: i64 = 0;

    // a1[0x4D2] -> читаем байт по смещению 0x4D2
    let val_4d2 = *a1.add(0x4D2);

    if val_4d2 != a2 {
        // v5 = a1[0x4D4] == 0;
        let v5 = *a1.add(0x4D4) == 0;

        // a1[0x4D2] = a2;
        *a1.add(0x4D2) = a2;

        if !v5 {
            // (*(void (__fastcall **)(_QWORD))(**((_QWORD **)a1 + 127) + 96LL))(*((_QWORD *)a1 + 127));
            // 1. Получаем указатель по смещению: a1 + 127 * 8 байт (т.к. каст к QWORD*) = смещение 1016 (0x3F8)
            let ptr_127 = *(a1.add(127 * 8) as *mut *mut usize);
            // 2. Читаем vtable этого объекта: **ptr_127
            let vtable_127 = *ptr_127;
            // 3. Сдвигаемся в vtable на 96 байт и берем адрес функции
            let func_addr = *((vtable_127 + 96) as *mut usize);
            // 4. Декларируем и вызываем функцию
            let func: unsafe extern "C" fn(*mut usize) = std::mem::transmute(func_addr);
            func(ptr_127);
        }

        if a3 != 0 {
            // (*(void (__fastcall **)(unsigned __int8 *))(*(_QWORD *)a1 + 848LL))(a1);
            // 1. Читаем vtable самого объекта a1 (первые 8 байт)
            let vtable_a1 = *(a1 as *mut usize);
            // 2. Берем функцию по смещению 848
            let func_addr = *((vtable_a1 + 848) as *mut usize);
            let func: unsafe extern "C" fn(*mut u8) = std::mem::transmute(func_addr);
            // 3. Вызываем, передавая сам a1 (this)
            func(a1);
        }

        // return (*(__int64 (__fastcall **)(unsigned __int8 *, _QWORD))(*(_QWORD *)a1 + 840LL))(a1, a1[1234]);
        // 1. Снова берем vtable объекта a1
        let vtable_a1 = *(a1 as *mut usize);
        // 2. Берем функцию по смещению 840
        let func_addr = *((vtable_a1 + 840) as *mut usize);
        let func: unsafe extern "C" fn(*mut u8, u64) -> i64 = std::mem::transmute(func_addr);

        // 3. Получаем второй аргумент: a1[1234] (1234 в десятичной = 0x4D2)
        let arg2 = *a1.add(1234) as u64;

        // 4. Вызываем и возвращаем результат
        result = func(a1, arg2);
        return result;
    }

    result
}