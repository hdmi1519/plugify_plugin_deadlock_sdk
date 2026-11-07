#include "dsdk.hpp"

dsdk::_AddServerCommand __dsdk_AddServerCommand = nullptr;

dsdk::_AddClientCommand __dsdk_AddClientCommand = nullptr;

dsdk::_AddChatCommand __dsdk_AddChatCommand = nullptr;

dsdk::_AddConsoleCommand __dsdk_AddConsoleCommand = nullptr;

dsdk::_RemoveCommand __dsdk_RemoveCommand = nullptr;

dsdk::_ServerCommand __dsdk_ServerCommand = nullptr;

dsdk::_ExecuteCommandAsPlayer __dsdk_ExecuteCommandAsPlayer = nullptr;

dsdk::_ClientCommand __dsdk_ClientCommand = nullptr;

dsdk::_PrintToChat __dsdk_PrintToChat = nullptr;

dsdk::_PrintToChatAll __dsdk_PrintToChatAll = nullptr;

dsdk::_PrintToConsole __dsdk_PrintToConsole = nullptr;

dsdk::_PrintToConsoleAll __dsdk_PrintToConsoleAll = nullptr;

dsdk::_GetPlayerController __dsdk_GetPlayerController = nullptr;

dsdk::_GetPlayerPawn __dsdk_GetPlayerPawn = nullptr;

dsdk::_GetPlayerSlot __dsdk_GetPlayerSlot = nullptr;

dsdk::_GetPlayerName __dsdk_GetPlayerName = nullptr;

dsdk::_GetSteamID __dsdk_GetSteamID = nullptr;

dsdk::_IsClientAuthenticated __dsdk_IsClientAuthenticated = nullptr;

dsdk::_IsClientConnected __dsdk_IsClientConnected = nullptr;

dsdk::_IsFakeClient __dsdk_IsFakeClient = nullptr;

dsdk::_CreateFakeClient __dsdk_CreateFakeClient = nullptr;

dsdk::_DisconnectClient __dsdk_DisconnectClient = nullptr;

dsdk::_KickClient __dsdk_KickClient = nullptr;

dsdk::_ChangeTeam __dsdk_ChangeTeam = nullptr;

dsdk::_GetPlayerPing __dsdk_GetPlayerPing = nullptr;

dsdk::_GetPlayerTimeConnected __dsdk_GetPlayerTimeConnected = nullptr;

dsdk::_SelectHero __dsdk_SelectHero = nullptr;

dsdk::_ResetHero __dsdk_ResetHero = nullptr;

dsdk::_PrecacheHero __dsdk_PrecacheHero = nullptr;

dsdk::_ForceRespawn __dsdk_ForceRespawn = nullptr;

dsdk::_GetHeroData __dsdk_GetHeroData = nullptr;

dsdk::_GetHeroName __dsdk_GetHeroName = nullptr;

dsdk::_AddAbility __dsdk_AddAbility = nullptr;

dsdk::_RemoveAbility __dsdk_RemoveAbility = nullptr;

dsdk::_RemoveAbilityByEntity __dsdk_RemoveAbilityByEntity = nullptr;

dsdk::_FindAbilityByName __dsdk_FindAbilityByName = nullptr;

dsdk::_GetAbilityBySlot __dsdk_GetAbilityBySlot = nullptr;

dsdk::_ExecuteAbility __dsdk_ExecuteAbility = nullptr;

dsdk::_ToggleActivate __dsdk_ToggleActivate = nullptr;

dsdk::_ResetAbilityCooldown __dsdk_ResetAbilityCooldown = nullptr;

dsdk::_GetAbilityMaxCharges __dsdk_GetAbilityMaxCharges = nullptr;

dsdk::_SetUpgradeBits __dsdk_SetUpgradeBits = nullptr;

dsdk::_AddItem __dsdk_AddItem = nullptr;

dsdk::_SellItem __dsdk_SellItem = nullptr;

dsdk::_GetItemImbueEffects __dsdk_GetItemImbueEffects = nullptr;

dsdk::_CanImbueAbility __dsdk_CanImbueAbility = nullptr;

dsdk::_ImbueAbility __dsdk_ImbueAbility = nullptr;

dsdk::_ModifyCurrency __dsdk_ModifyCurrency = nullptr;

dsdk::_GetCurrency __dsdk_GetCurrency = nullptr;

dsdk::_CreateTimer __dsdk_CreateTimer = nullptr;

dsdk::_KillTimer __dsdk_KillTimer = nullptr;

