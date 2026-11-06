// Generated from dsdk.pplugin (group: currency)

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

/// Modify currency (souls/gold) for player pawn
///
/// # Arguments
/// * `pawn` - (int64)
/// * `currencyType` - (uint32)
/// * `amount` - (int32)
/// * `source` - (uint32)
/// * `silent` - (bool)
/// * `forceGain` - (bool)
/// * `spendOnly` - (bool)
/// * `sourceAbility` - (int64)
/// * `sourceEntity` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ModifyCurrency(pawn: i64, currencyType: ECurrencyType, amount: i32, source: ECurrencySource, silent: bool, forceGain: bool, spendOnly: bool, sourceAbility: i64, sourceEntity: i64) {
    unsafe { __dsdk_ModifyCurrency.expect("ModifyCurrency function was not found")(pawn, currencyType, amount, source, silent, forceGain, spendOnly, sourceAbility, sourceEntity) }
}
pub type _ModifyCurrency = unsafe extern "C" fn(i64, ECurrencyType, i32, ECurrencySource, bool, bool, bool, i64, i64);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ModifyCurrency: Option<_ModifyCurrency> = None;

/// Get current currency value of pawn
///
/// # Arguments
/// * `pawn` - (int64)
/// * `currencyType` - (uint32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetCurrency(pawn: i64, currencyType: ECurrencyType) -> i32 {
    unsafe { __dsdk_GetCurrency.expect("GetCurrency function was not found")(pawn, currencyType) }
}
pub type _GetCurrency = unsafe extern "C" fn(i64, ECurrencyType) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetCurrency: Option<_GetCurrency> = None;

