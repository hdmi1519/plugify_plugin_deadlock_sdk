-- Generated from dsdk.pplugin

-- ECurrencyType: Deadlock currency types
ECurrencyType = {
  Invalid = 4294967295,
  Gold = 0,
  AbilityPoints = 1,
  AbilityUnlocks = 2,
  DeathPenaltyGold = 3,
  ItemDraftRerolls = 4,
  ItemEnhancements = 5,
  Count = 6,
}

-- ECurrencySource: Deadlock currency sources
ECurrencySource = {
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
  Count = 43,
}

-- EGameState: Deadlock game states
EGameState = {
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
  End = 11,
}

-- HookResult: Hook callback return value
HookResult = {
  Continue = 0,
  Changed = 1,
  Handled = 2,
  Stop = 3,
}


--- Register a server-console-only command
-- @param name string 
-- @param description string 
-- @param flags int64 
-- @param callback function 
-- @return bool 
-- @callback CommandCallback callback - 
-- @param playerSlot int32 
-- @param args string[] 
function AddServerCommand(name, description, flags, callback) end

--- Register a client-console-only command
-- @param name string 
-- @param description string 
-- @param flags int64 
-- @param callback function 
-- @return bool 
-- @callback CommandCallback callback - 
-- @param playerSlot int32 
-- @param args string[] 
function AddClientCommand(name, description, flags, callback) end

--- Register a client-chat-only command
-- @param name string 
-- @param description string 
-- @param flags int64 
-- @param callback function 
-- @return bool 
-- @callback CommandCallback callback - 
-- @param playerSlot int32 
-- @param args string[] 
function AddChatCommand(name, description, flags, callback) end

--- Register a server/chat console command
-- @param name string 
-- @param description string 
-- @param flags int64 
-- @param callback function 
-- @return bool 
-- @callback CommandCallback callback - 
-- @param playerSlot int32 
-- @param args string[] 
function AddConsoleCommand(name, description, flags, callback) end

--- Unregister a console command
-- @param name string 
-- @return bool 
function RemoveCommand(name) end

--- Execute a command on the server console
-- @param command string 
function ServerCommand(command) end

--- Execute a command on behalf of a player
-- @param playerSlot int32 
-- @param command string 
-- @return bool 
function ExecuteCommandAsPlayer(playerSlot, command) end

--- Execute command on client
-- @param playerSlot int32 
-- @param command string 
function ClientCommand(playerSlot, command) end

--- Print message to client chat
-- @param playerSlot int32 
-- @param message string 
function PrintToChat(playerSlot, message) end

--- Broadcast message to all players
-- @param message string 
function PrintToChatAll(message) end

--- Print message to client console
-- @param playerSlot int32 
-- @param message string 
function PrintToConsole(playerSlot, message) end

--- Print message to all player consoles
-- @param message string 
function PrintToConsoleAll(message) end

--- Get CBasePlayerController address for player slot
-- @param playerSlot int32 
-- @return int64 
function GetPlayerController(playerSlot) end

--- Get CCitadelPlayerPawn address for player slot
-- @param playerSlot int32 
-- @return int64 
function GetPlayerPawn(playerSlot) end

--- Get player slot from controller address
-- @param controller int64 
-- @return int32 
function GetPlayerSlot(controller) end

--- Get player display name
-- @param playerSlot int32 
-- @return string 
function GetPlayerName(playerSlot) end

--- Get player 64-bit SteamID
-- @param playerSlot int32 
-- @return uint64 
function GetSteamID(playerSlot) end

--- Check if player Steam ticket is validated
-- @param playerSlot int32 
-- @return bool 
function IsClientAuthenticated(playerSlot) end

--- Check if client is connected
-- @param playerSlot int32 
-- @return bool 
function IsClientConnected(playerSlot) end

--- Check if player is a bot/fake client
-- @param playerSlot int32 
-- @return bool 
function IsFakeClient(playerSlot) end

--- Create a fake client in the match
-- @param name string 
-- @return int32 
function CreateFakeClient(name) end

--- Disconnect a client with disconnection reason code
-- @param playerSlot int32 
-- @param reason int32 
function DisconnectClient(playerSlot, reason) end

--- Kick client with message and code
-- @param playerSlot int32 
-- @param reason string 
-- @param code int32 
function KickClient(playerSlot, reason, code) end

