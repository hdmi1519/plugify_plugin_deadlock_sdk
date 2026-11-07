// Generated from dsdk.pplugin

declare module "plugify" {
  /** Represents a plugin with metadata information. */
  type Plugin = {
    /** Unique identifier for the plugin */
    id: bigint;
    /** Name of the plugin */
    name: string;
    /** Description of the plugin */
    description: string;
    /** Version of the plugin */
    version: string;
    /** Author of the plugin */
    author: string;
    /** Website of the plugin */
    website: string;
    /** Software license of the plugin */
    license: string;
    /** Installation location of the plugin */
    location: string;
    /** List of plugin dependencies */
    dependencies: string[];
    /** Base directory where plugin files reside */
    base_dir: string;
    /** Directory for plugin extensions */
    extensions_dir: string;
    /** Directory for configuration files */
    configs_dir: string;
    /** Directory for plugin data files */
    data_dir: string;
    /** Directory for log files */
    logs_dir: string;
    /** Directory for cached files */
    cache_dir: string;
  };

  /** Represents a 2D vector with mathematical operations. */
  export type Vector2 = {
    /** X-coordinate of the vector */
    x: number;
    /** Y-coordinate of the vector */
    y: number;
    /** Adds another Vector2 to this vector */
    add(vector: Vector2): Vector2;
    /** Subtracts another Vector2 from this vector */
    subtract(vector: Vector2): Vector2;
    /** Scales this vector by a scalar */
    scale(scalar: number): Vector2;
    /** Returns the magnitude (length) of the vector */
    magnitude(): number;
    /** Returns a normalized (unit length) version of this vector */
    normalize(): Vector2;
    /** Returns the dot product with another Vector2 */
    dot(vector: Vector2): number;
    /** Computes the distance between this vector and another Vector2 */
    distanceTo(vector: Vector2): number;
    /** Converts vector to string */
    toString(): string;
  };

  export namespace Vector2 {
    /** Returns a zero vector (0, 0). */
    function zero(): Vector2;
    /** Returns a unit vector (1, 1). */
    function unit(): Vector2;
  }

  /** Represents a 3D vector with mathematical operations. */
  export type Vector3 = {
    /** X-coordinate of the vector */
    x: number;
    /** Y-coordinate of the vector */
    y: number;
    /** Z-coordinate of the vector */
    z: number;
    /** Adds another Vector3 to this vector */
    add(vector: Vector3): Vector3;
    /** Subtracts another Vector3 from this vector */
    subtract(vector: Vector3): Vector3;
    /** Scales this vector by a scalar */
    scale(scalar: number): Vector3;
    /** Returns the magnitude (length) of the vector */
    magnitude(): number;
    /** Returns a normalized (unit length) version of this vector */
    normalize(): Vector3;
    /** Returns the dot product with another Vector3 */
    dot(vector: Vector3): number;
    /** Computes the cross product with another Vector3 */
    cross(vector: Vector3): Vector3;
    /** Computes the distance between this vector and another Vector3 */
    distanceTo(vector: Vector3): number;
    /** Converts vector to string */
    toString(): string;
  };

  export namespace Vector3 {
    /** Returns a zero vector (0, 0, 0). */
    function zero(): Vector3;
    /** Returns a unit vector (1, 1, 1). */
    function unit(): Vector3;
  }

  /** Represents a 4D vector with mathematical operations. */
  export type Vector4 = {
    /** X-coordinate of the vector */
    x: number;
    /** Y-coordinate of the vector */
    y: number;
    /** Z-coordinate of the vector */
    z: number;
    /** W-coordinate of the vector */
    w: number;
    /** Adds another Vector4 to this vector */
    add(vector: Vector4): Vector4;
    /** Subtracts another Vector4 from this vector */
    subtract(vector: Vector4): Vector4;
    /** Scales this vector by a scalar */
    scale(scalar: number): Vector4;
    /** Returns the magnitude (length) of the vector */
    magnitude(): number;
    /** Returns a normalized (unit length) version of this vector */
    normalize(): Vector4;
    /** Returns the dot product with another Vector4 */
    dot(vector: Vector4): number;
    /** Computes the distance between this vector and another Vector4 */
    distanceTo(vector: Vector4): number;
    /** Converts vector to string */
    toString(): string;
  };

  export namespace Vector4 {
    /** Returns a zero vector (0, 0, 0, 0). */
    function zero(): Vector4;
    /** Returns a unit vector (1, 1, 1, 1). */
    function unit(): Vector4;
  }

  /** Represents a 4x4 matrix with transformation operations. */
  export type Matrix4x4 = {
    /** Matrix elements stored as a 2D array */
    m: number[][];
    /** Adds another matrix to this matrix */
    add(matrix: Matrix4x4): Matrix4x4;
    /** Subtracts another matrix from this matrix */
    subtract(matrix: Matrix4x4): Matrix4x4;
    /** Multiplies this matrix with another matrix */
    multiply(matrix: Matrix4x4): Matrix4x4;
    /** Multiplies this matrix with a Vector4 */
    multiplyVector(vector: Vector4): Vector4;
    /** Returns the transpose of this matrix */
    transpose(): Matrix4x4;
    /** Returns a string representation of the matrix */
    toString(): string;
  };

