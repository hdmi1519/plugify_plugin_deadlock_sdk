//go:build plugin
// +build plugin
package main

//TODO: replace "__package__" by your package name
import (
	"unsafe"
	"__package__/dsdk"
	"github.com/untrustedmodders/go-plugify"
)

var _ = unsafe.Sizeof(0)
var _ = plugify.ApiVersion

//go:linkname dsdk_AddServerCommand __package__/dsdk._AddServerCommand
var dsdk_AddServerCommand func(name string, description string, flags int64, callback dsdk.CommandCallback) bool
var Dsdk_AddServerCommand = &dsdk_AddServerCommand

//go:linkname dsdk_AddClientCommand __package__/dsdk._AddClientCommand
var dsdk_AddClientCommand func(name string, description string, flags int64, callback dsdk.CommandCallback) bool
var Dsdk_AddClientCommand = &dsdk_AddClientCommand

//go:linkname dsdk_AddChatCommand __package__/dsdk._AddChatCommand
var dsdk_AddChatCommand func(name string, description string, flags int64, callback dsdk.CommandCallback) bool
var Dsdk_AddChatCommand = &dsdk_AddChatCommand

//go:linkname dsdk_AddConsoleCommand __package__/dsdk._AddConsoleCommand
var dsdk_AddConsoleCommand func(name string, description string, flags int64, callback dsdk.CommandCallback) bool
var Dsdk_AddConsoleCommand = &dsdk_AddConsoleCommand

//go:linkname dsdk_RemoveCommand __package__/dsdk._RemoveCommand
var dsdk_RemoveCommand func(name string) bool
var Dsdk_RemoveCommand = &dsdk_RemoveCommand

//go:linkname dsdk_ServerCommand __package__/dsdk._ServerCommand
var dsdk_ServerCommand func(command string)
var Dsdk_ServerCommand = &dsdk_ServerCommand

//go:linkname dsdk_ExecuteCommandAsPlayer __package__/dsdk._ExecuteCommandAsPlayer
var dsdk_ExecuteCommandAsPlayer func(playerSlot int32, command string) bool
var Dsdk_ExecuteCommandAsPlayer = &dsdk_ExecuteCommandAsPlayer

//go:linkname dsdk_ClientCommand __package__/dsdk._ClientCommand
var dsdk_ClientCommand func(playerSlot int32, command string)
var Dsdk_ClientCommand = &dsdk_ClientCommand

//go:linkname dsdk_PrintToChat __package__/dsdk._PrintToChat
var dsdk_PrintToChat func(playerSlot int32, message string)
var Dsdk_PrintToChat = &dsdk_PrintToChat

//go:linkname dsdk_PrintToChatAll __package__/dsdk._PrintToChatAll
var dsdk_PrintToChatAll func(message string)
var Dsdk_PrintToChatAll = &dsdk_PrintToChatAll

//go:linkname dsdk_PrintToConsole __package__/dsdk._PrintToConsole
var dsdk_PrintToConsole func(playerSlot int32, message string)
var Dsdk_PrintToConsole = &dsdk_PrintToConsole

//go:linkname dsdk_PrintToConsoleAll __package__/dsdk._PrintToConsoleAll
var dsdk_PrintToConsoleAll func(message string)
var Dsdk_PrintToConsoleAll = &dsdk_PrintToConsoleAll

//go:linkname dsdk_GetPlayerController __package__/dsdk._GetPlayerController
var dsdk_GetPlayerController func(playerSlot int32) int64
var Dsdk_GetPlayerController = &dsdk_GetPlayerController

//go:linkname dsdk_GetPlayerPawn __package__/dsdk._GetPlayerPawn
var dsdk_GetPlayerPawn func(playerSlot int32) int64
var Dsdk_GetPlayerPawn = &dsdk_GetPlayerPawn

//go:linkname dsdk_GetPlayerSlot __package__/dsdk._GetPlayerSlot
var dsdk_GetPlayerSlot func(controller int64) int32
var Dsdk_GetPlayerSlot = &dsdk_GetPlayerSlot

//go:linkname dsdk_GetPlayerName __package__/dsdk._GetPlayerName
var dsdk_GetPlayerName func(playerSlot int32) string
var Dsdk_GetPlayerName = &dsdk_GetPlayerName

//go:linkname dsdk_GetSteamID __package__/dsdk._GetSteamID
var dsdk_GetSteamID func(playerSlot int32) uint64
var Dsdk_GetSteamID = &dsdk_GetSteamID

//go:linkname dsdk_IsClientAuthenticated __package__/dsdk._IsClientAuthenticated
var dsdk_IsClientAuthenticated func(playerSlot int32) bool
var Dsdk_IsClientAuthenticated = &dsdk_IsClientAuthenticated

//go:linkname dsdk_IsClientConnected __package__/dsdk._IsClientConnected
var dsdk_IsClientConnected func(playerSlot int32) bool
var Dsdk_IsClientConnected = &dsdk_IsClientConnected

//go:linkname dsdk_IsFakeClient __package__/dsdk._IsFakeClient
var dsdk_IsFakeClient func(playerSlot int32) bool
var Dsdk_IsFakeClient = &dsdk_IsFakeClient

//go:linkname dsdk_CreateFakeClient __package__/dsdk._CreateFakeClient
var dsdk_CreateFakeClient func(name string) int32
var Dsdk_CreateFakeClient = &dsdk_CreateFakeClient

//go:linkname dsdk_DisconnectClient __package__/dsdk._DisconnectClient
var dsdk_DisconnectClient func(playerSlot int32, reason int32)
var Dsdk_DisconnectClient = &dsdk_DisconnectClient

//go:linkname dsdk_KickClient __package__/dsdk._KickClient
var dsdk_KickClient func(playerSlot int32, reason string, code int32)
var Dsdk_KickClient = &dsdk_KickClient

//go:linkname dsdk_ChangeTeam __package__/dsdk._ChangeTeam
var dsdk_ChangeTeam func(controller int64, teamNum int32, keepHero bool)
var Dsdk_ChangeTeam = &dsdk_ChangeTeam

//go:linkname dsdk_GetPlayerPing __package__/dsdk._GetPlayerPing
var dsdk_GetPlayerPing func(playerSlot int32) int32
var Dsdk_GetPlayerPing = &dsdk_GetPlayerPing