--- Change team of player controller
-- @param controller int64 
-- @param teamNum int32 
-- @param keepHero bool 
function ChangeTeam(controller, teamNum, keepHero) end

--- Get ping of player in milliseconds
-- @param playerSlot int32 
-- @return int32 
function GetPlayerPing(playerSlot) end

--- Get connection time of player in seconds
-- @param playerSlot int32 
-- @return float 
function GetPlayerTimeConnected(playerSlot) end

--- Select a hero for controller
-- @param controller int64 
-- @param heroName string 
function SelectHero(controller, heroName) end

--- Reset hero state on pawn
-- @param pawn int64 
-- @param reset bool 
function ResetHero(pawn, reset) end

--- Precache hero assets
-- @param heroName string 
function PrecacheHero(heroName) end

--- Force immediate hero pawn respawn
-- @param pawn int64 
-- @param releaseButtons bool 
function ForceRespawn(pawn, releaseButtons) end

--- Lookup hero definition pointer
-- @param heroName string 
-- @return int64 
function GetHeroData(heroName) end

--- Get name of hero for pawn
-- @param pawn int64 
-- @return string 
function GetHeroName(pawn) end

--- Add an ability to player pawn
-- @param pawn int64 
-- @param abilityName string 
-- @param slot uint16 
-- @return int64 
function AddAbility(pawn, abilityName, slot) end

--- Remove ability by name from pawn
-- @param pawn int64 
-- @param abilityName string 
-- @return bool 
function RemoveAbility(pawn, abilityName) end

--- Remove ability by entity pointer
-- @param pawn int64 
-- @param ability int64 
-- @return bool 
function RemoveAbilityByEntity(pawn, ability) end

--- Find ability in ability component
-- @param abilityComponent int64 
-- @param abilityName string 
-- @return int64 
function FindAbilityByName(abilityComponent, abilityName) end

--- Get ability at slot index
-- @param abilityComponent int64 
-- @param slot int16 
-- @return int64 
function GetAbilityBySlot(abilityComponent, slot) end

--- Cast/execute an ability
-- @param abilityComponent int64 
-- @param ability int64 
-- @param altCast bool 
-- @param flags uint8 
-- @return int32 
function ExecuteAbility(abilityComponent, ability, altCast, flags) end

--- Toggle ability active status
-- @param ability int64 
-- @param activate bool 
function ToggleActivate(ability, activate) end

--- Reset ability cooldown and refill charges
-- @param ability int64 
function ResetAbilityCooldown(ability) end

--- Get maximum charges of an ability
-- @param ability int64 
-- @return int32 
function GetAbilityMaxCharges(ability) end

--- Set upgrade bits on ability
-- @param ability int64 
-- @param newBits int32 
function SetUpgradeBits(ability, newBits) end

--- Add an item to player pawn
-- @param pawn int64 
-- @param itemName string 
-- @param upgradeTier int32 
-- @return int64 
function AddItem(pawn, itemName, upgradeTier) end

--- Sell an item from pawn
-- @param pawn int64 
-- @param itemName string 
-- @param fullRefund bool 
-- @param forceSellPrice bool 
-- @return bool 
function SellItem(pawn, itemName, fullRefund, forceSellPrice) end

--- Get item imbue effect flags
-- @param itemName string 
-- @return int32 
function GetItemImbueEffects(itemName) end

--- Check if ability can receive imbue
-- @param targetAbility int64 
-- @param itemName string 
-- @return bool 
function CanImbueAbility(targetAbility, itemName) end

--- Imbue item onto target ability
-- @param item int64 
-- @param targetAbility int64 
-- @return bool 
function ImbueAbility(item, targetAbility) end

--- Modify currency (souls/gold) for player pawn
-- @param pawn int64 
-- @param currencyType uint32 
-- @param amount int32 
-- @param source uint32 
-- @param silent bool 
-- @param forceGain bool 
-- @param spendOnly bool 
-- @param sourceAbility int64 
-- @param sourceEntity int64 
function ModifyCurrency(pawn, currencyType, amount, source, silent, forceGain, spendOnly, sourceAbility, sourceEntity) end

--- Get current currency value of pawn
-- @param pawn int64 
-- @param currencyType uint32 
-- @return int32 
function GetCurrency(pawn, currencyType) end

