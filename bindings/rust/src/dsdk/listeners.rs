// Generated from dsdk.pplugin (group: listeners)

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

/// Register Currency modification listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnModifyCurrency_Register(callback: ModifyCurrencyCallback) {
    unsafe { __dsdk_OnModifyCurrency_Register.expect("OnModifyCurrency_Register function was not found")(callback) }
}
pub type _OnModifyCurrency_Register = unsafe extern "C" fn(ModifyCurrencyCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnModifyCurrency_Register: Option<_OnModifyCurrency_Register> = None;

/// Unregister Currency modification listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnModifyCurrency_Unregister(callback: ModifyCurrencyCallback) {
    unsafe { __dsdk_OnModifyCurrency_Unregister.expect("OnModifyCurrency_Unregister function was not found")(callback) }
}
pub type _OnModifyCurrency_Unregister = unsafe extern "C" fn(ModifyCurrencyCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnModifyCurrency_Unregister: Option<_OnModifyCurrency_Unregister> = None;

/// Register Entity take damage listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnTakeDamage_Register(callback: TakeDamageCallback) {
    unsafe { __dsdk_OnTakeDamage_Register.expect("OnTakeDamage_Register function was not found")(callback) }
}
pub type _OnTakeDamage_Register = unsafe extern "C" fn(TakeDamageCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnTakeDamage_Register: Option<_OnTakeDamage_Register> = None;

/// Unregister Entity take damage listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnTakeDamage_Unregister(callback: TakeDamageCallback) {
    unsafe { __dsdk_OnTakeDamage_Unregister.expect("OnTakeDamage_Unregister function was not found")(callback) }
}
pub type _OnTakeDamage_Unregister = unsafe extern "C" fn(TakeDamageCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnTakeDamage_Unregister: Option<_OnTakeDamage_Unregister> = None;

/// Register Client connection listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnClientConnect_Register(callback: ClientConnectCallback) {
    unsafe { __dsdk_OnClientConnect_Register.expect("OnClientConnect_Register function was not found")(callback) }
}
pub type _OnClientConnect_Register = unsafe extern "C" fn(ClientConnectCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnClientConnect_Register: Option<_OnClientConnect_Register> = None;

/// Unregister Client connection listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnClientConnect_Unregister(callback: ClientConnectCallback) {
    unsafe { __dsdk_OnClientConnect_Unregister.expect("OnClientConnect_Unregister function was not found")(callback) }
}
pub type _OnClientConnect_Unregister = unsafe extern "C" fn(ClientConnectCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnClientConnect_Unregister: Option<_OnClientConnect_Unregister> = None;

/// Register Client put in server listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnClientPutInServer_Register(callback: ClientPutInServerCallback) {
    unsafe { __dsdk_OnClientPutInServer_Register.expect("OnClientPutInServer_Register function was not found")(callback) }
}
pub type _OnClientPutInServer_Register = unsafe extern "C" fn(ClientPutInServerCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnClientPutInServer_Register: Option<_OnClientPutInServer_Register> = None;

/// Unregister Client put in server listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnClientPutInServer_Unregister(callback: ClientPutInServerCallback) {
    unsafe { __dsdk_OnClientPutInServer_Unregister.expect("OnClientPutInServer_Unregister function was not found")(callback) }
}
pub type _OnClientPutInServer_Unregister = unsafe extern "C" fn(ClientPutInServerCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnClientPutInServer_Unregister: Option<_OnClientPutInServer_Unregister> = None;

/// Register Client disconnect listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnClientDisconnect_Register(callback: ClientDisconnectCallback) {
    unsafe { __dsdk_OnClientDisconnect_Register.expect("OnClientDisconnect_Register function was not found")(callback) }
}
pub type _OnClientDisconnect_Register = unsafe extern "C" fn(ClientDisconnectCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnClientDisconnect_Register: Option<_OnClientDisconnect_Register> = None;

/// Unregister Client disconnect listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnClientDisconnect_Unregister(callback: ClientDisconnectCallback) {
    unsafe { __dsdk_OnClientDisconnect_Unregister.expect("OnClientDisconnect_Unregister function was not found")(callback) }
}
pub type _OnClientDisconnect_Unregister = unsafe extern "C" fn(ClientDisconnectCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnClientDisconnect_Unregister: Option<_OnClientDisconnect_Unregister> = None;

/// Register Server game tick frame listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnGameFrame_Register(callback: GameFrameCallback) {
    unsafe { __dsdk_OnGameFrame_Register.expect("OnGameFrame_Register function was not found")(callback) }
}
pub type _OnGameFrame_Register = unsafe extern "C" fn(GameFrameCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnGameFrame_Register: Option<_OnGameFrame_Register> = None;

/// Unregister Server game tick frame listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnGameFrame_Unregister(callback: GameFrameCallback) {
    unsafe { __dsdk_OnGameFrame_Unregister.expect("OnGameFrame_Unregister function was not found")(callback) }
}
pub type _OnGameFrame_Unregister = unsafe extern "C" fn(GameFrameCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnGameFrame_Unregister: Option<_OnGameFrame_Unregister> = None;

/// Register Entity created listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnEntityCreated_Register(callback: EntityCallback) {
    unsafe { __dsdk_OnEntityCreated_Register.expect("OnEntityCreated_Register function was not found")(callback) }
}
pub type _OnEntityCreated_Register = unsafe extern "C" fn(EntityCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnEntityCreated_Register: Option<_OnEntityCreated_Register> = None;

/// Unregister Entity created listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnEntityCreated_Unregister(callback: EntityCallback) {
    unsafe { __dsdk_OnEntityCreated_Unregister.expect("OnEntityCreated_Unregister function was not found")(callback) }
}
pub type _OnEntityCreated_Unregister = unsafe extern "C" fn(EntityCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnEntityCreated_Unregister: Option<_OnEntityCreated_Unregister> = None;

/// Register Entity spawned listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnEntitySpawned_Register(callback: EntityCallback) {
    unsafe { __dsdk_OnEntitySpawned_Register.expect("OnEntitySpawned_Register function was not found")(callback) }
}
pub type _OnEntitySpawned_Register = unsafe extern "C" fn(EntityCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnEntitySpawned_Register: Option<_OnEntitySpawned_Register> = None;

/// Unregister Entity spawned listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnEntitySpawned_Unregister(callback: EntityCallback) {
    unsafe { __dsdk_OnEntitySpawned_Unregister.expect("OnEntitySpawned_Unregister function was not found")(callback) }
}
pub type _OnEntitySpawned_Unregister = unsafe extern "C" fn(EntityCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnEntitySpawned_Unregister: Option<_OnEntitySpawned_Unregister> = None;

/// Register Entity deleted listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnEntityDeleted_Register(callback: EntityCallback) {
    unsafe { __dsdk_OnEntityDeleted_Register.expect("OnEntityDeleted_Register function was not found")(callback) }
}
pub type _OnEntityDeleted_Register = unsafe extern "C" fn(EntityCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnEntityDeleted_Register: Option<_OnEntityDeleted_Register> = None;

/// Unregister Entity deleted listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnEntityDeleted_Unregister(callback: EntityCallback) {
    unsafe { __dsdk_OnEntityDeleted_Unregister.expect("OnEntityDeleted_Unregister function was not found")(callback) }
}
pub type _OnEntityDeleted_Unregister = unsafe extern "C" fn(EntityCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnEntityDeleted_Unregister: Option<_OnEntityDeleted_Unregister> = None;

/// Register Game state change listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnGameStateChanged_Register(callback: GameStateChangedCallback) {
    unsafe { __dsdk_OnGameStateChanged_Register.expect("OnGameStateChanged_Register function was not found")(callback) }
}
pub type _OnGameStateChanged_Register = unsafe extern "C" fn(GameStateChangedCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnGameStateChanged_Register: Option<_OnGameStateChanged_Register> = None;

/// Unregister Game state change listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnGameStateChanged_Unregister(callback: GameStateChangedCallback) {
    unsafe { __dsdk_OnGameStateChanged_Unregister.expect("OnGameStateChanged_Unregister function was not found")(callback) }
}
pub type _OnGameStateChanged_Unregister = unsafe extern "C" fn(GameStateChangedCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnGameStateChanged_Unregister: Option<_OnGameStateChanged_Unregister> = None;

/// Register Entity AcceptInput listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnEntityAcceptInput_Register(callback: EntityIOCallback) {
    unsafe { __dsdk_OnEntityAcceptInput_Register.expect("OnEntityAcceptInput_Register function was not found")(callback) }
}
pub type _OnEntityAcceptInput_Register = unsafe extern "C" fn(EntityIOCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnEntityAcceptInput_Register: Option<_OnEntityAcceptInput_Register> = None;

/// Unregister Entity AcceptInput listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnEntityAcceptInput_Unregister(callback: EntityIOCallback) {
    unsafe { __dsdk_OnEntityAcceptInput_Unregister.expect("OnEntityAcceptInput_Unregister function was not found")(callback) }
}
pub type _OnEntityAcceptInput_Unregister = unsafe extern "C" fn(EntityIOCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnEntityAcceptInput_Unregister: Option<_OnEntityAcceptInput_Unregister> = None;

/// Register NPC schedule selection listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnNpcSelectSchedule_Register(callback: NpcSelectScheduleCallback) {
    unsafe { __dsdk_OnNpcSelectSchedule_Register.expect("OnNpcSelectSchedule_Register function was not found")(callback) }
}
pub type _OnNpcSelectSchedule_Register = unsafe extern "C" fn(NpcSelectScheduleCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnNpcSelectSchedule_Register: Option<_OnNpcSelectSchedule_Register> = None;

/// Unregister NPC schedule selection listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnNpcSelectSchedule_Unregister(callback: NpcSelectScheduleCallback) {
    unsafe { __dsdk_OnNpcSelectSchedule_Unregister.expect("OnNpcSelectSchedule_Unregister function was not found")(callback) }
}
pub type _OnNpcSelectSchedule_Unregister = unsafe extern "C" fn(NpcSelectScheduleCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnNpcSelectSchedule_Unregister: Option<_OnNpcSelectSchedule_Unregister> = None;

/// Register Entity FireOutput listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnEntityFireOutput_Register(callback: EntityOutputCallback) {
    unsafe { __dsdk_OnEntityFireOutput_Register.expect("OnEntityFireOutput_Register function was not found")(callback) }
}
pub type _OnEntityFireOutput_Register = unsafe extern "C" fn(EntityOutputCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnEntityFireOutput_Register: Option<_OnEntityFireOutput_Register> = None;

/// Unregister Entity FireOutput listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnEntityFireOutput_Unregister(callback: EntityOutputCallback) {
    unsafe { __dsdk_OnEntityFireOutput_Unregister.expect("OnEntityFireOutput_Unregister function was not found")(callback) }
}
pub type _OnEntityFireOutput_Unregister = unsafe extern "C" fn(EntityOutputCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnEntityFireOutput_Unregister: Option<_OnEntityFireOutput_Unregister> = None;

/// Register CBasePlayerController::ProcessUsercmds listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnProcessUsercmds_Register(callback: ProcessUsercmdsCallback) {
    unsafe { __dsdk_OnProcessUsercmds_Register.expect("OnProcessUsercmds_Register function was not found")(callback) }
}
pub type _OnProcessUsercmds_Register = unsafe extern "C" fn(ProcessUsercmdsCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnProcessUsercmds_Register: Option<_OnProcessUsercmds_Register> = None;

/// Unregister CBasePlayerController::ProcessUsercmds listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnProcessUsercmds_Unregister(callback: ProcessUsercmdsCallback) {
    unsafe { __dsdk_OnProcessUsercmds_Unregister.expect("OnProcessUsercmds_Unregister function was not found")(callback) }
}
pub type _OnProcessUsercmds_Unregister = unsafe extern "C" fn(ProcessUsercmdsCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnProcessUsercmds_Unregister: Option<_OnProcessUsercmds_Unregister> = None;

/// Register CCitadelPlayerPawn::AbilityThink listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnAbilityThink_Register(callback: AbilityThinkCallback) {
    unsafe { __dsdk_OnAbilityThink_Register.expect("OnAbilityThink_Register function was not found")(callback) }
}
pub type _OnAbilityThink_Register = unsafe extern "C" fn(AbilityThinkCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnAbilityThink_Register: Option<_OnAbilityThink_Register> = None;

/// Unregister CCitadelPlayerPawn::AbilityThink listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnAbilityThink_Unregister(callback: AbilityThinkCallback) {
    unsafe { __dsdk_OnAbilityThink_Unregister.expect("OnAbilityThink_Unregister function was not found")(callback) }
}
pub type _OnAbilityThink_Unregister = unsafe extern "C" fn(AbilityThinkCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnAbilityThink_Unregister: Option<_OnAbilityThink_Unregister> = None;

/// Register CModifierProperty::AddModifier listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnAddModifier_Register(callback: AddModifierCallback) {
    unsafe { __dsdk_OnAddModifier_Register.expect("OnAddModifier_Register function was not found")(callback) }
}
pub type _OnAddModifier_Register = unsafe extern "C" fn(AddModifierCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnAddModifier_Register: Option<_OnAddModifier_Register> = None;

/// Unregister CModifierProperty::AddModifier listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnAddModifier_Unregister(callback: AddModifierCallback) {
    unsafe { __dsdk_OnAddModifier_Unregister.expect("OnAddModifier_Unregister function was not found")(callback) }
}
pub type _OnAddModifier_Unregister = unsafe extern "C" fn(AddModifierCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnAddModifier_Unregister: Option<_OnAddModifier_Unregister> = None;

/// Register CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnHeroInitialized_Register(callback: HeroInitializedCallback) {
    unsafe { __dsdk_OnHeroInitialized_Register.expect("OnHeroInitialized_Register function was not found")(callback) }
}
pub type _OnHeroInitialized_Register = unsafe extern "C" fn(HeroInitializedCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnHeroInitialized_Register: Option<_OnHeroInitialized_Register> = None;

/// Unregister CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnHeroInitialized_Unregister(callback: HeroInitializedCallback) {
    unsafe { __dsdk_OnHeroInitialized_Unregister.expect("OnHeroInitialized_Unregister function was not found")(callback) }
}
pub type _OnHeroInitialized_Unregister = unsafe extern "C" fn(HeroInitializedCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnHeroInitialized_Unregister: Option<_OnHeroInitialized_Unregister> = None;

/// Register game event listener hook (e.g. player_death, player_respawned)
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnGameEvent_Register(callback: GameEventCallback) {
    unsafe { __dsdk_OnGameEvent_Register.expect("OnGameEvent_Register function was not found")(callback) }
}
pub type _OnGameEvent_Register = unsafe extern "C" fn(GameEventCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnGameEvent_Register: Option<_OnGameEvent_Register> = None;

/// Unregister game event listener hook
///
/// # Arguments
/// * `callback` - (function)
#[track_caller]
#[allow(dead_code, non_snake_case)]
pub fn OnGameEvent_Unregister(callback: GameEventCallback) {
    unsafe { __dsdk_OnGameEvent_Unregister.expect("OnGameEvent_Unregister function was not found")(callback) }
}
pub type _OnGameEvent_Unregister = unsafe extern "C" fn(GameEventCallback);
#[allow(dead_code, non_upper_case_globals)]
#[unsafe(no_mangle)]
pub static mut __dsdk_OnGameEvent_Unregister: Option<_OnGameEvent_Unregister> = None;

