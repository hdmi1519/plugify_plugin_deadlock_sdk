// Generated from dsdk.pplugin (group: navigation)

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

/// Find nearest point on navmesh
///
/// # Arguments
/// * `x` - (float)
/// * `y` - (float)
/// * `z` - (float)
/// * `maxDistance` - (float)
/// * `hull` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn NavGetNearestPoint(x: f32, y: f32, z: f32, maxDistance: f32, hull: i32) -> bool {
    unsafe { __dsdk_NavGetNearestPoint.expect("NavGetNearestPoint function was not found")(x, y, z, maxDistance, hull) }
}
pub type _NavGetNearestPoint = unsafe extern "C" fn(f32, f32, f32, f32, i32) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_NavGetNearestPoint: Option<_NavGetNearestPoint> = None;

/// Get ground elevation from navmesh
///
/// # Arguments
/// * `x` - (float)
/// * `y` - (float)
/// * `z` - (float)
/// * `maxDistance` - (float)
/// * `hull` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn NavGetGroundHeight(x: f32, y: f32, z: f32, maxDistance: f32, hull: i32) -> f32 {
    unsafe { __dsdk_NavGetGroundHeight.expect("NavGetGroundHeight function was not found")(x, y, z, maxDistance, hull) }
}
pub type _NavGetGroundHeight = unsafe extern "C" fn(f32, f32, f32, f32, i32) -> f32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_NavGetGroundHeight: Option<_NavGetGroundHeight> = None;

