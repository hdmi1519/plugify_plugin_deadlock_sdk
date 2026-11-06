from collections.abc import Callable
from enum import IntEnum
from plugify.plugin import Vector2, Vector3, Vector4, Matrix4x4

# Generated from dsdk.pplugin

class ECurrencyType(IntEnum):
    """
    Deadlock currency types
    """
    Invalid = 4294967295
    Gold = 0
    AbilityPoints = 1
    AbilityUnlocks = 2
    DeathPenaltyGold = 3
    ItemDraftRerolls = 4
    ItemEnhancements = 5
    Count = 6

class ECurrencySource(IntEnum):
    """
    Deadlock currency sources
    """
    Invalid = 4294967295
    ItemPurchase = 0
    ItemUpgrade = 1
    ItemSale = 2
    TreasureChest = 3
    AbilityPurchase = 4
    StartingAmount = 5
    LevelUp = 6
    Cheats = 7
    ResetDeathPenalty = 8
    DroppedOnDeath = 9
    HeroSwap = 10
    PlayerKill = 11
    PlayerKillAssist = 12
    BossKill = 13
    LaneTrooperKill = 14
    NeutralTrooperKill = 15
    NeutralBossKill = 16
    DeniedFromEnemy = 17
    AssassinatePlayerKill = 18
    ItemTrophyCollector = 19
    ItemCultistSacrifice = 20
    ItemGooseEgg = 21
    OrbPlayer = 22
    OrbDeny = 23
    OrbLaneTrooper = 24
    OrbNeutralTrooper = 25
    OrbTier1TrooperBoss = 26
    OrbTier2TrooperBoss = 27
    OrbBaseGuardians = 28
    OrbShrines = 29
    OrbTier3TrooperBoss = 30
    OrbDeployable = 31
    OrbTrophyKill = 32
    OrbTreasureChest = 33
    OrbSiegeTrooper = 34
    OrbSpawner = 35
    NeutralWorldPickup = 36
    BreakablePickup = 37
    PlayerKillComeback = 38
    TeamBonus = 39
    ItemDraftRerollUsed = 40
    ItemEnhancementUsed = 41
    StreetBrawlRoundReset = 42
    Count = 43

class EGameState(IntEnum):
    """
    Deadlock game states
    """
    Invalid = 0
    Init = 1
    WaitingForPlayersToJoin = 2
    HeroSelection = 3
    MatchIntro = 4
    WaitForMapToLoad = 5
    PreGameWait = 6
    GameInProgress = 7
    PostGame = 8
    PostGamePlayOfTheGame = 9
    Abandoned = 10
    End = 11

class HookResult(IntEnum):
    """
    Hook callback return value
    """
    Continue = 0
    Changed = 1
    Handled = 2
    Stop = 3


def AddServerCommand(name: str, description: str, flags: int, callback: Callable[[int, list[str]], None]) -> bool:
    """
    Register a server-console-only command

    Args:
        name (string): 
        description (string): 
        flags (int64): 
        callback (function): 

    Returns:
        bool: 

    Callback Prototype (CommandCallback):
        Args:
            playerSlot (int32): 
            args (string[]): 
    """
    ...

def AddClientCommand(name: str, description: str, flags: int, callback: Callable[[int, list[str]], None]) -> bool:
    """
    Register a client-console-only command

    Args:
        name (string): 
        description (string): 
        flags (int64): 
        callback (function): 

    Returns:
        bool: 

    Callback Prototype (CommandCallback):
        Args:
            playerSlot (int32): 
            args (string[]): 
    """
    ...

def AddChatCommand(name: str, description: str, flags: int, callback: Callable[[int, list[str]], None]) -> bool:
    """
    Register a client-chat-only command

    Args:
        name (string): 
        description (string): 
        flags (int64): 
        callback (function): 

    Returns:
        bool: 

    Callback Prototype (CommandCallback):
        Args:
            playerSlot (int32): 
            args (string[]): 
    """
    ...

def AddConsoleCommand(name: str, description: str, flags: int, callback: Callable[[int, list[str]], None]) -> bool:
    """
    Register a server/chat console command

    Args:
        name (string): 
        description (string): 
        flags (int64): 
        callback (function): 

    Returns:
        bool: 

    Callback Prototype (CommandCallback):
        Args:
            playerSlot (int32): 
            args (string[]): 
    """
    ...

def RemoveCommand(name: str) -> bool:
    """
    Unregister a console command

    Args:
        name (string): 

    Returns:
        bool: 
    """
    ...

def ServerCommand(command: str) -> None:
    """
    Execute a command on the server console

    Args:
        command (string): 
    """
    ...

def ExecuteCommandAsPlayer(playerSlot: int, command: str) -> bool:
    """
    Execute a command on behalf of a player

    Args:
        playerSlot (int32): 
        command (string): 

    Returns:
        bool: 
    """
    ...

def ClientCommand(playerSlot: int, command: str) -> None:
    """
    Execute command on client

    Args:
        playerSlot (int32): 
        command (string): 
    """
    ...

def PrintToChat(playerSlot: int, message: str) -> None:
    """
    Print message to client chat

    Args:
        playerSlot (int32): 
        message (string): 
    """
    ...

def PrintToChatAll(message: str) -> None:
    """
    Broadcast message to all players

    Args:
        message (string): 
    """
    ...

def PrintToConsole(playerSlot: int, message: str) -> None:
    """
    Print message to client console

    Args:
        playerSlot (int32): 
        message (string): 
    """
    ...

def PrintToConsoleAll(message: str) -> None:
    """
    Print message to all player consoles

    Args:
        message (string): 
    """
    ...

def GetPlayerController(playerSlot: int) -> int:
    """
    Get CBasePlayerController address for player slot

    Args:
        playerSlot (int32): 

    Returns:
        int64: 
    """
    ...

def GetPlayerPawn(playerSlot: int) -> int:
    """
    Get CCitadelPlayerPawn address for player slot

    Args:
        playerSlot (int32): 

    Returns:
        int64: 
    """
    ...

