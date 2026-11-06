// Generated from dsdk.pplugin (group: listeners)

export module dsdk.listeners;
export import dsdk.enums;
export import dsdk.aliases;
export import dsdk.delegates;

import <cstdint>;
import <plg>;

#if defined(_WIN32)
#define PLUGIFY_EXPORT __declspec(dllexport)
#else
#define PLUGIFY_EXPORT __attribute__((visibility("default")))
#endif

export namespace dsdk {

  using _OnModifyCurrency_Register = void (*)(ModifyCurrencyCallback);
  PLUGIFY_EXPORT _OnModifyCurrency_Register __dsdk_OnModifyCurrency_Register = nullptr;
  /**
   * @brief Register Currency modification listener hook
   * @param callback (function)
   */

  void OnModifyCurrency_Register(ModifyCurrencyCallback callback) {
    return __dsdk_OnModifyCurrency_Register(callback);
  }

  using _OnModifyCurrency_Unregister = void (*)(ModifyCurrencyCallback);
  PLUGIFY_EXPORT _OnModifyCurrency_Unregister __dsdk_OnModifyCurrency_Unregister = nullptr;
  /**
   * @brief Unregister Currency modification listener hook
   * @param callback (function)
   */

  void OnModifyCurrency_Unregister(ModifyCurrencyCallback callback) {
    return __dsdk_OnModifyCurrency_Unregister(callback);
  }

  using _OnTakeDamage_Register = void (*)(TakeDamageCallback);
  PLUGIFY_EXPORT _OnTakeDamage_Register __dsdk_OnTakeDamage_Register = nullptr;
  /**
   * @brief Register Entity take damage listener hook
   * @param callback (function)
   */

  void OnTakeDamage_Register(TakeDamageCallback callback) {
    return __dsdk_OnTakeDamage_Register(callback);
  }

  using _OnTakeDamage_Unregister = void (*)(TakeDamageCallback);
  PLUGIFY_EXPORT _OnTakeDamage_Unregister __dsdk_OnTakeDamage_Unregister = nullptr;
  /**
   * @brief Unregister Entity take damage listener hook
   * @param callback (function)
   */

  void OnTakeDamage_Unregister(TakeDamageCallback callback) {
    return __dsdk_OnTakeDamage_Unregister(callback);
  }

  using _OnClientConnect_Register = void (*)(ClientConnectCallback);
  PLUGIFY_EXPORT _OnClientConnect_Register __dsdk_OnClientConnect_Register = nullptr;
  /**
   * @brief Register Client connection listener hook
   * @param callback (function)
   */

  void OnClientConnect_Register(ClientConnectCallback callback) {
    return __dsdk_OnClientConnect_Register(callback);
  }

  using _OnClientConnect_Unregister = void (*)(ClientConnectCallback);
  PLUGIFY_EXPORT _OnClientConnect_Unregister __dsdk_OnClientConnect_Unregister = nullptr;
  /**
   * @brief Unregister Client connection listener hook
   * @param callback (function)
   */

  void OnClientConnect_Unregister(ClientConnectCallback callback) {
    return __dsdk_OnClientConnect_Unregister(callback);
  }

  using _OnClientPutInServer_Register = void (*)(ClientPutInServerCallback);
  PLUGIFY_EXPORT _OnClientPutInServer_Register __dsdk_OnClientPutInServer_Register = nullptr;
  /**
   * @brief Register Client put in server listener hook
   * @param callback (function)
   */

  void OnClientPutInServer_Register(ClientPutInServerCallback callback) {
    return __dsdk_OnClientPutInServer_Register(callback);
  }

  using _OnClientPutInServer_Unregister = void (*)(ClientPutInServerCallback);
  PLUGIFY_EXPORT _OnClientPutInServer_Unregister __dsdk_OnClientPutInServer_Unregister = nullptr;
  /**
   * @brief Unregister Client put in server listener hook
   * @param callback (function)
   */

  void OnClientPutInServer_Unregister(ClientPutInServerCallback callback) {
    return __dsdk_OnClientPutInServer_Unregister(callback);
  }

  using _OnClientDisconnect_Register = void (*)(ClientDisconnectCallback);
  PLUGIFY_EXPORT _OnClientDisconnect_Register __dsdk_OnClientDisconnect_Register = nullptr;
  /**
   * @brief Register Client disconnect listener hook
   * @param callback (function)
   */

