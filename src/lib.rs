use std::ffi::c_void;
use std::thread;

use windows_sys::Win32::Foundation::{HMODULE, TRUE};
use windows_sys::core::BOOL;
use windows_sys::Win32::System::SystemServices::{DLL_PROCESS_ATTACH, DLL_PROCESS_DETACH};

pub mod bot;
pub mod game;
pub mod memory;
pub mod config;

type LPVOID = *mut c_void;

#[unsafe(no_mangle)]
#[allow(non_snake_case)]
pub unsafe extern "system" fn DllMain(
    _h_module: HMODULE,
    dw_reason: u32,
    _lp_reserved: LPVOID,
) -> BOOL {
    match dw_reason {
        DLL_PROCESS_ATTACH => {
            thread::spawn(|| {
                unsafe { game::client::client_initialization(); }
            });
        }
        DLL_PROCESS_DETACH => {}
        _ => {}
    }
    TRUE
}