  export namespace Matrix4x4 {
    /** Returns an identity matrix. */
    function identity(): Matrix4x4;
    /** Returns a zero matrix (all values set to 0). */
    function zero(): Matrix4x4;
    /** Creates a scaling matrix with scale factors for each axis. */
    function scaling(sx: number, sy: number, sz: number): Matrix4x4;
    /** Creates a translation matrix using given translation values. */
    function translation(tx: number, ty: number, tz: number): Matrix4x4;
    /** Creates a rotation matrix around the X-axis. */
    function rotationX(angle: number): Matrix4x4;
    /** Creates a rotation matrix around the Y-axis. */
    function rotationY(angle: number): Matrix4x4;
    /** Creates a rotation matrix around the Z-axis. */
    function rotationZ(angle: number): Matrix4x4;
  }
}

declare module ":dsdk" {
  import { Vector2, Vector3, Vector4, Matrix4x4 } from "plugify";

  /** Deadlock currency types */
  export const enum ECurrencyType {
    Invalid = 4294967295,
    Gold = 0,
    AbilityPoints = 1,
    AbilityUnlocks = 2,
    DeathPenaltyGold = 3,
    ItemDraftRerolls = 4,
    ItemEnhancements = 5,
    Count = 6
  }

  /** Deadlock currency sources */
  export const enum ECurrencySource {
    Invalid = 4294967295,
    ItemPurchase = 0,
    ItemUpgrade = 1,
    ItemSale = 2,
    TreasureChest = 3,
    AbilityPurchase = 4,
    StartingAmount = 5,
    LevelUp = 6,
    Cheats = 7,
    ResetDeathPenalty = 8,
    DroppedOnDeath = 9,
    HeroSwap = 10,
    PlayerKill = 11,
    PlayerKillAssist = 12,
    BossKill = 13,
    LaneTrooperKill = 14,
    NeutralTrooperKill = 15,
    NeutralBossKill = 16,
    DeniedFromEnemy = 17,
    AssassinatePlayerKill = 18,
    ItemTrophyCollector = 19,
    ItemCultistSacrifice = 20,
    ItemGooseEgg = 21,
    OrbPlayer = 22,
    OrbDeny = 23,
    OrbLaneTrooper = 24,
    OrbNeutralTrooper = 25,
    OrbTier1TrooperBoss = 26,
    OrbTier2TrooperBoss = 27,
    OrbBaseGuardians = 28,
    OrbShrines = 29,
    OrbTier3TrooperBoss = 30,
    OrbDeployable = 31,
    OrbTrophyKill = 32,
    OrbTreasureChest = 33,
    OrbSiegeTrooper = 34,
    OrbSpawner = 35,
    NeutralWorldPickup = 36,
    BreakablePickup = 37,
    PlayerKillComeback = 38,
    TeamBonus = 39,
    ItemDraftRerollUsed = 40,
    ItemEnhancementUsed = 41,
    StreetBrawlRoundReset = 42,
    Count = 43
  }

  /** Deadlock game states */
  export const enum EGameState {
    Invalid = 0,
    Init = 1,
    WaitingForPlayersToJoin = 2,
    HeroSelection = 3,
    MatchIntro = 4,
    WaitForMapToLoad = 5,
    PreGameWait = 6,
    GameInProgress = 7,
    PostGame = 8,
    PostGamePlayOfTheGame = 9,
    Abandoned = 10,
    End = 11
  }

  /** Hook callback return value */
  export const enum HookResult {
    Continue = 0,
    Changed = 1,
    Handled = 2,
    Stop = 3
  }


  export type CommandCallback = (playerSlot: number, args: string[]) => void;

  export type TimerCallback = () => void;

  export type ModifyCurrencyCallback = (pawn: number, currencyType: ECurrencyType, amount: number, source: ECurrencySource, silent: boolean, forceGain: boolean, spendOnly: boolean, sourceAbility: number, sourceEntity: number) => HookResult;

  export type TakeDamageCallback = (victim: number, damageInfo: number) => HookResult;

  export type ClientConnectCallback = (playerSlot: number, name: string, steamId: bigint) => boolean;

  export type ClientPutInServerCallback = (playerSlot: number) => void;

  export type ClientDisconnectCallback = (playerSlot: number, reason: number) => void;

  export type GameFrameCallback = (simulating: boolean, firstTick: boolean, lastTick: boolean) => void;

  export type EntityCallback = (entity: number) => void;

  export type GameStateChangedCallback = (newState: EGameState) => void;

  export type EntityIOCallback = (className: string, inputName: string, entity: number, activator: number, caller: number, value: string) => HookResult;

  export type NpcSelectScheduleCallback = (npc: number, chosenId: string) => string;

  export type EntityOutputCallback = (callerClass: string, outputName: string, activator: number, caller: number, delay: number) => HookResult;

  export type ProcessUsercmdsCallback = (playerSlot: number, numCmds: number, paused: boolean) => void;

  export type AbilityThinkCallback = (playerSlot: number, pawn: number) => void;

  export type AddModifierCallback = (modifierProp: number, caster: number, ability: number, team: number) => HookResult;

  export type HeroInitializedCallback = (pawn: number) => void;

  export type GameEventCallback = (eventName: string, event: number) => void;


  /**
   * Register a server-console-only command
   * @param name
   * @param description
   * @param flags
   * @param callback
   */
  export function AddServerCommand(name: string, description: string, flags: number, callback: CommandCallback): boolean;