//go:linkname dsdk_SelectHero __package__/dsdk._SelectHero
var dsdk_SelectHero func(controller int64, heroName string)
var Dsdk_SelectHero = &dsdk_SelectHero

//go:linkname dsdk_ResetHero __package__/dsdk._ResetHero
var dsdk_ResetHero func(pawn int64, reset bool)
var Dsdk_ResetHero = &dsdk_ResetHero

//go:linkname dsdk_PrecacheHero __package__/dsdk._PrecacheHero
var dsdk_PrecacheHero func(heroName string)
var Dsdk_PrecacheHero = &dsdk_PrecacheHero

//go:linkname dsdk_ForceRespawn __package__/dsdk._ForceRespawn
var dsdk_ForceRespawn func(pawn int64, releaseButtons bool)
var Dsdk_ForceRespawn = &dsdk_ForceRespawn

//go:linkname dsdk_GetHeroData __package__/dsdk._GetHeroData
var dsdk_GetHeroData func(heroName string) int64
var Dsdk_GetHeroData = &dsdk_GetHeroData

//go:linkname dsdk_GetHeroName __package__/dsdk._GetHeroName
var dsdk_GetHeroName func(pawn int64) string
var Dsdk_GetHeroName = &dsdk_GetHeroName

//go:linkname dsdk_AddAbility __package__/dsdk._AddAbility
var dsdk_AddAbility func(pawn int64, abilityName string, slot uint16) int64
var Dsdk_AddAbility = &dsdk_AddAbility

//go:linkname dsdk_RemoveAbility __package__/dsdk._RemoveAbility
var dsdk_RemoveAbility func(pawn int64, abilityName string) bool
var Dsdk_RemoveAbility = &dsdk_RemoveAbility

//go:linkname dsdk_RemoveAbilityByEntity __package__/dsdk._RemoveAbilityByEntity
var dsdk_RemoveAbilityByEntity func(pawn int64, ability int64) bool
var Dsdk_RemoveAbilityByEntity = &dsdk_RemoveAbilityByEntity

//go:linkname dsdk_FindAbilityByName __package__/dsdk._FindAbilityByName
var dsdk_FindAbilityByName func(abilityComponent int64, abilityName string) int64
var Dsdk_FindAbilityByName = &dsdk_FindAbilityByName

//go:linkname dsdk_GetAbilityBySlot __package__/dsdk._GetAbilityBySlot
var dsdk_GetAbilityBySlot func(abilityComponent int64, slot int16) int64
var Dsdk_GetAbilityBySlot = &dsdk_GetAbilityBySlot

//go:linkname dsdk_ExecuteAbility __package__/dsdk._ExecuteAbility
var dsdk_ExecuteAbility func(abilityComponent int64, ability int64, altCast bool, flags uint8) int32
var Dsdk_ExecuteAbility = &dsdk_ExecuteAbility

//go:linkname dsdk_ToggleActivate __package__/dsdk._ToggleActivate
var dsdk_ToggleActivate func(ability int64, activate bool)
var Dsdk_ToggleActivate = &dsdk_ToggleActivate

//go:linkname dsdk_ResetAbilityCooldown __package__/dsdk._ResetAbilityCooldown
var dsdk_ResetAbilityCooldown func(ability int64)
var Dsdk_ResetAbilityCooldown = &dsdk_ResetAbilityCooldown

//go:linkname dsdk_GetAbilityMaxCharges __package__/dsdk._GetAbilityMaxCharges
var dsdk_GetAbilityMaxCharges func(ability int64) int32
var Dsdk_GetAbilityMaxCharges = &dsdk_GetAbilityMaxCharges

//go:linkname dsdk_SetUpgradeBits __package__/dsdk._SetUpgradeBits
var dsdk_SetUpgradeBits func(ability int64, newBits int32)
var Dsdk_SetUpgradeBits = &dsdk_SetUpgradeBits

//go:linkname dsdk_AddItem __package__/dsdk._AddItem
var dsdk_AddItem func(pawn int64, itemName string, upgradeTier int32) int64
var Dsdk_AddItem = &dsdk_AddItem

//go:linkname dsdk_SellItem __package__/dsdk._SellItem
var dsdk_SellItem func(pawn int64, itemName string, fullRefund bool, forceSellPrice bool) bool
var Dsdk_SellItem = &dsdk_SellItem

//go:linkname dsdk_GetItemImbueEffects __package__/dsdk._GetItemImbueEffects
var dsdk_GetItemImbueEffects func(itemName string) int32
var Dsdk_GetItemImbueEffects = &dsdk_GetItemImbueEffects

//go:linkname dsdk_CanImbueAbility __package__/dsdk._CanImbueAbility
var dsdk_CanImbueAbility func(targetAbility int64, itemName string) bool
var Dsdk_CanImbueAbility = &dsdk_CanImbueAbility

//go:linkname dsdk_ImbueAbility __package__/dsdk._ImbueAbility
var dsdk_ImbueAbility func(item int64, targetAbility int64) bool
var Dsdk_ImbueAbility = &dsdk_ImbueAbility

//go:linkname dsdk_ModifyCurrency __package__/dsdk._ModifyCurrency
var dsdk_ModifyCurrency func(pawn int64, currencyType dsdk.ECurrencyType, amount int32, source dsdk.ECurrencySource, silent bool, forceGain bool, spendOnly bool, sourceAbility int64, sourceEntity int64)
var Dsdk_ModifyCurrency = &dsdk_ModifyCurrency

//go:linkname dsdk_GetCurrency __package__/dsdk._GetCurrency
var dsdk_GetCurrency func(pawn int64, currencyType dsdk.ECurrencyType) int32
var Dsdk_GetCurrency = &dsdk_GetCurrency

//go:linkname dsdk_CreateTimer __package__/dsdk._CreateTimer
var dsdk_CreateTimer func(interval float32, callback dsdk.TimerCallback, repeating bool) int64
var Dsdk_CreateTimer = &dsdk_CreateTimer

//go:linkname dsdk_KillTimer __package__/dsdk._KillTimer
var dsdk_KillTimer func(timerId int64) bool
var Dsdk_KillTimer = &dsdk_KillTimer

//go:linkname dsdk_GetConfigString __package__/dsdk._GetConfigString
var dsdk_GetConfigString func(key string, defaultValue string) string
var Dsdk_GetConfigString = &dsdk_GetConfigString

