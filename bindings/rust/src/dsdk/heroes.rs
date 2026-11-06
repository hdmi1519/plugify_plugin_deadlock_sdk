// Generated from dsdk.pplugin (group: heroes)

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

/// Select a hero for controller
///
/// # Arguments
/// * `controller` - (int64)
/// * `heroName` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SelectHero(controller: i64, heroName: &Str) {
    unsafe { __dsdk_SelectHero.expect("SelectHero function was not found")(controller, heroName) }
}
pub type _SelectHero = unsafe extern "C" fn(i64, &Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SelectHero: Option<_SelectHero> = None;

/// Reset hero state on pawn
///
/// # Arguments
/// * `pawn` - (int64)
/// * `reset` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ResetHero(pawn: i64, reset: bool) {
    unsafe { __dsdk_ResetHero.expect("ResetHero function was not found")(pawn, reset) }
}
pub type _ResetHero = unsafe extern "C" fn(i64, bool);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ResetHero: Option<_ResetHero> = None;

/// Precache hero assets
///
/// # Arguments
/// * `heroName` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn PrecacheHero(heroName: &Str) {
    unsafe { __dsdk_PrecacheHero.expect("PrecacheHero function was not found")(heroName) }
}
pub type _PrecacheHero = unsafe extern "C" fn(&Str);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_PrecacheHero: Option<_PrecacheHero> = None;

/// Force immediate hero pawn respawn
///
/// # Arguments
/// * `pawn` - (int64)
/// * `releaseButtons` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ForceRespawn(pawn: i64, releaseButtons: bool) {
    unsafe { __dsdk_ForceRespawn.expect("ForceRespawn function was not found")(pawn, releaseButtons) }
}
pub type _ForceRespawn = unsafe extern "C" fn(i64, bool);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ForceRespawn: Option<_ForceRespawn> = None;

/// Lookup hero definition pointer
///
/// # Arguments
/// * `heroName` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetHeroData(heroName: &Str) -> i64 {
    unsafe { __dsdk_GetHeroData.expect("GetHeroData function was not found")(heroName) }
}
pub type _GetHeroData = unsafe extern "C" fn(&Str) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetHeroData: Option<_GetHeroData> = None;

/// Get name of hero for pawn
///
/// # Arguments
/// * `pawn` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetHeroName(pawn: i64) -> Str {
    unsafe { __dsdk_GetHeroName.expect("GetHeroName function was not found")(pawn) }
}
pub type _GetHeroName = unsafe extern "C" fn(i64) -> Str;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetHeroName: Option<_GetHeroName> = None;