  void OnClientDisconnect_Register(ClientDisconnectCallback callback) {
    return __dsdk_OnClientDisconnect_Register(callback);
  }

  using _OnClientDisconnect_Unregister = void (*)(ClientDisconnectCallback);
  PLUGIFY_EXPORT _OnClientDisconnect_Unregister __dsdk_OnClientDisconnect_Unregister = nullptr;
  /**
   * @brief Unregister Client disconnect listener hook
   * @param callback (function)
   */

  void OnClientDisconnect_Unregister(ClientDisconnectCallback callback) {
    return __dsdk_OnClientDisconnect_Unregister(callback);
  }

  using _OnGameFrame_Register = void (*)(GameFrameCallback);
  PLUGIFY_EXPORT _OnGameFrame_Register __dsdk_OnGameFrame_Register = nullptr;
  /**
   * @brief Register Server game tick frame listener hook
   * @param callback (function)
   */

  void OnGameFrame_Register(GameFrameCallback callback) {
    return __dsdk_OnGameFrame_Register(callback);
  }

  using _OnGameFrame_Unregister = void (*)(GameFrameCallback);
  PLUGIFY_EXPORT _OnGameFrame_Unregister __dsdk_OnGameFrame_Unregister = nullptr;
  /**
   * @brief Unregister Server game tick frame listener hook
   * @param callback (function)
   */

  void OnGameFrame_Unregister(GameFrameCallback callback) {
    return __dsdk_OnGameFrame_Unregister(callback);
  }

  using _OnEntityCreated_Register = void (*)(EntityCallback);
  PLUGIFY_EXPORT _OnEntityCreated_Register __dsdk_OnEntityCreated_Register = nullptr;
  /**
   * @brief Register Entity created listener hook
   * @param callback (function)
   */

  void OnEntityCreated_Register(EntityCallback callback) {
    return __dsdk_OnEntityCreated_Register(callback);
  }

  using _OnEntityCreated_Unregister = void (*)(EntityCallback);
  PLUGIFY_EXPORT _OnEntityCreated_Unregister __dsdk_OnEntityCreated_Unregister = nullptr;
  /**
   * @brief Unregister Entity created listener hook
   * @param callback (function)
   */

  void OnEntityCreated_Unregister(EntityCallback callback) {
    return __dsdk_OnEntityCreated_Unregister(callback);
  }

  using _OnEntitySpawned_Register = void (*)(EntityCallback);
  PLUGIFY_EXPORT _OnEntitySpawned_Register __dsdk_OnEntitySpawned_Register = nullptr;
  /**
   * @brief Register Entity spawned listener hook
   * @param callback (function)
   */

  void OnEntitySpawned_Register(EntityCallback callback) {
    return __dsdk_OnEntitySpawned_Register(callback);
  }

  using _OnEntitySpawned_Unregister = void (*)(EntityCallback);
  PLUGIFY_EXPORT _OnEntitySpawned_Unregister __dsdk_OnEntitySpawned_Unregister = nullptr;
  /**
   * @brief Unregister Entity spawned listener hook
   * @param callback (function)
   */

  void OnEntitySpawned_Unregister(EntityCallback callback) {
    return __dsdk_OnEntitySpawned_Unregister(callback);
  }

  using _OnEntityDeleted_Register = void (*)(EntityCallback);
  PLUGIFY_EXPORT _OnEntityDeleted_Register __dsdk_OnEntityDeleted_Register = nullptr;
  /**
   * @brief Register Entity deleted listener hook
   * @param callback (function)
   */

  void OnEntityDeleted_Register(EntityCallback callback) {
    return __dsdk_OnEntityDeleted_Register(callback);
  }

  using _OnEntityDeleted_Unregister = void (*)(EntityCallback);
  PLUGIFY_EXPORT _OnEntityDeleted_Unregister __dsdk_OnEntityDeleted_Unregister = nullptr;
  /**
   * @brief Unregister Entity deleted listener hook
   * @param callback (function)
   */

  void OnEntityDeleted_Unregister(EntityCallback callback) {
    return __dsdk_OnEntityDeleted_Unregister(callback);
  }

