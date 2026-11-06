module imported.dsdk.heroes;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Select a hero for controller

	Params:
		controller = 
		heroName = 
+/
void SelectHero(long controller, string heroName) {
	PlgS _var1 = (heroName);

	__dsdk_SelectHero(controller, _var1);
}
alias _SelectHero = extern (C) void function(long controller, const ref PlgS heroName);
export __gshared _SelectHero __dsdk_SelectHero = null;

/++
	Reset hero state on pawn

	Params:
		pawn = 
		reset = 
+/
void ResetHero(long pawn, bool reset) {
	__dsdk_ResetHero(pawn, reset);
}
alias _ResetHero = extern (C) void function(long pawn, bool reset);
export __gshared _ResetHero __dsdk_ResetHero = null;

/++
	Precache hero assets

	Params:
		heroName = 
+/
void PrecacheHero(string heroName) {
	PlgS _var0 = (heroName);

	__dsdk_PrecacheHero(_var0);
}
alias _PrecacheHero = extern (C) void function(const ref PlgS heroName);
export __gshared _PrecacheHero __dsdk_PrecacheHero = null;

/++
	Force immediate hero pawn respawn

	Params:
		pawn = 
		releaseButtons = 
+/
void ForceRespawn(long pawn, bool releaseButtons) {
	__dsdk_ForceRespawn(pawn, releaseButtons);
}
alias _ForceRespawn = extern (C) void function(long pawn, bool releaseButtons);
export __gshared _ForceRespawn __dsdk_ForceRespawn = null;

/++
	Lookup hero definition pointer

	Params:
		heroName = 

	Returns:
		Return value
+/
long GetHeroData(string heroName) {
	PlgS _var0 = (heroName);

	return __dsdk_GetHeroData(_var0);
}
alias _GetHeroData = extern (C) long function(const ref PlgS heroName);
export __gshared _GetHeroData __dsdk_GetHeroData = null;

/++
	Get name of hero for pawn

	Params:
		pawn = 

	Returns:
		Return value
+/
string GetHeroName(long pawn) {
	return __dsdk_GetHeroName(pawn);
}
alias _GetHeroName = extern (C) PlgS function(long pawn);
export __gshared _GetHeroName __dsdk_GetHeroName = null;

