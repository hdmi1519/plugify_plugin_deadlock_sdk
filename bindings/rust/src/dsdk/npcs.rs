// Generated from dsdk.pplugin (group: npcs)

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

/// Direct AI NPC to move to goal location
///
/// # Arguments
/// * `npc` - (int64)
/// * `x` - (float)
/// * `y` - (float)
/// * `z` - (float)
/// * `run` - (bool)
/// * `tolerance` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn NpcMoveTo(npc: i64, x: f32, y: f32, z: f32, run: bool, tolerance: f32) {
    unsafe { __dsdk_NpcMoveTo.expect("NpcMoveTo function was not found")(npc, x, y, z, run, tolerance) }
}
pub type _NpcMoveTo = unsafe extern "C" fn(i64, f32, f32, f32, bool, f32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_NpcMoveTo: Option<_NpcMoveTo> = None;

/// Stop movement of AI NPC
///
/// # Arguments
/// * `npc` - (int64)
/// * `instant` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn NpcStopMoving(npc: i64, instant: bool) {
    unsafe { __dsdk_NpcStopMoving.expect("NpcStopMoving function was not found")(npc, instant) }
}
pub type _NpcStopMoving = unsafe extern "C" fn(i64, bool);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_NpcStopMoving: Option<_NpcStopMoving> = None;

/// Set target enemy entity of AI NPC
///
/// # Arguments
/// * `npc` - (int64)
/// * `enemy` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn NpcSetEnemy(npc: i64, enemy: i64) {
    unsafe { __dsdk_NpcSetEnemy.expect("NpcSetEnemy function was not found")(npc, enemy) }
}
pub type _NpcSetEnemy = unsafe extern "C" fn(i64, i64);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_NpcSetEnemy: Option<_NpcSetEnemy> = None;

/// Set NPC AI state
///
/// # Arguments
/// * `npc` - (int64)
/// * `state` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn NpcSetState(npc: i64, state: i32) {
    unsafe { __dsdk_NpcSetState.expect("NpcSetState function was not found")(npc, state) }
}
pub type _NpcSetState = unsafe extern "C" fn(i64, i32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_NpcSetState: Option<_NpcSetState> = None;

/// Spawn lane or neutral trooper NPC
///
/// # Arguments
/// * `posX` - (float)
/// * `posY` - (float)
/// * `posZ` - (float)
/// * `pitch` - (float)
/// * `yaw` - (float)
/// * `roll` - (float)
/// * `team` - (int32)
/// * `type_` - (int32)
/// * `variant` - (int32)
/// * `snapToGround` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn NpcCreateTrooper(posX: f32, posY: f32, posZ: f32, pitch: f32, yaw: f32, roll: f32, team: i32, type_: i32, variant: i32, snapToGround: bool) -> i64 {
    unsafe { __dsdk_NpcCreateTrooper.expect("NpcCreateTrooper function was not found")(posX, posY, posZ, pitch, yaw, roll, team, type_, variant, snapToGround) }
}
pub type _NpcCreateTrooper = unsafe extern "C" fn(f32, f32, f32, f32, f32, f32, i32, i32, i32, bool) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_NpcCreateTrooper: Option<_NpcCreateTrooper> = None;