dsdk::_GetConfigString __dsdk_GetConfigString = nullptr;

dsdk::_GetConfigInt __dsdk_GetConfigInt = nullptr;

dsdk::_GetConfigBool __dsdk_GetConfigBool = nullptr;

dsdk::_GetConfigFloat __dsdk_GetConfigFloat = nullptr;

dsdk::_GetGameState __dsdk_GetGameState = nullptr;

dsdk::_GetMatchTime __dsdk_GetMatchTime = nullptr;

dsdk::_ChangeGameState __dsdk_ChangeGameState = nullptr;

dsdk::_SetWaitingForPlayersRoster __dsdk_SetWaitingForPlayersRoster = nullptr;

dsdk::_SetMatchStartOnAnyMap __dsdk_SetMatchStartOnAnyMap = nullptr;

dsdk::_GetMatchStartOnAnyMap __dsdk_GetMatchStartOnAnyMap = nullptr;

dsdk::_RegisterGameEvent __dsdk_RegisterGameEvent = nullptr;

dsdk::_CreateGameEvent __dsdk_CreateGameEvent = nullptr;

dsdk::_FireGameEvent __dsdk_FireGameEvent = nullptr;

dsdk::_FreeGameEvent __dsdk_FreeGameEvent = nullptr;

dsdk::_GameEventGetBool __dsdk_GameEventGetBool = nullptr;

dsdk::_GameEventGetInt __dsdk_GameEventGetInt = nullptr;

dsdk::_GameEventGetFloat __dsdk_GameEventGetFloat = nullptr;

dsdk::_GameEventGetString __dsdk_GameEventGetString = nullptr;

dsdk::_GameEventGetUint64 __dsdk_GameEventGetUint64 = nullptr;

dsdk::_GameEventSetBool __dsdk_GameEventSetBool = nullptr;

dsdk::_GameEventSetInt __dsdk_GameEventSetInt = nullptr;

dsdk::_GameEventSetFloat __dsdk_GameEventSetFloat = nullptr;

dsdk::_GameEventSetString __dsdk_GameEventSetString = nullptr;

dsdk::_GameEventGetPlayerSlot __dsdk_GameEventGetPlayerSlot = nullptr;

dsdk::_GameEventGetPlayerPawn __dsdk_GameEventGetPlayerPawn = nullptr;

dsdk::_GameEventGetPlayerController __dsdk_GameEventGetPlayerController = nullptr;

dsdk::_GetMapName __dsdk_GetMapName = nullptr;

dsdk::_IsMapValid __dsdk_IsMapValid = nullptr;

dsdk::_SetServerKeyValue __dsdk_SetServerKeyValue = nullptr;

dsdk::_ClearServerKeyValues __dsdk_ClearServerKeyValues = nullptr;

dsdk::_SetServerAddons __dsdk_SetServerAddons = nullptr;

dsdk::_AddFileSystemSearchPath __dsdk_AddFileSystemSearchPath = nullptr;

dsdk::_HasCommandLineParm __dsdk_HasCommandLineParm = nullptr;

dsdk::_SetConnectRejectReason __dsdk_SetConnectRejectReason = nullptr;

dsdk::_GetGlobalVars __dsdk_GetGlobalVars = nullptr;

dsdk::_GetGameTime __dsdk_GetGameTime = nullptr;

dsdk::_GetGameTickCount __dsdk_GetGameTickCount = nullptr;

dsdk::_FindConVar __dsdk_FindConVar = nullptr;

dsdk::_CreateConVar __dsdk_CreateConVar = nullptr;

dsdk::_GetConVarInt __dsdk_GetConVarInt = nullptr;

dsdk::_GetConVarFloat __dsdk_GetConVarFloat = nullptr;

dsdk::_GetConVarString __dsdk_GetConVarString = nullptr;

dsdk::_GetConVarBool __dsdk_GetConVarBool = nullptr;

dsdk::_SetConVarInt __dsdk_SetConVarInt = nullptr;

dsdk::_SetConVarFloat __dsdk_SetConVarFloat = nullptr;

dsdk::_SetConVarString __dsdk_SetConVarString = nullptr;

dsdk::_CreateDamageInfo __dsdk_CreateDamageInfo = nullptr;

dsdk::_DestroyDamageInfo __dsdk_DestroyDamageInfo = nullptr;

dsdk::_TakeDamage __dsdk_TakeDamage = nullptr;

dsdk::_ApplyDamage __dsdk_ApplyDamage = nullptr;

dsdk::_GetMaxHealth __dsdk_GetMaxHealth = nullptr;

