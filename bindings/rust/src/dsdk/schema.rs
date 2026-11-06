// Generated from dsdk.pplugin (group: schema)

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

/// Get byte offset of class field in schema
///
/// # Arguments
/// * `className` - (string)
/// * `fieldName` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetSchemaFieldOffset(className: &Str, fieldName: &Str) -> i32 {
    unsafe { __dsdk_GetSchemaFieldOffset.expect("GetSchemaFieldOffset function was not found")(className, fieldName) }
}
pub type _GetSchemaFieldOffset = unsafe extern "C" fn(&Str, &Str) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetSchemaFieldOffset: Option<_GetSchemaFieldOffset> = None;

/// Notify network system of field modification
///
/// # Arguments
/// * `entity` - (int64)
/// * `fieldOffset` - (int32)
/// * `chainOffset` - (int16)
/// * `networkStateChangedOffset` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn NotifyStateChanged(entity: i64, fieldOffset: i32, chainOffset: i16, networkStateChangedOffset: i32) {
    unsafe { __dsdk_NotifyStateChanged.expect("NotifyStateChanged function was not found")(entity, fieldOffset, chainOffset, networkStateChangedOffset) }
}
pub type _NotifyStateChanged = unsafe extern "C" fn(i64, i32, i16, i32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_NotifyStateChanged: Option<_NotifyStateChanged> = None;

/// Set string field in schema structure
///
/// # Arguments
/// * `entity` - (int64)
/// * `className` - (string)
/// * `fieldName` - (string)
/// * `value` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetSchemaString(entity: i64, className: &Str, fieldName: &Str, value: &Str) {
    unsafe { __dsdk_SetSchemaString.expect("SetSchemaString function was not found")(entity, className, fieldName, value) }
}
pub type _SetSchemaString = unsafe extern "C" fn(i64, &Str, &Str, &Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetSchemaString: Option<_SetSchemaString> = None;

/// Get sizeof schema class
///
/// # Arguments
/// * `className` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetSchemaClassSize(className: &Str) -> i32 {
    unsafe { __dsdk_GetSchemaClassSize.expect("GetSchemaClassSize function was not found")(className) }
}
pub type _GetSchemaClassSize = unsafe extern "C" fn(&Str) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetSchemaClassSize: Option<_GetSchemaClassSize> = None;