def GetPlayerSlot(controller: int) -> int:
    """
    Get player slot from controller address

    Args:
        controller (int64): 

    Returns:
        int32: 
    """
    ...

def GetPlayerName(playerSlot: int) -> str:
    """
    Get player display name

    Args:
        playerSlot (int32): 

    Returns:
        string: 
    """
    ...

def GetSteamID(playerSlot: int) -> int:
    """
    Get player 64-bit SteamID

    Args:
        playerSlot (int32): 

    Returns:
        uint64: 
    """
    ...

def IsClientAuthenticated(playerSlot: int) -> bool:
    """
    Check if player Steam ticket is validated

    Args:
        playerSlot (int32): 

    Returns:
        bool: 
    """
    ...

def IsClientConnected(playerSlot: int) -> bool:
    """
    Check if client is connected

    Args:
        playerSlot (int32): 

    Returns:
        bool: 
    """
    ...

def IsFakeClient(playerSlot: int) -> bool:
    """
    Check if player is a bot/fake client

    Args:
        playerSlot (int32): 

    Returns:
        bool: 
    """
    ...

def CreateFakeClient(name: str) -> int:
    """
    Create a fake client in the match

    Args:
        name (string): 

    Returns:
        int32: 
    """
    ...

def DisconnectClient(playerSlot: int, reason: int) -> None:
    """
    Disconnect a client with disconnection reason code

    Args:
        playerSlot (int32): 
        reason (int32): 
    """
    ...

def KickClient(playerSlot: int, reason: str, code: int) -> None:
    """
    Kick client with message and code

    Args:
        playerSlot (int32): 
        reason (string): 
        code (int32): 
    """
    ...

def ChangeTeam(controller: int, teamNum: int, keepHero: bool) -> None:
    """
    Change team of player controller

    Args:
        controller (int64): 
        teamNum (int32): 
        keepHero (bool): 
    """
    ...

def GetPlayerPing(playerSlot: int) -> int:
    """
    Get ping of player in milliseconds

    Args:
        playerSlot (int32): 

    Returns:
        int32: 
    """
    ...

def SelectHero(controller: int, heroName: str) -> None:
    """
    Select a hero for controller

    Args:
        controller (int64): 
        heroName (string): 
    """
    ...

def ResetHero(pawn: int, reset: bool) -> None:
    """
    Reset hero state on pawn

    Args:
        pawn (int64): 
        reset (bool): 
    """
    ...

def PrecacheHero(heroName: str) -> None:
    """
    Precache hero assets

    Args:
        heroName (string): 
    """
    ...

def ForceRespawn(pawn: int, releaseButtons: bool) -> None:
    """
    Force immediate hero pawn respawn

    Args:
        pawn (int64): 
        releaseButtons (bool): 
    """
    ...

def GetHeroData(heroName: str) -> int:
    """
    Lookup hero definition pointer

    Args:
        heroName (string): 

    Returns:
        int64: 
    """
    ...

def GetHeroName(pawn: int) -> str:
    """
    Get name of hero for pawn

    Args:
        pawn (int64): 

    Returns:
        string: 
    """
    ...

def AddAbility(pawn: int, abilityName: str, slot: int) -> int:
    """
    Add an ability to player pawn

    Args:
        pawn (int64): 
        abilityName (string): 
        slot (uint16): 

    Returns:
        int64: 
    """
    ...

def RemoveAbility(pawn: int, abilityName: str) -> bool:
    """
    Remove ability by name from pawn

    Args:
        pawn (int64): 
        abilityName (string): 

    Returns:
        bool: 
    """
    ...

def RemoveAbilityByEntity(pawn: int, ability: int) -> bool:
    """
    Remove ability by entity pointer

    Args:
        pawn (int64): 
        ability (int64): 

    Returns:
        bool: 
    """
    ...

def FindAbilityByName(abilityComponent: int, abilityName: str) -> int:
    """
    Find ability in ability component

    Args:
        abilityComponent (int64): 
        abilityName (string): 

    Returns:
        int64: 
    """
    ...

def GetAbilityBySlot(abilityComponent: int, slot: int) -> int:
    """
    Get ability at slot index

    Args:
        abilityComponent (int64): 
        slot (int16): 

    Returns:
        int64: 
    """
    ...

def ExecuteAbility(abilityComponent: int, ability: int, altCast: bool, flags: int) -> int:
    """
    Cast/execute an ability

    Args:
        abilityComponent (int64): 
        ability (int64): 
        altCast (bool): 
        flags (uint8): 

    Returns:
        int32: 
    """
    ...

def ToggleActivate(ability: int, activate: bool) -> None:
    """
    Toggle ability active status

    Args:
        ability (int64): 
        activate (bool): 
    """
    ...

def ResetAbilityCooldown(ability: int) -> None:
    """
    Reset ability cooldown and refill charges

    Args:
        ability (int64): 
    """
    ...

def GetAbilityMaxCharges(ability: int) -> int:
    """
    Get maximum charges of an ability

    Args:
        ability (int64): 

    Returns:
        int32: 
    """
    ...

def SetUpgradeBits(ability: int, newBits: int) -> None:
    """
    Set upgrade bits on ability

    Args:
        ability (int64): 
        newBits (int32): 
    """
    ...

def AddItem(pawn: int, itemName: str, upgradeTier: int) -> int:
    """
    Add an item to player pawn

    Args:
        pawn (int64): 
        itemName (string): 
        upgradeTier (int32): 

    Returns:
        int64: 
    """
    ...

def SellItem(pawn: int, itemName: str, fullRefund: bool, forceSellPrice: bool) -> bool:
    """
    Sell an item from pawn

    Args:
        pawn (int64): 
        itemName (string): 
        fullRefund (bool): 
        forceSellPrice (bool): 

    Returns:
        bool: 
    """
    ...

def GetItemImbueEffects(itemName: str) -> int:
    """
    Get item imbue effect flags

    Args:
        itemName (string): 

    Returns:
        int32: 
    """
    ...

def CanImbueAbility(targetAbility: int, itemName: str) -> bool:
    """
    Check if ability can receive imbue

    Args:
        targetAbility (int64): 
        itemName (string): 

    Returns:
        bool: 
    """
    ...