  /**
   * Register a client-console-only command
   * @param name
   * @param description
   * @param flags
   * @param callback
   */
  export function AddClientCommand(name: string, description: string, flags: number, callback: CommandCallback): boolean;

  /**
   * Register a client-chat-only command
   * @param name
   * @param description
   * @param flags
   * @param callback
   */
  export function AddChatCommand(name: string, description: string, flags: number, callback: CommandCallback): boolean;

  /**
   * Register a server/chat console command
   * @param name
   * @param description
   * @param flags
   * @param callback
   */
  export function AddConsoleCommand(name: string, description: string, flags: number, callback: CommandCallback): boolean;

  /**
   * Unregister a console command
   * @param name
   */
  export function RemoveCommand(name: string): boolean;

  /**
   * Execute a command on the server console
   * @param command
   */
  export function ServerCommand(command: string): void;

  /**
   * Execute a command on behalf of a player
   * @param playerSlot
   * @param command
   */
  export function ExecuteCommandAsPlayer(playerSlot: number, command: string): boolean;

  /**
   * Execute command on client
   * @param playerSlot
   * @param command
   */
  export function ClientCommand(playerSlot: number, command: string): void;

  /**
   * Print message to client chat
   * @param playerSlot
   * @param message
   */
  export function PrintToChat(playerSlot: number, message: string): void;

  /**
   * Broadcast message to all players
   * @param message
   */
  export function PrintToChatAll(message: string): void;

  /**
   * Print message to client console
   * @param playerSlot
   * @param message
   */
  export function PrintToConsole(playerSlot: number, message: string): void;

  /**
   * Print message to all player consoles
   * @param message
   */
  export function PrintToConsoleAll(message: string): void;

  /**
   * Get CBasePlayerController address for player slot
   * @param playerSlot
   */
  export function GetPlayerController(playerSlot: number): number;

  /**
   * Get CCitadelPlayerPawn address for player slot
   * @param playerSlot
   */
  export function GetPlayerPawn(playerSlot: number): number;

  /**
   * Get player slot from controller address
   * @param controller
   */
  export function GetPlayerSlot(controller: number): number;

  /**
   * Get player display name
   * @param playerSlot
   */
  export function GetPlayerName(playerSlot: number): string;

  /**
   * Get player 64-bit SteamID
   * @param playerSlot
   */
  export function GetSteamID(playerSlot: number): bigint;

  /**
   * Check if player Steam ticket is validated
   * @param playerSlot
   */
  export function IsClientAuthenticated(playerSlot: number): boolean;

  /**
   * Check if client is connected
   * @param playerSlot
   */
  export function IsClientConnected(playerSlot: number): boolean;

  /**
   * Check if player is a bot/fake client
   * @param playerSlot
   */
  export function IsFakeClient(playerSlot: number): boolean;

  /**
   * Create a fake client in the match
   * @param name
   */
  export function CreateFakeClient(name: string): number;

  /**
   * Disconnect a client with disconnection reason code
   * @param playerSlot
   * @param reason
   */
  export function DisconnectClient(playerSlot: number, reason: number): void;

  /**
   * Kick client with message and code
   * @param playerSlot
   * @param reason
   * @param code
   */
  export function KickClient(playerSlot: number, reason: string, code: number): void;

  /**
   * Change team of player controller
   * @param controller
   * @param teamNum
   * @param keepHero
   */
  export function ChangeTeam(controller: number, teamNum: number, keepHero: boolean): void;

  /**
   * Get ping of player in milliseconds
   * @param playerSlot
   */
  export function GetPlayerPing(playerSlot: number): number;

  /**
   * Get connection time of player in seconds
   * @param playerSlot
   */
  export function GetPlayerTimeConnected(playerSlot: number): number;

  /**
   * Select a hero for controller
   * @param controller
   * @param heroName
   */
  export function SelectHero(controller: number, heroName: string): void;

  /**
   * Reset hero state on pawn
   * @param pawn
   * @param reset
   */
  export function ResetHero(pawn: number, reset: boolean): void;

  /**
   * Precache hero assets
   * @param heroName
   */
  export function PrecacheHero(heroName: string): void;

  /**
   * Force immediate hero pawn respawn
   * @param pawn
   * @param releaseButtons
   */
  export function ForceRespawn(pawn: number, releaseButtons: boolean): void;

  /**
   * Lookup hero definition pointer
   * @param heroName
   */
  export function GetHeroData(heroName: string): number;

  /**
   * Get name of hero for pawn
   * @param pawn
   */
  export function GetHeroName(pawn: number): string;

  /**
   * Add an ability to player pawn
   * @param pawn
   * @param abilityName
   * @param slot
   */
  export function AddAbility(pawn: number, abilityName: string, slot: number): number;

  /**
   * Remove ability by name from pawn
   * @param pawn
   * @param abilityName
   */
  export function RemoveAbility(pawn: number, abilityName: string): boolean;

  /**
   * Remove ability by entity pointer
   * @param pawn
   * @param ability
   */
  export function RemoveAbilityByEntity(pawn: number, ability: number): boolean;

  /**
   * Find ability in ability component
   * @param abilityComponent
   * @param abilityName
   */
  export function FindAbilityByName(abilityComponent: number, abilityName: string): number;

