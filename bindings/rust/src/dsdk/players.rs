// Generated from dsdk.pplugin (group: players)

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

/// Get CBasePlayerController address for player slot
///
/// # Arguments
/// * `playerSlot` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetPlayerController(playerSlot: i32) -> i64 {
    unsafe { __dsdk_GetPlayerController.expect("GetPlayerController function was not found")(playerSlot) }
}
pub type _GetPlayerController = unsafe extern "C" fn(i32) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetPlayerController: Option<_GetPlayerController> = None;

/// Get CCitadelPlayerPawn address for player slot
///
/// # Arguments
/// * `playerSlot` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetPlayerPawn(playerSlot: i32) -> i64 {
    unsafe { __dsdk_GetPlayerPawn.expect("GetPlayerPawn function was not found")(playerSlot) }
}
pub type _GetPlayerPawn = unsafe extern "C" fn(i32) -> i64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetPlayerPawn: Option<_GetPlayerPawn> = None;

/// Get player slot from controller address
///
/// # Arguments
/// * `controller` - (int64)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetPlayerSlot(controller: i64) -> i32 {
    unsafe { __dsdk_GetPlayerSlot.expect("GetPlayerSlot function was not found")(controller) }
}
pub type _GetPlayerSlot = unsafe extern "C" fn(i64) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetPlayerSlot: Option<_GetPlayerSlot> = None;

/// Get player display name
///
/// # Arguments
/// * `playerSlot` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetPlayerName(playerSlot: i32) -> Str {
    unsafe { __dsdk_GetPlayerName.expect("GetPlayerName function was not found")(playerSlot) }
}
pub type _GetPlayerName = unsafe extern "C" fn(i32) -> Str;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetPlayerName: Option<_GetPlayerName> = None;

/// Get player 64-bit SteamID
///
/// # Arguments
/// * `playerSlot` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetSteamID(playerSlot: i32) -> u64 {
    unsafe { __dsdk_GetSteamID.expect("GetSteamID function was not found")(playerSlot) }
}
pub type _GetSteamID = unsafe extern "C" fn(i32) -> u64;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetSteamID: Option<_GetSteamID> = None;

/// Check if player Steam ticket is validated
///
/// # Arguments
/// * `playerSlot` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn IsClientAuthenticated(playerSlot: i32) -> bool {
    unsafe { __dsdk_IsClientAuthenticated.expect("IsClientAuthenticated function was not found")(playerSlot) }
}
pub type _IsClientAuthenticated = unsafe extern "C" fn(i32) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_IsClientAuthenticated: Option<_IsClientAuthenticated> = None;

/// Check if client is connected
///
/// # Arguments
/// * `playerSlot` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn IsClientConnected(playerSlot: i32) -> bool {
    unsafe { __dsdk_IsClientConnected.expect("IsClientConnected function was not found")(playerSlot) }
}
pub type _IsClientConnected = unsafe extern "C" fn(i32) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_IsClientConnected: Option<_IsClientConnected> = None;

/// Check if player is a bot/fake client
///
/// # Arguments
/// * `playerSlot` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn IsFakeClient(playerSlot: i32) -> bool {
    unsafe { __dsdk_IsFakeClient.expect("IsFakeClient function was not found")(playerSlot) }
}
pub type _IsFakeClient = unsafe extern "C" fn(i32) -> bool;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_IsFakeClient: Option<_IsFakeClient> = None;

/// Create a fake client in the match
///
/// # Arguments
/// * `name` - (string)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn CreateFakeClient(name: &Str) -> i32 {
    unsafe { __dsdk_CreateFakeClient.expect("CreateFakeClient function was not found")(name) }
}
pub type _CreateFakeClient = unsafe extern "C" fn(&Str) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_CreateFakeClient: Option<_CreateFakeClient> = None;

/// Disconnect a client with disconnection reason code
///
/// # Arguments
/// * `playerSlot` - (int32)
/// * `reason` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn DisconnectClient(playerSlot: i32, reason: i32) {
    unsafe { __dsdk_DisconnectClient.expect("DisconnectClient function was not found")(playerSlot, reason) }
}
pub type _DisconnectClient = unsafe extern "C" fn(i32, i32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_DisconnectClient: Option<_DisconnectClient> = None;

/// Kick client with message and code
///
/// # Arguments
/// * `playerSlot` - (int32)
/// * `reason` - (string)
/// * `code` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn KickClient(playerSlot: i32, reason: &Str, code: i32) {
    unsafe { __dsdk_KickClient.expect("KickClient function was not found")(playerSlot, reason, code) }
}
pub type _KickClient = unsafe extern "C" fn(i32, &Str, i32);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_KickClient: Option<_KickClient> = None;

/// Change team of player controller
///
/// # Arguments
/// * `controller` - (int64)
/// * `teamNum` - (int32)
/// * `keepHero` - (bool)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn ChangeTeam(controller: i64, teamNum: i32, keepHero: bool) {
    unsafe { __dsdk_ChangeTeam.expect("ChangeTeam function was not found")(controller, teamNum, keepHero) }
}
pub type _ChangeTeam = unsafe extern "C" fn(i64, i32, bool);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_ChangeTeam: Option<_ChangeTeam> = None;

/// Get ping of player in milliseconds
///
/// # Arguments
/// * `playerSlot` - (int32)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn GetPlayerPing(playerSlot: i32) -> i32 {
    unsafe { __dsdk_GetPlayerPing.expect("GetPlayerPing function was not found")(playerSlot) }
}
pub type _GetPlayerPing = unsafe extern "C" fn(i32) -> i32;
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_GetPlayerPing: Option<_GetPlayerPing> = None;

