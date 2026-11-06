module imported.dsdk.server;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Get currently loaded map name

	Returns:
		Return value
+/
string GetMapName() {
	return __dsdk_GetMapName();
}
alias _GetMapName = extern (C) PlgS function();
export __gshared _GetMapName __dsdk_GetMapName = null;

/++
	Check if map exists and can be loaded

	Params:
		map = 

	Returns:
		Return value
+/
bool IsMapValid(string map) {
	PlgS _var0 = (map);

	return __dsdk_IsMapValid(_var0);
}
alias _IsMapValid = extern (C) bool function(const ref PlgS map);
export __gshared _IsMapValid __dsdk_IsMapValid = null;

/++
	Set Steam A2S rule key-value

	Params:
		key = 
		value = 

	Returns:
		Return value
+/
bool SetServerKeyValue(string key, string value) {
	PlgS _var0 = (key);

	PlgS _var1 = (value);

	return __dsdk_SetServerKeyValue(_var0, _var1);
}
alias _SetServerKeyValue = extern (C) bool function(const ref PlgS key, const ref PlgS value);
export __gshared _SetServerKeyValue __dsdk_SetServerKeyValue = null;

/++
	Clear Steam A2S rules

	Returns:
		Return value
+/
bool ClearServerKeyValues() {
	return __dsdk_ClearServerKeyValues();
}
alias _ClearServerKeyValues = extern (C) bool function();
export __gshared _ClearServerKeyValues __dsdk_ClearServerKeyValues = null;

/++
	Set active server workshop addons

	Params:
		addons = 
+/
void SetServerAddons(string addons) {
	PlgS _var0 = (addons);

	__dsdk_SetServerAddons(_var0);
}
alias _SetServerAddons = extern (C) void function(const ref PlgS addons);
export __gshared _SetServerAddons __dsdk_SetServerAddons = null;

/++
	Add file search path

	Params:
		path = 
		pathId = 
		addType = 

	Returns:
		Return value
+/
bool AddFileSystemSearchPath(string path, string pathId, int addType) {
	PlgS _var0 = (path);

	PlgS _var1 = (pathId);

	return __dsdk_AddFileSystemSearchPath(_var0, _var1, addType);
}
alias _AddFileSystemSearchPath = extern (C) bool function(const ref PlgS path, const ref PlgS pathId, int addType);
export __gshared _AddFileSystemSearchPath __dsdk_AddFileSystemSearchPath = null;

/++
	Check if command line argument exists

	Params:
		parm = 

	Returns:
		Return value
+/
bool HasCommandLineParm(string parm) {
	PlgS _var0 = (parm);

	return __dsdk_HasCommandLineParm(_var0);
}
alias _HasCommandLineParm = extern (C) bool function(const ref PlgS parm);
export __gshared _HasCommandLineParm __dsdk_HasCommandLineParm = null;

/++
	Set reject reason for connection rejection

	Params:
		reason = 
+/
void SetConnectRejectReason(string reason) {
	PlgS _var0 = (reason);

	__dsdk_SetConnectRejectReason(_var0);
}
alias _SetConnectRejectReason = extern (C) void function(const ref PlgS reason);
export __gshared _SetConnectRejectReason __dsdk_SetConnectRejectReason = null;

/++
	Get CGlobalVars pointer

	Returns:
		Return value
+/
long GetGlobalVars() {
	return __dsdk_GetGlobalVars();
}
alias _GetGlobalVars = extern (C) long function();
export __gshared _GetGlobalVars __dsdk_GetGlobalVars = null;

/++
	Get current engine game time in seconds

	Returns:
		Return value
+/
float GetGameTime() {
	return __dsdk_GetGameTime();
}
alias _GetGameTime = extern (C) float function();
export __gshared _GetGameTime __dsdk_GetGameTime = null;

/++
	Get current engine tick count

	Returns:
		Return value
+/
int GetGameTickCount() {
	return __dsdk_GetGameTickCount();
}
alias _GetGameTickCount = extern (C) int function();
export __gshared _GetGameTickCount __dsdk_GetGameTickCount = null;