--- Create a one-shot or repeating timer
-- @param interval float 
-- @param callback function 
-- @param repeating bool 
-- @return int64 
-- @callback TimerCallback callback - 
function CreateTimer(interval, callback, repeating) end

--- Stop and delete an active timer
-- @param timerId int64 
-- @return bool 
function KillTimer(timerId) end

--- Read string from settings.jsonc
-- @param key string 
-- @param defaultValue string 
-- @return string 
function GetConfigString(key, defaultValue) end

--- Read int from settings.jsonc
-- @param key string 
-- @param defaultValue int32 
-- @return int32 
function GetConfigInt(key, defaultValue) end

--- Read bool from settings.jsonc
-- @param key string 
-- @param defaultValue bool 
-- @return bool 
function GetConfigBool(key, defaultValue) end

--- Read float from settings.jsonc
-- @param key string 
-- @param defaultValue float 
-- @return float 
function GetConfigFloat(key, defaultValue) end

--- Get current game state enum
-- @return int32 
function GetGameState() end

--- Get current match clock in seconds
-- @return float 
function GetMatchTime() end

--- Force Deadlock game state change
-- @param newState int32 
function ChangeGameState(newState) end

--- Set waiting for players roster counts
-- @param readyCount uint32 
-- @param totalCount uint32 
function SetWaitingForPlayersRoster(readyCount, totalCount) end

--- Enable/disable match start sequence on custom maps
-- @param enabled bool 
function SetMatchStartOnAnyMap(enabled) end

--- Check if match start on custom maps is enabled
-- @return bool 
function GetMatchStartOnAnyMap() end

--- Register game event listener for engine event
-- @param name string 
function RegisterGameEvent(name) end

--- Create a new game event
-- @param name string 
-- @param force bool 
-- @return int64 
function CreateGameEvent(name, force) end

--- Fire game event
-- @param event int64 
-- @param dontBroadcast bool 
-- @return bool 
function FireGameEvent(event, dontBroadcast) end

--- Free game event object
-- @param event int64 
function FreeGameEvent(event) end

--- Get boolean key from game event
-- @param event int64 
-- @param key string 
-- @param def bool 
-- @return bool 
function GameEventGetBool(event, key, def) end

--- Get int32 key from game event
-- @param event int64 
-- @param key string 
-- @param def int32 
-- @return int32 
function GameEventGetInt(event, key, def) end

--- Get float key from game event
-- @param event int64 
-- @param key string 
-- @param def float 
-- @return float 
function GameEventGetFloat(event, key, def) end

--- Get string key from game event
-- @param event int64 
-- @param key string 
-- @param def string 
-- @return string 
function GameEventGetString(event, key, def) end

--- Get uint64 key from game event
-- @param event int64 
-- @param key string 
-- @param def uint64 
-- @return uint64 
function GameEventGetUint64(event, key, def) end

--- Set boolean key in game event
-- @param event int64 
-- @param key string 
-- @param val bool 
function GameEventSetBool(event, key, val) end

--- Set int32 key in game event
-- @param event int64 
-- @param key string 
-- @param val int32 
function GameEventSetInt(event, key, val) end

--- Set float key in game event
-- @param event int64 
-- @param key string 
-- @param val float 
function GameEventSetFloat(event, key, val) end

--- Set string key in game event
-- @param event int64 
-- @param key string 
-- @param val string 
function GameEventSetString(event, key, val) end

--- Gets player slot from an event key (e.g. userid)
-- @param event int64 
-- @param key string 
-- @return int32 
function GameEventGetPlayerSlot(event, key) end

--- Gets player pawn pointer from an event key (e.g. userid)
-- @param event int64 
-- @param key string 
-- @return int64 
function GameEventGetPlayerPawn(event, key) end

--- Gets player controller pointer from an event key (e.g. userid)
-- @param event int64 
-- @param key string 
-- @return int64 
function GameEventGetPlayerController(event, key) end

--- Get currently loaded map name
-- @return string 
function GetMapName() end

--- Check if map exists and can be loaded
-- @param map string 
-- @return bool 
function IsMapValid(map) end

--- Set Steam A2S rule key-value
-- @param key string 
-- @param value string 
-- @return bool 
function SetServerKeyValue(key, value) end

--- Clear Steam A2S rules
-- @return bool 
function ClearServerKeyValues() end

--- Set active server workshop addons
-- @param addons string 
function SetServerAddons(addons) end

