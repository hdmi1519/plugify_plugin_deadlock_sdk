// Generated from dsdk.pplugin (group: precaching)

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

/// Precache resource by VPK path
///
/// # Arguments
/// * `path` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn PrecacheResource(path: &Str) {
    unsafe { __dsdk_PrecacheResource.expect("PrecacheResource function was not found")(path) }
}
pub type _PrecacheResource = unsafe extern "C" fn(&Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_PrecacheResource: Option<_PrecacheResource> = None;

/// Precache model resource
///
/// # Arguments
/// * `modelPath` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn PrecacheModel(modelPath: &Str) {
    unsafe { __dsdk_PrecacheModel.expect("PrecacheModel function was not found")(modelPath) }
}
pub type _PrecacheModel = unsafe extern "C" fn(&Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_PrecacheModel: Option<_PrecacheModel> = None;

