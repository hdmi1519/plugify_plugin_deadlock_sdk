package dsdk

/*
#include "listeners.h"
#cgo noescape OnModifyCurrency_Register
#cgo noescape OnModifyCurrency_Unregister
#cgo noescape OnTakeDamage_Register
#cgo noescape OnTakeDamage_Unregister
#cgo noescape OnClientConnect_Register
#cgo noescape OnClientConnect_Unregister
#cgo noescape OnClientPutInServer_Register
#cgo noescape OnClientPutInServer_Unregister
#cgo noescape OnClientDisconnect_Register
#cgo noescape OnClientDisconnect_Unregister
#cgo noescape OnGameFrame_Register
#cgo noescape OnGameFrame_Unregister
#cgo noescape OnEntityCreated_Register
#cgo noescape OnEntityCreated_Unregister
#cgo noescape OnEntitySpawned_Register
#cgo noescape OnEntitySpawned_Unregister
#cgo noescape OnEntityDeleted_Register
#cgo noescape OnEntityDeleted_Unregister
#cgo noescape OnGameStateChanged_Register
#cgo noescape OnGameStateChanged_Unregister
#cgo noescape OnEntityAcceptInput_Register
#cgo noescape OnEntityAcceptInput_Unregister
#cgo noescape OnNpcSelectSchedule_Register
#cgo noescape OnNpcSelectSchedule_Unregister
#cgo noescape OnEntityFireOutput_Register
#cgo noescape OnEntityFireOutput_Unregister
#cgo noescape OnProcessUsercmds_Register
#cgo noescape OnProcessUsercmds_Unregister
#cgo noescape OnAbilityThink_Register
#cgo noescape OnAbilityThink_Unregister
#cgo noescape OnAddModifier_Register
#cgo noescape OnAddModifier_Unregister
#cgo noescape OnHeroInitialized_Register
#cgo noescape OnHeroInitialized_Unregister
#cgo noescape OnGameEvent_Register
#cgo noescape OnGameEvent_Unregister
*/
import "C"
import (
	"errors"
	"reflect"
	"runtime"
	"unsafe"
	"github.com/untrustedmodders/go-plugify"
)

var _ = errors.New("")
var _ = reflect.TypeOf(0)
var _ = runtime.GOOS
var _ = unsafe.Sizeof(0)
var _ = plugify.ApiVersion

// Generated from dsdk (group: listeners)

var _OnModifyCurrency_Register = func(callback ModifyCurrencyCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnModifyCurrency_Register(__callback)
}

// OnModifyCurrency_Register 
//  @brief Register Currency modification listener hook
//
func OnModifyCurrency_Register(callback ModifyCurrencyCallback) {
	_OnModifyCurrency_Register(callback)
}

var _OnModifyCurrency_Unregister = func(callback ModifyCurrencyCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnModifyCurrency_Unregister(__callback)
}

// OnModifyCurrency_Unregister 
//  @brief Unregister Currency modification listener hook
//
func OnModifyCurrency_Unregister(callback ModifyCurrencyCallback) {
	_OnModifyCurrency_Unregister(callback)
}

var _OnTakeDamage_Register = func(callback TakeDamageCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnTakeDamage_Register(__callback)
}

// OnTakeDamage_Register 
//  @brief Register Entity take damage listener hook
//
func OnTakeDamage_Register(callback TakeDamageCallback) {
	_OnTakeDamage_Register(callback)
}

var _OnTakeDamage_Unregister = func(callback TakeDamageCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnTakeDamage_Unregister(__callback)
}

// OnTakeDamage_Unregister 
//  @brief Unregister Entity take damage listener hook
//
func OnTakeDamage_Unregister(callback TakeDamageCallback) {
	_OnTakeDamage_Unregister(callback)
}

var _OnClientConnect_Register = func(callback ClientConnectCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnClientConnect_Register(__callback)
}

// OnClientConnect_Register 
//  @brief Register Client connection listener hook
//
func OnClientConnect_Register(callback ClientConnectCallback) {
	_OnClientConnect_Register(callback)
}

var _OnClientConnect_Unregister = func(callback ClientConnectCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnClientConnect_Unregister(__callback)
}

// OnClientConnect_Unregister 
//  @brief Unregister Client connection listener hook
//
func OnClientConnect_Unregister(callback ClientConnectCallback) {
	_OnClientConnect_Unregister(callback)
}

var _OnClientPutInServer_Register = func(callback ClientPutInServerCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnClientPutInServer_Register(__callback)
}

// OnClientPutInServer_Register 
//  @brief Register Client put in server listener hook
//
func OnClientPutInServer_Register(callback ClientPutInServerCallback) {
	_OnClientPutInServer_Register(callback)
}

var _OnClientPutInServer_Unregister = func(callback ClientPutInServerCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnClientPutInServer_Unregister(__callback)
}