--- Add file search path
-- @param path string 
-- @param pathId string 
-- @param addType int32 
-- @return bool 
function AddFileSystemSearchPath(path, pathId, addType) end

--- Check if command line argument exists
-- @param parm string 
-- @return bool 
function HasCommandLineParm(parm) end

--- Set reject reason for connection rejection
-- @param reason string 
function SetConnectRejectReason(reason) end

--- Get CGlobalVars pointer
-- @return int64 
function GetGlobalVars() end

--- Get current engine game time in seconds
-- @return float 
function GetGameTime() end

--- Get current engine tick count
-- @return int32 
function GetGameTickCount() end

--- Find ConVar by name
-- @param name string 
-- @return uint64 
function FindConVar(name) end

--- Create custom ConVar
-- @param name string 
-- @param defaultValue string 
-- @param description string 
-- @param flags uint64 
-- @return uint64 
function CreateConVar(name, defaultValue, description, flags) end

--- Get ConVar integer value
-- @param handle uint64 
-- @return int32 
function GetConVarInt(handle) end

--- Get ConVar float value
-- @param handle uint64 
-- @return float 
function GetConVarFloat(handle) end

--- Get ConVar string value
-- @param handle uint64 
-- @return string 
function GetConVarString(handle) end

--- Get ConVar bool value
-- @param handle uint64 
-- @return bool 
function GetConVarBool(handle) end

--- Set ConVar int value
-- @param handle uint64 
-- @param value int32 
function SetConVarInt(handle, value) end

--- Set ConVar float value
-- @param handle uint64 
-- @param value float 
function SetConVarFloat(handle, value) end

--- Set ConVar string value
-- @param handle uint64 
-- @param value string 
-- @return bool 
function SetConVarString(handle, value) end

--- Create CTakeDamageInfo instance
-- @param inflictor int64 
-- @param attacker int64 
-- @param ability int64 
-- @param damage float 
-- @param damageType int32 
-- @return int64 
function CreateDamageInfo(inflictor, attacker, ability, damage, damageType) end

--- Free CTakeDamageInfo instance
-- @param info int64 
function DestroyDamageInfo(info) end

--- Inflict damage on victim entity
-- @param victim int64 
-- @param info int64 
function TakeDamage(victim, info) end

--- Apply damage bypassing damage filters
-- @param victim int64 
-- @param info int64 
function ApplyDamage(victim, info) end

--- Get maximum health of entity
-- @param entity int64 
-- @return int32 
function GetMaxHealth(entity) end

--- Heal entity by amount
-- @param entity int64 
-- @param amount float 
-- @return int32 
function Heal(entity, amount) end

--- Add modifier to entity
-- @param entity int64 
-- @param modifierName string 
-- @param kv3 int64 
-- @param caster int64 
-- @param ability int64 
-- @param team int32 
-- @return int64 
function AddModifier(entity, modifierName, kv3, caster, ability, team) end

--- Remove modifier instance from entity
-- @param entity int64 
-- @param modifier int64 
-- @return bool 
function RemoveModifier(entity, modifier) end

--- Create entity instance by class name
-- @param className string 
-- @return int64 
function CreateEntityByName(className) end

--- Queue entity spawn with optional entity keyvalues
-- @param entity int64 
-- @param ekv int64 
function QueueSpawnEntity(entity, ekv) end

--- Execute queued entity creation
function ExecuteQueuedCreation() end

--- Remove/destroy entity
-- @param entity int64 
function RemoveEntity(entity) end

--- Get entity pointer by index
-- @param index int32 
-- @return int64 
function GetEntityByIndex(index) end

--- Resolve entity pointer from uint32 handle
-- @param handle uint32 
-- @return int64 
function GetEntityFromHandle(handle) end

--- Get handle of entity
-- @param entity int64 
-- @return uint32 
function GetEntityHandle(entity) end

--- Find entity by name
-- @param startEntity int64 
-- @param name string 
-- @return int64 
function FindEntityByName(startEntity, name) end

--- Get designer name of entity
-- @param entity int64 
-- @return string 
function GetEntityDesignerName(entity) end

--- Get class name of entity
-- @param entity int64 
-- @return string 
function GetEntityClassname(entity) end