def ImbueAbility(item: int, targetAbility: int) -> bool:
    """
    Imbue item onto target ability

    Args:
        item (int64): 
        targetAbility (int64): 

    Returns:
        bool: 
    """
    ...

def ModifyCurrency(pawn: int, currencyType: ECurrencyType, amount: int, source: ECurrencySource, silent: bool, forceGain: bool, spendOnly: bool, sourceAbility: int, sourceEntity: int) -> None:
    """
    Modify currency (souls/gold) for player pawn

    Args:
        pawn (int64): 
        currencyType (uint32): 
        amount (int32): 
        source (uint32): 
        silent (bool): 
        forceGain (bool): 
        spendOnly (bool): 
        sourceAbility (int64): 
        sourceEntity (int64): 
    """
    ...

def GetCurrency(pawn: int, currencyType: ECurrencyType) -> int:
    """
    Get current currency value of pawn

    Args:
        pawn (int64): 
        currencyType (uint32): 

    Returns:
        int32: 
    """
    ...

def CreateTimer(interval: float, callback: Callable[[], None], repeating: bool) -> int:
    """
    Create a one-shot or repeating timer

    Args:
        interval (float): 
        callback (function): 
        repeating (bool): 

    Returns:
        int64: 

    Callback Prototype (TimerCallback):
    """
    ...

def KillTimer(timerId: int) -> bool:
    """
    Stop and delete an active timer

    Args:
        timerId (int64): 

    Returns:
        bool: 
    """
    ...

def GetConfigString(key: str, defaultValue: str) -> str:
    """
    Read string from settings.jsonc

    Args:
        key (string): 
        defaultValue (string): 

    Returns:
        string: 
    """
    ...

def GetConfigInt(key: str, defaultValue: int) -> int:
    """
    Read int from settings.jsonc

    Args:
        key (string): 
        defaultValue (int32): 

    Returns:
        int32: 
    """
    ...

def GetConfigBool(key: str, defaultValue: bool) -> bool:
    """
    Read bool from settings.jsonc

    Args:
        key (string): 
        defaultValue (bool): 

    Returns:
        bool: 
    """
    ...

def GetConfigFloat(key: str, defaultValue: float) -> float:
    """
    Read float from settings.jsonc

    Args:
        key (string): 
        defaultValue (float): 

    Returns:
        float: 
    """
    ...

def GetGameState() -> EGameState:
    """
    Get current game state enum

    Returns:
        int32: 
    """
    ...

def ChangeGameState(newState: EGameState) -> None:
    """
    Force Deadlock game state change

    Args:
        newState (int32): 
    """
    ...

def SetWaitingForPlayersRoster(readyCount: int, totalCount: int) -> None:
    """
    Set waiting for players roster counts

    Args:
        readyCount (uint32): 
        totalCount (uint32): 
    """
    ...

def SetMatchStartOnAnyMap(enabled: bool) -> None:
    """
    Enable/disable match start sequence on custom maps

    Args:
        enabled (bool): 
    """
    ...

def GetMatchStartOnAnyMap() -> bool:
    """
    Check if match start on custom maps is enabled

    Returns:
        bool: 
    """
    ...

def RegisterGameEvent(name: str) -> None:
    """
    Register game event listener for engine event

    Args:
        name (string): 
    """
    ...

def CreateGameEvent(name: str, force: bool) -> int:
    """
    Create a new game event

    Args:
        name (string): 
        force (bool): 

    Returns:
        int64: 
    """
    ...

def FireGameEvent(event: int, dontBroadcast: bool) -> bool:
    """
    Fire game event

    Args:
        event (int64): 
        dontBroadcast (bool): 

    Returns:
        bool: 
    """
    ...

def FreeGameEvent(event: int) -> None:
    """
    Free game event object

    Args:
        event (int64): 
    """
    ...

def GameEventGetBool(event: int, key: str, def_: bool) -> bool:
    """
    Get boolean key from game event

    Args:
        event (int64): 
        key (string): 
        def_ (bool): 

    Returns:
        bool: 
    """
    ...

def GameEventGetInt(event: int, key: str, def_: int) -> int:
    """
    Get int32 key from game event

    Args:
        event (int64): 
        key (string): 
        def_ (int32): 

    Returns:
        int32: 
    """
    ...

def GameEventGetFloat(event: int, key: str, def_: float) -> float:
    """
    Get float key from game event

    Args:
        event (int64): 
        key (string): 
        def_ (float): 

    Returns:
        float: 
    """
    ...

def GameEventGetString(event: int, key: str, def_: str) -> str:
    """
    Get string key from game event

    Args:
        event (int64): 
        key (string): 
        def_ (string): 

    Returns:
        string: 
    """
    ...

def GameEventGetUint64(event: int, key: str, def_: int) -> int:
    """
    Get uint64 key from game event

    Args:
        event (int64): 
        key (string): 
        def_ (uint64): 

    Returns:
        uint64: 
    """
    ...

def GameEventSetBool(event: int, key: str, val: bool) -> None:
    """
    Set boolean key in game event

    Args:
        event (int64): 
        key (string): 
        val (bool): 
    """
    ...

def GameEventSetInt(event: int, key: str, val: int) -> None:
    """
    Set int32 key in game event

    Args:
        event (int64): 
        key (string): 
        val (int32): 
    """
    ...

def GameEventSetFloat(event: int, key: str, val: float) -> None:
    """
    Set float key in game event

    Args:
        event (int64): 
        key (string): 
        val (float): 
    """
    ...

def GameEventSetString(event: int, key: str, val: str) -> None:
    """
    Set string key in game event

    Args:
        event (int64): 
        key (string): 
        val (string): 
    """
    ...

def GameEventGetPlayerSlot(event: int, key: str) -> int:
    """
    Gets player slot from an event key (e.g. userid)

    Args:
        event (int64): 
        key (string): 

    Returns:
        int32: 
    """
    ...

