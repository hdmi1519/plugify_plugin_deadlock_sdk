// Generated from dsdk.pplugin (group: damage)

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

/// Create CTakeDamageInfo instance
///
/// # Arguments
/// * `inflictor` - (int64)
/// * `attacker` - (int64)
/// * `ability` - (int64)
/// * `damage` - (float)
/// * `damageType` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn CreateDamageInfo(inflictor: i64, attacker: i64, ability: i64, damage: f32, damageType: i32) -> i64 {
    unsafe { __dsdk_CreateDamageInfo.expect("CreateDamageInfo function was not found")(inflictor, attacker, ability, damage, damageType) }
}
pub type _CreateDamageInfo = unsafe extern "C" fn(i64, i64, i64, f32, i32) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_CreateDamageInfo: Option<_CreateDamageInfo> = None;

/// Free CTakeDamageInfo instance
///
/// # Arguments
/// * `info` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn DestroyDamageInfo(info: i64) {
    unsafe { __dsdk_DestroyDamageInfo.expect("DestroyDamageInfo function was not found")(info) }
}
pub type _DestroyDamageInfo = unsafe extern "C" fn(i64);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_DestroyDamageInfo: Option<_DestroyDamageInfo> = None;

/// Inflict damage on victim entity
///
/// # Arguments
/// * `victim` - (int64)
/// * `info` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn TakeDamage(victim: i64, info: i64) {
    unsafe { __dsdk_TakeDamage.expect("TakeDamage function was not found")(victim, info) }
}
pub type _TakeDamage = unsafe extern "C" fn(i64, i64);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_TakeDamage: Option<_TakeDamage> = None;

/// Apply damage bypassing damage filters
///
/// # Arguments
/// * `victim` - (int64)
/// * `info` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ApplyDamage(victim: i64, info: i64) {
    unsafe { __dsdk_ApplyDamage.expect("ApplyDamage function was not found")(victim, info) }
}
pub type _ApplyDamage = unsafe extern "C" fn(i64, i64);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ApplyDamage: Option<_ApplyDamage> = None;

/// Get maximum health of entity
///
/// # Arguments
/// * `entity` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetMaxHealth(entity: i64) -> i32 {
    unsafe { __dsdk_GetMaxHealth.expect("GetMaxHealth function was not found")(entity) }
}
pub type _GetMaxHealth = unsafe extern "C" fn(i64) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetMaxHealth: Option<_GetMaxHealth> = None;

/// Heal entity by amount
///
/// # Arguments
/// * `entity` - (int64)
/// * `amount` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn Heal(entity: i64, amount: f32) -> i32 {
    unsafe { __dsdk_Heal.expect("Heal function was not found")(entity, amount) }
}
pub type _Heal = unsafe extern "C" fn(i64, f32) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_Heal: Option<_Heal> = None;

