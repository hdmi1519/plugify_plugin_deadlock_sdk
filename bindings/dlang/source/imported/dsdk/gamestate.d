module imported.dsdk.gamestate;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Get current game state enum

	Returns:
		Return value
+/
EGameState GetGameState() {
	return __dsdk_GetGameState();
}
alias _GetGameState = extern (C) EGameState function();
export __gshared _GetGameState __dsdk_GetGameState = null;

/++
	Get current match clock in seconds

	Returns:
		Return value
+/
float GetMatchTime() {
	return __dsdk_GetMatchTime();
}
alias _GetMatchTime = extern (C) float function();
export __gshared _GetMatchTime __dsdk_GetMatchTime = null;

/++
	Force Deadlock game state change

	Params:
		newState = 
+/
void ChangeGameState(EGameState newState) {
	__dsdk_ChangeGameState(newState);
}
alias _ChangeGameState = extern (C) void function(EGameState newState);
export __gshared _ChangeGameState __dsdk_ChangeGameState = null;

/++
	Set waiting for players roster counts

	Params:
		readyCount = 
		totalCount = 
+/
void SetWaitingForPlayersRoster(uint readyCount, uint totalCount) {
	__dsdk_SetWaitingForPlayersRoster(readyCount, totalCount);
}
alias _SetWaitingForPlayersRoster = extern (C) void function(uint readyCount, uint totalCount);
export __gshared _SetWaitingForPlayersRoster __dsdk_SetWaitingForPlayersRoster = null;

/++
	Enable/disable match start sequence on custom maps

	Params:
		enabled = 
+/
void SetMatchStartOnAnyMap(bool enabled) {
	__dsdk_SetMatchStartOnAnyMap(enabled);
}
alias _SetMatchStartOnAnyMap = extern (C) void function(bool enabled);
export __gshared _SetMatchStartOnAnyMap __dsdk_SetMatchStartOnAnyMap = null;

/++
	Check if match start on custom maps is enabled

	Returns:
		Return value
+/
bool GetMatchStartOnAnyMap() {
	return __dsdk_GetMatchStartOnAnyMap();
}
alias _GetMatchStartOnAnyMap = extern (C) bool function();
export __gshared _GetMatchStartOnAnyMap __dsdk_GetMatchStartOnAnyMap = null;

