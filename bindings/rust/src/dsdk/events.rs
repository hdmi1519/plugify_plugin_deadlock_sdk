// Generated from dsdk.pplugin (group: events)

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

/// Register game event listener for engine event
///
/// # Arguments
/// * `name` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn RegisterGameEvent(name: &Str) {
    unsafe { __dsdk_RegisterGameEvent.expect("RegisterGameEvent function was not found")(name) }
}
pub type _RegisterGameEvent = unsafe extern "C" fn(&Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_RegisterGameEvent: Option<_RegisterGameEvent> = None;

/// Create a new game event
///
/// # Arguments
/// * `name` - (string)
/// * `force` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn CreateGameEvent(name: &Str, force: bool) -> i64 {
    unsafe { __dsdk_CreateGameEvent.expect("CreateGameEvent function was not found")(name, force) }
}
pub type _CreateGameEvent = unsafe extern "C" fn(&Str, bool) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_CreateGameEvent: Option<_CreateGameEvent> = None;

/// Fire game event
///
/// # Arguments
/// * `event` - (int64)
/// * `dontBroadcast` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn FireGameEvent(event: i64, dontBroadcast: bool) -> bool {
    unsafe { __dsdk_FireGameEvent.expect("FireGameEvent function was not found")(event, dontBroadcast) }
}
pub type _FireGameEvent = unsafe extern "C" fn(i64, bool) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_FireGameEvent: Option<_FireGameEvent> = None;

/// Free game event object
///
/// # Arguments
/// * `event` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn FreeGameEvent(event: i64) {
    unsafe { __dsdk_FreeGameEvent.expect("FreeGameEvent function was not found")(event) }
}
pub type _FreeGameEvent = unsafe extern "C" fn(i64);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_FreeGameEvent: Option<_FreeGameEvent> = None;

/// Get boolean key from game event
///
/// # Arguments
/// * `event` - (int64)
/// * `key` - (string)
/// * `def` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GameEventGetBool(event: i64, key: &Str, def: bool) -> bool {
    unsafe { __dsdk_GameEventGetBool.expect("GameEventGetBool function was not found")(event, key, def) }
}
pub type _GameEventGetBool = unsafe extern "C" fn(i64, &Str, bool) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GameEventGetBool: Option<_GameEventGetBool> = None;

/// Get int32 key from game event
///
/// # Arguments
/// * `event` - (int64)
/// * `key` - (string)
/// * `def` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GameEventGetInt(event: i64, key: &Str, def: i32) -> i32 {
    unsafe { __dsdk_GameEventGetInt.expect("GameEventGetInt function was not found")(event, key, def) }
}
pub type _GameEventGetInt = unsafe extern "C" fn(i64, &Str, i32) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GameEventGetInt: Option<_GameEventGetInt> = None;

/// Get float key from game event
///
/// # Arguments
/// * `event` - (int64)
/// * `key` - (string)
/// * `def` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GameEventGetFloat(event: i64, key: &Str, def: f32) -> f32 {
    unsafe { __dsdk_GameEventGetFloat.expect("GameEventGetFloat function was not found")(event, key, def) }
}
pub type _GameEventGetFloat = unsafe extern "C" fn(i64, &Str, f32) -> f32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GameEventGetFloat: Option<_GameEventGetFloat> = None;

/// Get string key from game event
///
/// # Arguments
/// * `event` - (int64)
/// * `key` - (string)
/// * `def` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GameEventGetString(event: i64, key: &Str, def: &Str) -> Str {
    unsafe { __dsdk_GameEventGetString.expect("GameEventGetString function was not found")(event, key, def) }
}
pub type _GameEventGetString = unsafe extern "C" fn(i64, &Str, &Str) -> Str;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GameEventGetString: Option<_GameEventGetString> = None;

