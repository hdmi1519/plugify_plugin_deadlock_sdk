#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: listeners)

namespace dsdk {

  using _OnModifyCurrency_Register = void (*)(ModifyCurrencyCallback);
}
extern "C" PLUGIN_API dsdk::_OnModifyCurrency_Register __dsdk_OnModifyCurrency_Register;
namespace dsdk {
  /**
   * @brief Register Currency modification listener hook
   * @param callback (function)
   */
  inline void OnModifyCurrency_Register(ModifyCurrencyCallback callback) {
    return __dsdk_OnModifyCurrency_Register(callback);
  }

  using _OnModifyCurrency_Unregister = void (*)(ModifyCurrencyCallback);
}
extern "C" PLUGIN_API dsdk::_OnModifyCurrency_Unregister __dsdk_OnModifyCurrency_Unregister;
namespace dsdk {
  /**
   * @brief Unregister Currency modification listener hook
   * @param callback (function)
   */
  inline void OnModifyCurrency_Unregister(ModifyCurrencyCallback callback) {
    return __dsdk_OnModifyCurrency_Unregister(callback);
  }

  using _OnTakeDamage_Register = void (*)(TakeDamageCallback);
}
extern "C" PLUGIN_API dsdk::_OnTakeDamage_Register __dsdk_OnTakeDamage_Register;
namespace dsdk {
  /**
   * @brief Register Entity take damage listener hook
   * @param callback (function)
   */
  inline void OnTakeDamage_Register(TakeDamageCallback callback) {
    return __dsdk_OnTakeDamage_Register(callback);
  }

  using _OnTakeDamage_Unregister = void (*)(TakeDamageCallback);
}
extern "C" PLUGIN_API dsdk::_OnTakeDamage_Unregister __dsdk_OnTakeDamage_Unregister;
namespace dsdk {
  /**
   * @brief Unregister Entity take damage listener hook
   * @param callback (function)
   */
  inline void OnTakeDamage_Unregister(TakeDamageCallback callback) {
    return __dsdk_OnTakeDamage_Unregister(callback);
  }

  using _OnClientConnect_Register = void (*)(ClientConnectCallback);
}
extern "C" PLUGIN_API dsdk::_OnClientConnect_Register __dsdk_OnClientConnect_Register;
namespace dsdk {
  /**
   * @brief Register Client connection listener hook
   * @param callback (function)
   */
  inline void OnClientConnect_Register(ClientConnectCallback callback) {
    return __dsdk_OnClientConnect_Register(callback);
  }

  using _OnClientConnect_Unregister = void (*)(ClientConnectCallback);
}
extern "C" PLUGIN_API dsdk::_OnClientConnect_Unregister __dsdk_OnClientConnect_Unregister;
namespace dsdk {
  /**
   * @brief Unregister Client connection listener hook
   * @param callback (function)
   */
  inline void OnClientConnect_Unregister(ClientConnectCallback callback) {
    return __dsdk_OnClientConnect_Unregister(callback);
  }

  using _OnClientPutInServer_Register = void (*)(ClientPutInServerCallback);
}
extern "C" PLUGIN_API dsdk::_OnClientPutInServer_Register __dsdk_OnClientPutInServer_Register;
namespace dsdk {
  /**
   * @brief Register Client put in server listener hook
   * @param callback (function)
   */
  inline void OnClientPutInServer_Register(ClientPutInServerCallback callback) {
    return __dsdk_OnClientPutInServer_Register(callback);
  }

  using _OnClientPutInServer_Unregister = void (*)(ClientPutInServerCallback);
}
extern "C" PLUGIN_API dsdk::_OnClientPutInServer_Unregister __dsdk_OnClientPutInServer_Unregister;
namespace dsdk {
  /**
   * @brief Unregister Client put in server listener hook
   * @param callback (function)
   */
  inline void OnClientPutInServer_Unregister(ClientPutInServerCallback callback) {
    return __dsdk_OnClientPutInServer_Unregister(callback);
  }

  using _OnClientDisconnect_Register = void (*)(ClientDisconnectCallback);
}
extern "C" PLUGIN_API dsdk::_OnClientDisconnect_Register __dsdk_OnClientDisconnect_Register;
namespace dsdk {
  /**
   * @brief Register Client disconnect listener hook
   * @param callback (function)
   */
  inline void OnClientDisconnect_Register(ClientDisconnectCallback callback) {
    return __dsdk_OnClientDisconnect_Register(callback);
  }