//go:linkname dsdk_GetConfigInt __package__/dsdk._GetConfigInt
var dsdk_GetConfigInt func(key string, defaultValue int32) int32
var Dsdk_GetConfigInt = &dsdk_GetConfigInt

//go:linkname dsdk_GetConfigBool __package__/dsdk._GetConfigBool
var dsdk_GetConfigBool func(key string, defaultValue bool) bool
var Dsdk_GetConfigBool = &dsdk_GetConfigBool

//go:linkname dsdk_GetConfigFloat __package__/dsdk._GetConfigFloat
var dsdk_GetConfigFloat func(key string, defaultValue float32) float32
var Dsdk_GetConfigFloat = &dsdk_GetConfigFloat

//go:linkname dsdk_GetGameState __package__/dsdk._GetGameState
var dsdk_GetGameState func() dsdk.EGameState
var Dsdk_GetGameState = &dsdk_GetGameState

//go:linkname dsdk_ChangeGameState __package__/dsdk._ChangeGameState
var dsdk_ChangeGameState func(newState dsdk.EGameState)
var Dsdk_ChangeGameState = &dsdk_ChangeGameState

//go:linkname dsdk_SetWaitingForPlayersRoster __package__/dsdk._SetWaitingForPlayersRoster
var dsdk_SetWaitingForPlayersRoster func(readyCount uint32, totalCount uint32)
var Dsdk_SetWaitingForPlayersRoster = &dsdk_SetWaitingForPlayersRoster

//go:linkname dsdk_SetMatchStartOnAnyMap __package__/dsdk._SetMatchStartOnAnyMap
var dsdk_SetMatchStartOnAnyMap func(enabled bool)
var Dsdk_SetMatchStartOnAnyMap = &dsdk_SetMatchStartOnAnyMap

//go:linkname dsdk_GetMatchStartOnAnyMap __package__/dsdk._GetMatchStartOnAnyMap
var dsdk_GetMatchStartOnAnyMap func() bool
var Dsdk_GetMatchStartOnAnyMap = &dsdk_GetMatchStartOnAnyMap

//go:linkname dsdk_RegisterGameEvent __package__/dsdk._RegisterGameEvent
var dsdk_RegisterGameEvent func(name string)
var Dsdk_RegisterGameEvent = &dsdk_RegisterGameEvent

//go:linkname dsdk_CreateGameEvent __package__/dsdk._CreateGameEvent
var dsdk_CreateGameEvent func(name string, force bool) int64
var Dsdk_CreateGameEvent = &dsdk_CreateGameEvent

//go:linkname dsdk_FireGameEvent __package__/dsdk._FireGameEvent
var dsdk_FireGameEvent func(event int64, dontBroadcast bool) bool
var Dsdk_FireGameEvent = &dsdk_FireGameEvent

//go:linkname dsdk_FreeGameEvent __package__/dsdk._FreeGameEvent
var dsdk_FreeGameEvent func(event int64)
var Dsdk_FreeGameEvent = &dsdk_FreeGameEvent

//go:linkname dsdk_GameEventGetBool __package__/dsdk._GameEventGetBool
var dsdk_GameEventGetBool func(event int64, key string, def bool) bool
var Dsdk_GameEventGetBool = &dsdk_GameEventGetBool

//go:linkname dsdk_GameEventGetInt __package__/dsdk._GameEventGetInt
var dsdk_GameEventGetInt func(event int64, key string, def int32) int32
var Dsdk_GameEventGetInt = &dsdk_GameEventGetInt

//go:linkname dsdk_GameEventGetFloat __package__/dsdk._GameEventGetFloat
var dsdk_GameEventGetFloat func(event int64, key string, def float32) float32
var Dsdk_GameEventGetFloat = &dsdk_GameEventGetFloat

//go:linkname dsdk_GameEventGetString __package__/dsdk._GameEventGetString
var dsdk_GameEventGetString func(event int64, key string, def string) string
var Dsdk_GameEventGetString = &dsdk_GameEventGetString

//go:linkname dsdk_GameEventGetUint64 __package__/dsdk._GameEventGetUint64
var dsdk_GameEventGetUint64 func(event int64, key string, def uint64) uint64
var Dsdk_GameEventGetUint64 = &dsdk_GameEventGetUint64

//go:linkname dsdk_GameEventSetBool __package__/dsdk._GameEventSetBool
var dsdk_GameEventSetBool func(event int64, key string, val bool)
var Dsdk_GameEventSetBool = &dsdk_GameEventSetBool

//go:linkname dsdk_GameEventSetInt __package__/dsdk._GameEventSetInt
var dsdk_GameEventSetInt func(event int64, key string, val int32)
var Dsdk_GameEventSetInt = &dsdk_GameEventSetInt

//go:linkname dsdk_GameEventSetFloat __package__/dsdk._GameEventSetFloat
var dsdk_GameEventSetFloat func(event int64, key string, val float32)
var Dsdk_GameEventSetFloat = &dsdk_GameEventSetFloat

//go:linkname dsdk_GameEventSetString __package__/dsdk._GameEventSetString
var dsdk_GameEventSetString func(event int64, key string, val string)
var Dsdk_GameEventSetString = &dsdk_GameEventSetString

//go:linkname dsdk_GameEventGetPlayerSlot __package__/dsdk._GameEventGetPlayerSlot
var dsdk_GameEventGetPlayerSlot func(event int64, key string) int32
var Dsdk_GameEventGetPlayerSlot = &dsdk_GameEventGetPlayerSlot

//go:linkname dsdk_GameEventGetPlayerPawn __package__/dsdk._GameEventGetPlayerPawn
var dsdk_GameEventGetPlayerPawn func(event int64, key string) int64
var Dsdk_GameEventGetPlayerPawn = &dsdk_GameEventGetPlayerPawn

//go:linkname dsdk_GameEventGetPlayerController __package__/dsdk._GameEventGetPlayerController
var dsdk_GameEventGetPlayerController func(event int64, key string) int64
var Dsdk_GameEventGetPlayerController = &dsdk_GameEventGetPlayerController

//go:linkname dsdk_GetMapName __package__/dsdk._GetMapName
var dsdk_GetMapName func() string
var Dsdk_GetMapName = &dsdk_GetMapName