  /**
   * Get ability at slot index
   * @param abilityComponent
   * @param slot
   */
  export function GetAbilityBySlot(abilityComponent: number, slot: number): number;

  /**
   * Cast/execute an ability
   * @param abilityComponent
   * @param ability
   * @param altCast
   * @param flags
   */
  export function ExecuteAbility(abilityComponent: number, ability: number, altCast: boolean, flags: number): number;

  /**
   * Toggle ability active status
   * @param ability
   * @param activate
   */
  export function ToggleActivate(ability: number, activate: boolean): void;

  /**
   * Reset ability cooldown and refill charges
   * @param ability
   */
  export function ResetAbilityCooldown(ability: number): void;

  /**
   * Get maximum charges of an ability
   * @param ability
   */
  export function GetAbilityMaxCharges(ability: number): number;

  /**
   * Set upgrade bits on ability
   * @param ability
   * @param newBits
   */
  export function SetUpgradeBits(ability: number, newBits: number): void;

  /**
   * Add an item to player pawn
   * @param pawn
   * @param itemName
   * @param upgradeTier
   */
  export function AddItem(pawn: number, itemName: string, upgradeTier: number): number;

  /**
   * Sell an item from pawn
   * @param pawn
   * @param itemName
   * @param fullRefund
   * @param forceSellPrice
   */
  export function SellItem(pawn: number, itemName: string, fullRefund: boolean, forceSellPrice: boolean): boolean;

  /**
   * Get item imbue effect flags
   * @param itemName
   */
  export function GetItemImbueEffects(itemName: string): number;

  /**
   * Check if ability can receive imbue
   * @param targetAbility
   * @param itemName
   */
  export function CanImbueAbility(targetAbility: number, itemName: string): boolean;

  /**
   * Imbue item onto target ability
   * @param item
   * @param targetAbility
   */
  export function ImbueAbility(item: number, targetAbility: number): boolean;

  /**
   * Modify currency (souls/gold) for player pawn
   * @param pawn
   * @param currencyType
   * @param amount
   * @param source
   * @param silent
   * @param forceGain
   * @param spendOnly
   * @param sourceAbility
   * @param sourceEntity
   */
  export function ModifyCurrency(pawn: number, currencyType: ECurrencyType, amount: number, source: ECurrencySource, silent: boolean, forceGain: boolean, spendOnly: boolean, sourceAbility: number, sourceEntity: number): void;

  /**
   * Get current currency value of pawn
   * @param pawn
   * @param currencyType
   */
  export function GetCurrency(pawn: number, currencyType: ECurrencyType): number;

  /**
   * Create a one-shot or repeating timer
   * @param interval
   * @param callback
   * @param repeating
   */
  export function CreateTimer(interval: number, callback: TimerCallback, repeating: boolean): number;

  /**
   * Stop and delete an active timer
   * @param timerId
   */
  export function KillTimer(timerId: number): boolean;

  /**
   * Read string from settings.jsonc
   * @param key
   * @param defaultValue
   */
  export function GetConfigString(key: string, defaultValue: string): string;

  /**
   * Read int from settings.jsonc
   * @param key
   * @param defaultValue
   */
  export function GetConfigInt(key: string, defaultValue: number): number;

  /**
   * Read bool from settings.jsonc
   * @param key
   * @param defaultValue
   */
  export function GetConfigBool(key: string, defaultValue: boolean): boolean;

  /**
   * Read float from settings.jsonc
   * @param key
   * @param defaultValue
   */
  export function GetConfigFloat(key: string, defaultValue: number): number;

  /**
   * Get current game state enum
   */
  export function GetGameState(): EGameState;

  /**
   * Force Deadlock game state change
   * @param newState
   */
  export function ChangeGameState(newState: EGameState): void;

  /**
   * Set waiting for players roster counts
   * @param readyCount
   * @param totalCount
   */
  export function SetWaitingForPlayersRoster(readyCount: number, totalCount: number): void;

  /**
   * Enable/disable match start sequence on custom maps
   * @param enabled
   */
  export function SetMatchStartOnAnyMap(enabled: boolean): void;

  /**
   * Check if match start on custom maps is enabled
   */
  export function GetMatchStartOnAnyMap(): boolean;

  /**
   * Register game event listener for engine event
   * @param name
   */
  export function RegisterGameEvent(name: string): void;

  /**
   * Create a new game event
   * @param name
   * @param force
   */
  export function CreateGameEvent(name: string, force: boolean): number;

  /**
   * Fire game event
   * @param event
   * @param dontBroadcast
   */
  export function FireGameEvent(event: number, dontBroadcast: boolean): boolean;

  /**
   * Free game event object
   * @param event
   */
  export function FreeGameEvent(event: number): void;

  /**
   * Get boolean key from game event
   * @param event
   * @param key
   * @param def
   */
  export function GameEventGetBool(event: number, key: string, def: boolean): boolean;

  /**
   * Get int32 key from game event
   * @param event
   * @param key
   * @param def
   */
  export function GameEventGetInt(event: number, key: string, def: number): number;

  /**
   * Get float key from game event
   * @param event
   * @param key
   * @param def
   */
  export function GameEventGetFloat(event: number, key: string, def: number): number;

  /**
   * Get string key from game event
   * @param event
   * @param key
   * @param def
   */
  export function GameEventGetString(event: number, key: string, def: string): string;