  using _OnClientDisconnect_Unregister = void (*)(ClientDisconnectCallback);
}
extern "C" PLUGIN_API dsdk::_OnClientDisconnect_Unregister __dsdk_OnClientDisconnect_Unregister;
namespace dsdk {
  /**
   * @brief Unregister Client disconnect listener hook
   * @param callback (function)
   */
  inline void OnClientDisconnect_Unregister(ClientDisconnectCallback callback) {
    return __dsdk_OnClientDisconnect_Unregister(callback);
  }

  using _OnGameFrame_Register = void (*)(GameFrameCallback);
}
extern "C" PLUGIN_API dsdk::_OnGameFrame_Register __dsdk_OnGameFrame_Register;
namespace dsdk {
  /**
   * @brief Register Server game tick frame listener hook
   * @param callback (function)
   */
  inline void OnGameFrame_Register(GameFrameCallback callback) {
    return __dsdk_OnGameFrame_Register(callback);
  }

  using _OnGameFrame_Unregister = void (*)(GameFrameCallback);
}
extern "C" PLUGIN_API dsdk::_OnGameFrame_Unregister __dsdk_OnGameFrame_Unregister;
namespace dsdk {
  /**
   * @brief Unregister Server game tick frame listener hook
   * @param callback (function)
   */
  inline void OnGameFrame_Unregister(GameFrameCallback callback) {
    return __dsdk_OnGameFrame_Unregister(callback);
  }

  using _OnEntityCreated_Register = void (*)(EntityCallback);
}
extern "C" PLUGIN_API dsdk::_OnEntityCreated_Register __dsdk_OnEntityCreated_Register;
namespace dsdk {
  /**
   * @brief Register Entity created listener hook
   * @param callback (function)
   */
  inline void OnEntityCreated_Register(EntityCallback callback) {
    return __dsdk_OnEntityCreated_Register(callback);
  }

  using _OnEntityCreated_Unregister = void (*)(EntityCallback);
}
extern "C" PLUGIN_API dsdk::_OnEntityCreated_Unregister __dsdk_OnEntityCreated_Unregister;
namespace dsdk {
  /**
   * @brief Unregister Entity created listener hook
   * @param callback (function)
   */
  inline void OnEntityCreated_Unregister(EntityCallback callback) {
    return __dsdk_OnEntityCreated_Unregister(callback);
  }

  using _OnEntitySpawned_Register = void (*)(EntityCallback);
}
extern "C" PLUGIN_API dsdk::_OnEntitySpawned_Register __dsdk_OnEntitySpawned_Register;
namespace dsdk {
  /**
   * @brief Register Entity spawned listener hook
   * @param callback (function)
   */
  inline void OnEntitySpawned_Register(EntityCallback callback) {
    return __dsdk_OnEntitySpawned_Register(callback);
  }

  using _OnEntitySpawned_Unregister = void (*)(EntityCallback);
}
extern "C" PLUGIN_API dsdk::_OnEntitySpawned_Unregister __dsdk_OnEntitySpawned_Unregister;
namespace dsdk {
  /**
   * @brief Unregister Entity spawned listener hook
   * @param callback (function)
   */
  inline void OnEntitySpawned_Unregister(EntityCallback callback) {
    return __dsdk_OnEntitySpawned_Unregister(callback);
  }

  using _OnEntityDeleted_Register = void (*)(EntityCallback);
}
extern "C" PLUGIN_API dsdk::_OnEntityDeleted_Register __dsdk_OnEntityDeleted_Register;
namespace dsdk {
  /**
   * @brief Register Entity deleted listener hook
   * @param callback (function)
   */
  inline void OnEntityDeleted_Register(EntityCallback callback) {
    return __dsdk_OnEntityDeleted_Register(callback);
  }

  using _OnEntityDeleted_Unregister = void (*)(EntityCallback);
}
extern "C" PLUGIN_API dsdk::_OnEntityDeleted_Unregister __dsdk_OnEntityDeleted_Unregister;
namespace dsdk {
  /**
   * @brief Unregister Entity deleted listener hook
   * @param callback (function)
   */
  inline void OnEntityDeleted_Unregister(EntityCallback callback) {
    return __dsdk_OnEntityDeleted_Unregister(callback);
  }

