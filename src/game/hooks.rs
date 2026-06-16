use std::arch::naked_asm;
use std::sync::atomic::{AtomicUsize, Ordering};

// ==========================================
// 1. ИГРОК (Player Struct) | Регистр: RAX
// ==========================================
pub static PLAYER_PTR: AtomicUsize = AtomicUsize::new(0);
pub static mut PLAYER_RET: usize = 0;

#[unsafe(naked)]
pub unsafe extern "sysv64" fn hook_player() {
    naked_asm!(
        "push rbx",
        "lea rbx, [rip + {ptr_addr}]",     // <--- RIP-относительная загрузка адреса
        "mov [rbx], rax",
        "pop rbx",
        "cmp dword ptr [rax+0x1A8], 0x00",
        "jmp qword ptr [rip + {jmp_back}]",// <--- RIP-относительный прыжок (qword = 8 байт)
        ptr_addr = sym PLAYER_PTR,
        jmp_back = sym PLAYER_RET
    );
}

// ==========================================
// 2. РАДАР (Radar / Entities) | Регистр: R14
// ==========================================
pub static RADAR_PTR: AtomicUsize = AtomicUsize::new(0);
pub static mut RADAR_RET: usize = 0;

#[unsafe(naked)]
pub unsafe extern "sysv64" fn hook_radar() {
    naked_asm!(
        "push rax",
        "lea rax, [rip + {ptr_addr}]",
        "mov [rax], r14",
        "pop rax",
        "movsd [r14+0x2E8], xmm0",
        "jmp qword ptr [rip + {jmp_back}]",
        ptr_addr = sym RADAR_PTR,
        jmp_back = sym RADAR_RET
    );
}

// ==========================================
// 3. КАМЕРА / FOV (Camera / W2S) | Регистр: RDI
// ==========================================
pub static FOV_PTR: AtomicUsize = AtomicUsize::new(0);
pub static mut FOV_RET: usize = 0;

#[unsafe(naked)]
pub unsafe extern "sysv64" fn hook_fov() {
    naked_asm!(
        "push rax",
        "lea rax, [rip + {ptr_addr}]",
        "mov [rax], rdi",
        "pop rax",
        "movss xmm6, [rdi+0x4B0]",
        "jmp qword ptr [rip + {jmp_back}]",
        ptr_addr = sym FOV_PTR,
        jmp_back = sym FOV_RET
    );
}

// ==========================================
// 4. МЫШЬ / INPUT (Mouse) | Регистр: RDI
// ==========================================
pub static MOUSE_PTR: AtomicUsize = AtomicUsize::new(0);
pub static mut MOUSE_RET: usize = 0;

#[unsafe(naked)]
pub unsafe extern "sysv64" fn hook_mouse() {
    naked_asm!(
        "push rax",
        "lea rax, [rip + {ptr_addr}]",
        "mov [rax], rdi",
        "pop rax",
        "mov [rdi+0x210], rdx",
        "jmp qword ptr [rip + {jmp_back}]",
        ptr_addr = sym MOUSE_PTR,
        jmp_back = sym MOUSE_RET
    );
}

// ==========================================
// 5. ДВИЖЕНИЕ (Movement Controller) | Регистр: RCX
// ==========================================
pub static MOVEMENT_PTR: AtomicUsize = AtomicUsize::new(0);
pub static mut MOVEMENT_RET: usize = 0;

#[unsafe(naked)]
pub unsafe extern "sysv64" fn hook_movement() {
    naked_asm!(
        "push rax",
        "lea rax, [rip + {ptr_addr}]",
        "mov [rax], rcx",
        "pop rax",
        "mov rbx, rcx",
        "mov r14, [rdx]",
        "jmp qword ptr [rip + {jmp_back}]",
        ptr_addr = sym MOVEMENT_PTR,
        jmp_back = sym MOVEMENT_RET
    );
}

// ==========================================
// УДОБНЫЕ ГЕТТЕРЫ
// ==========================================

pub fn get_player() -> Option<usize> {
    let addr = PLAYER_PTR.load(Ordering::Relaxed);
    if addr == 0 { None } else { Some(addr) }
}

pub fn get_radar() -> Option<usize> {
    let addr = RADAR_PTR.load(Ordering::Relaxed);
    if addr == 0 { None } else { Some(addr) }
}

pub fn get_fov() -> Option<usize> {
    let addr = FOV_PTR.load(Ordering::Relaxed);
    if addr == 0 { None } else { Some(addr) }
}

pub fn get_mouse() -> Option<usize> {
    let addr = MOUSE_PTR.load(Ordering::Relaxed);
    if addr == 0 { None } else { Some(addr) }
}

pub fn get_movement() -> Option<usize> {
    let addr = MOVEMENT_PTR.load(Ordering::Relaxed);
    if addr == 0 { None } else { Some(addr) }
}