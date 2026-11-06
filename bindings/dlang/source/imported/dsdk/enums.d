module imported.dsdk.enums;

/// Ownership type for RAII wrappers
enum Ownership : bool {
	Borrowed = false,
	Owned = true
}

/// Deadlock currency types
enum ECurrencyType : uint {
	Invalid = 4_294_967_295,
	Gold = 0,
	AbilityPoints = 1,
	AbilityUnlocks = 2,
	DeathPenaltyGold = 3,
	ItemDraftRerolls = 4,
	ItemEnhancements = 5,
	Count = 6,
}

/// Deadlock currency sources
enum ECurrencySource : uint {
	Invalid = 4_294_967_295,
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

/// Deadlock game states
enum EGameState : int {
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

/// Hook callback return value
enum HookResult : int {
	Continue = 0,
	Changed = 1,
	Handled = 2,
	Stop = 3,
}