  using _OnGameStateChanged_Register = void (*)(GameStateChangedCallback);
  PLUGIFY_EXPORT _OnGameStateChanged_Register __dsdk_OnGameStateChanged_Register = nullptr;
  /**
   * @brief Register Game state change listener hook
   * @param callback (function)
   */

  void OnGameStateChanged_Register(GameStateChangedCallback callback) {
    return __dsdk_OnGameStateChanged_Register(callback);
  }

  using _OnGameStateChanged_Unregister = void (*)(GameStateChangedCallback);
  PLUGIFY_EXPORT _OnGameStateChanged_Unregister __dsdk_OnGameStateChanged_Unregister = nullptr;
  /**
   * @brief Unregister Game state change listener hook
   * @param callback (function)
   */

  void OnGameStateChanged_Unregister(GameStateChangedCallback callback) {
    return __dsdk_OnGameStateChanged_Unregister(callback);
  }

  using _OnEntityAcceptInput_Register = void (*)(EntityIOCallback);
  PLUGIFY_EXPORT _OnEntityAcceptInput_Register __dsdk_OnEntityAcceptInput_Register = nullptr;
  /**
   * @brief Register Entity AcceptInput listener hook
   * @param callback (function)
   */

  void OnEntityAcceptInput_Register(EntityIOCallback callback) {
    return __dsdk_OnEntityAcceptInput_Register(callback);
  }

  using _OnEntityAcceptInput_Unregister = void (*)(EntityIOCallback);
  PLUGIFY_EXPORT _OnEntityAcceptInput_Unregister __dsdk_OnEntityAcceptInput_Unregister = nullptr;
  /**
   * @brief Unregister Entity AcceptInput listener hook
   * @param callback (function)
   */

  void OnEntityAcceptInput_Unregister(EntityIOCallback callback) {
    return __dsdk_OnEntityAcceptInput_Unregister(callback);
  }

  using _OnNpcSelectSchedule_Register = void (*)(NpcSelectScheduleCallback);
  PLUGIFY_EXPORT _OnNpcSelectSchedule_Register __dsdk_OnNpcSelectSchedule_Register = nullptr;
  /**
   * @brief Register NPC schedule selection listener hook
   * @param callback (function)
   */

  void OnNpcSelectSchedule_Register(NpcSelectScheduleCallback callback) {
    return __dsdk_OnNpcSelectSchedule_Register(callback);
  }

  using _OnNpcSelectSchedule_Unregister = void (*)(NpcSelectScheduleCallback);
  PLUGIFY_EXPORT _OnNpcSelectSchedule_Unregister __dsdk_OnNpcSelectSchedule_Unregister = nullptr;
  /**
   * @brief Unregister NPC schedule selection listener hook
   * @param callback (function)
   */

  void OnNpcSelectSchedule_Unregister(NpcSelectScheduleCallback callback) {
    return __dsdk_OnNpcSelectSchedule_Unregister(callback);
  }

  using _OnEntityFireOutput_Register = void (*)(EntityOutputCallback);
  PLUGIFY_EXPORT _OnEntityFireOutput_Register __dsdk_OnEntityFireOutput_Register = nullptr;
  /**
   * @brief Register Entity FireOutput listener hook
   * @param callback (function)
   */

  void OnEntityFireOutput_Register(EntityOutputCallback callback) {
    return __dsdk_OnEntityFireOutput_Register(callback);
  }

  using _OnEntityFireOutput_Unregister = void (*)(EntityOutputCallback);
  PLUGIFY_EXPORT _OnEntityFireOutput_Unregister __dsdk_OnEntityFireOutput_Unregister = nullptr;
  /**
   * @brief Unregister Entity FireOutput listener hook
   * @param callback (function)
   */

  void OnEntityFireOutput_Unregister(EntityOutputCallback callback) {
    return __dsdk_OnEntityFireOutput_Unregister(callback);
  }

  using _OnProcessUsercmds_Register = void (*)(ProcessUsercmdsCallback);
  PLUGIFY_EXPORT _OnProcessUsercmds_Register __dsdk_OnProcessUsercmds_Register = nullptr;
  /**
   * @brief Register CBasePlayerController::ProcessUsercmds listener hook
   * @param callback (function)
   */