// OnClientPutInServer_Unregister 
//  @brief Unregister Client put in server listener hook
//
func OnClientPutInServer_Unregister(callback ClientPutInServerCallback) {
	_OnClientPutInServer_Unregister(callback)
}

var _OnClientDisconnect_Register = func(callback ClientDisconnectCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnClientDisconnect_Register(__callback)
}

// OnClientDisconnect_Register 
//  @brief Register Client disconnect listener hook
//
func OnClientDisconnect_Register(callback ClientDisconnectCallback) {
	_OnClientDisconnect_Register(callback)
}

var _OnClientDisconnect_Unregister = func(callback ClientDisconnectCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnClientDisconnect_Unregister(__callback)
}

// OnClientDisconnect_Unregister 
//  @brief Unregister Client disconnect listener hook
//
func OnClientDisconnect_Unregister(callback ClientDisconnectCallback) {
	_OnClientDisconnect_Unregister(callback)
}

var _OnGameFrame_Register = func(callback GameFrameCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnGameFrame_Register(__callback)
}

// OnGameFrame_Register 
//  @brief Register Server game tick frame listener hook
//
func OnGameFrame_Register(callback GameFrameCallback) {
	_OnGameFrame_Register(callback)
}

var _OnGameFrame_Unregister = func(callback GameFrameCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnGameFrame_Unregister(__callback)
}

// OnGameFrame_Unregister 
//  @brief Unregister Server game tick frame listener hook
//
func OnGameFrame_Unregister(callback GameFrameCallback) {
	_OnGameFrame_Unregister(callback)
}

var _OnEntityCreated_Register = func(callback EntityCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnEntityCreated_Register(__callback)
}

// OnEntityCreated_Register 
//  @brief Register Entity created listener hook
//
func OnEntityCreated_Register(callback EntityCallback) {
	_OnEntityCreated_Register(callback)
}

var _OnEntityCreated_Unregister = func(callback EntityCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnEntityCreated_Unregister(__callback)
}

// OnEntityCreated_Unregister 
//  @brief Unregister Entity created listener hook
//
func OnEntityCreated_Unregister(callback EntityCallback) {
	_OnEntityCreated_Unregister(callback)
}

var _OnEntitySpawned_Register = func(callback EntityCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnEntitySpawned_Register(__callback)
}

// OnEntitySpawned_Register 
//  @brief Register Entity spawned listener hook
//
func OnEntitySpawned_Register(callback EntityCallback) {
	_OnEntitySpawned_Register(callback)
}

var _OnEntitySpawned_Unregister = func(callback EntityCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnEntitySpawned_Unregister(__callback)
}

// OnEntitySpawned_Unregister 
//  @brief Unregister Entity spawned listener hook
//
func OnEntitySpawned_Unregister(callback EntityCallback) {
	_OnEntitySpawned_Unregister(callback)
}

var _OnEntityDeleted_Register = func(callback EntityCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnEntityDeleted_Register(__callback)
}

// OnEntityDeleted_Register 
//  @brief Register Entity deleted listener hook
//
func OnEntityDeleted_Register(callback EntityCallback) {
	_OnEntityDeleted_Register(callback)
}

var _OnEntityDeleted_Unregister = func(callback EntityCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnEntityDeleted_Unregister(__callback)
}

// OnEntityDeleted_Unregister 
//  @brief Unregister Entity deleted listener hook
//
func OnEntityDeleted_Unregister(callback EntityCallback) {
	_OnEntityDeleted_Unregister(callback)
}

var _OnGameStateChanged_Register = func(callback GameStateChangedCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnGameStateChanged_Register(__callback)
}

// OnGameStateChanged_Register 
//  @brief Register Game state change listener hook
//
func OnGameStateChanged_Register(callback GameStateChangedCallback) {
	_OnGameStateChanged_Register(callback)
}

var _OnGameStateChanged_Unregister = func(callback GameStateChangedCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnGameStateChanged_Unregister(__callback)
}

// OnGameStateChanged_Unregister 
//  @brief Unregister Game state change listener hook
//
func OnGameStateChanged_Unregister(callback GameStateChangedCallback) {
	_OnGameStateChanged_Unregister(callback)
}

var _OnEntityAcceptInput_Register = func(callback EntityIOCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnEntityAcceptInput_Register(__callback)
}

// OnEntityAcceptInput_Register 
//  @brief Register Entity AcceptInput listener hook
//
func OnEntityAcceptInput_Register(callback EntityIOCallback) {
	_OnEntityAcceptInput_Register(callback)
}

var _OnEntityAcceptInput_Unregister = func(callback EntityIOCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnEntityAcceptInput_Unregister(__callback)
}

// OnEntityAcceptInput_Unregister 
//  @brief Unregister Entity AcceptInput listener hook
//
func OnEntityAcceptInput_Unregister(callback EntityIOCallback) {
	_OnEntityAcceptInput_Unregister(callback)
}

var _OnNpcSelectSchedule_Register = func(callback NpcSelectScheduleCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnNpcSelectSchedule_Register(__callback)
}

