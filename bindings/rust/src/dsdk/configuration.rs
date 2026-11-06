// Generated from dsdk.pplugin (group: configuration)

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

/// Read string from settings.jsonc
///
/// # Arguments
/// * `key` - (string)
/// * `defaultValue` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetConfigString(key: &Str, defaultValue: &Str) -> Str {
    unsafe { __dsdk_GetConfigString.expect("GetConfigString function was not found")(key, defaultValue) }
}
pub type _GetConfigString = unsafe extern "C" fn(&Str, &Str) -> Str;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetConfigString: Option<_GetConfigString> = None;

/// Read int from settings.jsonc
///
/// # Arguments
/// * `key` - (string)
/// * `defaultValue` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetConfigInt(key: &Str, defaultValue: i32) -> i32 {
    unsafe { __dsdk_GetConfigInt.expect("GetConfigInt function was not found")(key, defaultValue) }
}
pub type _GetConfigInt = unsafe extern "C" fn(&Str, i32) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetConfigInt: Option<_GetConfigInt> = None;

/// Read bool from settings.jsonc
///
/// # Arguments
/// * `key` - (string)
/// * `defaultValue` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetConfigBool(key: &Str, defaultValue: bool) -> bool {
    unsafe { __dsdk_GetConfigBool.expect("GetConfigBool function was not found")(key, defaultValue) }
}
pub type _GetConfigBool = unsafe extern "C" fn(&Str, bool) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetConfigBool: Option<_GetConfigBool> = None;

/// Read float from settings.jsonc
///
/// # Arguments
/// * `key` - (string)
/// * `defaultValue` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetConfigFloat(key: &Str, defaultValue: f32) -> f32 {
    unsafe { __dsdk_GetConfigFloat.expect("GetConfigFloat function was not found")(key, defaultValue) }
}
pub type _GetConfigFloat = unsafe extern "C" fn(&Str, f32) -> f32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetConfigFloat: Option<_GetConfigFloat> = None;