//go:linkname dsdk_IsMapValid __package__/dsdk._IsMapValid
var dsdk_IsMapValid func(map_ string) bool
var Dsdk_IsMapValid = &dsdk_IsMapValid

//go:linkname dsdk_SetServerKeyValue __package__/dsdk._SetServerKeyValue
var dsdk_SetServerKeyValue func(key string, value string) bool
var Dsdk_SetServerKeyValue = &dsdk_SetServerKeyValue

//go:linkname dsdk_ClearServerKeyValues __package__/dsdk._ClearServerKeyValues
var dsdk_ClearServerKeyValues func() bool
var Dsdk_ClearServerKeyValues = &dsdk_ClearServerKeyValues

//go:linkname dsdk_SetServerAddons __package__/dsdk._SetServerAddons
var dsdk_SetServerAddons func(addons string)
var Dsdk_SetServerAddons = &dsdk_SetServerAddons

//go:linkname dsdk_AddFileSystemSearchPath __package__/dsdk._AddFileSystemSearchPath
var dsdk_AddFileSystemSearchPath func(path string, pathId string, addType int32) bool
var Dsdk_AddFileSystemSearchPath = &dsdk_AddFileSystemSearchPath

//go:linkname dsdk_HasCommandLineParm __package__/dsdk._HasCommandLineParm
var dsdk_HasCommandLineParm func(parm string) bool
var Dsdk_HasCommandLineParm = &dsdk_HasCommandLineParm

//go:linkname dsdk_SetConnectRejectReason __package__/dsdk._SetConnectRejectReason
var dsdk_SetConnectRejectReason func(reason string)
var Dsdk_SetConnectRejectReason = &dsdk_SetConnectRejectReason

//go:linkname dsdk_GetGlobalVars __package__/dsdk._GetGlobalVars
var dsdk_GetGlobalVars func() int64
var Dsdk_GetGlobalVars = &dsdk_GetGlobalVars

//go:linkname dsdk_GetGameTime __package__/dsdk._GetGameTime
var dsdk_GetGameTime func() float32
var Dsdk_GetGameTime = &dsdk_GetGameTime

//go:linkname dsdk_GetGameTickCount __package__/dsdk._GetGameTickCount
var dsdk_GetGameTickCount func() int32
var Dsdk_GetGameTickCount = &dsdk_GetGameTickCount

//go:linkname dsdk_FindConVar __package__/dsdk._FindConVar
var dsdk_FindConVar func(name string) uint64
var Dsdk_FindConVar = &dsdk_FindConVar

//go:linkname dsdk_CreateConVar __package__/dsdk._CreateConVar
var dsdk_CreateConVar func(name string, defaultValue string, description string, flags uint64) uint64
var Dsdk_CreateConVar = &dsdk_CreateConVar

//go:linkname dsdk_GetConVarInt __package__/dsdk._GetConVarInt
var dsdk_GetConVarInt func(handle uint64) int32
var Dsdk_GetConVarInt = &dsdk_GetConVarInt

//go:linkname dsdk_GetConVarFloat __package__/dsdk._GetConVarFloat
var dsdk_GetConVarFloat func(handle uint64) float32
var Dsdk_GetConVarFloat = &dsdk_GetConVarFloat

//go:linkname dsdk_GetConVarString __package__/dsdk._GetConVarString
var dsdk_GetConVarString func(handle uint64) string
var Dsdk_GetConVarString = &dsdk_GetConVarString

//go:linkname dsdk_GetConVarBool __package__/dsdk._GetConVarBool
var dsdk_GetConVarBool func(handle uint64) bool
var Dsdk_GetConVarBool = &dsdk_GetConVarBool

//go:linkname dsdk_SetConVarInt __package__/dsdk._SetConVarInt
var dsdk_SetConVarInt func(handle uint64, value int32)
var Dsdk_SetConVarInt = &dsdk_SetConVarInt

//go:linkname dsdk_SetConVarFloat __package__/dsdk._SetConVarFloat
var dsdk_SetConVarFloat func(handle uint64, value float32)
var Dsdk_SetConVarFloat = &dsdk_SetConVarFloat

//go:linkname dsdk_SetConVarString __package__/dsdk._SetConVarString
var dsdk_SetConVarString func(handle uint64, value string) bool
var Dsdk_SetConVarString = &dsdk_SetConVarString

//go:linkname dsdk_CreateDamageInfo __package__/dsdk._CreateDamageInfo
var dsdk_CreateDamageInfo func(inflictor int64, attacker int64, ability int64, damage float32, damageType int32) int64
var Dsdk_CreateDamageInfo = &dsdk_CreateDamageInfo

//go:linkname dsdk_DestroyDamageInfo __package__/dsdk._DestroyDamageInfo
var dsdk_DestroyDamageInfo func(info int64)
var Dsdk_DestroyDamageInfo = &dsdk_DestroyDamageInfo

//go:linkname dsdk_TakeDamage __package__/dsdk._TakeDamage
var dsdk_TakeDamage func(victim int64, info int64)
var Dsdk_TakeDamage = &dsdk_TakeDamage

//go:linkname dsdk_ApplyDamage __package__/dsdk._ApplyDamage
var dsdk_ApplyDamage func(victim int64, info int64)
var Dsdk_ApplyDamage = &dsdk_ApplyDamage

//go:linkname dsdk_GetMaxHealth __package__/dsdk._GetMaxHealth
var dsdk_GetMaxHealth func(entity int64) int32
var Dsdk_GetMaxHealth = &dsdk_GetMaxHealth

//go:linkname dsdk_Heal __package__/dsdk._Heal
var dsdk_Heal func(entity int64, amount float32) int32
var Dsdk_Heal = &dsdk_Heal

//go:linkname dsdk_AddModifier __package__/dsdk._AddModifier
var dsdk_AddModifier func(entity int64, modifierName string, kv3 int64, caster int64, ability int64, team int32) int64
var Dsdk_AddModifier = &dsdk_AddModifier

//go:linkname dsdk_RemoveModifier __package__/dsdk._RemoveModifier
var dsdk_RemoveModifier func(entity int64, modifier int64) bool
var Dsdk_RemoveModifier = &dsdk_RemoveModifier

