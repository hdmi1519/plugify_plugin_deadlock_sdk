// Generated from dsdk.pplugin (group: zones)

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

/// Spawn a glowing laser beam entity between two world points
///
/// # Arguments
/// * `startX` - (float)
/// * `startY` - (float)
/// * `startZ` - (float)
/// * `endX` - (float)
/// * `endY` - (float)
/// * `endZ` - (float)
/// * `width` - (float)
/// * `r` - (uint8)
/// * `g` - (uint8)
/// * `b` - (uint8)
/// * `a` - (uint8)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn CreateBeam(startX: f32, startY: f32, startZ: f32, endX: f32, endY: f32, endZ: f32, width: f32, r: u8, g: u8, b: u8, a: u8) -> i64 {
    unsafe { __dsdk_CreateBeam.expect("CreateBeam function was not found")(startX, startY, startZ, endX, endY, endZ, width, r, g, b, a) }
}
pub type _CreateBeam = unsafe extern "C" fn(f32, f32, f32, f32, f32, f32, f32, u8, u8, u8, u8) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_CreateBeam: Option<_CreateBeam> = None;

/// Create a spatial trigger volume box
///
/// # Arguments
/// * `name` - (string)
/// * `minX` - (float)
/// * `minY` - (float)
/// * `minZ` - (float)
/// * `maxX` - (float)
/// * `maxY` - (float)
/// * `maxZ` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn CreateZone(name: &Str, minX: f32, minY: f32, minZ: f32, maxX: f32, maxY: f32, maxZ: f32) -> i64 {
    unsafe { __dsdk_CreateZone.expect("CreateZone function was not found")(name, minX, minY, minZ, maxX, maxY, maxZ) }
}
pub type _CreateZone = unsafe extern "C" fn(&Str, f32, f32, f32, f32, f32, f32) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_CreateZone: Option<_CreateZone> = None;

/// Destroy a spatial zone trigger
///
/// # Arguments
/// * `zoneId` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn DestroyZone(zoneId: i64) {
    unsafe { __dsdk_DestroyZone.expect("DestroyZone function was not found")(zoneId) }
}
pub type _DestroyZone = unsafe extern "C" fn(i64);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_DestroyZone: Option<_DestroyZone> = None;

