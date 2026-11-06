// Generated from dsdk.pplugin

export module dsdk.delegates;

export import dsdk.enums;
export import dsdk.aliases;

import <cstdint>;
import <plg>;

export namespace dsdk {

  using CommandCallback = void (*)(int32_t, const plg::vector<plg::string>&);


  using TimerCallback = void (*)();


  using ModifyCurrencyCallback = HookResult (*)(int64_t, ECurrencyType, int32_t, ECurrencySource, bool, bool, bool, int64_t, int64_t);


  using TakeDamageCallback = HookResult (*)(int64_t, int64_t);


  using ClientConnectCallback = bool (*)(int32_t, const plg::string&, uint64_t);


  using ClientPutInServerCallback = void (*)(int32_t);


  using ClientDisconnectCallback = void (*)(int32_t, int32_t);


  using GameFrameCallback = void (*)(bool, bool, bool);


  using EntityCallback = void (*)(int64_t);


  using GameStateChangedCallback = void (*)(EGameState);


  using EntityIOCallback = HookResult (*)(const plg::string&, const plg::string&, int64_t, int64_t, int64_t, const plg::string&);


  using NpcSelectScheduleCallback = plg::string (*)(int64_t, const plg::string&);


  using EntityOutputCallback = HookResult (*)(const plg::string&, const plg::string&, int64_t, int64_t, float);


  using ProcessUsercmdsCallback = void (*)(int32_t, int32_t, bool);


  using AbilityThinkCallback = void (*)(int32_t, int64_t);


  using AddModifierCallback = HookResult (*)(int64_t, int64_t, uint32_t, int32_t);


  using HeroInitializedCallback = void (*)(int64_t);


  using GameEventCallback = void (*)(const plg::string&, int64_t);


} // namespace dsdk
