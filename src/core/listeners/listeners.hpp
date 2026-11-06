#pragma once

#include "listener_manager.hpp"
#include <plg/string.hpp>
#include <cstdint>

namespace dsdk {

// Hook return results
enum class HookResult : int32_t {
    Continue = 0,
    Changed = 1,
    Handled = 2,
    Stop = 3
};

// Callback signatures
using ModifyCurrencyCallback = int32_t (*)(int64_t pawn, uint32_t currencyType, int32_t amount, uint32_t source, bool silent, bool forceGain, bool spendOnly, int64_t sourceAbility, int64_t sourceEntity);
using TakeDamageCallback = int32_t (*)(int64_t victim, int64_t damageInfo);
using ClientConnectCallback = bool (*)(int32_t playerSlot, const plg::string &name, uint64_t steamId);
using ClientPutInServerCallback = void (*)(int32_t playerSlot);
using ClientDisconnectCallback = void (*)(int32_t playerSlot, int32_t reason);
using GameFrameCallback = void (*)(bool simulating, bool firstTick, bool lastTick);
using EntityCallback = void (*)(int64_t entity);
using GameStateChangedCallback = void (*)(int32_t newState);
using EntityIOCallback = int32_t (*)(const plg::string &className, const plg::string &inputName, int64_t entity, int64_t activator, int64_t caller, const plg::string &value);
using EntityOutputCallback = int32_t (*)(const plg::string &callerClass, const plg::string &outputName, int64_t activator, int64_t caller, float delay);
using NpcSelectScheduleCallback = plg::string (*)(int64_t npc, const plg::string &chosenId);
using ProcessUsercmdsCallback = void (*)(int32_t playerSlot, int32_t numCmds, bool paused);
using AbilityThinkCallback = void (*)(int32_t playerSlot, int64_t pawn);
using AddModifierCallback = int32_t (*)(int64_t modifierProp, int64_t caster, uint32_t ability, int32_t team);
using HeroInitializedCallback = void (*)(int64_t pawn);
using GameEventCallback = void (*)(const plg::string &eventName, int64_t event);

// Listener manager instances
inline ListenerManager<ModifyCurrencyCallback> g_ModifyCurrencyListeners;
inline ListenerManager<TakeDamageCallback> g_TakeDamageListeners;
inline ListenerManager<ClientConnectCallback> g_ClientConnectListeners;
inline ListenerManager<ClientPutInServerCallback> g_ClientPutInServerListeners;
inline ListenerManager<ClientDisconnectCallback> g_ClientDisconnectListeners;
inline ListenerManager<GameFrameCallback> g_GameFrameListeners;
inline ListenerManager<EntityCallback> g_EntityCreatedListeners;
inline ListenerManager<EntityCallback> g_EntitySpawnedListeners;
inline ListenerManager<EntityCallback> g_EntityDeletedListeners;
inline ListenerManager<GameStateChangedCallback> g_GameStateChangedListeners;
inline ListenerManager<EntityIOCallback> g_EntityAcceptInputListeners;
inline ListenerManager<EntityOutputCallback> g_EntityOutputListeners;
inline ListenerManager<NpcSelectScheduleCallback> g_NpcSelectScheduleListeners;
inline ListenerManager<ProcessUsercmdsCallback> g_ProcessUsercmdsListeners;
inline ListenerManager<AbilityThinkCallback> g_AbilityThinkListeners;
inline ListenerManager<AddModifierCallback> g_AddModifierListeners;
inline ListenerManager<HeroInitializedCallback> g_HeroInitializedListeners;
inline ListenerManager<GameEventCallback> g_GameEventListeners;

} // namespace dsdk
