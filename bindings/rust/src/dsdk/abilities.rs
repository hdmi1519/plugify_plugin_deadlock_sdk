// Generated from dsdk.pplugin (group: abilities)

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

/// Add an ability to player pawn
///
/// # Arguments
/// * `pawn` - (int64)
/// * `abilityName` - (string)
/// * `slot` - (uint16)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn AddAbility(pawn: i64, abilityName: &Str, slot: u16) -> i64 {
    unsafe { __dsdk_AddAbility.expect("AddAbility function was not found")(pawn, abilityName, slot) }
}
pub type _AddAbility = unsafe extern "C" fn(i64, &Str, u16) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_AddAbility: Option<_AddAbility> = None;

/// Remove ability by name from pawn
///
/// # Arguments
/// * `pawn` - (int64)
/// * `abilityName` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn RemoveAbility(pawn: i64, abilityName: &Str) -> bool {
    unsafe { __dsdk_RemoveAbility.expect("RemoveAbility function was not found")(pawn, abilityName) }
}
pub type _RemoveAbility = unsafe extern "C" fn(i64, &Str) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_RemoveAbility: Option<_RemoveAbility> = None;

/// Remove ability by entity pointer
///
/// # Arguments
/// * `pawn` - (int64)
/// * `ability` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn RemoveAbilityByEntity(pawn: i64, ability: i64) -> bool {
    unsafe { __dsdk_RemoveAbilityByEntity.expect("RemoveAbilityByEntity function was not found")(pawn, ability) }
}
pub type _RemoveAbilityByEntity = unsafe extern "C" fn(i64, i64) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_RemoveAbilityByEntity: Option<_RemoveAbilityByEntity> = None;

/// Find ability in ability component
///
/// # Arguments
/// * `abilityComponent` - (int64)
/// * `abilityName` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn FindAbilityByName(abilityComponent: i64, abilityName: &Str) -> i64 {
    unsafe { __dsdk_FindAbilityByName.expect("FindAbilityByName function was not found")(abilityComponent, abilityName) }
}
pub type _FindAbilityByName = unsafe extern "C" fn(i64, &Str) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_FindAbilityByName: Option<_FindAbilityByName> = None;

/// Get ability at slot index
///
/// # Arguments
/// * `abilityComponent` - (int64)
/// * `slot` - (int16)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetAbilityBySlot(abilityComponent: i64, slot: i16) -> i64 {
    unsafe { __dsdk_GetAbilityBySlot.expect("GetAbilityBySlot function was not found")(abilityComponent, slot) }
}
pub type _GetAbilityBySlot = unsafe extern "C" fn(i64, i16) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetAbilityBySlot: Option<_GetAbilityBySlot> = None;

/// Cast/execute an ability
///
/// # Arguments
/// * `abilityComponent` - (int64)
/// * `ability` - (int64)
/// * `altCast` - (bool)
/// * `flags` - (uint8)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ExecuteAbility(abilityComponent: i64, ability: i64, altCast: bool, flags: u8) -> i32 {
    unsafe { __dsdk_ExecuteAbility.expect("ExecuteAbility function was not found")(abilityComponent, ability, altCast, flags) }
}
pub type _ExecuteAbility = unsafe extern "C" fn(i64, i64, bool, u8) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ExecuteAbility: Option<_ExecuteAbility> = None;

/// Toggle ability active status
///
/// # Arguments
/// * `ability` - (int64)
/// * `activate` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ToggleActivate(ability: i64, activate: bool) {
    unsafe { __dsdk_ToggleActivate.expect("ToggleActivate function was not found")(ability, activate) }
}
pub type _ToggleActivate = unsafe extern "C" fn(i64, bool);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ToggleActivate: Option<_ToggleActivate> = None;

/// Reset ability cooldown and refill charges
///
/// # Arguments
/// * `ability` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ResetAbilityCooldown(ability: i64) {
    unsafe { __dsdk_ResetAbilityCooldown.expect("ResetAbilityCooldown function was not found")(ability) }
}
pub type _ResetAbilityCooldown = unsafe extern "C" fn(i64);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ResetAbilityCooldown: Option<_ResetAbilityCooldown> = None;

/// Get maximum charges of an ability
///
/// # Arguments
/// * `ability` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetAbilityMaxCharges(ability: i64) -> i32 {
    unsafe { __dsdk_GetAbilityMaxCharges.expect("GetAbilityMaxCharges function was not found")(ability) }
}
pub type _GetAbilityMaxCharges = unsafe extern "C" fn(i64) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetAbilityMaxCharges: Option<_GetAbilityMaxCharges> = None;

/// Set upgrade bits on ability
///
/// # Arguments
/// * `ability` - (int64)
/// * `newBits` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetUpgradeBits(ability: i64, newBits: i32) {
    unsafe { __dsdk_SetUpgradeBits.expect("SetUpgradeBits function was not found")(ability, newBits) }
}
pub type _SetUpgradeBits = unsafe extern "C" fn(i64, i32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetUpgradeBits: Option<_SetUpgradeBits> = None;

