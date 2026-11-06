using System;
using System.Numerics;

using Plugify;

// Generated from dsdk.pplugin

namespace dsdk {
#pragma warning disable CS0649

	public delegate void CommandCallback(int playerSlot, string[] args);

	public delegate void TimerCallback();

	public delegate HookResult ModifyCurrencyCallback(long pawn, ECurrencyType currencyType, int amount, ECurrencySource source, Bool8 silent, Bool8 forceGain, Bool8 spendOnly, long sourceAbility, long sourceEntity);

	public delegate HookResult TakeDamageCallback(long victim, long damageInfo);

	public delegate Bool8 ClientConnectCallback(int playerSlot, string name, ulong steamId);

	public delegate void ClientPutInServerCallback(int playerSlot);

	public delegate void ClientDisconnectCallback(int playerSlot, int reason);

	public delegate void GameFrameCallback(Bool8 simulating, Bool8 firstTick, Bool8 lastTick);

	public delegate void EntityCallback(long entity);

	public delegate void GameStateChangedCallback(EGameState newState);

	public delegate HookResult EntityIOCallback(string className, string inputName, long entity, long activator, long caller, string value);

	public delegate string NpcSelectScheduleCallback(long npc, string chosenId);

	public delegate HookResult EntityOutputCallback(string callerClass, string outputName, long activator, long caller, float delay);

	public delegate void ProcessUsercmdsCallback(int playerSlot, int numCmds, Bool8 paused);

	public delegate void AbilityThinkCallback(int playerSlot, long pawn);

	public delegate HookResult AddModifierCallback(long modifierProp, long caster, uint ability, int team);

	public delegate void HeroInitializedCallback(long pawn);

	public delegate void GameEventCallback(string eventName, long event_);

#pragma warning restore CS0649
}
