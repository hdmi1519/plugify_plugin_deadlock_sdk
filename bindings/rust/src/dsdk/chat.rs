// Generated from dsdk.pplugin (group: chat)

#[allow(unused_imports)]
use std::sync::RwLock;
#[allow(unused_imports)]
use super::enums::*;
#[allow(unused_imports)]
use super::aliases::*;
#[allow(unused_imports)]
use super::delegates::*;
#[allow(unused_imports)]
use plugify::{scope, Str, Arr, Var, Vec2, Vec3, Vec4, Mat4x4};

/// Print message to client chat
///
/// # Arguments
/// * `playerSlot` - (int32)
/// * `message` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn PrintToChat(playerSlot: i32, message: &Str) {
    unsafe { __dsdk_PrintToChat.expect("PrintToChat function was not found")(playerSlot, message) }
}
pub type _PrintToChat = unsafe extern "C" fn(i32, &Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_PrintToChat: Option<_PrintToChat> = None;

/// Broadcast message to all players
///
/// # Arguments
/// * `message` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn PrintToChatAll(message: &Str) {
    unsafe { __dsdk_PrintToChatAll.expect("PrintToChatAll function was not found")(message) }
}
pub type _PrintToChatAll = unsafe extern "C" fn(&Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_PrintToChatAll: Option<_PrintToChatAll> = None;

/// Print message to client console
///
/// # Arguments
/// * `playerSlot` - (int32)
/// * `message` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn PrintToConsole(playerSlot: i32, message: &Str) {
    unsafe { __dsdk_PrintToConsole.expect("PrintToConsole function was not found")(playerSlot, message) }
}
pub type _PrintToConsole = unsafe extern "C" fn(i32, &Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_PrintToConsole: Option<_PrintToConsole> = None;

/// Print message to all player consoles
///
/// # Arguments
/// * `message` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn PrintToConsoleAll(message: &Str) {
    unsafe { __dsdk_PrintToConsoleAll.expect("PrintToConsoleAll function was not found")(message) }
}
pub type _PrintToConsoleAll = unsafe extern "C" fn(&Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_PrintToConsoleAll: Option<_PrintToConsoleAll> = None;

/// Display a HUD game announcement banner to a player
///
/// # Arguments
/// * `playerSlot` - (int32)
/// * `title` - (string)
/// * `description` - (string)
/// * `duration` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn HudAnnounce(playerSlot: i32, title: &Str, description: &Str, duration: f32) {
    unsafe { __dsdk_HudAnnounce.expect("HudAnnounce function was not found")(playerSlot, title, description, duration) }
}
pub type _HudAnnounce = unsafe extern "C" fn(i32, &Str, &Str, f32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_HudAnnounce: Option<_HudAnnounce> = None;

/// Display a HUD game announcement banner to all players
///
/// # Arguments
/// * `title` - (string)
/// * `description` - (string)
/// * `duration` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn HudAnnounceAll(title: &Str, description: &Str, duration: f32) {
    unsafe { __dsdk_HudAnnounceAll.expect("HudAnnounceAll function was not found")(title, description, duration) }
}
pub type _HudAnnounceAll = unsafe extern "C" fn(&Str, &Str, f32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_HudAnnounceAll: Option<_HudAnnounceAll> = None;

