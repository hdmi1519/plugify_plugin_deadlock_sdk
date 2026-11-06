module imported.dsdk.listeners;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Register Currency modification listener hook

	Params:
		callback = 
+/
void OnModifyCurrency_Register(ModifyCurrencyCallback callback) {
	__dsdk_OnModifyCurrency_Register(callback);
}
alias _OnModifyCurrency_Register = extern (C) void function(ModifyCurrencyCallback callback);
export __gshared _OnModifyCurrency_Register __dsdk_OnModifyCurrency_Register = null;

/++
	Unregister Currency modification listener hook

	Params:
		callback = 
+/
void OnModifyCurrency_Unregister(ModifyCurrencyCallback callback) {
	__dsdk_OnModifyCurrency_Unregister(callback);
}
alias _OnModifyCurrency_Unregister = extern (C) void function(ModifyCurrencyCallback callback);
export __gshared _OnModifyCurrency_Unregister __dsdk_OnModifyCurrency_Unregister = null;

/++
	Register Entity take damage listener hook

	Params:
		callback = 
+/
void OnTakeDamage_Register(TakeDamageCallback callback) {
	__dsdk_OnTakeDamage_Register(callback);
}
alias _OnTakeDamage_Register = extern (C) void function(TakeDamageCallback callback);
export __gshared _OnTakeDamage_Register __dsdk_OnTakeDamage_Register = null;

/++
	Unregister Entity take damage listener hook

	Params:
		callback = 
+/
void OnTakeDamage_Unregister(TakeDamageCallback callback) {
	__dsdk_OnTakeDamage_Unregister(callback);
}
alias _OnTakeDamage_Unregister = extern (C) void function(TakeDamageCallback callback);
export __gshared _OnTakeDamage_Unregister __dsdk_OnTakeDamage_Unregister = null;

/++
	Register Client connection listener hook

	Params:
		callback = 
+/
void OnClientConnect_Register(ClientConnectCallback callback) {
	__dsdk_OnClientConnect_Register(callback);
}
alias _OnClientConnect_Register = extern (C) void function(ClientConnectCallback callback);
export __gshared _OnClientConnect_Register __dsdk_OnClientConnect_Register = null;

/++
	Unregister Client connection listener hook

	Params:
		callback = 
+/
void OnClientConnect_Unregister(ClientConnectCallback callback) {
	__dsdk_OnClientConnect_Unregister(callback);
}
alias _OnClientConnect_Unregister = extern (C) void function(ClientConnectCallback callback);
export __gshared _OnClientConnect_Unregister __dsdk_OnClientConnect_Unregister = null;

/++
	Register Client put in server listener hook

	Params:
		callback = 
+/
void OnClientPutInServer_Register(ClientPutInServerCallback callback) {
	__dsdk_OnClientPutInServer_Register(callback);
}
alias _OnClientPutInServer_Register = extern (C) void function(ClientPutInServerCallback callback);
export __gshared _OnClientPutInServer_Register __dsdk_OnClientPutInServer_Register = null;

/++
	Unregister Client put in server listener hook

	Params:
		callback = 
+/
void OnClientPutInServer_Unregister(ClientPutInServerCallback callback) {
	__dsdk_OnClientPutInServer_Unregister(callback);
}
alias _OnClientPutInServer_Unregister = extern (C) void function(ClientPutInServerCallback callback);
export __gshared _OnClientPutInServer_Unregister __dsdk_OnClientPutInServer_Unregister = null;

/++
	Register Client disconnect listener hook

	Params:
		callback = 
+/
void OnClientDisconnect_Register(ClientDisconnectCallback callback) {
	__dsdk_OnClientDisconnect_Register(callback);
}
alias _OnClientDisconnect_Register = extern (C) void function(ClientDisconnectCallback callback);
export __gshared _OnClientDisconnect_Register __dsdk_OnClientDisconnect_Register = null;