  using _OnGameStateChanged_Register = void (*)(GameStateChangedCallback);
}
extern "C" PLUGIN_API dsdk::_OnGameStateChanged_Register __dsdk_OnGameStateChanged_Register;
namespace dsdk {
  /**
   * @brief Register Game state change listener hook
   * @param callback (function)
   */
  inline void OnGameStateChanged_Register(GameStateChangedCallback callback) {
    return __dsdk_OnGameStateChanged_Register(callback);
  }

  using _OnGameStateChanged_Unregister = void (*)(GameStateChangedCallback);
}
extern "C" PLUGIN_API dsdk::_OnGameStateChanged_Unregister __dsdk_OnGameStateChanged_Unregister;
namespace dsdk {
  /**
   * @brief Unregister Game state change listener hook
   * @param callback (function)
   */
  inline void OnGameStateChanged_Unregister(GameStateChangedCallback callback) {
    return __dsdk_OnGameStateChanged_Unregister(callback);
  }

  using _OnEntityAcceptInput_Register = void (*)(EntityIOCallback);
}
extern "C" PLUGIN_API dsdk::_OnEntityAcceptInput_Register __dsdk_OnEntityAcceptInput_Register;
namespace dsdk {
  /**
   * @brief Register Entity AcceptInput listener hook
   * @param callback (function)
   */
  inline void OnEntityAcceptInput_Register(EntityIOCallback callback) {
    return __dsdk_OnEntityAcceptInput_Register(callback);
  }

  using _OnEntityAcceptInput_Unregister = void (*)(EntityIOCallback);
}
extern "C" PLUGIN_API dsdk::_OnEntityAcceptInput_Unregister __dsdk_OnEntityAcceptInput_Unregister;
namespace dsdk {
  /**
   * @brief Unregister Entity AcceptInput listener hook
   * @param callback (function)
   */
  inline void OnEntityAcceptInput_Unregister(EntityIOCallback callback) {
    return __dsdk_OnEntityAcceptInput_Unregister(callback);
  }

  using _OnNpcSelectSchedule_Register = void (*)(NpcSelectScheduleCallback);
}
extern "C" PLUGIN_API dsdk::_OnNpcSelectSchedule_Register __dsdk_OnNpcSelectSchedule_Register;
namespace dsdk {
  /**
   * @brief Register NPC schedule selection listener hook
   * @param callback (function)
   */
  inline void OnNpcSelectSchedule_Register(NpcSelectScheduleCallback callback) {
    return __dsdk_OnNpcSelectSchedule_Register(callback);
  }

  using _OnNpcSelectSchedule_Unregister = void (*)(NpcSelectScheduleCallback);
}
extern "C" PLUGIN_API dsdk::_OnNpcSelectSchedule_Unregister __dsdk_OnNpcSelectSchedule_Unregister;
namespace dsdk {
  /**
   * @brief Unregister NPC schedule selection listener hook
   * @param callback (function)
   */
  inline void OnNpcSelectSchedule_Unregister(NpcSelectScheduleCallback callback) {
    return __dsdk_OnNpcSelectSchedule_Unregister(callback);
  }

  using _OnEntityFireOutput_Register = void (*)(EntityOutputCallback);
}
extern "C" PLUGIN_API dsdk::_OnEntityFireOutput_Register __dsdk_OnEntityFireOutput_Register;
namespace dsdk {
  /**
   * @brief Register Entity FireOutput listener hook
   * @param callback (function)
   */
  inline void OnEntityFireOutput_Register(EntityOutputCallback callback) {
    return __dsdk_OnEntityFireOutput_Register(callback);
  }

  using _OnEntityFireOutput_Unregister = void (*)(EntityOutputCallback);
}
extern "C" PLUGIN_API dsdk::_OnEntityFireOutput_Unregister __dsdk_OnEntityFireOutput_Unregister;
namespace dsdk {
  /**
   * @brief Unregister Entity FireOutput listener hook
   * @param callback (function)
   */
  inline void OnEntityFireOutput_Unregister(EntityOutputCallback callback) {
    return __dsdk_OnEntityFireOutput_Unregister(callback);
  }

  using _OnProcessUsercmds_Register = void (*)(ProcessUsercmdsCallback);
}
extern "C" PLUGIN_API dsdk::_OnProcessUsercmds_Register __dsdk_OnProcessUsercmds_Register;
namespace dsdk {
  /**
   * @brief Register CBasePlayerController::ProcessUsercmds listener hook
   * @param callback (function)
   */
  inline void OnProcessUsercmds_Register(ProcessUsercmdsCallback callback) {
    return __dsdk_OnProcessUsercmds_Register(callback);
  }