dsdk::_Heal __dsdk_Heal = nullptr;

dsdk::_AddModifier __dsdk_AddModifier = nullptr;

dsdk::_RemoveModifier __dsdk_RemoveModifier = nullptr;

dsdk::_CreateEntityByName __dsdk_CreateEntityByName = nullptr;

dsdk::_QueueSpawnEntity __dsdk_QueueSpawnEntity = nullptr;

dsdk::_ExecuteQueuedCreation __dsdk_ExecuteQueuedCreation = nullptr;

dsdk::_RemoveEntity __dsdk_RemoveEntity = nullptr;

dsdk::_GetEntityByIndex __dsdk_GetEntityByIndex = nullptr;

dsdk::_GetEntityFromHandle __dsdk_GetEntityFromHandle = nullptr;

dsdk::_GetEntityHandle __dsdk_GetEntityHandle = nullptr;

dsdk::_FindEntityByName __dsdk_FindEntityByName = nullptr;

dsdk::_GetEntityDesignerName __dsdk_GetEntityDesignerName = nullptr;

dsdk::_GetEntityClassname __dsdk_GetEntityClassname = nullptr;

dsdk::_Teleport __dsdk_Teleport = nullptr;

dsdk::_SetModel __dsdk_SetModel = nullptr;

dsdk::_GetModelName __dsdk_GetModelName = nullptr;

dsdk::_SetScale __dsdk_SetScale = nullptr;

dsdk::_SetMoveType __dsdk_SetMoveType = nullptr;

dsdk::_SetGravityScale __dsdk_SetGravityScale = nullptr;

dsdk::_EntityDerivesFrom __dsdk_EntityDerivesFrom = nullptr;

dsdk::_GetSchemaFieldOffset __dsdk_GetSchemaFieldOffset = nullptr;

dsdk::_NotifyStateChanged __dsdk_NotifyStateChanged = nullptr;

dsdk::_SetSchemaString __dsdk_SetSchemaString = nullptr;

dsdk::_GetSchemaClassSize __dsdk_GetSchemaClassSize = nullptr;

dsdk::_EmitSound __dsdk_EmitSound = nullptr;

dsdk::_TakeSoundEventGuid __dsdk_TakeSoundEventGuid = nullptr;

dsdk::_CreateParticle __dsdk_CreateParticle = nullptr;

dsdk::_DestroyParticle __dsdk_DestroyParticle = nullptr;

dsdk::_PrecacheResource __dsdk_PrecacheResource = nullptr;

dsdk::_PrecacheModel __dsdk_PrecacheModel = nullptr;

dsdk::_CreateWorldText __dsdk_CreateWorldText = nullptr;

dsdk::_SetWorldTextMessage __dsdk_SetWorldTextMessage = nullptr;

dsdk::_CreateBeam __dsdk_CreateBeam = nullptr;

dsdk::_CreateZone __dsdk_CreateZone = nullptr;

dsdk::_DestroyZone __dsdk_DestroyZone = nullptr;

dsdk::_LineTrace __dsdk_LineTrace = nullptr;

dsdk::_NpcMoveTo __dsdk_NpcMoveTo = nullptr;

dsdk::_NpcStopMoving __dsdk_NpcStopMoving = nullptr;

dsdk::_NpcSetEnemy __dsdk_NpcSetEnemy = nullptr;

dsdk::_NpcSetState __dsdk_NpcSetState = nullptr;

dsdk::_NpcCreateTrooper __dsdk_NpcCreateTrooper = nullptr;

dsdk::_NavGetNearestPoint __dsdk_NavGetNearestPoint = nullptr;

dsdk::_NavGetGroundHeight __dsdk_NavGetGroundHeight = nullptr;

dsdk::_BotCreate __dsdk_BotCreate = nullptr;

dsdk::_BotGetBrain __dsdk_BotGetBrain = nullptr;

dsdk::_BotGetPawn __dsdk_BotGetPawn = nullptr;

dsdk::_BotSetLane __dsdk_BotSetLane = nullptr;

dsdk::_BotGetLane __dsdk_BotGetLane = nullptr;

dsdk::_AcceptInput __dsdk_AcceptInput = nullptr;

dsdk::_SendNetMessage __dsdk_SendNetMessage = nullptr;

dsdk::_GetNetMessageName __dsdk_GetNetMessageName = nullptr;

dsdk::_KV3Create __dsdk_KV3Create = nullptr;

dsdk::_KV3Destroy __dsdk_KV3Destroy = nullptr;