def GameEventGetPlayerPawn(event: int, key: str) -> int:
    """
    Gets player pawn pointer from an event key (e.g. userid)

    Args:
        event (int64): 
        key (string): 

    Returns:
        int64: 
    """
    ...

def GameEventGetPlayerController(event: int, key: str) -> int:
    """
    Gets player controller pointer from an event key (e.g. userid)

    Args:
        event (int64): 
        key (string): 

    Returns:
        int64: 
    """
    ...

def GetMapName() -> str:
    """
    Get currently loaded map name

    Returns:
        string: 
    """
    ...

def IsMapValid(map: str) -> bool:
    """
    Check if map exists and can be loaded

    Args:
        map (string): 

    Returns:
        bool: 
    """
    ...

def SetServerKeyValue(key: str, value: str) -> bool:
    """
    Set Steam A2S rule key-value

    Args:
        key (string): 
        value (string): 

    Returns:
        bool: 
    """
    ...

def ClearServerKeyValues() -> bool:
    """
    Clear Steam A2S rules

    Returns:
        bool: 
    """
    ...

def SetServerAddons(addons: str) -> None:
    """
    Set active server workshop addons

    Args:
        addons (string): 
    """
    ...

def AddFileSystemSearchPath(path: str, pathId: str, addType: int) -> bool:
    """
    Add file search path

    Args:
        path (string): 
        pathId (string): 
        addType (int32): 

    Returns:
        bool: 
    """
    ...

def HasCommandLineParm(parm: str) -> bool:
    """
    Check if command line argument exists

    Args:
        parm (string): 

    Returns:
        bool: 
    """
    ...

def SetConnectRejectReason(reason: str) -> None:
    """
    Set reject reason for connection rejection

    Args:
        reason (string): 
    """
    ...

def GetGlobalVars() -> int:
    """
    Get CGlobalVars pointer

    Returns:
        int64: 
    """
    ...

def GetGameTime() -> float:
    """
    Get current engine game time in seconds

    Returns:
        float: 
    """
    ...

def GetGameTickCount() -> int:
    """
    Get current engine tick count

    Returns:
        int32: 
    """
    ...

def FindConVar(name: str) -> int:
    """
    Find ConVar by name

    Args:
        name (string): 

    Returns:
        uint64: 
    """
    ...

def CreateConVar(name: str, defaultValue: str, description: str, flags: int) -> int:
    """
    Create custom ConVar

    Args:
        name (string): 
        defaultValue (string): 
        description (string): 
        flags (uint64): 

    Returns:
        uint64: 
    """
    ...

def GetConVarInt(handle: int) -> int:
    """
    Get ConVar integer value

    Args:
        handle (uint64): 

    Returns:
        int32: 
    """
    ...

def GetConVarFloat(handle: int) -> float:
    """
    Get ConVar float value

    Args:
        handle (uint64): 

    Returns:
        float: 
    """
    ...

def GetConVarString(handle: int) -> str:
    """
    Get ConVar string value

    Args:
        handle (uint64): 

    Returns:
        string: 
    """
    ...

def GetConVarBool(handle: int) -> bool:
    """
    Get ConVar bool value

    Args:
        handle (uint64): 

    Returns:
        bool: 
    """
    ...

def SetConVarInt(handle: int, value: int) -> None:
    """
    Set ConVar int value

    Args:
        handle (uint64): 
        value (int32): 
    """
    ...

def SetConVarFloat(handle: int, value: float) -> None:
    """
    Set ConVar float value

    Args:
        handle (uint64): 
        value (float): 
    """
    ...

def SetConVarString(handle: int, value: str) -> bool:
    """
    Set ConVar string value

    Args:
        handle (uint64): 
        value (string): 

    Returns:
        bool: 
    """
    ...

def CreateDamageInfo(inflictor: int, attacker: int, ability: int, damage: float, damageType: int) -> int:
    """
    Create CTakeDamageInfo instance

    Args:
        inflictor (int64): 
        attacker (int64): 
        ability (int64): 
        damage (float): 
        damageType (int32): 

    Returns:
        int64: 
    """
    ...

def DestroyDamageInfo(info: int) -> None:
    """
    Free CTakeDamageInfo instance

    Args:
        info (int64): 
    """
    ...

def TakeDamage(victim: int, info: int) -> None:
    """
    Inflict damage on victim entity

    Args:
        victim (int64): 
        info (int64): 
    """
    ...

def ApplyDamage(victim: int, info: int) -> None:
    """
    Apply damage bypassing damage filters

    Args:
        victim (int64): 
        info (int64): 
    """
    ...

def GetMaxHealth(entity: int) -> int:
    """
    Get maximum health of entity

    Args:
        entity (int64): 

    Returns:
        int32: 
    """
    ...

def Heal(entity: int, amount: float) -> int:
    """
    Heal entity by amount

    Args:
        entity (int64): 
        amount (float): 

    Returns:
        int32: 
    """
    ...

def AddModifier(entity: int, modifierName: str, kv3: int, caster: int, ability: int, team: int) -> int:
    """
    Add modifier to entity

    Args:
        entity (int64): 
        modifierName (string): 
        kv3 (int64): 
        caster (int64): 
        ability (int64): 
        team (int32): 

    Returns:
        int64: 
    """
    ...

def RemoveModifier(entity: int, modifier: int) -> bool:
    """
    Remove modifier instance from entity

    Args:
        entity (int64): 
        modifier (int64): 

    Returns:
        bool: 
    """
    ...

def CreateEntityByName(className: str) -> int:
    """
    Create entity instance by class name

    Args:
        className (string): 

    Returns:
        int64: 
    """
    ...

def QueueSpawnEntity(entity: int, ekv: int) -> None:
    """
    Queue entity spawn with optional entity keyvalues

    Args:
        entity (int64): 
        ekv (int64): 
    """
    ...

def ExecuteQueuedCreation() -> None:
    """
    Execute queued entity creation
    """
    ...

def RemoveEntity(entity: int) -> None:
    """
    Remove/destroy entity

    Args:
        entity (int64): 
    """
    ...

def GetEntityByIndex(index: int) -> int:
    """
    Get entity pointer by index

    Args:
        index (int32): 

    Returns:
        int64: 
    """
    ...

