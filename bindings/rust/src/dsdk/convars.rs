// Generated from dsdk.pplugin (group: convars)

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

/// Find ConVar by name
///
/// # Arguments
/// * `name` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn FindConVar(name: &Str) -> u64 {
    unsafe { __dsdk_FindConVar.expect("FindConVar function was not found")(name) }
}
pub type _FindConVar = unsafe extern "C" fn(&Str) -> u64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_FindConVar: Option<_FindConVar> = None;

/// Create custom ConVar
///
/// # Arguments
/// * `name` - (string)
/// * `defaultValue` - (string)
/// * `description` - (string)
/// * `flags` - (uint64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn CreateConVar(name: &Str, defaultValue: &Str, description: &Str, flags: u64) -> u64 {
    unsafe { __dsdk_CreateConVar.expect("CreateConVar function was not found")(name, defaultValue, description, flags) }
}
pub type _CreateConVar = unsafe extern "C" fn(&Str, &Str, &Str, u64) -> u64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_CreateConVar: Option<_CreateConVar> = None;

/// Get ConVar integer value
///
/// # Arguments
/// * `handle` - (uint64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetConVarInt(handle: u64) -> i32 {
    unsafe { __dsdk_GetConVarInt.expect("GetConVarInt function was not found")(handle) }
}
pub type _GetConVarInt = unsafe extern "C" fn(u64) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetConVarInt: Option<_GetConVarInt> = None;

/// Get ConVar float value
///
/// # Arguments
/// * `handle` - (uint64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetConVarFloat(handle: u64) -> f32 {
    unsafe { __dsdk_GetConVarFloat.expect("GetConVarFloat function was not found")(handle) }
}
pub type _GetConVarFloat = unsafe extern "C" fn(u64) -> f32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetConVarFloat: Option<_GetConVarFloat> = None;

/// Get ConVar string value
///
/// # Arguments
/// * `handle` - (uint64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetConVarString(handle: u64) -> Str {
    unsafe { __dsdk_GetConVarString.expect("GetConVarString function was not found")(handle) }
}
pub type _GetConVarString = unsafe extern "C" fn(u64) -> Str;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetConVarString: Option<_GetConVarString> = None;

/// Get ConVar bool value
///
/// # Arguments
/// * `handle` - (uint64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetConVarBool(handle: u64) -> bool {
    unsafe { __dsdk_GetConVarBool.expect("GetConVarBool function was not found")(handle) }
}
pub type _GetConVarBool = unsafe extern "C" fn(u64) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetConVarBool: Option<_GetConVarBool> = None;

/// Set ConVar int value
///
/// # Arguments
/// * `handle` - (uint64)
/// * `value` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetConVarInt(handle: u64, value: i32) {
    unsafe { __dsdk_SetConVarInt.expect("SetConVarInt function was not found")(handle, value) }
}
pub type _SetConVarInt = unsafe extern "C" fn(u64, i32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetConVarInt: Option<_SetConVarInt> = None;

/// Set ConVar float value
///
/// # Arguments
/// * `handle` - (uint64)
/// * `value` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetConVarFloat(handle: u64, value: f32) {
    unsafe { __dsdk_SetConVarFloat.expect("SetConVarFloat function was not found")(handle, value) }
}
pub type _SetConVarFloat = unsafe extern "C" fn(u64, f32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetConVarFloat: Option<_SetConVarFloat> = None;

/// Set ConVar string value
///
/// # Arguments
/// * `handle` - (uint64)
/// * `value` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetConVarString(handle: u64, value: &Str) -> bool {
    unsafe { __dsdk_SetConVarString.expect("SetConVarString function was not found")(handle, value) }
}
pub type _SetConVarString = unsafe extern "C" fn(u64, &Str) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetConVarString: Option<_SetConVarString> = None;

