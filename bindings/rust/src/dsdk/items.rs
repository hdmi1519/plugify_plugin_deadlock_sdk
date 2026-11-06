// Generated from dsdk.pplugin (group: items)

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

/// Add an item to player pawn
///
/// # Arguments
/// * `pawn` - (int64)
/// * `itemName` - (string)
/// * `upgradeTier` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn AddItem(pawn: i64, itemName: &Str, upgradeTier: i32) -> i64 {
    unsafe { __dsdk_AddItem.expect("AddItem function was not found")(pawn, itemName, upgradeTier) }
}
pub type _AddItem = unsafe extern "C" fn(i64, &Str, i32) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_AddItem: Option<_AddItem> = None;

/// Sell an item from pawn
///
/// # Arguments
/// * `pawn` - (int64)
/// * `itemName` - (string)
/// * `fullRefund` - (bool)
/// * `forceSellPrice` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn SellItem(pawn: i64, itemName: &Str, fullRefund: bool, forceSellPrice: bool) -> bool {
    unsafe { __dsdk_SellItem.expect("SellItem function was not found")(pawn, itemName, fullRefund, forceSellPrice) }
}
pub type _SellItem = unsafe extern "C" fn(i64, &Str, bool, bool) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_SellItem: Option<_SellItem> = None;

/// Get item imbue effect flags
///
/// # Arguments
/// * `itemName` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetItemImbueEffects(itemName: &Str) -> i32 {
    unsafe { __dsdk_GetItemImbueEffects.expect("GetItemImbueEffects function was not found")(itemName) }
}
pub type _GetItemImbueEffects = unsafe extern "C" fn(&Str) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetItemImbueEffects: Option<_GetItemImbueEffects> = None;

/// Check if ability can receive imbue
///
/// # Arguments
/// * `targetAbility` - (int64)
/// * `itemName` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn CanImbueAbility(targetAbility: i64, itemName: &Str) -> bool {
    unsafe { __dsdk_CanImbueAbility.expect("CanImbueAbility function was not found")(targetAbility, itemName) }
}
pub type _CanImbueAbility = unsafe extern "C" fn(i64, &Str) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_CanImbueAbility: Option<_CanImbueAbility> = None;

/// Imbue item onto target ability
///
/// # Arguments
/// * `item` - (int64)
/// * `targetAbility` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ImbueAbility(item: i64, targetAbility: i64) -> bool {
    unsafe { __dsdk_ImbueAbility.expect("ImbueAbility function was not found")(item, targetAbility) }
}
pub type _ImbueAbility = unsafe extern "C" fn(i64, i64) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ImbueAbility: Option<_ImbueAbility> = None;

