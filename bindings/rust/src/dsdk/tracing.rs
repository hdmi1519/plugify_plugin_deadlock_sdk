// Generated from dsdk.pplugin (group: tracing)

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

/// Perform physics raycast trace between start and end vectors
///
/// # Arguments
/// * `startX` - (float)
/// * `startY` - (float)
/// * `startZ` - (float)
/// * `endX` - (float)
/// * `endY` - (float)
/// * `endZ` - (float)
/// * `mask` - (uint32)
/// * `ignoreEntity` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn LineTrace(startX: f32, startY: f32, startZ: f32, endX: f32, endY: f32, endZ: f32, mask: u32, ignoreEntity: i64) -> bool {
    unsafe { __dsdk_LineTrace.expect("LineTrace function was not found")(startX, startY, startZ, endX, endY, endZ, mask, ignoreEntity) }
}
pub type _LineTrace = unsafe extern "C" fn(f32, f32, f32, f32, f32, f32, u32, i64) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_LineTrace: Option<_LineTrace> = None;

