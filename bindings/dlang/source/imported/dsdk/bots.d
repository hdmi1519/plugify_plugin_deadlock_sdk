module imported.dsdk.bots;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Spawn a bot hero into the match

	Params:
		heroName = 
		team = 
		posX = 
		posY = 
		posZ = 
		assignLane = 

	Returns:
		Return value
+/
long BotCreate(string heroName, int team, float posX, float posY, float posZ, bool assignLane) {
	PlgS _var0 = (heroName);

	return __dsdk_BotCreate(_var0, team, posX, posY, posZ, assignLane);
}
alias _BotCreate = extern (C) long function(const ref PlgS heroName, int team, float posX, float posY, float posZ, bool assignLane);
export __gshared _BotCreate __dsdk_BotCreate = null;

/++
	Get brain entity pointer for player bot pawn

	Params:
		pawn = 

	Returns:
		Return value
+/
long BotGetBrain(long pawn) {
	return __dsdk_BotGetBrain(pawn);
}
alias _BotGetBrain = extern (C) long function(long pawn);
export __gshared _BotGetBrain __dsdk_BotGetBrain = null;

/++
	Get pawn entity controlled by bot brain

	Params:
		brain = 

	Returns:
		Return value
+/
long BotGetPawn(long brain) {
	return __dsdk_BotGetPawn(brain);
}
alias _BotGetPawn = extern (C) long function(long brain);
export __gshared _BotGetPawn __dsdk_BotGetPawn = null;

/++
	Assign lane index to bot

	Params:
		pawn = 
		lane = 

	Returns:
		Return value
+/
bool BotSetLane(long pawn, int lane) {
	return __dsdk_BotSetLane(pawn, lane);
}
alias _BotSetLane = extern (C) bool function(long pawn, int lane);
export __gshared _BotSetLane __dsdk_BotSetLane = null;

/++
	Get assigned lane index of bot

	Params:
		pawn = 

	Returns:
		Return value
+/
int BotGetLane(long pawn) {
	return __dsdk_BotGetLane(pawn);
}
alias _BotGetLane = extern (C) int function(long pawn);
export __gshared _BotGetLane __dsdk_BotGetLane = null;