def GetEntityFromHandle(handle: int) -> int:
    """
    Resolve entity pointer from uint32 handle

    Args:
        handle (uint32): 

    Returns:
        int64: 
    """
    ...

def GetEntityHandle(entity: int) -> int:
    """
    Get handle of entity

    Args:
        entity (int64): 

    Returns:
        uint32: 
    """
    ...

def FindEntityByName(startEntity: int, name: str) -> int:
    """
    Find entity by name

    Args:
        startEntity (int64): 
        name (string): 

    Returns:
        int64: 
    """
    ...

def GetEntityDesignerName(entity: int) -> str:
    """
    Get designer name of entity

    Args:
        entity (int64): 

    Returns:
        string: 
    """
    ...

def GetEntityClassname(entity: int) -> str:
    """
    Get class name of entity

    Args:
        entity (int64): 

    Returns:
        string: 
    """
    ...

def Teleport(entity: int, posX: float, posY: float, posZ: float, angPitch: float, angYaw: float, angRoll: float, velX: float, velY: float, velZ: float) -> None:
    """
    Teleport entity with position, angles and velocity

    Args:
        entity (int64): 
        posX (float): 
        posY (float): 
        posZ (float): 
        angPitch (float): 
        angYaw (float): 
        angRoll (float): 
        velX (float): 
        velY (float): 
        velZ (float): 
    """
    ...

def SetModel(entity: int, modelName: str) -> None:
    """
    Set visual model of entity

    Args:
        entity (int64): 
        modelName (string): 
    """
    ...

def GetModelName(entity: int) -> str:
    """
    Get model name of entity

    Args:
        entity (int64): 

    Returns:
        string: 
    """
    ...

def SetScale(entity: int, scale: float) -> None:
    """
    Set visual scale of entity

    Args:
        entity (int64): 
        scale (float): 
    """
    ...

def SetMoveType(entity: int, moveType: int) -> None:
    """
    Set entity move type

    Args:
        entity (int64): 
        moveType (uint8): 
    """
    ...

def SetGravityScale(entity: int, scale: float) -> None:
    """
    Set entity gravity multiplier

    Args:
        entity (int64): 
        scale (float): 
    """
    ...

def EntityDerivesFrom(entity: int, baseClassName: str) -> bool:
    """
    Check if entity class derives from base class name

    Args:
        entity (int64): 
        baseClassName (string): 

    Returns:
        bool: 
    """
    ...

def GetSchemaFieldOffset(className: str, fieldName: str) -> int:
    """
    Get byte offset of class field in schema

    Args:
        className (string): 
        fieldName (string): 

    Returns:
        int32: 
    """
    ...

def NotifyStateChanged(entity: int, fieldOffset: int, chainOffset: int, networkStateChangedOffset: int) -> None:
    """
    Notify network system of field modification

    Args:
        entity (int64): 
        fieldOffset (int32): 
        chainOffset (int16): 
        networkStateChangedOffset (int32): 
    """
    ...

def SetSchemaString(entity: int, className: str, fieldName: str, value: str) -> None:
    """
    Set string field in schema structure

    Args:
        entity (int64): 
        className (string): 
        fieldName (string): 
        value (string): 
    """
    ...

def GetSchemaClassSize(className: str) -> int:
    """
    Get sizeof schema class

    Args:
        className (string): 

    Returns:
        int32: 
    """
    ...

def EmitSound(entity: int, soundName: str, pitch: int, volume: float, delay: float) -> None:
    """
    Emit sound event from entity

    Args:
        entity (int64): 
        soundName (string): 
        pitch (int32): 
        volume (float): 
        delay (float): 
    """
    ...

def TakeSoundEventGuid() -> int:
    """
    Generate unique sound event GUID

    Returns:
        uint32: 
    """
    ...

def CreateParticle(particleName: str, attachType: int, entity: int) -> int:
    """
    Create and dispatch particle effect

    Args:
        particleName (string): 
        attachType (int32): 
        entity (int64): 

    Returns:
        int64: 
    """
    ...

def DestroyParticle(particle: int, destroyImmediately: bool) -> None:
    """
    Destroy active particle instance

    Args:
        particle (int64): 
        destroyImmediately (bool): 
    """
    ...

def PrecacheResource(path: str) -> None:
    """
    Precache resource by VPK path

    Args:
        path (string): 
    """
    ...

def PrecacheModel(modelPath: str) -> None:
    """
    Precache model resource

    Args:
        modelPath (string): 
    """
    ...

def CreateWorldText(message: str, x: float, y: float, z: float, fontSize: float, r: int, g: int, b: int, a: int) -> int:
    """
    Create 3D point_worldtext entity in the world

    Args:
        message (string): 
        x (float): 
        y (float): 
        z (float): 
        fontSize (float): 
        r (uint8): 
        g (uint8): 
        b (uint8): 
        a (uint8): 

    Returns:
        int64: 
    """
    ...

def SetWorldTextMessage(worldText: int, text: str) -> None:
    """
    Update message text of CPointWorldText

    Args:
        worldText (int64): 
        text (string): 
    """
    ...

def CreateBeam(startX: float, startY: float, startZ: float, endX: float, endY: float, endZ: float, width: float, r: int, g: int, b: int, a: int) -> int:
    """
    Spawn a glowing laser beam entity between two world points

    Args:
        startX (float): 
        startY (float): 
        startZ (float): 
        endX (float): 
        endY (float): 
        endZ (float): 
        width (float): 
        r (uint8): 
        g (uint8): 
        b (uint8): 
        a (uint8): 

    Returns:
        int64: 
    """
    ...

def CreateZone(name: str, minX: float, minY: float, minZ: float, maxX: float, maxY: float, maxZ: float) -> int:
    """
    Create a spatial trigger volume box

    Args:
        name (string): 
        minX (float): 
        minY (float): 
        minZ (float): 
        maxX (float): 
        maxY (float): 
        maxZ (float): 

    Returns:
        int64: 
    """
    ...