//go:linkname dsdk_CreateEntityByName __package__/dsdk._CreateEntityByName
var dsdk_CreateEntityByName func(className string) int64
var Dsdk_CreateEntityByName = &dsdk_CreateEntityByName

//go:linkname dsdk_QueueSpawnEntity __package__/dsdk._QueueSpawnEntity
var dsdk_QueueSpawnEntity func(entity int64, ekv int64)
var Dsdk_QueueSpawnEntity = &dsdk_QueueSpawnEntity

//go:linkname dsdk_ExecuteQueuedCreation __package__/dsdk._ExecuteQueuedCreation
var dsdk_ExecuteQueuedCreation func()
var Dsdk_ExecuteQueuedCreation = &dsdk_ExecuteQueuedCreation

//go:linkname dsdk_RemoveEntity __package__/dsdk._RemoveEntity
var dsdk_RemoveEntity func(entity int64)
var Dsdk_RemoveEntity = &dsdk_RemoveEntity

//go:linkname dsdk_GetEntityByIndex __package__/dsdk._GetEntityByIndex
var dsdk_GetEntityByIndex func(index int32) int64
var Dsdk_GetEntityByIndex = &dsdk_GetEntityByIndex

//go:linkname dsdk_GetEntityFromHandle __package__/dsdk._GetEntityFromHandle
var dsdk_GetEntityFromHandle func(handle uint32) int64
var Dsdk_GetEntityFromHandle = &dsdk_GetEntityFromHandle

//go:linkname dsdk_GetEntityHandle __package__/dsdk._GetEntityHandle
var dsdk_GetEntityHandle func(entity int64) uint32
var Dsdk_GetEntityHandle = &dsdk_GetEntityHandle

//go:linkname dsdk_FindEntityByName __package__/dsdk._FindEntityByName
var dsdk_FindEntityByName func(startEntity int64, name string) int64
var Dsdk_FindEntityByName = &dsdk_FindEntityByName

//go:linkname dsdk_GetEntityDesignerName __package__/dsdk._GetEntityDesignerName
var dsdk_GetEntityDesignerName func(entity int64) string
var Dsdk_GetEntityDesignerName = &dsdk_GetEntityDesignerName

//go:linkname dsdk_GetEntityClassname __package__/dsdk._GetEntityClassname
var dsdk_GetEntityClassname func(entity int64) string
var Dsdk_GetEntityClassname = &dsdk_GetEntityClassname

//go:linkname dsdk_Teleport __package__/dsdk._Teleport
var dsdk_Teleport func(entity int64, posX float32, posY float32, posZ float32, angPitch float32, angYaw float32, angRoll float32, velX float32, velY float32, velZ float32)
var Dsdk_Teleport = &dsdk_Teleport

//go:linkname dsdk_SetModel __package__/dsdk._SetModel
var dsdk_SetModel func(entity int64, modelName string)
var Dsdk_SetModel = &dsdk_SetModel

//go:linkname dsdk_GetModelName __package__/dsdk._GetModelName
var dsdk_GetModelName func(entity int64) string
var Dsdk_GetModelName = &dsdk_GetModelName

//go:linkname dsdk_SetScale __package__/dsdk._SetScale
var dsdk_SetScale func(entity int64, scale float32)
var Dsdk_SetScale = &dsdk_SetScale

//go:linkname dsdk_SetMoveType __package__/dsdk._SetMoveType
var dsdk_SetMoveType func(entity int64, moveType uint8)
var Dsdk_SetMoveType = &dsdk_SetMoveType

//go:linkname dsdk_SetGravityScale __package__/dsdk._SetGravityScale
var dsdk_SetGravityScale func(entity int64, scale float32)
var Dsdk_SetGravityScale = &dsdk_SetGravityScale

//go:linkname dsdk_EntityDerivesFrom __package__/dsdk._EntityDerivesFrom
var dsdk_EntityDerivesFrom func(entity int64, baseClassName string) bool
var Dsdk_EntityDerivesFrom = &dsdk_EntityDerivesFrom

//go:linkname dsdk_GetSchemaFieldOffset __package__/dsdk._GetSchemaFieldOffset
var dsdk_GetSchemaFieldOffset func(className string, fieldName string) int32
var Dsdk_GetSchemaFieldOffset = &dsdk_GetSchemaFieldOffset

//go:linkname dsdk_NotifyStateChanged __package__/dsdk._NotifyStateChanged
var dsdk_NotifyStateChanged func(entity int64, fieldOffset int32, chainOffset int16, networkStateChangedOffset int32)
var Dsdk_NotifyStateChanged = &dsdk_NotifyStateChanged

//go:linkname dsdk_SetSchemaString __package__/dsdk._SetSchemaString
var dsdk_SetSchemaString func(entity int64, className string, fieldName string, value string)
var Dsdk_SetSchemaString = &dsdk_SetSchemaString

//go:linkname dsdk_GetSchemaClassSize __package__/dsdk._GetSchemaClassSize
var dsdk_GetSchemaClassSize func(className string) int32
var Dsdk_GetSchemaClassSize = &dsdk_GetSchemaClassSize

//go:linkname dsdk_EmitSound __package__/dsdk._EmitSound
var dsdk_EmitSound func(entity int64, soundName string, pitch int32, volume float32, delay float32)
var Dsdk_EmitSound = &dsdk_EmitSound

//go:linkname dsdk_TakeSoundEventGuid __package__/dsdk._TakeSoundEventGuid
var dsdk_TakeSoundEventGuid func() uint32
var Dsdk_TakeSoundEventGuid = &dsdk_TakeSoundEventGuid

//go:linkname dsdk_CreateParticle __package__/dsdk._CreateParticle
var dsdk_CreateParticle func(particleName string, attachType int32, entity int64) int64
var Dsdk_CreateParticle = &dsdk_CreateParticle

//go:linkname dsdk_DestroyParticle __package__/dsdk._DestroyParticle
var dsdk_DestroyParticle func(particle int64, destroyImmediately bool)
var Dsdk_DestroyParticle = &dsdk_DestroyParticle

//go:linkname dsdk_PrecacheResource __package__/dsdk._PrecacheResource
var dsdk_PrecacheResource func(path string)
var Dsdk_PrecacheResource = &dsdk_PrecacheResource

//go:linkname dsdk_PrecacheModel __package__/dsdk._PrecacheModel
var dsdk_PrecacheModel func(modelPath string)
var Dsdk_PrecacheModel = &dsdk_PrecacheModel

