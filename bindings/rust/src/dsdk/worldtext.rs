// Generated from dsdk.pplugin (group: worldtext)

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

/// Create 3D point_worldtext entity in the world
///
/// # Arguments
/// * `message` - (string)
/// * `x` - (float)
/// * `y` - (float)
/// * `z` - (float)
/// * `fontSize` - (float)
/// * `r` - (uint8)
/// * `g` - (uint8)
/// * `b` - (uint8)
/// * `a` - (uint8)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn CreateWorldText(message: &Str, x: f32, y: f32, z: f32, fontSize: f32, r: u8, g: u8, b: u8, a: u8) -> i64 {
    unsafe { __dsdk_CreateWorldText.expect("CreateWorldText function was not found")(message, x, y, z, fontSize, r, g, b, a) }
}
pub type _CreateWorldText = unsafe extern "C" fn(&Str, f32, f32, f32, f32, u8, u8, u8, u8) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_CreateWorldText: Option<_CreateWorldText> = None;

/// Update message text of CPointWorldText
///
/// # Arguments
/// * `worldText` - (int64)
/// * `text` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetWorldTextMessage(worldText: i64, text: &Str) {
    unsafe { __dsdk_SetWorldTextMessage.expect("SetWorldTextMessage function was not found")(worldText, text) }
}
pub type _SetWorldTextMessage = unsafe extern "C" fn(i64, &Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetWorldTextMessage: Option<_SetWorldTextMessage> = None;