--- Teleport entity with position, angles and velocity
-- @param entity int64 
-- @param posX float 
-- @param posY float 
-- @param posZ float 
-- @param angPitch float 
-- @param angYaw float 
-- @param angRoll float 
-- @param velX float 
-- @param velY float 
-- @param velZ float 
function Teleport(entity, posX, posY, posZ, angPitch, angYaw, angRoll, velX, velY, velZ) end

--- Set visual model of entity
-- @param entity int64 
-- @param modelName string 
function SetModel(entity, modelName) end

--- Get model name of entity
-- @param entity int64 
-- @return string 
function GetModelName(entity) end

--- Set visual scale of entity
-- @param entity int64 
-- @param scale float 
function SetScale(entity, scale) end

--- Set entity move type
-- @param entity int64 
-- @param moveType uint8 
function SetMoveType(entity, moveType) end

--- Set entity gravity multiplier
-- @param entity int64 
-- @param scale float 
function SetGravityScale(entity, scale) end

--- Check if entity class derives from base class name
-- @param entity int64 
-- @param baseClassName string 
-- @return bool 
function EntityDerivesFrom(entity, baseClassName) end

--- Get byte offset of class field in schema
-- @param className string 
-- @param fieldName string 
-- @return int32 
function GetSchemaFieldOffset(className, fieldName) end

--- Notify network system of field modification
-- @param entity int64 
-- @param fieldOffset int32 
-- @param chainOffset int16 
-- @param networkStateChangedOffset int32 
function NotifyStateChanged(entity, fieldOffset, chainOffset, networkStateChangedOffset) end

--- Set string field in schema structure
-- @param entity int64 
-- @param className string 
-- @param fieldName string 
-- @param value string 
function SetSchemaString(entity, className, fieldName, value) end

--- Get sizeof schema class
-- @param className string 
-- @return int32 
function GetSchemaClassSize(className) end

--- Emit sound event from entity
-- @param entity int64 
-- @param soundName string 
-- @param pitch int32 
-- @param volume float 
-- @param delay float 
function EmitSound(entity, soundName, pitch, volume, delay) end

--- Generate unique sound event GUID
-- @return uint32 
function TakeSoundEventGuid() end

--- Create and dispatch particle effect
-- @param particleName string 
-- @param attachType int32 
-- @param entity int64 
-- @return int64 
function CreateParticle(particleName, attachType, entity) end

--- Destroy active particle instance
-- @param particle int64 
-- @param destroyImmediately bool 
function DestroyParticle(particle, destroyImmediately) end

--- Precache resource by VPK path
-- @param path string 
function PrecacheResource(path) end

--- Precache model resource
-- @param modelPath string 
function PrecacheModel(modelPath) end

--- Create 3D point_worldtext entity in the world
-- @param message string 
-- @param x float 
-- @param y float 
-- @param z float 
-- @param fontSize float 
-- @param r uint8 
-- @param g uint8 
-- @param b uint8 
-- @param a uint8 
-- @return int64 
function CreateWorldText(message, x, y, z, fontSize, r, g, b, a) end

--- Update message text of CPointWorldText
-- @param worldText int64 
-- @param text string 
function SetWorldTextMessage(worldText, text) end

--- Spawn a glowing laser beam entity between two world points
-- @param startX float 
-- @param startY float 
-- @param startZ float 
-- @param endX float 
-- @param endY float 
-- @param endZ float 
-- @param width float 
-- @param r uint8 
-- @param g uint8 
-- @param b uint8 
-- @param a uint8 
-- @return int64 
function CreateBeam(startX, startY, startZ, endX, endY, endZ, width, r, g, b, a) end

--- Create a spatial trigger volume box
-- @param name string 
-- @param minX float 
-- @param minY float 
-- @param minZ float 
-- @param maxX float 
-- @param maxY float 
-- @param maxZ float 
-- @return int64 
function CreateZone(name, minX, minY, minZ, maxX, maxY, maxZ) end

--- Destroy a spatial zone trigger
-- @param zoneId int64 
function DestroyZone(zoneId) end

--- Perform physics raycast trace between start and end vectors
-- @param startX float 
-- @param startY float 
-- @param startZ float 
-- @param endX float 
-- @param endY float 
-- @param endZ float 
-- @param mask uint32 
-- @param ignoreEntity int64 
-- @return bool 
function LineTrace(startX, startY, startZ, endX, endY, endZ, mask, ignoreEntity) end