//go:linkname dsdk_CreateWorldText __package__/dsdk._CreateWorldText
var dsdk_CreateWorldText func(message string, x float32, y float32, z float32, fontSize float32, r uint8, g uint8, b uint8, a uint8) int64
var Dsdk_CreateWorldText = &dsdk_CreateWorldText

//go:linkname dsdk_SetWorldTextMessage __package__/dsdk._SetWorldTextMessage
var dsdk_SetWorldTextMessage func(worldText int64, text string)
var Dsdk_SetWorldTextMessage = &dsdk_SetWorldTextMessage

//go:linkname dsdk_CreateBeam __package__/dsdk._CreateBeam
var dsdk_CreateBeam func(startX float32, startY float32, startZ float32, endX float32, endY float32, endZ float32, width float32, r uint8, g uint8, b uint8, a uint8) int64
var Dsdk_CreateBeam = &dsdk_CreateBeam

//go:linkname dsdk_CreateZone __package__/dsdk._CreateZone
var dsdk_CreateZone func(name string, minX float32, minY float32, minZ float32, maxX float32, maxY float32, maxZ float32) int64
var Dsdk_CreateZone = &dsdk_CreateZone

//go:linkname dsdk_DestroyZone __package__/dsdk._DestroyZone
var dsdk_DestroyZone func(zoneId int64)
var Dsdk_DestroyZone = &dsdk_DestroyZone

//go:linkname dsdk_LineTrace __package__/dsdk._LineTrace
var dsdk_LineTrace func(startX float32, startY float32, startZ float32, endX float32, endY float32, endZ float32, mask uint32, ignoreEntity int64) bool
var Dsdk_LineTrace = &dsdk_LineTrace

//go:linkname dsdk_NpcMoveTo __package__/dsdk._NpcMoveTo
var dsdk_NpcMoveTo func(npc int64, x float32, y float32, z float32, run bool, tolerance float32)
var Dsdk_NpcMoveTo = &dsdk_NpcMoveTo

//go:linkname dsdk_NpcStopMoving __package__/dsdk._NpcStopMoving
var dsdk_NpcStopMoving func(npc int64, instant bool)
var Dsdk_NpcStopMoving = &dsdk_NpcStopMoving

//go:linkname dsdk_NpcSetEnemy __package__/dsdk._NpcSetEnemy
var dsdk_NpcSetEnemy func(npc int64, enemy int64)
var Dsdk_NpcSetEnemy = &dsdk_NpcSetEnemy

//go:linkname dsdk_NpcSetState __package__/dsdk._NpcSetState
var dsdk_NpcSetState func(npc int64, state int32)
var Dsdk_NpcSetState = &dsdk_NpcSetState

//go:linkname dsdk_NpcCreateTrooper __package__/dsdk._NpcCreateTrooper
var dsdk_NpcCreateTrooper func(posX float32, posY float32, posZ float32, pitch float32, yaw float32, roll float32, team int32, type_ int32, variant int32, snapToGround bool) int64
var Dsdk_NpcCreateTrooper = &dsdk_NpcCreateTrooper

//go:linkname dsdk_NavGetNearestPoint __package__/dsdk._NavGetNearestPoint
var dsdk_NavGetNearestPoint func(x float32, y float32, z float32, maxDistance float32, hull int32) bool
var Dsdk_NavGetNearestPoint = &dsdk_NavGetNearestPoint

//go:linkname dsdk_NavGetGroundHeight __package__/dsdk._NavGetGroundHeight
var dsdk_NavGetGroundHeight func(x float32, y float32, z float32, maxDistance float32, hull int32) float32
var Dsdk_NavGetGroundHeight = &dsdk_NavGetGroundHeight

//go:linkname dsdk_BotCreate __package__/dsdk._BotCreate
var dsdk_BotCreate func(heroName string, team int32, posX float32, posY float32, posZ float32, assignLane bool) int64
var Dsdk_BotCreate = &dsdk_BotCreate

//go:linkname dsdk_BotGetBrain __package__/dsdk._BotGetBrain
var dsdk_BotGetBrain func(pawn int64) int64
var Dsdk_BotGetBrain = &dsdk_BotGetBrain

//go:linkname dsdk_BotGetPawn __package__/dsdk._BotGetPawn
var dsdk_BotGetPawn func(brain int64) int64
var Dsdk_BotGetPawn = &dsdk_BotGetPawn

//go:linkname dsdk_BotSetLane __package__/dsdk._BotSetLane
var dsdk_BotSetLane func(pawn int64, lane int32) bool
var Dsdk_BotSetLane = &dsdk_BotSetLane

//go:linkname dsdk_BotGetLane __package__/dsdk._BotGetLane
var dsdk_BotGetLane func(pawn int64) int32
var Dsdk_BotGetLane = &dsdk_BotGetLane

//go:linkname dsdk_AcceptInput __package__/dsdk._AcceptInput
var dsdk_AcceptInput func(entity int64, inputName string, activator int64, caller int64, value string)
var Dsdk_AcceptInput = &dsdk_AcceptInput

//go:linkname dsdk_SendNetMessage __package__/dsdk._SendNetMessage
var dsdk_SendNetMessage func(msgId int32, protoBytes []uint8, recipientMask uint64, bufType int32)
var Dsdk_SendNetMessage = &dsdk_SendNetMessage

//go:linkname dsdk_GetNetMessageName __package__/dsdk._GetNetMessageName
var dsdk_GetNetMessageName func(msgId int32) string
var Dsdk_GetNetMessageName = &dsdk_GetNetMessageName

//go:linkname dsdk_KV3Create __package__/dsdk._KV3Create
var dsdk_KV3Create func() int64
var Dsdk_KV3Create = &dsdk_KV3Create

//go:linkname dsdk_KV3Destroy __package__/dsdk._KV3Destroy
var dsdk_KV3Destroy func(kv3 int64)
var Dsdk_KV3Destroy = &dsdk_KV3Destroy

//go:linkname dsdk_KV3SetString __package__/dsdk._KV3SetString
var dsdk_KV3SetString func(kv3 int64, key string, value string)
var Dsdk_KV3SetString = &dsdk_KV3SetString