  void OnProcessUsercmds_Register(ProcessUsercmdsCallback callback) {
    return __dsdk_OnProcessUsercmds_Register(callback);
  }

  using _OnProcessUsercmds_Unregister = void (*)(ProcessUsercmdsCallback);
  PLUGIFY_EXPORT _OnProcessUsercmds_Unregister __dsdk_OnProcessUsercmds_Unregister = nullptr;
  /**
   * @brief Unregister CBasePlayerController::ProcessUsercmds listener hook
   * @param callback (function)
   */

  void OnProcessUsercmds_Unregister(ProcessUsercmdsCallback callback) {
    return __dsdk_OnProcessUsercmds_Unregister(callback);
  }

  using _OnAbilityThink_Register = void (*)(AbilityThinkCallback);
  PLUGIFY_EXPORT _OnAbilityThink_Register __dsdk_OnAbilityThink_Register = nullptr;
  /**
   * @brief Register CCitadelPlayerPawn::AbilityThink listener hook
   * @param callback (function)
   */

  void OnAbilityThink_Register(AbilityThinkCallback callback) {
    return __dsdk_OnAbilityThink_Register(callback);
  }

  using _OnAbilityThink_Unregister = void (*)(AbilityThinkCallback);
  PLUGIFY_EXPORT _OnAbilityThink_Unregister __dsdk_OnAbilityThink_Unregister = nullptr;
  /**
   * @brief Unregister CCitadelPlayerPawn::AbilityThink listener hook
   * @param callback (function)
   */

  void OnAbilityThink_Unregister(AbilityThinkCallback callback) {
    return __dsdk_OnAbilityThink_Unregister(callback);
  }

  using _OnAddModifier_Register = void (*)(AddModifierCallback);
  PLUGIFY_EXPORT _OnAddModifier_Register __dsdk_OnAddModifier_Register = nullptr;
  /**
   * @brief Register CModifierProperty::AddModifier listener hook
   * @param callback (function)
   */

  void OnAddModifier_Register(AddModifierCallback callback) {
    return __dsdk_OnAddModifier_Register(callback);
  }

  using _OnAddModifier_Unregister = void (*)(AddModifierCallback);
  PLUGIFY_EXPORT _OnAddModifier_Unregister __dsdk_OnAddModifier_Unregister = nullptr;
  /**
   * @brief Unregister CModifierProperty::AddModifier listener hook
   * @param callback (function)
   */

  void OnAddModifier_Unregister(AddModifierCallback callback) {
    return __dsdk_OnAddModifier_Unregister(callback);
  }

  using _OnHeroInitialized_Register = void (*)(HeroInitializedCallback);
  PLUGIFY_EXPORT _OnHeroInitialized_Register __dsdk_OnHeroInitialized_Register = nullptr;
  /**
   * @brief Register CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
   * @param callback (function)
   */

  void OnHeroInitialized_Register(HeroInitializedCallback callback) {
    return __dsdk_OnHeroInitialized_Register(callback);
  }

  using _OnHeroInitialized_Unregister = void (*)(HeroInitializedCallback);
  PLUGIFY_EXPORT _OnHeroInitialized_Unregister __dsdk_OnHeroInitialized_Unregister = nullptr;
  /**
   * @brief Unregister CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
   * @param callback (function)
   */

  void OnHeroInitialized_Unregister(HeroInitializedCallback callback) {
    return __dsdk_OnHeroInitialized_Unregister(callback);
  }

  using _OnGameEvent_Register = void (*)(GameEventCallback);
  PLUGIFY_EXPORT _OnGameEvent_Register __dsdk_OnGameEvent_Register = nullptr;
  /**
   * @brief Register game event listener hook (e.g. player_death, player_respawned)
   * @param callback (function)
   */

  void OnGameEvent_Register(GameEventCallback callback) {
    return __dsdk_OnGameEvent_Register(callback);
  }

  using _OnGameEvent_Unregister = void (*)(GameEventCallback);
  PLUGIFY_EXPORT _OnGameEvent_Unregister __dsdk_OnGameEvent_Unregister = nullptr;
  /**
   * @brief Unregister game event listener hook
   * @param callback (function)
   */

  void OnGameEvent_Unregister(GameEventCallback callback) {
    return __dsdk_OnGameEvent_Unregister(callback);
  }

} // namespace dsdk
