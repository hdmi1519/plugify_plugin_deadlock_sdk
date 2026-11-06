// Generated from dsdk.pplugin (group: modifiers)

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

/// Add modifier to entity
///
/// # Arguments
/// * `entity` - (int64)
/// * `modifierName` - (string)
/// * `kv3` - (int64)
/// * `caster` - (int64)
/// * `ability` - (int64)
/// * `team` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn AddModifier(entity: i64, modifierName: &Str, kv3: i64, caster: i64, ability: i64, team: i32) -> i64 {
    unsafe { __dsdk_AddModifier.expect("AddModifier function was not found")(entity, modifierName, kv3, caster, ability, team) }
}
pub type _AddModifier = unsafe extern "C" fn(i64, &Str, i64, i64, i64, i32) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_AddModifier: Option<_AddModifier> = None;

/// Remove modifier instance from entity
///
/// # Arguments
/// * `entity` - (int64)
/// * `modifier` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn RemoveModifier(entity: i64, modifier: i64) -> bool {
    unsafe { __dsdk_RemoveModifier.expect("RemoveModifier function was not found")(entity, modifier) }
}
pub type _RemoveModifier = unsafe extern "C" fn(i64, i64) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_RemoveModifier: Option<_RemoveModifier> = None;

