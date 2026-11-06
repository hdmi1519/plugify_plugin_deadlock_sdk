#include "pch.hpp"
#include "core/listeners/listeners.hpp"

extern "C" {

PLUGIN_API void OnModifyCurrency_Register(dsdk::ModifyCurrencyCallback callback) {
    dsdk::g_ModifyCurrencyListeners.Register(callback);
}
PLUGIN_API void OnModifyCurrency_Unregister(dsdk::ModifyCurrencyCallback callback) {
    dsdk::g_ModifyCurrencyListeners.Unregister(callback);
}

PLUGIN_API void OnTakeDamage_Register(dsdk::TakeDamageCallback callback) {
    dsdk::g_TakeDamageListeners.Register(callback);
}
PLUGIN_API void OnTakeDamage_Unregister(dsdk::TakeDamageCallback callback) {
    dsdk::g_TakeDamageListeners.Unregister(callback);
}

PLUGIN_API void OnClientConnect_Register(dsdk::ClientConnectCallback callback) {
    dsdk::g_ClientConnectListeners.Register(callback);
}
PLUGIN_API void OnClientConnect_Unregister(dsdk::ClientConnectCallback callback) {
    dsdk::g_ClientConnectListeners.Unregister(callback);
}

PLUGIN_API void OnClientPutInServer_Register(dsdk::ClientPutInServerCallback callback) {
    dsdk::g_ClientPutInServerListeners.Register(callback);
}
PLUGIN_API void OnClientPutInServer_Unregister(dsdk::ClientPutInServerCallback callback) {
    dsdk::g_ClientPutInServerListeners.Unregister(callback);
}

PLUGIN_API void OnClientDisconnect_Register(dsdk::ClientDisconnectCallback callback) {
    dsdk::g_ClientDisconnectListeners.Register(callback);
}
PLUGIN_API void OnClientDisconnect_Unregister(dsdk::ClientDisconnectCallback callback) {
    dsdk::g_ClientDisconnectListeners.Unregister(callback);
}

PLUGIN_API void OnGameFrame_Register(dsdk::GameFrameCallback callback) {
    dsdk::g_GameFrameListeners.Register(callback);
}
PLUGIN_API void OnGameFrame_Unregister(dsdk::GameFrameCallback callback) {
    dsdk::g_GameFrameListeners.Unregister(callback);
}

PLUGIN_API void OnEntityCreated_Register(dsdk::EntityCallback callback) {
    dsdk::g_EntityCreatedListeners.Register(callback);
}
PLUGIN_API void OnEntityCreated_Unregister(dsdk::EntityCallback callback) {
    dsdk::g_EntityCreatedListeners.Unregister(callback);
}

PLUGIN_API void OnEntitySpawned_Register(dsdk::EntityCallback callback) {
    dsdk::g_EntitySpawnedListeners.Register(callback);
}
PLUGIN_API void OnEntitySpawned_Unregister(dsdk::EntityCallback callback) {
    dsdk::g_EntitySpawnedListeners.Unregister(callback);
}

PLUGIN_API void OnEntityDeleted_Register(dsdk::EntityCallback callback) {
    dsdk::g_EntityDeletedListeners.Register(callback);
}
PLUGIN_API void OnEntityDeleted_Unregister(dsdk::EntityCallback callback) {
    dsdk::g_EntityDeletedListeners.Unregister(callback);
}

PLUGIN_API void OnGameStateChanged_Register(dsdk::GameStateChangedCallback callback) {
    dsdk::g_GameStateChangedListeners.Register(callback);
}
PLUGIN_API void OnGameStateChanged_Unregister(dsdk::GameStateChangedCallback callback) {
    dsdk::g_GameStateChangedListeners.Unregister(callback);
}

PLUGIN_API void OnEntityAcceptInput_Register(dsdk::EntityIOCallback callback) {
    dsdk::g_EntityAcceptInputListeners.Register(callback);
}
PLUGIN_API void OnEntityAcceptInput_Unregister(dsdk::EntityIOCallback callback) {
    dsdk::g_EntityAcceptInputListeners.Unregister(callback);
}

PLUGIN_API void OnEntityFireOutput_Register(dsdk::EntityOutputCallback callback) {
    dsdk::g_EntityOutputListeners.Register(callback);
}
PLUGIN_API void OnEntityFireOutput_Unregister(dsdk::EntityOutputCallback callback) {
    dsdk::g_EntityOutputListeners.Unregister(callback);
}

PLUGIN_API void OnNpcSelectSchedule_Register(dsdk::NpcSelectScheduleCallback callback) {
    dsdk::g_NpcSelectScheduleListeners.Register(callback);
}
PLUGIN_API void OnNpcSelectSchedule_Unregister(dsdk::NpcSelectScheduleCallback callback) {
    dsdk::g_NpcSelectScheduleListeners.Unregister(callback);
}

PLUGIN_API void OnProcessUsercmds_Register(dsdk::ProcessUsercmdsCallback callback) {
    dsdk::g_ProcessUsercmdsListeners.Register(callback);
}
PLUGIN_API void OnProcessUsercmds_Unregister(dsdk::ProcessUsercmdsCallback callback) {
    dsdk::g_ProcessUsercmdsListeners.Unregister(callback);
}

PLUGIN_API void OnAbilityThink_Register(dsdk::AbilityThinkCallback callback) {
    dsdk::g_AbilityThinkListeners.Register(callback);
}
PLUGIN_API void OnAbilityThink_Unregister(dsdk::AbilityThinkCallback callback) {
    dsdk::g_AbilityThinkListeners.Unregister(callback);
}

PLUGIN_API void OnAddModifier_Register(dsdk::AddModifierCallback callback) {
    dsdk::g_AddModifierListeners.Register(callback);
}
PLUGIN_API void OnAddModifier_Unregister(dsdk::AddModifierCallback callback) {
    dsdk::g_AddModifierListeners.Unregister(callback);
}

PLUGIN_API void OnHeroInitialized_Register(dsdk::HeroInitializedCallback callback) {
    dsdk::g_HeroInitializedListeners.Register(callback);
}
PLUGIN_API void OnHeroInitialized_Unregister(dsdk::HeroInitializedCallback callback) {
    dsdk::g_HeroInitializedListeners.Unregister(callback);
}

}