  /**
   * Get uint64 key from game event
   * @param event
   * @param key
   * @param def
   */
  export function GameEventGetUint64(event: number, key: string, def: bigint): bigint;

  /**
   * Set boolean key in game event
   * @param event
   * @param key
   * @param val
   */
  export function GameEventSetBool(event: number, key: string, val: boolean): void;

  /**
   * Set int32 key in game event
   * @param event
   * @param key
   * @param val
   */
  export function GameEventSetInt(event: number, key: string, val: number): void;

  /**
   * Set float key in game event
   * @param event
   * @param key
   * @param val
   */
  export function GameEventSetFloat(event: number, key: string, val: number): void;

  /**
   * Set string key in game event
   * @param event
   * @param key
   * @param val
   */
  export function GameEventSetString(event: number, key: string, val: string): void;

  /**
   * Gets player slot from an event key (e.g. userid)
   * @param event
   * @param key
   */
  export function GameEventGetPlayerSlot(event: number, key: string): number;

  /**
   * Gets player pawn pointer from an event key (e.g. userid)
   * @param event
   * @param key
   */
  export function GameEventGetPlayerPawn(event: number, key: string): number;

  /**
   * Gets player controller pointer from an event key (e.g. userid)
   * @param event
   * @param key
   */
  export function GameEventGetPlayerController(event: number, key: string): number;

  /**
   * Get currently loaded map name
   */
  export function GetMapName(): string;

  /**
   * Check if map exists and can be loaded
   * @param map
   */
  export function IsMapValid(map: string): boolean;

  /**
   * Set Steam A2S rule key-value
   * @param key
   * @param value
   */
  export function SetServerKeyValue(key: string, value: string): boolean;

  /**
   * Clear Steam A2S rules
   */
  export function ClearServerKeyValues(): boolean;

  /**
   * Set active server workshop addons
   * @param addons
   */
  export function SetServerAddons(addons: string): void;

  /**
   * Add file search path
   * @param path
   * @param pathId
   * @param addType
   */
  export function AddFileSystemSearchPath(path: string, pathId: string, addType: number): boolean;

  /**
   * Check if command line argument exists
   * @param parm
   */
  export function HasCommandLineParm(parm: string): boolean;

  /**
   * Set reject reason for connection rejection
   * @param reason
   */
  export function SetConnectRejectReason(reason: string): void;

  /**
   * Get CGlobalVars pointer
   */
  export function GetGlobalVars(): number;

  /**
   * Get current engine game time in seconds
   */
  export function GetGameTime(): number;

  /**
   * Get current engine tick count
   */
  export function GetGameTickCount(): number;

  /**
   * Find ConVar by name
   * @param name
   */
  export function FindConVar(name: string): bigint;

  /**
   * Create custom ConVar
   * @param name
   * @param defaultValue
   * @param description
   * @param flags
   */
  export function CreateConVar(name: string, defaultValue: string, description: string, flags: bigint): bigint;

  /**
   * Get ConVar integer value
   * @param handle
   */
  export function GetConVarInt(handle: bigint): number;

  /**
   * Get ConVar float value
   * @param handle
   */
  export function GetConVarFloat(handle: bigint): number;

  /**
   * Get ConVar string value
   * @param handle
   */
  export function GetConVarString(handle: bigint): string;

  /**
   * Get ConVar bool value
   * @param handle
   */
  export function GetConVarBool(handle: bigint): boolean;

  /**
   * Set ConVar int value
   * @param handle
   * @param value
   */
  export function SetConVarInt(handle: bigint, value: number): void;

  /**
   * Set ConVar float value
   * @param handle
   * @param value
   */
  export function SetConVarFloat(handle: bigint, value: number): void;

  /**
   * Set ConVar string value
   * @param handle
   * @param value
   */
  export function SetConVarString(handle: bigint, value: string): boolean;

  /**
   * Create CTakeDamageInfo instance
   * @param inflictor
   * @param attacker
   * @param ability
   * @param damage
   * @param damageType
   */
  export function CreateDamageInfo(inflictor: number, attacker: number, ability: number, damage: number, damageType: number): number;

  /**
   * Free CTakeDamageInfo instance
   * @param info
   */
  export function DestroyDamageInfo(info: number): void;

  /**
   * Inflict damage on victim entity
   * @param victim
   * @param info
   */
  export function TakeDamage(victim: number, info: number): void;

  /**
   * Apply damage bypassing damage filters
   * @param victim
   * @param info
   */
  export function ApplyDamage(victim: number, info: number): void;

  /**
   * Get maximum health of entity
   * @param entity
   */
  export function GetMaxHealth(entity: number): number;

  /**
   * Heal entity by amount
   * @param entity
   * @param amount
   */
  export function Heal(entity: number, amount: number): number;

  /**
   * Add modifier to entity
   * @param entity
   * @param modifierName
   * @param kv3
   * @param caster
   * @param ability
   * @param team
   */
  export function AddModifier(entity: number, modifierName: string, kv3: number, caster: number, ability: number, team: number): number;

  /**
   * Remove modifier instance from entity
   * @param entity
   * @param modifier
   */
  export function RemoveModifier(entity: number, modifier: number): boolean;

  /**
   * Create entity instance by class name
   * @param className
   */
  export function CreateEntityByName(className: string): number;