def DestroyZone(zoneId: int) -> None:
    """
    Destroy a spatial zone trigger

    Args:
        zoneId (int64): 
    """
    ...

def LineTrace(startX: float, startY: float, startZ: float, endX: float, endY: float, endZ: float, mask: int, ignoreEntity: int) -> bool:
    """
    Perform physics raycast trace between start and end vectors

    Args:
        startX (float): 
        startY (float): 
        startZ (float): 
        endX (float): 
        endY (float): 
        endZ (float): 
        mask (uint32): 
        ignoreEntity (int64): 

    Returns:
        bool: 
    """
    ...

def NpcMoveTo(npc: int, x: float, y: float, z: float, run: bool, tolerance: float) -> None:
    """
    Direct AI NPC to move to goal location

    Args:
        npc (int64): 
        x (float): 
        y (float): 
        z (float): 
        run (bool): 
        tolerance (float): 
    """
    ...

def NpcStopMoving(npc: int, instant: bool) -> None:
    """
    Stop movement of AI NPC

    Args:
        npc (int64): 
        instant (bool): 
    """
    ...

def NpcSetEnemy(npc: int, enemy: int) -> None:
    """
    Set target enemy entity of AI NPC

    Args:
        npc (int64): 
        enemy (int64): 
    """
    ...

def NpcSetState(npc: int, state: int) -> None:
    """
    Set NPC AI state

    Args:
        npc (int64): 
        state (int32): 
    """
    ...

def NpcCreateTrooper(posX: float, posY: float, posZ: float, pitch: float, yaw: float, roll: float, team: int, type: int, variant: int, snapToGround: bool) -> int:
    """
    Spawn lane or neutral trooper NPC

    Args:
        posX (float): 
        posY (float): 
        posZ (float): 
        pitch (float): 
        yaw (float): 
        roll (float): 
        team (int32): 
        type (int32): 
        variant (int32): 
        snapToGround (bool): 

    Returns:
        int64: 
    """
    ...

def NavGetNearestPoint(x: float, y: float, z: float, maxDistance: float, hull: int) -> bool:
    """
    Find nearest point on navmesh

    Args:
        x (float): 
        y (float): 
        z (float): 
        maxDistance (float): 
        hull (int32): 

    Returns:
        bool: 
    """
    ...

def NavGetGroundHeight(x: float, y: float, z: float, maxDistance: float, hull: int) -> float:
    """
    Get ground elevation from navmesh

    Args:
        x (float): 
        y (float): 
        z (float): 
        maxDistance (float): 
        hull (int32): 

    Returns:
        float: 
    """
    ...

def BotCreate(heroName: str, team: int, posX: float, posY: float, posZ: float, assignLane: bool) -> int:
    """
    Spawn a bot hero into the match

    Args:
        heroName (string): 
        team (int32): 
        posX (float): 
        posY (float): 
        posZ (float): 
        assignLane (bool): 

    Returns:
        int64: 
    """
    ...

def BotGetBrain(pawn: int) -> int:
    """
    Get brain entity pointer for player bot pawn

    Args:
        pawn (int64): 

    Returns:
        int64: 
    """
    ...

def BotGetPawn(brain: int) -> int:
    """
    Get pawn entity controlled by bot brain

    Args:
        brain (int64): 

    Returns:
        int64: 
    """
    ...

def BotSetLane(pawn: int, lane: int) -> bool:
    """
    Assign lane index to bot

    Args:
        pawn (int64): 
        lane (int32): 

    Returns:
        bool: 
    """
    ...

def BotGetLane(pawn: int) -> int:
    """
    Get assigned lane index of bot

    Args:
        pawn (int64): 

    Returns:
        int32: 
    """
    ...

def AcceptInput(entity: int, inputName: str, activator: int, caller: int, value: str) -> None:
    """
    Fire input on target entity

    Args:
        entity (int64): 
        inputName (string): 
        activator (int64): 
        caller (int64): 
        value (string): 
    """
    ...

def SendNetMessage(msgId: int, protoBytes: list[int], recipientMask: int, bufType: int) -> None:
    """
    Send protobuf network message to clients

    Args:
        msgId (int32): 
        protoBytes (uint8[]): 
        recipientMask (uint64): 
        bufType (int32): 
    """
    ...

def GetNetMessageName(msgId: int) -> str:
    """
    Get registered network message name

    Args:
        msgId (int32): 

    Returns:
        string: 
    """
    ...

def KV3Create() -> int:
    """
    Allocate new KeyValues3 document

    Returns:
        int64: 
    """
    ...

def KV3Destroy(kv3: int) -> None:
    """
    Free KeyValues3 document

    Args:
        kv3 (int64): 
    """
    ...

def KV3SetString(kv3: int, key: str, value: str) -> None:
    """
    Set string value in KeyValues3 document

    Args:
        kv3 (int64): 
        key (string): 
        value (string): 
    """
    ...

def KV3SetBool(kv3: int, key: str, value: bool) -> None:
    """
    Set bool value in KeyValues3 document

    Args:
        kv3 (int64): 
        key (string): 
        value (bool): 
    """
    ...

def KV3SetInt(kv3: int, key: str, value: int) -> None:
    """
    Set int32 value in KeyValues3 document

    Args:
        kv3 (int64): 
        key (string): 
        value (int32): 
    """
    ...

def KV3SetFloat(kv3: int, key: str, value: float) -> None:
    """
    Set float value in KeyValues3 document

    Args:
        kv3 (int64): 
        key (string): 
        value (float): 
    """
    ...

def OnModifyCurrency_Register(callback: Callable[[int, ECurrencyType, int, ECurrencySource, bool, bool, bool, int, int], HookResult]) -> None:
    """
    Register Currency modification listener hook

    Args:
        callback (function): 

    Callback Prototype (ModifyCurrencyCallback):
        Args:
            pawn (int64): 
            currencyType (uint32): 
            amount (int32): 
            source (uint32): 
            silent (bool): 
            forceGain (bool): 
            spendOnly (bool): 
            sourceAbility (int64): 
            sourceEntity (int64): 

        Returns:
            int32: 
    """
    ...