/// Get uint64 key from game event
///
/// # Arguments
/// * `event` - (int64)
/// * `key` - (string)
/// * `def` - (uint64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GameEventGetUint64(event: i64, key: &Str, def: u64) -> u64 {
    unsafe { __dsdk_GameEventGetUint64.expect("GameEventGetUint64 function was not found")(event, key, def) }
}
pub type _GameEventGetUint64 = unsafe extern "C" fn(i64, &Str, u64) -> u64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GameEventGetUint64: Option<_GameEventGetUint64> = None;

/// Set boolean key in game event
///
/// # Arguments
/// * `event` - (int64)
/// * `key` - (string)
/// * `val` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GameEventSetBool(event: i64, key: &Str, val: bool) {
    unsafe { __dsdk_GameEventSetBool.expect("GameEventSetBool function was not found")(event, key, val) }
}
pub type _GameEventSetBool = unsafe extern "C" fn(i64, &Str, bool);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GameEventSetBool: Option<_GameEventSetBool> = None;

/// Set int32 key in game event
///
/// # Arguments
/// * `event` - (int64)
/// * `key` - (string)
/// * `val` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GameEventSetInt(event: i64, key: &Str, val: i32) {
    unsafe { __dsdk_GameEventSetInt.expect("GameEventSetInt function was not found")(event, key, val) }
}
pub type _GameEventSetInt = unsafe extern "C" fn(i64, &Str, i32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GameEventSetInt: Option<_GameEventSetInt> = None;

/// Set float key in game event
///
/// # Arguments
/// * `event` - (int64)
/// * `key` - (string)
/// * `val` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GameEventSetFloat(event: i64, key: &Str, val: f32) {
    unsafe { __dsdk_GameEventSetFloat.expect("GameEventSetFloat function was not found")(event, key, val) }
}
pub type _GameEventSetFloat = unsafe extern "C" fn(i64, &Str, f32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GameEventSetFloat: Option<_GameEventSetFloat> = None;

/// Set string key in game event
///
/// # Arguments
/// * `event` - (int64)
/// * `key` - (string)
/// * `val` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GameEventSetString(event: i64, key: &Str, val: &Str) {
    unsafe { __dsdk_GameEventSetString.expect("GameEventSetString function was not found")(event, key, val) }
}
pub type _GameEventSetString = unsafe extern "C" fn(i64, &Str, &Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GameEventSetString: Option<_GameEventSetString> = None;

/// Gets player slot from an event key (e.g. userid)
///
/// # Arguments
/// * `event` - (int64)
/// * `key` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GameEventGetPlayerSlot(event: i64, key: &Str) -> i32 {
    unsafe { __dsdk_GameEventGetPlayerSlot.expect("GameEventGetPlayerSlot function was not found")(event, key) }
}
pub type _GameEventGetPlayerSlot = unsafe extern "C" fn(i64, &Str) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GameEventGetPlayerSlot: Option<_GameEventGetPlayerSlot> = None;

/// Gets player pawn pointer from an event key (e.g. userid)
///
/// # Arguments
/// * `event` - (int64)
/// * `key` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GameEventGetPlayerPawn(event: i64, key: &Str) -> i64 {
    unsafe { __dsdk_GameEventGetPlayerPawn.expect("GameEventGetPlayerPawn function was not found")(event, key) }
}
pub type _GameEventGetPlayerPawn = unsafe extern "C" fn(i64, &Str) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GameEventGetPlayerPawn: Option<_GameEventGetPlayerPawn> = None;

/// Gets player controller pointer from an event key (e.g. userid)
///
/// # Arguments
/// * `event` - (int64)
/// * `key` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GameEventGetPlayerController(event: i64, key: &Str) -> i64 {
    unsafe { __dsdk_GameEventGetPlayerController.expect("GameEventGetPlayerController function was not found")(event, key) }
}
pub type _GameEventGetPlayerController = unsafe extern "C" fn(i64, &Str) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GameEventGetPlayerController: Option<_GameEventGetPlayerController> = None;