/++
	Unregister Client disconnect listener hook

	Params:
		callback = 
+/
void OnClientDisconnect_Unregister(ClientDisconnectCallback callback) {
	__dsdk_OnClientDisconnect_Unregister(callback);
}
alias _OnClientDisconnect_Unregister = extern (C) void function(ClientDisconnectCallback callback);
export __gshared _OnClientDisconnect_Unregister __dsdk_OnClientDisconnect_Unregister = null;

/++
	Register Server game tick frame listener hook

	Params:
		callback = 
+/
void OnGameFrame_Register(GameFrameCallback callback) {
	__dsdk_OnGameFrame_Register(callback);
}
alias _OnGameFrame_Register = extern (C) void function(GameFrameCallback callback);
export __gshared _OnGameFrame_Register __dsdk_OnGameFrame_Register = null;

/++
	Unregister Server game tick frame listener hook

	Params:
		callback = 
+/
void OnGameFrame_Unregister(GameFrameCallback callback) {
	__dsdk_OnGameFrame_Unregister(callback);
}
alias _OnGameFrame_Unregister = extern (C) void function(GameFrameCallback callback);
export __gshared _OnGameFrame_Unregister __dsdk_OnGameFrame_Unregister = null;

/++
	Register Entity created listener hook

	Params:
		callback = 
+/
void OnEntityCreated_Register(EntityCallback callback) {
	__dsdk_OnEntityCreated_Register(callback);
}
alias _OnEntityCreated_Register = extern (C) void function(EntityCallback callback);
export __gshared _OnEntityCreated_Register __dsdk_OnEntityCreated_Register = null;

/++
	Unregister Entity created listener hook

	Params:
		callback = 
+/
void OnEntityCreated_Unregister(EntityCallback callback) {
	__dsdk_OnEntityCreated_Unregister(callback);
}
alias _OnEntityCreated_Unregister = extern (C) void function(EntityCallback callback);
export __gshared _OnEntityCreated_Unregister __dsdk_OnEntityCreated_Unregister = null;

/++
	Register Entity spawned listener hook

	Params:
		callback = 
+/
void OnEntitySpawned_Register(EntityCallback callback) {
	__dsdk_OnEntitySpawned_Register(callback);
}
alias _OnEntitySpawned_Register = extern (C) void function(EntityCallback callback);
export __gshared _OnEntitySpawned_Register __dsdk_OnEntitySpawned_Register = null;

/++
	Unregister Entity spawned listener hook

	Params:
		callback = 
+/
void OnEntitySpawned_Unregister(EntityCallback callback) {
	__dsdk_OnEntitySpawned_Unregister(callback);
}
alias _OnEntitySpawned_Unregister = extern (C) void function(EntityCallback callback);
export __gshared _OnEntitySpawned_Unregister __dsdk_OnEntitySpawned_Unregister = null;

/++
	Register Entity deleted listener hook

	Params:
		callback = 
+/
void OnEntityDeleted_Register(EntityCallback callback) {
	__dsdk_OnEntityDeleted_Register(callback);
}
alias _OnEntityDeleted_Register = extern (C) void function(EntityCallback callback);
export __gshared _OnEntityDeleted_Register __dsdk_OnEntityDeleted_Register = null;

/++
	Unregister Entity deleted listener hook

	Params:
		callback = 
+/
void OnEntityDeleted_Unregister(EntityCallback callback) {
	__dsdk_OnEntityDeleted_Unregister(callback);
}
alias _OnEntityDeleted_Unregister = extern (C) void function(EntityCallback callback);
export __gshared _OnEntityDeleted_Unregister __dsdk_OnEntityDeleted_Unregister = null;

/++
	Register Game state change listener hook

	Params:
		callback = 
+/
void OnGameStateChanged_Register(GameStateChangedCallback callback) {
	__dsdk_OnGameStateChanged_Register(callback);
}
alias _OnGameStateChanged_Register = extern (C) void function(GameStateChangedCallback callback);
export __gshared _OnGameStateChanged_Register __dsdk_OnGameStateChanged_Register = null;