--- Direct AI NPC to move to goal location
-- @param npc int64 
-- @param x float 
-- @param y float 
-- @param z float 
-- @param run bool 
-- @param tolerance float 
function NpcMoveTo(npc, x, y, z, run, tolerance) end

--- Stop movement of AI NPC
-- @param npc int64 
-- @param instant bool 
function NpcStopMoving(npc, instant) end

--- Set target enemy entity of AI NPC
-- @param npc int64 
-- @param enemy int64 
function NpcSetEnemy(npc, enemy) end

--- Set NPC AI state
-- @param npc int64 
-- @param state int32 
function NpcSetState(npc, state) end

--- Spawn lane or neutral trooper NPC
-- @param posX float 
-- @param posY float 
-- @param posZ float 
-- @param pitch float 
-- @param yaw float 
-- @param roll float 
-- @param team int32 
-- @param type int32 
-- @param variant int32 
-- @param snapToGround bool 
-- @return int64 
function NpcCreateTrooper(posX, posY, posZ, pitch, yaw, roll, team, type, variant, snapToGround) end

--- Find nearest point on navmesh
-- @param x float 
-- @param y float 
-- @param z float 
-- @param maxDistance float 
-- @param hull int32 
-- @return bool 
function NavGetNearestPoint(x, y, z, maxDistance, hull) end

--- Get ground elevation from navmesh
-- @param x float 
-- @param y float 
-- @param z float 
-- @param maxDistance float 
-- @param hull int32 
-- @return float 
function NavGetGroundHeight(x, y, z, maxDistance, hull) end

--- Spawn a bot hero into the match
-- @param heroName string 
-- @param team int32 
-- @param posX float 
-- @param posY float 
-- @param posZ float 
-- @param assignLane bool 
-- @return int64 
function BotCreate(heroName, team, posX, posY, posZ, assignLane) end

--- Get brain entity pointer for player bot pawn
-- @param pawn int64 
-- @return int64 
function BotGetBrain(pawn) end

--- Get pawn entity controlled by bot brain
-- @param brain int64 
-- @return int64 
function BotGetPawn(brain) end

--- Assign lane index to bot
-- @param pawn int64 
-- @param lane int32 
-- @return bool 
function BotSetLane(pawn, lane) end

--- Get assigned lane index of bot
-- @param pawn int64 
-- @return int32 
function BotGetLane(pawn) end

--- Fire input on target entity
-- @param entity int64 
-- @param inputName string 
-- @param activator int64 
-- @param caller int64 
-- @param value string 
function AcceptInput(entity, inputName, activator, caller, value) end

--- Send protobuf network message to clients
-- @param msgId int32 
-- @param protoBytes uint8[] 
-- @param recipientMask uint64 
-- @param bufType int32 
function SendNetMessage(msgId, protoBytes, recipientMask, bufType) end

--- Get registered network message name
-- @param msgId int32 
-- @return string 
function GetNetMessageName(msgId) end

--- Allocate new KeyValues3 document
-- @return int64 
function KV3Create() end

--- Free KeyValues3 document
-- @param kv3 int64 
function KV3Destroy(kv3) end

--- Set string value in KeyValues3 document
-- @param kv3 int64 
-- @param key string 
-- @param value string 
function KV3SetString(kv3, key, value) end

--- Set bool value in KeyValues3 document
-- @param kv3 int64 
-- @param key string 
-- @param value bool 
function KV3SetBool(kv3, key, value) end

--- Set int32 value in KeyValues3 document
-- @param kv3 int64 
-- @param key string 
-- @param value int32 
function KV3SetInt(kv3, key, value) end

--- Set float value in KeyValues3 document
-- @param kv3 int64 
-- @param key string 
-- @param value float 
function KV3SetFloat(kv3, key, value) end

--- Register Currency modification listener hook
-- @param callback function 
-- @callback ModifyCurrencyCallback callback - 
-- @param pawn int64 
-- @param currencyType uint32 
-- @param amount int32 
-- @param source uint32 
-- @param silent bool 
-- @param forceGain bool 
-- @param spendOnly bool 
-- @param sourceAbility int64 
-- @param sourceEntity int64 
-- @return int32 
function OnModifyCurrency_Register(callback) end

