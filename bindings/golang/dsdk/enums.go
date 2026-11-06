package dsdk

// Generated from dsdk

// ECurrencyType - Deadlock currency types
type ECurrencyType uint32

const (
	ECurrencyType_Invalid ECurrencyType = 4294967295
	ECurrencyType_Gold ECurrencyType = 0
	ECurrencyType_AbilityPoints ECurrencyType = 1
	ECurrencyType_AbilityUnlocks ECurrencyType = 2
	ECurrencyType_DeathPenaltyGold ECurrencyType = 3
	ECurrencyType_ItemDraftRerolls ECurrencyType = 4
	ECurrencyType_ItemEnhancements ECurrencyType = 5
	ECurrencyType_Count ECurrencyType = 6
)

// ECurrencySource - Deadlock currency sources
type ECurrencySource uint32

const (
	ECurrencySource_Invalid ECurrencySource = 4294967295
	ECurrencySource_ItemPurchase ECurrencySource = 0
	ECurrencySource_ItemUpgrade ECurrencySource = 1
	ECurrencySource_ItemSale ECurrencySource = 2
	ECurrencySource_TreasureChest ECurrencySource = 3
	ECurrencySource_AbilityPurchase ECurrencySource = 4
	ECurrencySource_StartingAmount ECurrencySource = 5
	ECurrencySource_LevelUp ECurrencySource = 6
	ECurrencySource_Cheats ECurrencySource = 7
	ECurrencySource_ResetDeathPenalty ECurrencySource = 8
	ECurrencySource_DroppedOnDeath ECurrencySource = 9
	ECurrencySource_HeroSwap ECurrencySource = 10
	ECurrencySource_PlayerKill ECurrencySource = 11
	ECurrencySource_PlayerKillAssist ECurrencySource = 12
	ECurrencySource_BossKill ECurrencySource = 13
	ECurrencySource_LaneTrooperKill ECurrencySource = 14
	ECurrencySource_NeutralTrooperKill ECurrencySource = 15
	ECurrencySource_NeutralBossKill ECurrencySource = 16
	ECurrencySource_DeniedFromEnemy ECurrencySource = 17
	ECurrencySource_AssassinatePlayerKill ECurrencySource = 18
	ECurrencySource_ItemTrophyCollector ECurrencySource = 19
	ECurrencySource_ItemCultistSacrifice ECurrencySource = 20
	ECurrencySource_ItemGooseEgg ECurrencySource = 21
	ECurrencySource_OrbPlayer ECurrencySource = 22
	ECurrencySource_OrbDeny ECurrencySource = 23
	ECurrencySource_OrbLaneTrooper ECurrencySource = 24
	ECurrencySource_OrbNeutralTrooper ECurrencySource = 25
	ECurrencySource_OrbTier1TrooperBoss ECurrencySource = 26
	ECurrencySource_OrbTier2TrooperBoss ECurrencySource = 27
	ECurrencySource_OrbBaseGuardians ECurrencySource = 28
	ECurrencySource_OrbShrines ECurrencySource = 29
	ECurrencySource_OrbTier3TrooperBoss ECurrencySource = 30
	ECurrencySource_OrbDeployable ECurrencySource = 31
	ECurrencySource_OrbTrophyKill ECurrencySource = 32
	ECurrencySource_OrbTreasureChest ECurrencySource = 33
	ECurrencySource_OrbSiegeTrooper ECurrencySource = 34
	ECurrencySource_OrbSpawner ECurrencySource = 35
	ECurrencySource_NeutralWorldPickup ECurrencySource = 36
	ECurrencySource_BreakablePickup ECurrencySource = 37
	ECurrencySource_PlayerKillComeback ECurrencySource = 38
	ECurrencySource_TeamBonus ECurrencySource = 39
	ECurrencySource_ItemDraftRerollUsed ECurrencySource = 40
	ECurrencySource_ItemEnhancementUsed ECurrencySource = 41
	ECurrencySource_StreetBrawlRoundReset ECurrencySource = 42
	ECurrencySource_Count ECurrencySource = 43
)

// EGameState - Deadlock game states
type EGameState int32

const (
	EGameState_Invalid EGameState = 0
	EGameState_Init EGameState = 1
	EGameState_WaitingForPlayersToJoin EGameState = 2
	EGameState_HeroSelection EGameState = 3
	EGameState_MatchIntro EGameState = 4
	EGameState_WaitForMapToLoad EGameState = 5
	EGameState_PreGameWait EGameState = 6
	EGameState_GameInProgress EGameState = 7
	EGameState_PostGame EGameState = 8
	EGameState_PostGamePlayOfTheGame EGameState = 9
	EGameState_Abandoned EGameState = 10
	EGameState_End EGameState = 11
)

// HookResult - Hook callback return value
type HookResult int32

const (
	HookResult_Continue HookResult = 0
	HookResult_Changed HookResult = 1
	HookResult_Handled HookResult = 2
	HookResult_Stop HookResult = 3
)