// OnNpcSelectSchedule_Register 
//  @brief Register NPC schedule selection listener hook
//
func OnNpcSelectSchedule_Register(callback NpcSelectScheduleCallback) {
	_OnNpcSelectSchedule_Register(callback)
}

var _OnNpcSelectSchedule_Unregister = func(callback NpcSelectScheduleCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnNpcSelectSchedule_Unregister(__callback)
}

// OnNpcSelectSchedule_Unregister 
//  @brief Unregister NPC schedule selection listener hook
//
func OnNpcSelectSchedule_Unregister(callback NpcSelectScheduleCallback) {
	_OnNpcSelectSchedule_Unregister(callback)
}

var _OnEntityFireOutput_Register = func(callback EntityOutputCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnEntityFireOutput_Register(__callback)
}

// OnEntityFireOutput_Register 
//  @brief Register Entity FireOutput listener hook
//
func OnEntityFireOutput_Register(callback EntityOutputCallback) {
	_OnEntityFireOutput_Register(callback)
}

var _OnEntityFireOutput_Unregister = func(callback EntityOutputCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnEntityFireOutput_Unregister(__callback)
}

// OnEntityFireOutput_Unregister 
//  @brief Unregister Entity FireOutput listener hook
//
func OnEntityFireOutput_Unregister(callback EntityOutputCallback) {
	_OnEntityFireOutput_Unregister(callback)
}

var _OnProcessUsercmds_Register = func(callback ProcessUsercmdsCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnProcessUsercmds_Register(__callback)
}

// OnProcessUsercmds_Register 
//  @brief Register CBasePlayerController::ProcessUsercmds listener hook
//
func OnProcessUsercmds_Register(callback ProcessUsercmdsCallback) {
	_OnProcessUsercmds_Register(callback)
}

var _OnProcessUsercmds_Unregister = func(callback ProcessUsercmdsCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnProcessUsercmds_Unregister(__callback)
}

// OnProcessUsercmds_Unregister 
//  @brief Unregister CBasePlayerController::ProcessUsercmds listener hook
//
func OnProcessUsercmds_Unregister(callback ProcessUsercmdsCallback) {
	_OnProcessUsercmds_Unregister(callback)
}

var _OnAbilityThink_Register = func(callback AbilityThinkCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnAbilityThink_Register(__callback)
}

// OnAbilityThink_Register 
//  @brief Register CCitadelPlayerPawn::AbilityThink listener hook
//
func OnAbilityThink_Register(callback AbilityThinkCallback) {
	_OnAbilityThink_Register(callback)
}

var _OnAbilityThink_Unregister = func(callback AbilityThinkCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnAbilityThink_Unregister(__callback)
}

// OnAbilityThink_Unregister 
//  @brief Unregister CCitadelPlayerPawn::AbilityThink listener hook
//
func OnAbilityThink_Unregister(callback AbilityThinkCallback) {
	_OnAbilityThink_Unregister(callback)
}

var _OnAddModifier_Register = func(callback AddModifierCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnAddModifier_Register(__callback)
}

// OnAddModifier_Register 
//  @brief Register CModifierProperty::AddModifier listener hook
//
func OnAddModifier_Register(callback AddModifierCallback) {
	_OnAddModifier_Register(callback)
}

var _OnAddModifier_Unregister = func(callback AddModifierCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnAddModifier_Unregister(__callback)
}

// OnAddModifier_Unregister 
//  @brief Unregister CModifierProperty::AddModifier listener hook
//
func OnAddModifier_Unregister(callback AddModifierCallback) {
	_OnAddModifier_Unregister(callback)
}

var _OnHeroInitialized_Register = func(callback HeroInitializedCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnHeroInitialized_Register(__callback)
}

// OnHeroInitialized_Register 
//  @brief Register CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
//
func OnHeroInitialized_Register(callback HeroInitializedCallback) {
	_OnHeroInitialized_Register(callback)
}

var _OnHeroInitialized_Unregister = func(callback HeroInitializedCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnHeroInitialized_Unregister(__callback)
}

// OnHeroInitialized_Unregister 
//  @brief Unregister CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
//
func OnHeroInitialized_Unregister(callback HeroInitializedCallback) {
	_OnHeroInitialized_Unregister(callback)
}

var _OnGameEvent_Register = func(callback GameEventCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnGameEvent_Register(__callback)
}

// OnGameEvent_Register 
//  @brief Register game event listener hook (e.g. player_death, player_respawned)
//
func OnGameEvent_Register(callback GameEventCallback) {
	_OnGameEvent_Register(callback)
}

var _OnGameEvent_Unregister = func(callback GameEventCallback) {
	__callback := plugify.GetFunctionPointerForDelegate(callback)
	C.OnGameEvent_Unregister(__callback)
}

// OnGameEvent_Unregister 
//  @brief Unregister game event listener hook
//
func OnGameEvent_Unregister(callback GameEventCallback) {
	_OnGameEvent_Unregister(callback)
}