  /**
   * Queue entity spawn with optional entity keyvalues
   * @param entity
   * @param ekv
   */
  export function QueueSpawnEntity(entity: number, ekv: number): void;

  /**
   * Execute queued entity creation
   */
  export function ExecuteQueuedCreation(): void;

  /**
   * Remove/destroy entity
   * @param entity
   */
  export function RemoveEntity(entity: number): void;

  /**
   * Get entity pointer by index
   * @param index
   */
  export function GetEntityByIndex(index: number): number;

  /**
   * Resolve entity pointer from uint32 handle
   * @param handle
   */
  export function GetEntityFromHandle(handle: number): number;

  /**
   * Get handle of entity
   * @param entity
   */
  export function GetEntityHandle(entity: number): number;

  /**
   * Find entity by name
   * @param startEntity
   * @param name
   */
  export function FindEntityByName(startEntity: number, name: string): number;

  /**
   * Get designer name of entity
   * @param entity
   */
  export function GetEntityDesignerName(entity: number): string;

  /**
   * Get class name of entity
   * @param entity
   */
  export function GetEntityClassname(entity: number): string;

  /**
   * Teleport entity with position, angles and velocity
   * @param entity
   * @param posX
   * @param posY
   * @param posZ
   * @param angPitch
   * @param angYaw
   * @param angRoll
   * @param velX
   * @param velY
   * @param velZ
   */
  export function Teleport(entity: number, posX: number, posY: number, posZ: number, angPitch: number, angYaw: number, angRoll: number, velX: number, velY: number, velZ: number): void;

  /**
   * Set visual model of entity
   * @param entity
   * @param modelName
   */
  export function SetModel(entity: number, modelName: string): void;

  /**
   * Get model name of entity
   * @param entity
   */
  export function GetModelName(entity: number): string;

  /**
   * Set visual scale of entity
   * @param entity
   * @param scale
   */
  export function SetScale(entity: number, scale: number): void;

  /**
   * Set entity move type
   * @param entity
   * @param moveType
   */
  export function SetMoveType(entity: number, moveType: number): void;

  /**
   * Set entity gravity multiplier
   * @param entity
   * @param scale
   */
  export function SetGravityScale(entity: number, scale: number): void;

  /**
   * Check if entity class derives from base class name
   * @param entity
   * @param baseClassName
   */
  export function EntityDerivesFrom(entity: number, baseClassName: string): boolean;

  /**
   * Get byte offset of class field in schema
   * @param className
   * @param fieldName
   */
  export function GetSchemaFieldOffset(className: string, fieldName: string): number;

  /**
   * Notify network system of field modification
   * @param entity
   * @param fieldOffset
   * @param chainOffset
   * @param networkStateChangedOffset
   */
  export function NotifyStateChanged(entity: number, fieldOffset: number, chainOffset: number, networkStateChangedOffset: number): void;

  /**
   * Set string field in schema structure
   * @param entity
   * @param className
   * @param fieldName
   * @param value
   */
  export function SetSchemaString(entity: number, className: string, fieldName: string, value: string): void;

  /**
   * Get sizeof schema class
   * @param className
   */
  export function GetSchemaClassSize(className: string): number;

  /**
   * Emit sound event from entity
   * @param entity
   * @param soundName
   * @param pitch
   * @param volume
   * @param delay
   */
  export function EmitSound(entity: number, soundName: string, pitch: number, volume: number, delay: number): void;

  /**
   * Generate unique sound event GUID
   */
  export function TakeSoundEventGuid(): number;

  /**
   * Create and dispatch particle effect
   * @param particleName
   * @param attachType
   * @param entity
   */
  export function CreateParticle(particleName: string, attachType: number, entity: number): number;

  /**
   * Destroy active particle instance
   * @param particle
   * @param destroyImmediately
   */
  export function DestroyParticle(particle: number, destroyImmediately: boolean): void;

  /**
   * Precache resource by VPK path
   * @param path
   */
  export function PrecacheResource(path: string): void;

  /**
   * Precache model resource
   * @param modelPath
   */
  export function PrecacheModel(modelPath: string): void;

  /**
   * Create 3D point_worldtext entity in the world
   * @param message
   * @param x
   * @param y
   * @param z
   * @param fontSize
   * @param r
   * @param g
   * @param b
   * @param a
   */
  export function CreateWorldText(message: string, x: number, y: number, z: number, fontSize: number, r: number, g: number, b: number, a: number): number;

  /**
   * Update message text of CPointWorldText
   * @param worldText
   * @param text
   */
  export function SetWorldTextMessage(worldText: number, text: string): void;

  /**
   * Spawn a glowing laser beam entity between two world points
   * @param startX
   * @param startY
   * @param startZ
   * @param endX
   * @param endY
   * @param endZ
   * @param width
   * @param r
   * @param g
   * @param b
   * @param a
   */
  export function CreateBeam(startX: number, startY: number, startZ: number, endX: number, endY: number, endZ: number, width: number, r: number, g: number, b: number, a: number): number;

  /**
   * Create a spatial trigger volume box
   * @param name
   * @param minX
   * @param minY
   * @param minZ
   * @param maxX
   * @param maxY
   * @param maxZ
   */
  export function CreateZone(name: string, minX: number, minY: number, minZ: number, maxX: number, maxY: number, maxZ: number): number;

  /**
   * Destroy a spatial zone trigger
   * @param zoneId
   */
  export function DestroyZone(zoneId: number): void;