  using _OnProcessUsercmds_Unregister = void (*)(ProcessUsercmdsCallback);
}
extern "C" PLUGIN_API dsdk::_OnProcessUsercmds_Unregister __dsdk_OnProcessUsercmds_Unregister;
namespace dsdk {
  /**
   * @brief Unregister CBasePlayerController::ProcessUsercmds listener hook
   * @param callback (function)
   */
  inline void OnProcessUsercmds_Unregister(ProcessUsercmdsCallback callback) {
    return __dsdk_OnProcessUsercmds_Unregister(callback);
  }

  using _OnAbilityThink_Register = void (*)(AbilityThinkCallback);
}
extern "C" PLUGIN_API dsdk::_OnAbilityThink_Register __dsdk_OnAbilityThink_Register;
namespace dsdk {
  /**
   * @brief Register CCitadelPlayerPawn::AbilityThink listener hook
   * @param callback (function)
   */
  inline void OnAbilityThink_Register(AbilityThinkCallback callback) {
    return __dsdk_OnAbilityThink_Register(callback);
  }

  using _OnAbilityThink_Unregister = void (*)(AbilityThinkCallback);
}
extern "C" PLUGIN_API dsdk::_OnAbilityThink_Unregister __dsdk_OnAbilityThink_Unregister;
namespace dsdk {
  /**
   * @brief Unregister CCitadelPlayerPawn::AbilityThink listener hook
   * @param callback (function)
   */
  inline void OnAbilityThink_Unregister(AbilityThinkCallback callback) {
    return __dsdk_OnAbilityThink_Unregister(callback);
  }

  using _OnAddModifier_Register = void (*)(AddModifierCallback);
}
extern "C" PLUGIN_API dsdk::_OnAddModifier_Register __dsdk_OnAddModifier_Register;
namespace dsdk {
  /**
   * @brief Register CModifierProperty::AddModifier listener hook
   * @param callback (function)
   */
  inline void OnAddModifier_Register(AddModifierCallback callback) {
    return __dsdk_OnAddModifier_Register(callback);
  }

  using _OnAddModifier_Unregister = void (*)(AddModifierCallback);
}
extern "C" PLUGIN_API dsdk::_OnAddModifier_Unregister __dsdk_OnAddModifier_Unregister;
namespace dsdk {
  /**
   * @brief Unregister CModifierProperty::AddModifier listener hook
   * @param callback (function)
   */
  inline void OnAddModifier_Unregister(AddModifierCallback callback) {
    return __dsdk_OnAddModifier_Unregister(callback);
  }

  using _OnHeroInitialized_Register = void (*)(HeroInitializedCallback);
}
extern "C" PLUGIN_API dsdk::_OnHeroInitialized_Register __dsdk_OnHeroInitialized_Register;
namespace dsdk {
  /**
   * @brief Register CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
   * @param callback (function)
   */
  inline void OnHeroInitialized_Register(HeroInitializedCallback callback) {
    return __dsdk_OnHeroInitialized_Register(callback);
  }

  using _OnHeroInitialized_Unregister = void (*)(HeroInitializedCallback);
}
extern "C" PLUGIN_API dsdk::_OnHeroInitialized_Unregister __dsdk_OnHeroInitialized_Unregister;
namespace dsdk {
  /**
   * @brief Unregister CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
   * @param callback (function)
   */
  inline void OnHeroInitialized_Unregister(HeroInitializedCallback callback) {
    return __dsdk_OnHeroInitialized_Unregister(callback);
  }

  using _OnGameEvent_Register = void (*)(GameEventCallback);
}
extern "C" PLUGIN_API dsdk::_OnGameEvent_Register __dsdk_OnGameEvent_Register;
namespace dsdk {
  /**
   * @brief Register game event listener hook (e.g. player_death, player_respawned)
   * @param callback (function)
   */
  inline void OnGameEvent_Register(GameEventCallback callback) {
    return __dsdk_OnGameEvent_Register(callback);
  }

  using _OnGameEvent_Unregister = void (*)(GameEventCallback);
}
extern "C" PLUGIN_API dsdk::_OnGameEvent_Unregister __dsdk_OnGameEvent_Unregister;
namespace dsdk {
  /**
   * @brief Unregister game event listener hook
   * @param callback (function)
   */
  inline void OnGameEvent_Unregister(GameEventCallback callback) {
    return __dsdk_OnGameEvent_Unregister(callback);
  }

} // namespace dsdk
