use std::ptr::{null, null_mut};
use windows_sys::Win32::System::Diagnostics::Debug;
use windows_sys::Win32::System::Diagnostics::Debug::ReadProcessMemory;

fn main() {
    println!("Hello, world!");
    unsafe {

        // Заглушка для чтения
        ReadProcessMemory(null_mut(), null(), null::<u8>() as *mut _, 0, null::<usize>() as *mut _);

    }
    return;
}