  /**
   * Perform physics raycast trace between start and end vectors
   * @param startX
   * @param startY
   * @param startZ
   * @param endX
   * @param endY
   * @param endZ
   * @param mask
   * @param ignoreEntity
   */
  export function LineTrace(startX: number, startY: number, startZ: number, endX: number, endY: number, endZ: number, mask: number, ignoreEntity: number): boolean;

  /**
   * Direct AI NPC to move to goal location
   * @param npc
   * @param x
   * @param y
   * @param z
   * @param run
   * @param tolerance
   */
  export function NpcMoveTo(npc: number, x: number, y: number, z: number, run: boolean, tolerance: number): void;

  /**
   * Stop movement of AI NPC
   * @param npc
   * @param instant
   */
  export function NpcStopMoving(npc: number, instant: boolean): void;

  /**
   * Set target enemy entity of AI NPC
   * @param npc
   * @param enemy
   */
  export function NpcSetEnemy(npc: number, enemy: number): void;

  /**
   * Set NPC AI state
   * @param npc
   * @param state
   */
  export function NpcSetState(npc: number, state: number): void;

  /**
   * Spawn lane or neutral trooper NPC
   * @param posX
   * @param posY
   * @param posZ
   * @param pitch
   * @param yaw
   * @param roll
   * @param team
   * @param type
   * @param variant
   * @param snapToGround
   */
  export function NpcCreateTrooper(posX: number, posY: number, posZ: number, pitch: number, yaw: number, roll: number, team: number, type: number, variant: number, snapToGround: boolean): number;

  /**
   * Find nearest point on navmesh
   * @param x
   * @param y
   * @param z
   * @param maxDistance
   * @param hull
   */
  export function NavGetNearestPoint(x: number, y: number, z: number, maxDistance: number, hull: number): boolean;

  /**
   * Get ground elevation from navmesh
   * @param x
   * @param y
   * @param z
   * @param maxDistance
   * @param hull
   */
  export function NavGetGroundHeight(x: number, y: number, z: number, maxDistance: number, hull: number): number;

  /**
   * Spawn a bot hero into the match
   * @param heroName
   * @param team
   * @param posX
   * @param posY
   * @param posZ
   * @param assignLane
   */
  export function BotCreate(heroName: string, team: number, posX: number, posY: number, posZ: number, assignLane: boolean): number;

  /**
   * Get brain entity pointer for player bot pawn
   * @param pawn
   */
  export function BotGetBrain(pawn: number): number;

  /**
   * Get pawn entity controlled by bot brain
   * @param brain
   */
  export function BotGetPawn(brain: number): number;

  /**
   * Assign lane index to bot
   * @param pawn
   * @param lane
   */
  export function BotSetLane(pawn: number, lane: number): boolean;

  /**
   * Get assigned lane index of bot
   * @param pawn
   */
  export function BotGetLane(pawn: number): number;

  /**
   * Fire input on target entity
   * @param entity
   * @param inputName
   * @param activator
   * @param caller
   * @param value
   */
  export function AcceptInput(entity: number, inputName: string, activator: number, caller: number, value: string): void;

  /**
   * Send protobuf network message to clients
   * @param msgId
   * @param protoBytes
   * @param recipientMask
   * @param bufType
   */
  export function SendNetMessage(msgId: number, protoBytes: number[], recipientMask: bigint, bufType: number): void;

  /**
   * Get registered network message name
   * @param msgId
   */
  export function GetNetMessageName(msgId: number): string;

  /**
   * Allocate new KeyValues3 document
   */
  export function KV3Create(): number;

  /**
   * Free KeyValues3 document
   * @param kv3
   */
  export function KV3Destroy(kv3: number): void;

  /**
   * Set string value in KeyValues3 document
   * @param kv3
   * @param key
   * @param value
   */
  export function KV3SetString(kv3: number, key: string, value: string): void;

  /**
   * Set bool value in KeyValues3 document
   * @param kv3
   * @param key
   * @param value
   */
  export function KV3SetBool(kv3: number, key: string, value: boolean): void;

  /**
   * Set int32 value in KeyValues3 document
   * @param kv3
   * @param key
   * @param value
   */
  export function KV3SetInt(kv3: number, key: string, value: number): void;

  /**
   * Set float value in KeyValues3 document
   * @param kv3
   * @param key
   * @param value
   */
  export function KV3SetFloat(kv3: number, key: string, value: number): void;

  /**
   * Register Currency modification listener hook
   * @param callback
   */
  export function OnModifyCurrency_Register(callback: ModifyCurrencyCallback): void;

  /**
   * Unregister Currency modification listener hook
   * @param callback
   */
  export function OnModifyCurrency_Unregister(callback: ModifyCurrencyCallback): void;

  /**
   * Register Entity take damage listener hook
   * @param callback
   */
  export function OnTakeDamage_Register(callback: TakeDamageCallback): void;

  /**
   * Unregister Entity take damage listener hook
   * @param callback
   */
  export function OnTakeDamage_Unregister(callback: TakeDamageCallback): void;

  /**
   * Register Client connection listener hook
   * @param callback
   */
  export function OnClientConnect_Register(callback: ClientConnectCallback): void;

  /**
   * Unregister Client connection listener hook
   * @param callback
   */
  export function OnClientConnect_Unregister(callback: ClientConnectCallback): void;