--- Unregister Currency modification listener hook
-- @param callback function 
-- @callback ModifyCurrencyCallback callback - 
-- @param pawn int64 
-- @param currencyType uint32 
-- @param amount int32 
-- @param source uint32 
-- @param silent bool 
-- @param forceGain bool 
-- @param spendOnly bool 
-- @param sourceAbility int64 
-- @param sourceEntity int64 
-- @return int32 
function OnModifyCurrency_Unregister(callback) end

--- Register Entity take damage listener hook
-- @param callback function 
-- @callback TakeDamageCallback callback - 
-- @param victim int64 
-- @param damageInfo int64 
-- @return int32 
function OnTakeDamage_Register(callback) end

--- Unregister Entity take damage listener hook
-- @param callback function 
-- @callback TakeDamageCallback callback - 
-- @param victim int64 
-- @param damageInfo int64 
-- @return int32 
function OnTakeDamage_Unregister(callback) end

--- Register Client connection listener hook
-- @param callback function 
-- @callback ClientConnectCallback callback - 
-- @param playerSlot int32 
-- @param name string 
-- @param steamId uint64 
-- @return bool 
function OnClientConnect_Register(callback) end

--- Unregister Client connection listener hook
-- @param callback function 
-- @callback ClientConnectCallback callback - 
-- @param playerSlot int32 
-- @param name string 
-- @param steamId uint64 
-- @return bool 
function OnClientConnect_Unregister(callback) end

--- Register Client put in server listener hook
-- @param callback function 
-- @callback ClientPutInServerCallback callback - 
-- @param playerSlot int32 
function OnClientPutInServer_Register(callback) end

--- Unregister Client put in server listener hook
-- @param callback function 
-- @callback ClientPutInServerCallback callback - 
-- @param playerSlot int32 
function OnClientPutInServer_Unregister(callback) end

--- Register Client disconnect listener hook
-- @param callback function 
-- @callback ClientDisconnectCallback callback - 
-- @param playerSlot int32 
-- @param reason int32 
function OnClientDisconnect_Register(callback) end

--- Unregister Client disconnect listener hook
-- @param callback function 
-- @callback ClientDisconnectCallback callback - 
-- @param playerSlot int32 
-- @param reason int32 
function OnClientDisconnect_Unregister(callback) end

--- Register Server game tick frame listener hook
-- @param callback function 
-- @callback GameFrameCallback callback - 
-- @param simulating bool 
-- @param firstTick bool 
-- @param lastTick bool 
function OnGameFrame_Register(callback) end

--- Unregister Server game tick frame listener hook
-- @param callback function 
-- @callback GameFrameCallback callback - 
-- @param simulating bool 
-- @param firstTick bool 
-- @param lastTick bool 
function OnGameFrame_Unregister(callback) end

--- Register Entity created listener hook
-- @param callback function 
-- @callback EntityCallback callback - 
-- @param entity int64 
function OnEntityCreated_Register(callback) end

--- Unregister Entity created listener hook
-- @param callback function 
-- @callback EntityCallback callback - 
-- @param entity int64 
function OnEntityCreated_Unregister(callback) end

--- Register Entity spawned listener hook
-- @param callback function 
-- @callback EntityCallback callback - 
-- @param entity int64 
function OnEntitySpawned_Register(callback) end

--- Unregister Entity spawned listener hook
-- @param callback function 
-- @callback EntityCallback callback - 
-- @param entity int64 
function OnEntitySpawned_Unregister(callback) end

--- Register Entity deleted listener hook
-- @param callback function 
-- @callback EntityCallback callback - 
-- @param entity int64 
function OnEntityDeleted_Register(callback) end

--- Unregister Entity deleted listener hook
-- @param callback function 
-- @callback EntityCallback callback - 
-- @param entity int64 
function OnEntityDeleted_Unregister(callback) end

--- Register Game state change listener hook
-- @param callback function 
-- @callback GameStateChangedCallback callback - 
-- @param newState int32 
function OnGameStateChanged_Register(callback) end

--- Unregister Game state change listener hook
-- @param callback function 
-- @callback GameStateChangedCallback callback - 
-- @param newState int32 
function OnGameStateChanged_Unregister(callback) end

--- Register Entity AcceptInput listener hook
-- @param callback function 
-- @callback EntityIOCallback callback - 
-- @param className string 
-- @param inputName string 
-- @param entity int64 
-- @param activator int64 
-- @param caller int64 
-- @param value string 
-- @return int32 
function OnEntityAcceptInput_Register(callback) end

