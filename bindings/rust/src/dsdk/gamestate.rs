// Generated from dsdk.pplugin (group: gamestate)

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

/// Get current game state enum
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetGameState() -> EGameState {
    unsafe { __dsdk_GetGameState.expect("GetGameState function was not found")() }
}
pub type _GetGameState = unsafe extern "C" fn() -> EGameState;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetGameState: Option<_GetGameState> = None;

/// Force Deadlock game state change
///
/// # Arguments
/// * `newState` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ChangeGameState(newState: EGameState) {
    unsafe { __dsdk_ChangeGameState.expect("ChangeGameState function was not found")(newState) }
}
pub type _ChangeGameState = unsafe extern "C" fn(EGameState);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ChangeGameState: Option<_ChangeGameState> = None;

/// Set waiting for players roster counts
///
/// # Arguments
/// * `readyCount` - (uint32)
/// * `totalCount` - (uint32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetWaitingForPlayersRoster(readyCount: u32, totalCount: u32) {
    unsafe { __dsdk_SetWaitingForPlayersRoster.expect("SetWaitingForPlayersRoster function was not found")(readyCount, totalCount) }
}
pub type _SetWaitingForPlayersRoster = unsafe extern "C" fn(u32, u32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetWaitingForPlayersRoster: Option<_SetWaitingForPlayersRoster> = None;

/// Enable/disable match start sequence on custom maps
///
/// # Arguments
/// * `enabled` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetMatchStartOnAnyMap(enabled: bool) {
    unsafe { __dsdk_SetMatchStartOnAnyMap.expect("SetMatchStartOnAnyMap function was not found")(enabled) }
}
pub type _SetMatchStartOnAnyMap = unsafe extern "C" fn(bool);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetMatchStartOnAnyMap: Option<_SetMatchStartOnAnyMap> = None;

/// Check if match start on custom maps is enabled
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetMatchStartOnAnyMap() -> bool {
    unsafe { __dsdk_GetMatchStartOnAnyMap.expect("GetMatchStartOnAnyMap function was not found")() }
}
pub type _GetMatchStartOnAnyMap = unsafe extern "C" fn() -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetMatchStartOnAnyMap: Option<_GetMatchStartOnAnyMap> = None;