//go:linkname dsdk_KV3SetBool __package__/dsdk._KV3SetBool
var dsdk_KV3SetBool func(kv3 int64, key string, value bool)
var Dsdk_KV3SetBool = &dsdk_KV3SetBool

//go:linkname dsdk_KV3SetInt __package__/dsdk._KV3SetInt
var dsdk_KV3SetInt func(kv3 int64, key string, value int32)
var Dsdk_KV3SetInt = &dsdk_KV3SetInt

//go:linkname dsdk_KV3SetFloat __package__/dsdk._KV3SetFloat
var dsdk_KV3SetFloat func(kv3 int64, key string, value float32)
var Dsdk_KV3SetFloat = &dsdk_KV3SetFloat

//go:linkname dsdk_OnModifyCurrency_Register __package__/dsdk._OnModifyCurrency_Register
var dsdk_OnModifyCurrency_Register func(callback dsdk.ModifyCurrencyCallback)
var Dsdk_OnModifyCurrency_Register = &dsdk_OnModifyCurrency_Register

//go:linkname dsdk_OnModifyCurrency_Unregister __package__/dsdk._OnModifyCurrency_Unregister
var dsdk_OnModifyCurrency_Unregister func(callback dsdk.ModifyCurrencyCallback)
var Dsdk_OnModifyCurrency_Unregister = &dsdk_OnModifyCurrency_Unregister

//go:linkname dsdk_OnTakeDamage_Register __package__/dsdk._OnTakeDamage_Register
var dsdk_OnTakeDamage_Register func(callback dsdk.TakeDamageCallback)
var Dsdk_OnTakeDamage_Register = &dsdk_OnTakeDamage_Register

//go:linkname dsdk_OnTakeDamage_Unregister __package__/dsdk._OnTakeDamage_Unregister
var dsdk_OnTakeDamage_Unregister func(callback dsdk.TakeDamageCallback)
var Dsdk_OnTakeDamage_Unregister = &dsdk_OnTakeDamage_Unregister

//go:linkname dsdk_OnClientConnect_Register __package__/dsdk._OnClientConnect_Register
var dsdk_OnClientConnect_Register func(callback dsdk.ClientConnectCallback)
var Dsdk_OnClientConnect_Register = &dsdk_OnClientConnect_Register

//go:linkname dsdk_OnClientConnect_Unregister __package__/dsdk._OnClientConnect_Unregister
var dsdk_OnClientConnect_Unregister func(callback dsdk.ClientConnectCallback)
var Dsdk_OnClientConnect_Unregister = &dsdk_OnClientConnect_Unregister

//go:linkname dsdk_OnClientPutInServer_Register __package__/dsdk._OnClientPutInServer_Register
var dsdk_OnClientPutInServer_Register func(callback dsdk.ClientPutInServerCallback)
var Dsdk_OnClientPutInServer_Register = &dsdk_OnClientPutInServer_Register

//go:linkname dsdk_OnClientPutInServer_Unregister __package__/dsdk._OnClientPutInServer_Unregister
var dsdk_OnClientPutInServer_Unregister func(callback dsdk.ClientPutInServerCallback)
var Dsdk_OnClientPutInServer_Unregister = &dsdk_OnClientPutInServer_Unregister

//go:linkname dsdk_OnClientDisconnect_Register __package__/dsdk._OnClientDisconnect_Register
var dsdk_OnClientDisconnect_Register func(callback dsdk.ClientDisconnectCallback)
var Dsdk_OnClientDisconnect_Register = &dsdk_OnClientDisconnect_Register

//go:linkname dsdk_OnClientDisconnect_Unregister __package__/dsdk._OnClientDisconnect_Unregister
var dsdk_OnClientDisconnect_Unregister func(callback dsdk.ClientDisconnectCallback)
var Dsdk_OnClientDisconnect_Unregister = &dsdk_OnClientDisconnect_Unregister

//go:linkname dsdk_OnGameFrame_Register __package__/dsdk._OnGameFrame_Register
var dsdk_OnGameFrame_Register func(callback dsdk.GameFrameCallback)
var Dsdk_OnGameFrame_Register = &dsdk_OnGameFrame_Register

//go:linkname dsdk_OnGameFrame_Unregister __package__/dsdk._OnGameFrame_Unregister
var dsdk_OnGameFrame_Unregister func(callback dsdk.GameFrameCallback)
var Dsdk_OnGameFrame_Unregister = &dsdk_OnGameFrame_Unregister

//go:linkname dsdk_OnEntityCreated_Register __package__/dsdk._OnEntityCreated_Register
var dsdk_OnEntityCreated_Register func(callback dsdk.EntityCallback)
var Dsdk_OnEntityCreated_Register = &dsdk_OnEntityCreated_Register

//go:linkname dsdk_OnEntityCreated_Unregister __package__/dsdk._OnEntityCreated_Unregister
var dsdk_OnEntityCreated_Unregister func(callback dsdk.EntityCallback)
var Dsdk_OnEntityCreated_Unregister = &dsdk_OnEntityCreated_Unregister

//go:linkname dsdk_OnEntitySpawned_Register __package__/dsdk._OnEntitySpawned_Register
var dsdk_OnEntitySpawned_Register func(callback dsdk.EntityCallback)
var Dsdk_OnEntitySpawned_Register = &dsdk_OnEntitySpawned_Register

//go:linkname dsdk_OnEntitySpawned_Unregister __package__/dsdk._OnEntitySpawned_Unregister
var dsdk_OnEntitySpawned_Unregister func(callback dsdk.EntityCallback)
var Dsdk_OnEntitySpawned_Unregister = &dsdk_OnEntitySpawned_Unregister

//go:linkname dsdk_OnEntityDeleted_Register __package__/dsdk._OnEntityDeleted_Register
var dsdk_OnEntityDeleted_Register func(callback dsdk.EntityCallback)
var Dsdk_OnEntityDeleted_Register = &dsdk_OnEntityDeleted_Register

//go:linkname dsdk_OnEntityDeleted_Unregister __package__/dsdk._OnEntityDeleted_Unregister
var dsdk_OnEntityDeleted_Unregister func(callback dsdk.EntityCallback)
var Dsdk_OnEntityDeleted_Unregister = &dsdk_OnEntityDeleted_Unregister

