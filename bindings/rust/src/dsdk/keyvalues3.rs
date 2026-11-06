// Generated from dsdk.pplugin (group: keyvalues3)

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

/// Allocate new KeyValues3 document
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn KV3Create() -> i64 {
    unsafe { __dsdk_KV3Create.expect("KV3Create function was not found")() }
}
pub type _KV3Create = unsafe extern "C" fn() -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_KV3Create: Option<_KV3Create> = None;

/// Free KeyValues3 document
///
/// # Arguments
/// * `kv3` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn KV3Destroy(kv3: i64) {
    unsafe { __dsdk_KV3Destroy.expect("KV3Destroy function was not found")(kv3) }
}
pub type _KV3Destroy = unsafe extern "C" fn(i64);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_KV3Destroy: Option<_KV3Destroy> = None;

/// Set string value in KeyValues3 document
///
/// # Arguments
/// * `kv3` - (int64)
/// * `key` - (string)
/// * `value` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn KV3SetString(kv3: i64, key: &Str, value: &Str) {
    unsafe { __dsdk_KV3SetString.expect("KV3SetString function was not found")(kv3, key, value) }
}
pub type _KV3SetString = unsafe extern "C" fn(i64, &Str, &Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_KV3SetString: Option<_KV3SetString> = None;

/// Set bool value in KeyValues3 document
///
/// # Arguments
/// * `kv3` - (int64)
/// * `key` - (string)
/// * `value` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn KV3SetBool(kv3: i64, key: &Str, value: bool) {
    unsafe { __dsdk_KV3SetBool.expect("KV3SetBool function was not found")(kv3, key, value) }
}
pub type _KV3SetBool = unsafe extern "C" fn(i64, &Str, bool);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_KV3SetBool: Option<_KV3SetBool> = None;

/// Set int32 value in KeyValues3 document
///
/// # Arguments
/// * `kv3` - (int64)
/// * `key` - (string)
/// * `value` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn KV3SetInt(kv3: i64, key: &Str, value: i32) {
    unsafe { __dsdk_KV3SetInt.expect("KV3SetInt function was not found")(kv3, key, value) }
}
pub type _KV3SetInt = unsafe extern "C" fn(i64, &Str, i32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_KV3SetInt: Option<_KV3SetInt> = None;

/// Set float value in KeyValues3 document
///
/// # Arguments
/// * `kv3` - (int64)
/// * `key` - (string)
/// * `value` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn KV3SetFloat(kv3: i64, key: &Str, value: f32) {
    unsafe { __dsdk_KV3SetFloat.expect("KV3SetFloat function was not found")(kv3, key, value) }
}
pub type _KV3SetFloat = unsafe extern "C" fn(i64, &Str, f32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_KV3SetFloat: Option<_KV3SetFloat> = None;