dsdk::_KV3SetString __dsdk_KV3SetString = nullptr;

dsdk::_KV3SetBool __dsdk_KV3SetBool = nullptr;

dsdk::_KV3SetInt __dsdk_KV3SetInt = nullptr;

dsdk::_KV3SetFloat __dsdk_KV3SetFloat = nullptr;

dsdk::_OnModifyCurrency_Register __dsdk_OnModifyCurrency_Register = nullptr;

dsdk::_OnModifyCurrency_Unregister __dsdk_OnModifyCurrency_Unregister = nullptr;

dsdk::_OnTakeDamage_Register __dsdk_OnTakeDamage_Register = nullptr;

dsdk::_OnTakeDamage_Unregister __dsdk_OnTakeDamage_Unregister = nullptr;

dsdk::_OnClientConnect_Register __dsdk_OnClientConnect_Register = nullptr;

dsdk::_OnClientConnect_Unregister __dsdk_OnClientConnect_Unregister = nullptr;

dsdk::_OnClientPutInServer_Register __dsdk_OnClientPutInServer_Register = nullptr;

dsdk::_OnClientPutInServer_Unregister __dsdk_OnClientPutInServer_Unregister = nullptr;

dsdk::_OnClientDisconnect_Register __dsdk_OnClientDisconnect_Register = nullptr;

dsdk::_OnClientDisconnect_Unregister __dsdk_OnClientDisconnect_Unregister = nullptr;

dsdk::_OnGameFrame_Register __dsdk_OnGameFrame_Register = nullptr;

dsdk::_OnGameFrame_Unregister __dsdk_OnGameFrame_Unregister = nullptr;

dsdk::_OnEntityCreated_Register __dsdk_OnEntityCreated_Register = nullptr;

dsdk::_OnEntityCreated_Unregister __dsdk_OnEntityCreated_Unregister = nullptr;

dsdk::_OnEntitySpawned_Register __dsdk_OnEntitySpawned_Register = nullptr;

dsdk::_OnEntitySpawned_Unregister __dsdk_OnEntitySpawned_Unregister = nullptr;

dsdk::_OnEntityDeleted_Register __dsdk_OnEntityDeleted_Register = nullptr;

dsdk::_OnEntityDeleted_Unregister __dsdk_OnEntityDeleted_Unregister = nullptr;

dsdk::_OnGameStateChanged_Register __dsdk_OnGameStateChanged_Register = nullptr;

dsdk::_OnGameStateChanged_Unregister __dsdk_OnGameStateChanged_Unregister = nullptr;

dsdk::_OnEntityAcceptInput_Register __dsdk_OnEntityAcceptInput_Register = nullptr;

dsdk::_OnEntityAcceptInput_Unregister __dsdk_OnEntityAcceptInput_Unregister = nullptr;

dsdk::_OnNpcSelectSchedule_Register __dsdk_OnNpcSelectSchedule_Register = nullptr;

dsdk::_OnNpcSelectSchedule_Unregister __dsdk_OnNpcSelectSchedule_Unregister = nullptr;

dsdk::_OnEntityFireOutput_Register __dsdk_OnEntityFireOutput_Register = nullptr;

dsdk::_OnEntityFireOutput_Unregister __dsdk_OnEntityFireOutput_Unregister = nullptr;

dsdk::_OnProcessUsercmds_Register __dsdk_OnProcessUsercmds_Register = nullptr;

dsdk::_OnProcessUsercmds_Unregister __dsdk_OnProcessUsercmds_Unregister = nullptr;

dsdk::_OnAbilityThink_Register __dsdk_OnAbilityThink_Register = nullptr;

dsdk::_OnAbilityThink_Unregister __dsdk_OnAbilityThink_Unregister = nullptr;

dsdk::_OnAddModifier_Register __dsdk_OnAddModifier_Register = nullptr;

dsdk::_OnAddModifier_Unregister __dsdk_OnAddModifier_Unregister = nullptr;

dsdk::_OnHeroInitialized_Register __dsdk_OnHeroInitialized_Register = nullptr;

dsdk::_OnHeroInitialized_Unregister __dsdk_OnHeroInitialized_Unregister = nullptr;

dsdk::_OnGameEvent_Register __dsdk_OnGameEvent_Register = nullptr;

dsdk::_OnGameEvent_Unregister __dsdk_OnGameEvent_Unregister = nullptr;

dsdk::_HudAnnounce __dsdk_HudAnnounce = nullptr;

dsdk::_HudAnnounceAll __dsdk_HudAnnounceAll = nullptr;