/++
	Unregister Game state change listener hook

	Params:
		callback = 
+/
void OnGameStateChanged_Unregister(GameStateChangedCallback callback) {
	__dsdk_OnGameStateChanged_Unregister(callback);
}
alias _OnGameStateChanged_Unregister = extern (C) void function(GameStateChangedCallback callback);
export __gshared _OnGameStateChanged_Unregister __dsdk_OnGameStateChanged_Unregister = null;

/++
	Register Entity AcceptInput listener hook

	Params:
		callback = 
+/
void OnEntityAcceptInput_Register(EntityIOCallback callback) {
	__dsdk_OnEntityAcceptInput_Register(callback);
}
alias _OnEntityAcceptInput_Register = extern (C) void function(EntityIOCallback callback);
export __gshared _OnEntityAcceptInput_Register __dsdk_OnEntityAcceptInput_Register = null;

/++
	Unregister Entity AcceptInput listener hook

	Params:
		callback = 
+/
void OnEntityAcceptInput_Unregister(EntityIOCallback callback) {
	__dsdk_OnEntityAcceptInput_Unregister(callback);
}
alias _OnEntityAcceptInput_Unregister = extern (C) void function(EntityIOCallback callback);
export __gshared _OnEntityAcceptInput_Unregister __dsdk_OnEntityAcceptInput_Unregister = null;

/++
	Register NPC schedule selection listener hook

	Params:
		callback = 
+/
void OnNpcSelectSchedule_Register(NpcSelectScheduleCallback callback) {
	__dsdk_OnNpcSelectSchedule_Register(callback);
}
alias _OnNpcSelectSchedule_Register = extern (C) void function(NpcSelectScheduleCallback callback);
export __gshared _OnNpcSelectSchedule_Register __dsdk_OnNpcSelectSchedule_Register = null;

/++
	Unregister NPC schedule selection listener hook

	Params:
		callback = 
+/
void OnNpcSelectSchedule_Unregister(NpcSelectScheduleCallback callback) {
	__dsdk_OnNpcSelectSchedule_Unregister(callback);
}
alias _OnNpcSelectSchedule_Unregister = extern (C) void function(NpcSelectScheduleCallback callback);
export __gshared _OnNpcSelectSchedule_Unregister __dsdk_OnNpcSelectSchedule_Unregister = null;

/++
	Register Entity FireOutput listener hook

	Params:
		callback = 
+/
void OnEntityFireOutput_Register(EntityOutputCallback callback) {
	__dsdk_OnEntityFireOutput_Register(callback);
}
alias _OnEntityFireOutput_Register = extern (C) void function(EntityOutputCallback callback);
export __gshared _OnEntityFireOutput_Register __dsdk_OnEntityFireOutput_Register = null;

/++
	Unregister Entity FireOutput listener hook

	Params:
		callback = 
+/
void OnEntityFireOutput_Unregister(EntityOutputCallback callback) {
	__dsdk_OnEntityFireOutput_Unregister(callback);
}
alias _OnEntityFireOutput_Unregister = extern (C) void function(EntityOutputCallback callback);
export __gshared _OnEntityFireOutput_Unregister __dsdk_OnEntityFireOutput_Unregister = null;

/++
	Register CBasePlayerController::ProcessUsercmds listener hook

	Params:
		callback = 
+/
void OnProcessUsercmds_Register(ProcessUsercmdsCallback callback) {
	__dsdk_OnProcessUsercmds_Register(callback);
}
alias _OnProcessUsercmds_Register = extern (C) void function(ProcessUsercmdsCallback callback);
export __gshared _OnProcessUsercmds_Register __dsdk_OnProcessUsercmds_Register = null;

/++
	Unregister CBasePlayerController::ProcessUsercmds listener hook

	Params:
		callback = 