  /**
   * Register Client put in server listener hook
   * @param callback
   */
  export function OnClientPutInServer_Register(callback: ClientPutInServerCallback): void;

  /**
   * Unregister Client put in server listener hook
   * @param callback
   */
  export function OnClientPutInServer_Unregister(callback: ClientPutInServerCallback): void;

  /**
   * Register Client disconnect listener hook
   * @param callback
   */
  export function OnClientDisconnect_Register(callback: ClientDisconnectCallback): void;

  /**
   * Unregister Client disconnect listener hook
   * @param callback
   */
  export function OnClientDisconnect_Unregister(callback: ClientDisconnectCallback): void;

  /**
   * Register Server game tick frame listener hook
   * @param callback
   */
  export function OnGameFrame_Register(callback: GameFrameCallback): void;

  /**
   * Unregister Server game tick frame listener hook
   * @param callback
   */
  export function OnGameFrame_Unregister(callback: GameFrameCallback): void;

  /**
   * Register Entity created listener hook
   * @param callback
   */
  export function OnEntityCreated_Register(callback: EntityCallback): void;

  /**
   * Unregister Entity created listener hook
   * @param callback
   */
  export function OnEntityCreated_Unregister(callback: EntityCallback): void;

  /**
   * Register Entity spawned listener hook
   * @param callback
   */
  export function OnEntitySpawned_Register(callback: EntityCallback): void;

  /**
   * Unregister Entity spawned listener hook
   * @param callback
   */
  export function OnEntitySpawned_Unregister(callback: EntityCallback): void;

  /**
   * Register Entity deleted listener hook
   * @param callback
   */
  export function OnEntityDeleted_Register(callback: EntityCallback): void;

  /**
   * Unregister Entity deleted listener hook
   * @param callback
   */
  export function OnEntityDeleted_Unregister(callback: EntityCallback): void;

  /**
   * Register Game state change listener hook
   * @param callback
   */
  export function OnGameStateChanged_Register(callback: GameStateChangedCallback): void;

  /**
   * Unregister Game state change listener hook
   * @param callback
   */
  export function OnGameStateChanged_Unregister(callback: GameStateChangedCallback): void;

  /**
   * Register Entity AcceptInput listener hook
   * @param callback
   */
  export function OnEntityAcceptInput_Register(callback: EntityIOCallback): void;

  /**
   * Unregister Entity AcceptInput listener hook
   * @param callback
   */
  export function OnEntityAcceptInput_Unregister(callback: EntityIOCallback): void;

  /**
   * Register NPC schedule selection listener hook
   * @param callback
   */
  export function OnNpcSelectSchedule_Register(callback: NpcSelectScheduleCallback): void;

  /**
   * Unregister NPC schedule selection listener hook
   * @param callback
   */
  export function OnNpcSelectSchedule_Unregister(callback: NpcSelectScheduleCallback): void;

  /**
   * Register Entity FireOutput listener hook
   * @param callback
   */
  export function OnEntityFireOutput_Register(callback: EntityOutputCallback): void;

  /**
   * Unregister Entity FireOutput listener hook
   * @param callback
   */
  export function OnEntityFireOutput_Unregister(callback: EntityOutputCallback): void;

  /**
   * Register CBasePlayerController::ProcessUsercmds listener hook
   * @param callback
   */
  export function OnProcessUsercmds_Register(callback: ProcessUsercmdsCallback): void;

  /**
   * Unregister CBasePlayerController::ProcessUsercmds listener hook
   * @param callback
   */
  export function OnProcessUsercmds_Unregister(callback: ProcessUsercmdsCallback): void;

  /**
   * Register CCitadelPlayerPawn::AbilityThink listener hook
   * @param callback
   */
  export function OnAbilityThink_Register(callback: AbilityThinkCallback): void;

  /**
   * Unregister CCitadelPlayerPawn::AbilityThink listener hook
   * @param callback
   */
  export function OnAbilityThink_Unregister(callback: AbilityThinkCallback): void;

  /**
   * Register CModifierProperty::AddModifier listener hook
   * @param callback
   */
  export function OnAddModifier_Register(callback: AddModifierCallback): void;

  /**
   * Unregister CModifierProperty::AddModifier listener hook
   * @param callback
   */
  export function OnAddModifier_Unregister(callback: AddModifierCallback): void;

  /**
   * Register CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
   * @param callback
   */
  export function OnHeroInitialized_Register(callback: HeroInitializedCallback): void;

  /**
   * Unregister CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
   * @param callback
   */
  export function OnHeroInitialized_Unregister(callback: HeroInitializedCallback): void;

  /**
   * Register game event listener hook (e.g. player_death, player_respawned)
   * @param callback
   */
  export function OnGameEvent_Register(callback: GameEventCallback): void;

  /**
   * Unregister game event listener hook
   * @param callback
   */
  export function OnGameEvent_Unregister(callback: GameEventCallback): void;

  /**
   * Display a HUD game announcement banner to a player
   * @param playerSlot
   * @param title
   * @param description
   * @param duration
   */
  export function HudAnnounce(playerSlot: number, title: string, description: string, duration: number): void;

  /**
   * Display a HUD game announcement banner to all players
   * @param title
   * @param description
   * @param duration
   */
  export function HudAnnounceAll(title: string, description: string, duration: number): void;

}