def OnModifyCurrency_Unregister(callback: Callable[[int, ECurrencyType, int, ECurrencySource, bool, bool, bool, int, int], HookResult]) -> None:
    """
    Unregister Currency modification listener hook

    Args:
        callback (function): 

    Callback Prototype (ModifyCurrencyCallback):
        Args:
            pawn (int64): 
            currencyType (uint32): 
            amount (int32): 
            source (uint32): 
            silent (bool): 
            forceGain (bool): 
            spendOnly (bool): 
            sourceAbility (int64): 
            sourceEntity (int64): 

        Returns:
            int32: 
    """
    ...

def OnTakeDamage_Register(callback: Callable[[int, int], HookResult]) -> None:
    """
    Register Entity take damage listener hook

    Args:
        callback (function): 

    Callback Prototype (TakeDamageCallback):
        Args:
            victim (int64): 
            damageInfo (int64): 

        Returns:
            int32: 
    """
    ...

def OnTakeDamage_Unregister(callback: Callable[[int, int], HookResult]) -> None:
    """
    Unregister Entity take damage listener hook

    Args:
        callback (function): 

    Callback Prototype (TakeDamageCallback):
        Args:
            victim (int64): 
            damageInfo (int64): 

        Returns:
            int32: 
    """
    ...

def OnClientConnect_Register(callback: Callable[[int, str, int], bool]) -> None:
    """
    Register Client connection listener hook

    Args:
        callback (function): 

    Callback Prototype (ClientConnectCallback):
        Args:
            playerSlot (int32): 
            name (string): 
            steamId (uint64): 

        Returns:
            bool: 
    """
    ...

def OnClientConnect_Unregister(callback: Callable[[int, str, int], bool]) -> None:
    """
    Unregister Client connection listener hook

    Args:
        callback (function): 

    Callback Prototype (ClientConnectCallback):
        Args:
            playerSlot (int32): 
            name (string): 
            steamId (uint64): 

        Returns:
            bool: 
    """
    ...

def OnClientPutInServer_Register(callback: Callable[[int], None]) -> None:
    """
    Register Client put in server listener hook

    Args:
        callback (function): 

    Callback Prototype (ClientPutInServerCallback):
        Args:
            playerSlot (int32): 
    """
    ...

def OnClientPutInServer_Unregister(callback: Callable[[int], None]) -> None:
    """
    Unregister Client put in server listener hook

    Args:
        callback (function): 

    Callback Prototype (ClientPutInServerCallback):
        Args:
            playerSlot (int32): 
    """
    ...

def OnClientDisconnect_Register(callback: Callable[[int, int], None]) -> None:
    """
    Register Client disconnect listener hook

    Args:
        callback (function): 

    Callback Prototype (ClientDisconnectCallback):
        Args:
            playerSlot (int32): 
            reason (int32): 
    """
    ...

def OnClientDisconnect_Unregister(callback: Callable[[int, int], None]) -> None:
    """
    Unregister Client disconnect listener hook

    Args:
        callback (function): 

    Callback Prototype (ClientDisconnectCallback):
        Args:
            playerSlot (int32): 
            reason (int32): 
    """
    ...

def OnGameFrame_Register(callback: Callable[[bool, bool, bool], None]) -> None:
    """
    Register Server game tick frame listener hook

    Args:
        callback (function): 

    Callback Prototype (GameFrameCallback):
        Args:
            simulating (bool): 
            firstTick (bool): 
            lastTick (bool): 
    """
    ...

def OnGameFrame_Unregister(callback: Callable[[bool, bool, bool], None]) -> None:
    """
    Unregister Server game tick frame listener hook

    Args:
        callback (function): 

    Callback Prototype (GameFrameCallback):
        Args:
            simulating (bool): 
            firstTick (bool): 
            lastTick (bool): 
    """
    ...

def OnEntityCreated_Register(callback: Callable[[int], None]) -> None:
    """
    Register Entity created listener hook

    Args:
        callback (function): 

    Callback Prototype (EntityCallback):
        Args:
            entity (int64): 
    """
    ...

def OnEntityCreated_Unregister(callback: Callable[[int], None]) -> None:
    """
    Unregister Entity created listener hook

    Args:
        callback (function): 

    Callback Prototype (EntityCallback):
        Args:
            entity (int64): 
    """
    ...

def OnEntitySpawned_Register(callback: Callable[[int], None]) -> None:
    """
    Register Entity spawned listener hook

    Args:
        callback (function): 

    Callback Prototype (EntityCallback):
        Args:
            entity (int64): 
    """
    ...

def OnEntitySpawned_Unregister(callback: Callable[[int], None]) -> None:
    """
    Unregister Entity spawned listener hook

    Args:
        callback (function): 

    Callback Prototype (EntityCallback):
        Args:
            entity (int64): 
    """
    ...

def OnEntityDeleted_Register(callback: Callable[[int], None]) -> None:
    """
    Register Entity deleted listener hook

    Args:
        callback (function): 

    Callback Prototype (EntityCallback):
        Args:
            entity (int64): 
    """
    ...

def OnEntityDeleted_Unregister(callback: Callable[[int], None]) -> None:
    """
    Unregister Entity deleted listener hook

    Args:
        callback (function): 

    Callback Prototype (EntityCallback):
        Args:
            entity (int64): 
    """
    ...

def OnGameStateChanged_Register(callback: Callable[[EGameState], None]) -> None:
    """
    Register Game state change listener hook

    Args:
        callback (function): 

    Callback Prototype (GameStateChangedCallback):
        Args:
            newState (int32): 
    """
    ...

def OnGameStateChanged_Unregister(callback: Callable[[EGameState], None]) -> None:
    """
    Unregister Game state change listener hook

    Args:
        callback (function): 

    Callback Prototype (GameStateChangedCallback):
        Args:
            newState (int32): 
    """
    ...

