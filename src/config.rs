// Player Struct | Регистр: RAX | Оригинал: cmp dword ptr [rax+1A8], 00 | 7 байт
pub const PLAYER_AOB: &str = "83 B8 A8 01 00 00 00 0F 8F 08";

// Radar / Entities | Регистр: R14 | Оригинал: movsd [r14+2E8], xmm0 | 9 байт
pub const RADAR_AOB: &str = "F2 41 0F 11 86 E8 02 00 00";

// Camera / FOV | Регистр: RDI | Оригинал: movss xmm6, [rdi+4B0] | 8 байт
pub const FOV_AOB: &str = "F3 0F 10 B7 B0 04 00 00";

// Mouse / Input | Регистр: RDI | Оригинал: mov [rdi+210], rdx | 7 байт
pub const MOUSE_AOB: &str = "48 89 97 10 02 00 00";

// Movement Controller | Регистр: RCX | Оригинал: mov rbx, rcx | mov r14, [rdx] | 6 байт
pub const MOVEMENT_CTRL_AOB: &str = "48 8B D9 4C 8B 32";

// Click Coords | Регистр: RCX | Оригинал: movsd [rcx], xmm1 | 9 байт
pub const CLICK_AOB: &str = "F2 0F 11 09 E8 9D EB 31 FE";

// Entity Struct | Регистр: RCX | Оригинал: movss xmm7, [rcx+2B8] | 8 байт
pub const ENTITY_TEST_AOB: &str = "F3 0F 10 B9 B8 02 00 00 F3";

// ProcessMoveRequest (MinHook) | Полный пролог функции
pub const PROCESS_MOVE_REQUEST_AOB: &str = "48 8B C4 48 89 58 ?? 48 89 68 ?? 48 89 70 ?? 57 41 54 41 55 41 56 41 57 48 81 EC ?? ?? ?? ?? 0F 29 70 ?? 0F 29 78 ?? 44 0F 29 40 ?? 48 8B FA";
