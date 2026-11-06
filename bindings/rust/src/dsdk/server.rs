// Generated from dsdk.pplugin (group: server)

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

/// Get currently loaded map name
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetMapName() -> Str {
    unsafe { __dsdk_GetMapName.expect("GetMapName function was not found")() }
}
pub type _GetMapName = unsafe extern "C" fn() -> Str;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetMapName: Option<_GetMapName> = None;

/// Check if map exists and can be loaded
///
/// # Arguments
/// * `map` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn IsMapValid(map: &Str) -> bool {
    unsafe { __dsdk_IsMapValid.expect("IsMapValid function was not found")(map) }
}
pub type _IsMapValid = unsafe extern "C" fn(&Str) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_IsMapValid: Option<_IsMapValid> = None;

/// Set Steam A2S rule key-value
///
/// # Arguments
/// * `key` - (string)
/// * `value` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetServerKeyValue(key: &Str, value: &Str) -> bool {
    unsafe { __dsdk_SetServerKeyValue.expect("SetServerKeyValue function was not found")(key, value) }
}
pub type _SetServerKeyValue = unsafe extern "C" fn(&Str, &Str) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetServerKeyValue: Option<_SetServerKeyValue> = None;

/// Clear Steam A2S rules
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ClearServerKeyValues() -> bool {
    unsafe { __dsdk_ClearServerKeyValues.expect("ClearServerKeyValues function was not found")() }
}
pub type _ClearServerKeyValues = unsafe extern "C" fn() -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ClearServerKeyValues: Option<_ClearServerKeyValues> = None;

/// Set active server workshop addons
///
/// # Arguments
/// * `addons` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetServerAddons(addons: &Str) {
    unsafe { __dsdk_SetServerAddons.expect("SetServerAddons function was not found")(addons) }
}
pub type _SetServerAddons = unsafe extern "C" fn(&Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetServerAddons: Option<_SetServerAddons> = None;

/// Add file search path
///
/// # Arguments
/// * `path` - (string)
/// * `pathId` - (string)
/// * `addType` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn AddFileSystemSearchPath(path: &Str, pathId: &Str, addType: i32) -> bool {
    unsafe { __dsdk_AddFileSystemSearchPath.expect("AddFileSystemSearchPath function was not found")(path, pathId, addType) }
}
pub type _AddFileSystemSearchPath = unsafe extern "C" fn(&Str, &Str, i32) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_AddFileSystemSearchPath: Option<_AddFileSystemSearchPath> = None;

/// Check if command line argument exists
///
/// # Arguments
/// * `parm` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn HasCommandLineParm(parm: &Str) -> bool {
    unsafe { __dsdk_HasCommandLineParm.expect("HasCommandLineParm function was not found")(parm) }
}
pub type _HasCommandLineParm = unsafe extern "C" fn(&Str) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_HasCommandLineParm: Option<_HasCommandLineParm> = None;

/// Set reject reason for connection rejection
///
/// # Arguments
/// * `reason` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetConnectRejectReason(reason: &Str) {
    unsafe { __dsdk_SetConnectRejectReason.expect("SetConnectRejectReason function was not found")(reason) }
}
pub type _SetConnectRejectReason = unsafe extern "C" fn(&Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetConnectRejectReason: Option<_SetConnectRejectReason> = None;

/// Get CGlobalVars pointer
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetGlobalVars() -> i64 {
    unsafe { __dsdk_GetGlobalVars.expect("GetGlobalVars function was not found")() }
}
pub type _GetGlobalVars = unsafe extern "C" fn() -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetGlobalVars: Option<_GetGlobalVars> = None;

/// Get current engine game time in seconds
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetGameTime() -> f32 {
    unsafe { __dsdk_GetGameTime.expect("GetGameTime function was not found")() }
}
pub type _GetGameTime = unsafe extern "C" fn() -> f32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetGameTime: Option<_GetGameTime> = None;

/// Get current engine tick count
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetGameTickCount() -> i32 {
    unsafe { __dsdk_GetGameTickCount.expect("GetGameTickCount function was not found")() }
}
pub type _GetGameTickCount = unsafe extern "C" fn() -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetGameTickCount: Option<_GetGameTickCount> = None;