def OnEntityAcceptInput_Register(callback: Callable[[str, str, int, int, int, str], HookResult]) -> None:
    """
    Register Entity AcceptInput listener hook

    Args:
        callback (function): 

    Callback Prototype (EntityIOCallback):
        Args:
            className (string): 
            inputName (string): 
            entity (int64): 
            activator (int64): 
            caller (int64): 
            value (string): 

        Returns:
            int32: 
    """
    ...

def OnEntityAcceptInput_Unregister(callback: Callable[[str, str, int, int, int, str], HookResult]) -> None:
    """
    Unregister Entity AcceptInput listener hook

    Args:
        callback (function): 

    Callback Prototype (EntityIOCallback):
        Args:
            className (string): 
            inputName (string): 
            entity (int64): 
            activator (int64): 
            caller (int64): 
            value (string): 

        Returns:
            int32: 
    """
    ...

def OnNpcSelectSchedule_Register(callback: Callable[[int, str], str]) -> None:
    """
    Register NPC schedule selection listener hook

    Args:
        callback (function): 

    Callback Prototype (NpcSelectScheduleCallback):
        Args:
            npc (int64): 
            chosenId (string): 

        Returns:
            string: 
    """
    ...

def OnNpcSelectSchedule_Unregister(callback: Callable[[int, str], str]) -> None:
    """
    Unregister NPC schedule selection listener hook

    Args:
        callback (function): 

    Callback Prototype (NpcSelectScheduleCallback):
        Args:
            npc (int64): 
            chosenId (string): 

        Returns:
            string: 
    """
    ...

def OnEntityFireOutput_Register(callback: Callable[[str, str, int, int, float], HookResult]) -> None:
    """
    Register Entity FireOutput listener hook

    Args:
        callback (function): 

    Callback Prototype (EntityOutputCallback):
        Args:
            callerClass (string): 
            outputName (string): 
            activator (int64): 
            caller (int64): 
            delay (float): 

        Returns:
            int32: 
    """
    ...

def OnEntityFireOutput_Unregister(callback: Callable[[str, str, int, int, float], HookResult]) -> None:
    """
    Unregister Entity FireOutput listener hook

    Args:
        callback (function): 

    Callback Prototype (EntityOutputCallback):
        Args:
            callerClass (string): 
            outputName (string): 
            activator (int64): 
            caller (int64): 
            delay (float): 

        Returns:
            int32: 
    """
    ...

def OnProcessUsercmds_Register(callback: Callable[[int, int, bool], None]) -> None:
    """
    Register CBasePlayerController::ProcessUsercmds listener hook

    Args:
        callback (function): 

    Callback Prototype (ProcessUsercmdsCallback):
        Args:
            playerSlot (int32): 
            numCmds (int32): 
            paused (bool): 
    """
    ...

def OnProcessUsercmds_Unregister(callback: Callable[[int, int, bool], None]) -> None:
    """
    Unregister CBasePlayerController::ProcessUsercmds listener hook

    Args:
        callback (function): 

    Callback Prototype (ProcessUsercmdsCallback):
        Args:
            playerSlot (int32): 
            numCmds (int32): 
            paused (bool): 
    """
    ...

def OnAbilityThink_Register(callback: Callable[[int, int], None]) -> None:
    """
    Register CCitadelPlayerPawn::AbilityThink listener hook

    Args:
        callback (function): 

    Callback Prototype (AbilityThinkCallback):
        Args:
            playerSlot (int32): 
            pawn (int64): 
    """
    ...

def OnAbilityThink_Unregister(callback: Callable[[int, int], None]) -> None:
    """
    Unregister CCitadelPlayerPawn::AbilityThink listener hook

    Args:
        callback (function): 

    Callback Prototype (AbilityThinkCallback):
        Args:
            playerSlot (int32): 
            pawn (int64): 
    """
    ...

def OnAddModifier_Register(callback: Callable[[int, int, int, int], HookResult]) -> None:
    """
    Register CModifierProperty::AddModifier listener hook

    Args:
        callback (function): 

    Callback Prototype (AddModifierCallback):
        Args:
            modifierProp (int64): 
            caster (int64): 
            ability (uint32): 
            team (int32): 

        Returns:
            int32: 
    """
    ...

def OnAddModifier_Unregister(callback: Callable[[int, int, int, int], HookResult]) -> None:
    """
    Unregister CModifierProperty::AddModifier listener hook

    Args:
        callback (function): 

    Callback Prototype (AddModifierCallback):
        Args:
            modifierProp (int64): 
            caster (int64): 
            ability (uint32): 
            team (int32): 

        Returns:
            int32: 
    """
    ...

def OnHeroInitialized_Register(callback: Callable[[int], None]) -> None:
    """
    Register CCitadelPlayerPawn::InitializeHeroOnPawn listener hook

    Args:
        callback (function): 

    Callback Prototype (HeroInitializedCallback):
        Args:
            pawn (int64): 
    """
    ...

def OnHeroInitialized_Unregister(callback: Callable[[int], None]) -> None:
    """
    Unregister CCitadelPlayerPawn::InitializeHeroOnPawn listener hook

    Args:
        callback (function): 

    Callback Prototype (HeroInitializedCallback):
        Args:
            pawn (int64): 
    """
    ...

def OnGameEvent_Register(callback: Callable[[str, int], None]) -> None:
    """
    Register game event listener hook (e.g. player_death, player_respawned)

    Args:
        callback (function): 

    Callback Prototype (GameEventCallback):
        Args:
            eventName (string): 
            event (int64): 
    """
    ...

def OnGameEvent_Unregister(callback: Callable[[str, int], None]) -> None:
    """
    Unregister game event listener hook

    Args:
        callback (function): 

    Callback Prototype (GameEventCallback):
        Args:
            eventName (string): 
            event (int64): 
    """
    ...

def HudAnnounce(playerSlot: int, title: str, description: str, duration: float) -> None:
    """
    Display a HUD game announcement banner to a player

    Args:
        playerSlot (int32): 
        title (string): 
        description (string): 
        duration (float): 
    """
    ...

def HudAnnounceAll(title: str, description: str, duration: float) -> None:
    """
    Display a HUD game announcement banner to all players

    Args:
        title (string): 
        description (string): 
        duration (float): 
    """
    ...