+/
void OnProcessUsercmds_Unregister(ProcessUsercmdsCallback callback) {
	__dsdk_OnProcessUsercmds_Unregister(callback);
}
alias _OnProcessUsercmds_Unregister = extern (C) void function(ProcessUsercmdsCallback callback);
export __gshared _OnProcessUsercmds_Unregister __dsdk_OnProcessUsercmds_Unregister = null;

/++
	Register CCitadelPlayerPawn::AbilityThink listener hook

	Params:
		callback = 
+/
void OnAbilityThink_Register(AbilityThinkCallback callback) {
	__dsdk_OnAbilityThink_Register(callback);
}
alias _OnAbilityThink_Register = extern (C) void function(AbilityThinkCallback callback);
export __gshared _OnAbilityThink_Register __dsdk_OnAbilityThink_Register = null;

/++
	Unregister CCitadelPlayerPawn::AbilityThink listener hook

	Params:
		callback = 
+/
void OnAbilityThink_Unregister(AbilityThinkCallback callback) {
	__dsdk_OnAbilityThink_Unregister(callback);
}
alias _OnAbilityThink_Unregister = extern (C) void function(AbilityThinkCallback callback);
export __gshared _OnAbilityThink_Unregister __dsdk_OnAbilityThink_Unregister = null;

/++
	Register CModifierProperty::AddModifier listener hook

	Params:
		callback = 
+/
void OnAddModifier_Register(AddModifierCallback callback) {
	__dsdk_OnAddModifier_Register(callback);
}
alias _OnAddModifier_Register = extern (C) void function(AddModifierCallback callback);
export __gshared _OnAddModifier_Register __dsdk_OnAddModifier_Register = null;

/++
	Unregister CModifierProperty::AddModifier listener hook

	Params:
		callback = 
+/
void OnAddModifier_Unregister(AddModifierCallback callback) {
	__dsdk_OnAddModifier_Unregister(callback);
}
alias _OnAddModifier_Unregister = extern (C) void function(AddModifierCallback callback);
export __gshared _OnAddModifier_Unregister __dsdk_OnAddModifier_Unregister = null;

/++
	Register CCitadelPlayerPawn::InitializeHeroOnPawn listener hook

	Params:
		callback = 
+/
void OnHeroInitialized_Register(HeroInitializedCallback callback) {
	__dsdk_OnHeroInitialized_Register(callback);
}
alias _OnHeroInitialized_Register = extern (C) void function(HeroInitializedCallback callback);
export __gshared _OnHeroInitialized_Register __dsdk_OnHeroInitialized_Register = null;

/++
	Unregister CCitadelPlayerPawn::InitializeHeroOnPawn listener hook

	Params:
		callback = 
+/
void OnHeroInitialized_Unregister(HeroInitializedCallback callback) {
	__dsdk_OnHeroInitialized_Unregister(callback);
}
alias _OnHeroInitialized_Unregister = extern (C) void function(HeroInitializedCallback callback);
export __gshared _OnHeroInitialized_Unregister __dsdk_OnHeroInitialized_Unregister = null;

/++
	Register game event listener hook (e.g. player_death, player_respawned)

	Params:
		callback = 
+/
void OnGameEvent_Register(GameEventCallback callback) {
	__dsdk_OnGameEvent_Register(callback);
}
alias _OnGameEvent_Register = extern (C) void function(GameEventCallback callback);
export __gshared _OnGameEvent_Register __dsdk_OnGameEvent_Register = null;

/++
	Unregister game event listener hook

	Params:
		callback = 
+/
void OnGameEvent_Unregister(GameEventCallback callback) {
	__dsdk_OnGameEvent_Unregister(callback);
}
alias _OnGameEvent_Unregister = extern (C) void function(GameEventCallback callback);
export __gshared _OnGameEvent_Unregister __dsdk_OnGameEvent_Unregister = null;