--- Unregister Entity AcceptInput listener hook
-- @param callback function 
-- @callback EntityIOCallback callback - 
-- @param className string 
-- @param inputName string 
-- @param entity int64 
-- @param activator int64 
-- @param caller int64 
-- @param value string 
-- @return int32 
function OnEntityAcceptInput_Unregister(callback) end

--- Register NPC schedule selection listener hook
-- @param callback function 
-- @callback NpcSelectScheduleCallback callback - 
-- @param npc int64 
-- @param chosenId string 
-- @return string 
function OnNpcSelectSchedule_Register(callback) end

--- Unregister NPC schedule selection listener hook
-- @param callback function 
-- @callback NpcSelectScheduleCallback callback - 
-- @param npc int64 
-- @param chosenId string 
-- @return string 
function OnNpcSelectSchedule_Unregister(callback) end

--- Register Entity FireOutput listener hook
-- @param callback function 
-- @callback EntityOutputCallback callback - 
-- @param callerClass string 
-- @param outputName string 
-- @param activator int64 
-- @param caller int64 
-- @param delay float 
-- @return int32 
function OnEntityFireOutput_Register(callback) end

--- Unregister Entity FireOutput listener hook
-- @param callback function 
-- @callback EntityOutputCallback callback - 
-- @param callerClass string 
-- @param outputName string 
-- @param activator int64 
-- @param caller int64 
-- @param delay float 
-- @return int32 
function OnEntityFireOutput_Unregister(callback) end

--- Register CBasePlayerController::ProcessUsercmds listener hook
-- @param callback function 
-- @callback ProcessUsercmdsCallback callback - 
-- @param playerSlot int32 
-- @param numCmds int32 
-- @param paused bool 
function OnProcessUsercmds_Register(callback) end

--- Unregister CBasePlayerController::ProcessUsercmds listener hook
-- @param callback function 
-- @callback ProcessUsercmdsCallback callback - 
-- @param playerSlot int32 
-- @param numCmds int32 
-- @param paused bool 
function OnProcessUsercmds_Unregister(callback) end

--- Register CCitadelPlayerPawn::AbilityThink listener hook
-- @param callback function 
-- @callback AbilityThinkCallback callback - 
-- @param playerSlot int32 
-- @param pawn int64 
function OnAbilityThink_Register(callback) end

--- Unregister CCitadelPlayerPawn::AbilityThink listener hook
-- @param callback function 
-- @callback AbilityThinkCallback callback - 
-- @param playerSlot int32 
-- @param pawn int64 
function OnAbilityThink_Unregister(callback) end

--- Register CModifierProperty::AddModifier listener hook
-- @param callback function 
-- @callback AddModifierCallback callback - 
-- @param modifierProp int64 
-- @param caster int64 
-- @param ability uint32 
-- @param team int32 
-- @return int32 
function OnAddModifier_Register(callback) end

--- Unregister CModifierProperty::AddModifier listener hook
-- @param callback function 
-- @callback AddModifierCallback callback - 
-- @param modifierProp int64 
-- @param caster int64 
-- @param ability uint32 
-- @param team int32 
-- @return int32 
function OnAddModifier_Unregister(callback) end

--- Register CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
-- @param callback function 
-- @callback HeroInitializedCallback callback - 
-- @param pawn int64 
function OnHeroInitialized_Register(callback) end

--- Unregister CCitadelPlayerPawn::InitializeHeroOnPawn listener hook
-- @param callback function 
-- @callback HeroInitializedCallback callback - 
-- @param pawn int64 
function OnHeroInitialized_Unregister(callback) end

--- Register game event listener hook (e.g. player_death, player_respawned)
-- @param callback function 
-- @callback GameEventCallback callback - 
-- @param eventName string 
-- @param event int64 
function OnGameEvent_Register(callback) end

--- Unregister game event listener hook
-- @param callback function 
-- @callback GameEventCallback callback - 
-- @param eventName string 
-- @param event int64 
function OnGameEvent_Unregister(callback) end

--- Display a HUD game announcement banner to a player
-- @param playerSlot int32 
-- @param title string 
-- @param description string 
-- @param duration float 
function HudAnnounce(playerSlot, title, description, duration) end

--- Display a HUD game announcement banner to all players
-- @param title string 
-- @param description string 
-- @param duration float 
function HudAnnounceAll(title, description, duration) end

