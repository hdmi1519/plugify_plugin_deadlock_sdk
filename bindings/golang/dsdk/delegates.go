package dsdk

import "github.com/untrustedmodders/go-plugify"

var _ = plugify.ApiVersion

// Generated from dsdk

type CommandCallback func(playerSlot int32, args []string)


type TimerCallback func()


type ModifyCurrencyCallback func(pawn int64, currencyType ECurrencyType, amount int32, source ECurrencySource, silent bool, forceGain bool, spendOnly bool, sourceAbility int64, sourceEntity int64) HookResult


type TakeDamageCallback func(victim int64, damageInfo int64) HookResult


type ClientConnectCallback func(playerSlot int32, name string, steamId uint64) bool


type ClientPutInServerCallback func(playerSlot int32)


type ClientDisconnectCallback func(playerSlot int32, reason int32)


type GameFrameCallback func(simulating bool, firstTick bool, lastTick bool)


type EntityCallback func(entity int64)


type GameStateChangedCallback func(newState EGameState)


type EntityIOCallback func(className string, inputName string, entity int64, activator int64, caller int64, value string) HookResult


type NpcSelectScheduleCallback func(npc int64, chosenId string) string


type EntityOutputCallback func(callerClass string, outputName string, activator int64, caller int64, delay float32) HookResult


type ProcessUsercmdsCallback func(playerSlot int32, numCmds int32, paused bool)


type AbilityThinkCallback func(playerSlot int32, pawn int64)


type AddModifierCallback func(modifierProp int64, caster int64, ability uint32, team int32) HookResult


type HeroInitializedCallback func(pawn int64)


type GameEventCallback func(eventName string, event int64)