//go:linkname dsdk_OnGameStateChanged_Register __package__/dsdk._OnGameStateChanged_Register
var dsdk_OnGameStateChanged_Register func(callback dsdk.GameStateChangedCallback)
var Dsdk_OnGameStateChanged_Register = &dsdk_OnGameStateChanged_Register

//go:linkname dsdk_OnGameStateChanged_Unregister __package__/dsdk._OnGameStateChanged_Unregister
var dsdk_OnGameStateChanged_Unregister func(callback dsdk.GameStateChangedCallback)
var Dsdk_OnGameStateChanged_Unregister = &dsdk_OnGameStateChanged_Unregister

//go:linkname dsdk_OnEntityAcceptInput_Register __package__/dsdk._OnEntityAcceptInput_Register
var dsdk_OnEntityAcceptInput_Register func(callback dsdk.EntityIOCallback)
var Dsdk_OnEntityAcceptInput_Register = &dsdk_OnEntityAcceptInput_Register

//go:linkname dsdk_OnEntityAcceptInput_Unregister __package__/dsdk._OnEntityAcceptInput_Unregister
var dsdk_OnEntityAcceptInput_Unregister func(callback dsdk.EntityIOCallback)
var Dsdk_OnEntityAcceptInput_Unregister = &dsdk_OnEntityAcceptInput_Unregister

//go:linkname dsdk_OnNpcSelectSchedule_Register __package__/dsdk._OnNpcSelectSchedule_Register
var dsdk_OnNpcSelectSchedule_Register func(callback dsdk.NpcSelectScheduleCallback)
var Dsdk_OnNpcSelectSchedule_Register = &dsdk_OnNpcSelectSchedule_Register

//go:linkname dsdk_OnNpcSelectSchedule_Unregister __package__/dsdk._OnNpcSelectSchedule_Unregister
var dsdk_OnNpcSelectSchedule_Unregister func(callback dsdk.NpcSelectScheduleCallback)
var Dsdk_OnNpcSelectSchedule_Unregister = &dsdk_OnNpcSelectSchedule_Unregister

//go:linkname dsdk_OnEntityFireOutput_Register __package__/dsdk._OnEntityFireOutput_Register
var dsdk_OnEntityFireOutput_Register func(callback dsdk.EntityOutputCallback)
var Dsdk_OnEntityFireOutput_Register = &dsdk_OnEntityFireOutput_Register

//go:linkname dsdk_OnEntityFireOutput_Unregister __package__/dsdk._OnEntityFireOutput_Unregister
var dsdk_OnEntityFireOutput_Unregister func(callback dsdk.EntityOutputCallback)
var Dsdk_OnEntityFireOutput_Unregister = &dsdk_OnEntityFireOutput_Unregister

//go:linkname dsdk_OnProcessUsercmds_Register __package__/dsdk._OnProcessUsercmds_Register
var dsdk_OnProcessUsercmds_Register func(callback dsdk.ProcessUsercmdsCallback)
var Dsdk_OnProcessUsercmds_Register = &dsdk_OnProcessUsercmds_Register

//go:linkname dsdk_OnProcessUsercmds_Unregister __package__/dsdk._OnProcessUsercmds_Unregister
var dsdk_OnProcessUsercmds_Unregister func(callback dsdk.ProcessUsercmdsCallback)
var Dsdk_OnProcessUsercmds_Unregister = &dsdk_OnProcessUsercmds_Unregister

//go:linkname dsdk_OnAbilityThink_Register __package__/dsdk._OnAbilityThink_Register
var dsdk_OnAbilityThink_Register func(callback dsdk.AbilityThinkCallback)
var Dsdk_OnAbilityThink_Register = &dsdk_OnAbilityThink_Register

//go:linkname dsdk_OnAbilityThink_Unregister __package__/dsdk._OnAbilityThink_Unregister
var dsdk_OnAbilityThink_Unregister func(callback dsdk.AbilityThinkCallback)
var Dsdk_OnAbilityThink_Unregister = &dsdk_OnAbilityThink_Unregister

//go:linkname dsdk_OnAddModifier_Register __package__/dsdk._OnAddModifier_Register
var dsdk_OnAddModifier_Register func(callback dsdk.AddModifierCallback)
var Dsdk_OnAddModifier_Register = &dsdk_OnAddModifier_Register

//go:linkname dsdk_OnAddModifier_Unregister __package__/dsdk._OnAddModifier_Unregister
var dsdk_OnAddModifier_Unregister func(callback dsdk.AddModifierCallback)
var Dsdk_OnAddModifier_Unregister = &dsdk_OnAddModifier_Unregister

//go:linkname dsdk_OnHeroInitialized_Register __package__/dsdk._OnHeroInitialized_Register
var dsdk_OnHeroInitialized_Register func(callback dsdk.HeroInitializedCallback)
var Dsdk_OnHeroInitialized_Register = &dsdk_OnHeroInitialized_Register

//go:linkname dsdk_OnHeroInitialized_Unregister __package__/dsdk._OnHeroInitialized_Unregister
var dsdk_OnHeroInitialized_Unregister func(callback dsdk.HeroInitializedCallback)
var Dsdk_OnHeroInitialized_Unregister = &dsdk_OnHeroInitialized_Unregister

//go:linkname dsdk_OnGameEvent_Register __package__/dsdk._OnGameEvent_Register
var dsdk_OnGameEvent_Register func(callback dsdk.GameEventCallback)
var Dsdk_OnGameEvent_Register = &dsdk_OnGameEvent_Register

//go:linkname dsdk_OnGameEvent_Unregister __package__/dsdk._OnGameEvent_Unregister
var dsdk_OnGameEvent_Unregister func(callback dsdk.GameEventCallback)
var Dsdk_OnGameEvent_Unregister = &dsdk_OnGameEvent_Unregister

//go:linkname dsdk_HudAnnounce __package__/dsdk._HudAnnounce
var dsdk_HudAnnounce func(playerSlot int32, title string, description string, duration float32)
var Dsdk_HudAnnounce = &dsdk_HudAnnounce

//go:linkname dsdk_HudAnnounceAll __package__/dsdk._HudAnnounceAll
var dsdk_HudAnnounceAll func(title string, description string, duration float32)
var Dsdk_HudAnnounceAll = &dsdk_HudAnnounceAll

/*func init() {
	dsdk.ModuleName = "__package__"
}*/
