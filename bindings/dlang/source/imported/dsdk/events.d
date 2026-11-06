module imported.dsdk.events;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Register game event listener for engine event

	Params:
		name = 
+/
void RegisterGameEvent(string name) {
	PlgS _var0 = (name);

	__dsdk_RegisterGameEvent(_var0);
}
alias _RegisterGameEvent = extern (C) void function(const ref PlgS name);
export __gshared _RegisterGameEvent __dsdk_RegisterGameEvent = null;

/++
	Create a new game event

	Params:
		name = 
		force = 

	Returns:
		Return value
+/
long CreateGameEvent(string name, bool force) {
	PlgS _var0 = (name);

	return __dsdk_CreateGameEvent(_var0, force);
}
alias _CreateGameEvent = extern (C) long function(const ref PlgS name, bool force);
export __gshared _CreateGameEvent __dsdk_CreateGameEvent = null;

/++
	Fire game event

	Params:
		event = 
		dontBroadcast = 

	Returns:
		Return value
+/
bool FireGameEvent(long event, bool dontBroadcast) {
	return __dsdk_FireGameEvent(event, dontBroadcast);
}
alias _FireGameEvent = extern (C) bool function(long event, bool dontBroadcast);
export __gshared _FireGameEvent __dsdk_FireGameEvent = null;

/++
	Free game event object

	Params:
		event = 
+/
void FreeGameEvent(long event) {
	__dsdk_FreeGameEvent(event);
}
alias _FreeGameEvent = extern (C) void function(long event);
export __gshared _FreeGameEvent __dsdk_FreeGameEvent = null;

/++
	Get boolean key from game event

	Params:
		event = 
		key = 
		def = 

	Returns:
		Return value
+/
bool GameEventGetBool(long event, string key, bool def) {
	PlgS _var1 = (key);

	return __dsdk_GameEventGetBool(event, _var1, def);
}
alias _GameEventGetBool = extern (C) bool function(long event, const ref PlgS key, bool def);
export __gshared _GameEventGetBool __dsdk_GameEventGetBool = null;

/++
	Get int32 key from game event

	Params:
		event = 
		key = 
		def = 

	Returns:
		Return value
+/
int GameEventGetInt(long event, string key, int def) {
	PlgS _var1 = (key);

	return __dsdk_GameEventGetInt(event, _var1, def);
}
alias _GameEventGetInt = extern (C) int function(long event, const ref PlgS key, int def);
export __gshared _GameEventGetInt __dsdk_GameEventGetInt = null;

/++
	Get float key from game event

	Params:
		event = 
		key = 
		def = 

	Returns:
		Return value
+/
float GameEventGetFloat(long event, string key, float def) {
	PlgS _var1 = (key);

	return __dsdk_GameEventGetFloat(event, _var1, def);
}
alias _GameEventGetFloat = extern (C) float function(long event, const ref PlgS key, float def);
export __gshared _GameEventGetFloat __dsdk_GameEventGetFloat = null;

/++
	Get string key from game event

	Params:
		event = 
		key = 
		def = 

	Returns:
		Return value
+/
string GameEventGetString(long event, string key, string def) {
	PlgS _var1 = (key);

	PlgS _var2 = (def);

	return __dsdk_GameEventGetString(event, _var1, _var2);
}
alias _GameEventGetString = extern (C) PlgS function(long event, const ref PlgS key, const ref PlgS def);
export __gshared _GameEventGetString __dsdk_GameEventGetString = null;

/++
	Get uint64 key from game event

	Params:
		event = 
		key = 
		def = 

	Returns:
		Return value
+/
ulong GameEventGetUint64(long event, string key, ulong def) {
	PlgS _var1 = (key);

	return __dsdk_GameEventGetUint64(event, _var1, def);
}
alias _GameEventGetUint64 = extern (C) ulong function(long event, const ref PlgS key, ulong def);
export __gshared _GameEventGetUint64 __dsdk_GameEventGetUint64 = null;

/++
	Set boolean key in game event

	Params:
		event = 
		key = 
		val = 
+/
void GameEventSetBool(long event, string key, bool val) {
	PlgS _var1 = (key);

	__dsdk_GameEventSetBool(event, _var1, val);
}
alias _GameEventSetBool = extern (C) void function(long event, const ref PlgS key, bool val);
export __gshared _GameEventSetBool __dsdk_GameEventSetBool = null;

/++
	Set int32 key in game event

	Params:
		event = 
		key = 
		val = 
+/
void GameEventSetInt(long event, string key, int val) {
	PlgS _var1 = (key);

	__dsdk_GameEventSetInt(event, _var1, val);
}
alias _GameEventSetInt = extern (C) void function(long event, const ref PlgS key, int val);
export __gshared _GameEventSetInt __dsdk_GameEventSetInt = null;

/++
	Set float key in game event

	Params:
		event = 
		key = 
		val = 
+/
void GameEventSetFloat(long event, string key, float val) {
	PlgS _var1 = (key);

	__dsdk_GameEventSetFloat(event, _var1, val);
}
alias _GameEventSetFloat = extern (C) void function(long event, const ref PlgS key, float val);
export __gshared _GameEventSetFloat __dsdk_GameEventSetFloat = null;

/++
	Set string key in game event

	Params:
		event = 
		key = 
		val = 
+/
void GameEventSetString(long event, string key, string val) {
	PlgS _var1 = (key);

	PlgS _var2 = (val);

	__dsdk_GameEventSetString(event, _var1, _var2);
}
alias _GameEventSetString = extern (C) void function(long event, const ref PlgS key, const ref PlgS val);
export __gshared _GameEventSetString __dsdk_GameEventSetString = null;

/++
	Gets player slot from an event key (e.g. userid)

	Params:
		event = 
		key = 

	Returns:
		Return value
+/
int GameEventGetPlayerSlot(long event, string key) {
	PlgS _var1 = (key);

	return __dsdk_GameEventGetPlayerSlot(event, _var1);
}
alias _GameEventGetPlayerSlot = extern (C) int function(long event, const ref PlgS key);
export __gshared _GameEventGetPlayerSlot __dsdk_GameEventGetPlayerSlot = null;

/++
	Gets player pawn pointer from an event key (e.g. userid)

	Params:
		event = 
		key = 

	Returns:
		Return value
+/
long GameEventGetPlayerPawn(long event, string key) {
	PlgS _var1 = (key);

	return __dsdk_GameEventGetPlayerPawn(event, _var1);
}
alias _GameEventGetPlayerPawn = extern (C) long function(long event, const ref PlgS key);
export __gshared _GameEventGetPlayerPawn __dsdk_GameEventGetPlayerPawn = null;

/++
	Gets player controller pointer from an event key (e.g. userid)

	Params:
		event = 
		key = 

	Returns:
		Return value
+/
long GameEventGetPlayerController(long event, string key) {
	PlgS _var1 = (key);

	return __dsdk_GameEventGetPlayerController(event, _var1);
}
alias _GameEventGetPlayerController = extern (C) long function(long event, const ref PlgS key);
export __gshared _GameEventGetPlayerController __dsdk_GameEventGetPlayerController = null;

