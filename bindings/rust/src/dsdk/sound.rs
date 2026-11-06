// Generated from dsdk.pplugin (group: sound)

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

/// Emit sound event from entity
///
/// # Arguments
/// * `entity` - (int64)
/// * `soundName` - (string)
/// * `pitch` - (int32)
/// * `volume` - (float)
/// * `delay` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn EmitSound(entity: i64, soundName: &Str, pitch: i32, volume: f32, delay: f32) {
    unsafe { __dsdk_EmitSound.expect("EmitSound function was not found")(entity, soundName, pitch, volume, delay) }
}
pub type _EmitSound = unsafe extern "C" fn(i64, &Str, i32, f32, f32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_EmitSound: Option<_EmitSound> = None;

/// Generate unique sound event GUID
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn TakeSoundEventGuid() -> u32 {
    unsafe { __dsdk_TakeSoundEventGuid.expect("TakeSoundEventGuid function was not found")() }
}
pub type _TakeSoundEventGuid = unsafe extern "C" fn() -> u32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_TakeSoundEventGuid: Option<_TakeSoundEventGuid> = None;

