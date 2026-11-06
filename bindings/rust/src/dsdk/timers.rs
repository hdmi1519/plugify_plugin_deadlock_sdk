// Generated from dsdk.pplugin (group: timers)

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

/// Create a one-shot or repeating timer
///
/// # Arguments
/// * `interval` - (float)
/// * `callback` - (function)
/// * `repeating` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn CreateTimer(interval: f32, callback: TimerCallback, repeating: bool) -> i64 {
    unsafe { __dsdk_CreateTimer.expect("CreateTimer function was not found")(interval, callback, repeating) }
}
pub type _CreateTimer = unsafe extern "C" fn(f32, TimerCallback, bool) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_CreateTimer: Option<_CreateTimer> = None;

/// Stop and delete an active timer
///
/// # Arguments
/// * `timerId` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn KillTimer(timerId: i64) -> bool {
    unsafe { __dsdk_KillTimer.expect("KillTimer function was not found")(timerId) }
}
pub type _KillTimer = unsafe extern "C" fn(i64) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_KillTimer: Option<_KillTimer> = None;

