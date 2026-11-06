// Generated from dsdk.pplugin (group: entities)

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

/// Create entity instance by class name
///
/// # Arguments
/// * `className` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn CreateEntityByName(className: &Str) -> i64 {
    unsafe { __dsdk_CreateEntityByName.expect("CreateEntityByName function was not found")(className) }
}
pub type _CreateEntityByName = unsafe extern "C" fn(&Str) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_CreateEntityByName: Option<_CreateEntityByName> = None;

/// Queue entity spawn with optional entity keyvalues
///
/// # Arguments
/// * `entity` - (int64)
/// * `ekv` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn QueueSpawnEntity(entity: i64, ekv: i64) {
    unsafe { __dsdk_QueueSpawnEntity.expect("QueueSpawnEntity function was not found")(entity, ekv) }
}
pub type _QueueSpawnEntity = unsafe extern "C" fn(i64, i64);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_QueueSpawnEntity: Option<_QueueSpawnEntity> = None;

/// Execute queued entity creation
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ExecuteQueuedCreation() {
    unsafe { __dsdk_ExecuteQueuedCreation.expect("ExecuteQueuedCreation function was not found")() }
}
pub type _ExecuteQueuedCreation = unsafe extern "C" fn();
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ExecuteQueuedCreation: Option<_ExecuteQueuedCreation> = None;

/// Remove/destroy entity
///
/// # Arguments
/// * `entity` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn RemoveEntity(entity: i64) {
    unsafe { __dsdk_RemoveEntity.expect("RemoveEntity function was not found")(entity) }
}
pub type _RemoveEntity = unsafe extern "C" fn(i64);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_RemoveEntity: Option<_RemoveEntity> = None;

/// Get entity pointer by index
///
/// # Arguments
/// * `index` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetEntityByIndex(index: i32) -> i64 {
    unsafe { __dsdk_GetEntityByIndex.expect("GetEntityByIndex function was not found")(index) }
}
pub type _GetEntityByIndex = unsafe extern "C" fn(i32) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetEntityByIndex: Option<_GetEntityByIndex> = None;

/// Resolve entity pointer from uint32 handle
///
/// # Arguments
/// * `handle` - (uint32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetEntityFromHandle(handle: u32) -> i64 {
    unsafe { __dsdk_GetEntityFromHandle.expect("GetEntityFromHandle function was not found")(handle) }
}
pub type _GetEntityFromHandle = unsafe extern "C" fn(u32) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetEntityFromHandle: Option<_GetEntityFromHandle> = None;

/// Get handle of entity
///
/// # Arguments
/// * `entity` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetEntityHandle(entity: i64) -> u32 {
    unsafe { __dsdk_GetEntityHandle.expect("GetEntityHandle function was not found")(entity) }
}
pub type _GetEntityHandle = unsafe extern "C" fn(i64) -> u32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetEntityHandle: Option<_GetEntityHandle> = None;

/// Find entity by name
///
/// # Arguments
/// * `startEntity` - (int64)
/// * `name` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn FindEntityByName(startEntity: i64, name: &Str) -> i64 {
    unsafe { __dsdk_FindEntityByName.expect("FindEntityByName function was not found")(startEntity, name) }
}
pub type _FindEntityByName = unsafe extern "C" fn(i64, &Str) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_FindEntityByName: Option<_FindEntityByName> = None;

/// Get designer name of entity
///
/// # Arguments
/// * `entity` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetEntityDesignerName(entity: i64) -> Str {
    unsafe { __dsdk_GetEntityDesignerName.expect("GetEntityDesignerName function was not found")(entity) }
}
pub type _GetEntityDesignerName = unsafe extern "C" fn(i64) -> Str;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetEntityDesignerName: Option<_GetEntityDesignerName> = None;

/// Get class name of entity
///
/// # Arguments
/// * `entity` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetEntityClassname(entity: i64) -> Str {
    unsafe { __dsdk_GetEntityClassname.expect("GetEntityClassname function was not found")(entity) }
}
pub type _GetEntityClassname = unsafe extern "C" fn(i64) -> Str;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetEntityClassname: Option<_GetEntityClassname> = None;

/// Teleport entity with position, angles and velocity
///
/// # Arguments
/// * `entity` - (int64)
/// * `posX` - (float)
/// * `posY` - (float)
/// * `posZ` - (float)
/// * `angPitch` - (float)
/// * `angYaw` - (float)
/// * `angRoll` - (float)
/// * `velX` - (float)
/// * `velY` - (float)
/// * `velZ` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn Teleport(entity: i64, posX: f32, posY: f32, posZ: f32, angPitch: f32, angYaw: f32, angRoll: f32, velX: f32, velY: f32, velZ: f32) {
    unsafe { __dsdk_Teleport.expect("Teleport function was not found")(entity, posX, posY, posZ, angPitch, angYaw, angRoll, velX, velY, velZ) }
}
pub type _Teleport = unsafe extern "C" fn(i64, f32, f32, f32, f32, f32, f32, f32, f32, f32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_Teleport: Option<_Teleport> = None;

/// Set visual model of entity
///
/// # Arguments
/// * `entity` - (int64)
/// * `modelName` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetModel(entity: i64, modelName: &Str) {
    unsafe { __dsdk_SetModel.expect("SetModel function was not found")(entity, modelName) }
}
pub type _SetModel = unsafe extern "C" fn(i64, &Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetModel: Option<_SetModel> = None;

/// Get model name of entity
///
/// # Arguments
/// * `entity` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetModelName(entity: i64) -> Str {
    unsafe { __dsdk_GetModelName.expect("GetModelName function was not found")(entity) }
}
pub type _GetModelName = unsafe extern "C" fn(i64) -> Str;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetModelName: Option<_GetModelName> = None;

/// Set visual scale of entity
///
/// # Arguments
/// * `entity` - (int64)
/// * `scale` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetScale(entity: i64, scale: f32) {
    unsafe { __dsdk_SetScale.expect("SetScale function was not found")(entity, scale) }
}
pub type _SetScale = unsafe extern "C" fn(i64, f32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetScale: Option<_SetScale> = None;

/// Set entity move type
///
/// # Arguments
/// * `entity` - (int64)
/// * `moveType` - (uint8)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetMoveType(entity: i64, moveType: u8) {
    unsafe { __dsdk_SetMoveType.expect("SetMoveType function was not found")(entity, moveType) }
}
pub type _SetMoveType = unsafe extern "C" fn(i64, u8);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetMoveType: Option<_SetMoveType> = None;

/// Set entity gravity multiplier
///
/// # Arguments
/// * `entity` - (int64)
/// * `scale` - (float)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SetGravityScale(entity: i64, scale: f32) {
    unsafe { __dsdk_SetGravityScale.expect("SetGravityScale function was not found")(entity, scale) }
}
pub type _SetGravityScale = unsafe extern "C" fn(i64, f32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SetGravityScale: Option<_SetGravityScale> = None;

/// Check if entity class derives from base class name
///
/// # Arguments
/// * `entity` - (int64)
/// * `baseClassName` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn EntityDerivesFrom(entity: i64, baseClassName: &Str) -> bool {
    unsafe { __dsdk_EntityDerivesFrom.expect("EntityDerivesFrom function was not found")(entity, baseClassName) }
}
pub type _EntityDerivesFrom = unsafe extern "C" fn(i64, &Str) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_EntityDerivesFrom: Option<_EntityDerivesFrom> = None;

