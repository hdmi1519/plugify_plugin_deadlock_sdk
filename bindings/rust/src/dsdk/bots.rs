// Generated from dsdk.pplugin (group: bots)

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

/// Spawn a bot hero into the match
///
/// # Arguments
/// * `heroName` - (string)
/// * `team` - (int32)
/// * `posX` - (float)
/// * `posY` - (float)
/// * `posZ` - (float)
/// * `assignLane` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn BotCreate(heroName: &Str, team: i32, posX: f32, posY: f32, posZ: f32, assignLane: bool) -> i64 {
    unsafe { __dsdk_BotCreate.expect("BotCreate function was not found")(heroName, team, posX, posY, posZ, assignLane) }
}
pub type _BotCreate = unsafe extern "C" fn(&Str, i32, f32, f32, f32, bool) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_BotCreate: Option<_BotCreate> = None;

/// Get brain entity pointer for player bot pawn
///
/// # Arguments
/// * `pawn` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn BotGetBrain(pawn: i64) -> i64 {
    unsafe { __dsdk_BotGetBrain.expect("BotGetBrain function was not found")(pawn) }
}
pub type _BotGetBrain = unsafe extern "C" fn(i64) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_BotGetBrain: Option<_BotGetBrain> = None;

/// Get pawn entity controlled by bot brain
///
/// # Arguments
/// * `brain` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn BotGetPawn(brain: i64) -> i64 {
    unsafe { __dsdk_BotGetPawn.expect("BotGetPawn function was not found")(brain) }
}
pub type _BotGetPawn = unsafe extern "C" fn(i64) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_BotGetPawn: Option<_BotGetPawn> = None;

/// Assign lane index to bot
///
/// # Arguments
/// * `pawn` - (int64)
/// * `lane` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn BotSetLane(pawn: i64, lane: i32) -> bool {
    unsafe { __dsdk_BotSetLane.expect("BotSetLane function was not found")(pawn, lane) }
}
pub type _BotSetLane = unsafe extern "C" fn(i64, i32) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_BotSetLane: Option<_BotSetLane> = None;

/// Get assigned lane index of bot
///
/// # Arguments
/// * `pawn` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn BotGetLane(pawn: i64) -> i32 {
    unsafe { __dsdk_BotGetLane.expect("BotGetLane function was not found")(pawn) }
}
pub type _BotGetLane = unsafe extern "C" fn(i64) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_BotGetLane: Option<_BotGetLane> = None;

