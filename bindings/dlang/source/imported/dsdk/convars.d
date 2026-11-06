module imported.dsdk.convars;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Find ConVar by name

	Params:
		name = 

	Returns:
		Return value
+/
ulong FindConVar(string name) {
	PlgS _var0 = (name);

	return __dsdk_FindConVar(_var0);
}
alias _FindConVar = extern (C) ulong function(const ref PlgS name);
export __gshared _FindConVar __dsdk_FindConVar = null;

/++
	Create custom ConVar

	Params:
		name = 
		defaultValue = 
		description = 
		flags = 

	Returns:
		Return value
+/
ulong CreateConVar(string name, string defaultValue, string description, ulong flags) {
	PlgS _var0 = (name);

	PlgS _var1 = (defaultValue);

	PlgS _var2 = (description);

	return __dsdk_CreateConVar(_var0, _var1, _var2, flags);
}
alias _CreateConVar = extern (C) ulong function(const ref PlgS name, const ref PlgS defaultValue, const ref PlgS description, ulong flags);
export __gshared _CreateConVar __dsdk_CreateConVar = null;

/++
	Get ConVar integer value

	Params:
		handle = 

	Returns:
		Return value
+/
int GetConVarInt(ulong handle) {
	return __dsdk_GetConVarInt(handle);
}
alias _GetConVarInt = extern (C) int function(ulong handle);
export __gshared _GetConVarInt __dsdk_GetConVarInt = null;

/++
	Get ConVar float value

	Params:
		handle = 

	Returns:
		Return value
+/
float GetConVarFloat(ulong handle) {
	return __dsdk_GetConVarFloat(handle);
}
alias _GetConVarFloat = extern (C) float function(ulong handle);
export __gshared _GetConVarFloat __dsdk_GetConVarFloat = null;

/++
	Get ConVar string value

	Params:
		handle = 

	Returns:
		Return value
+/
string GetConVarString(ulong handle) {
	return __dsdk_GetConVarString(handle);
}
alias _GetConVarString = extern (C) PlgS function(ulong handle);
export __gshared _GetConVarString __dsdk_GetConVarString = null;

/++
	Get ConVar bool value

	Params:
		handle = 

	Returns:
		Return value
+/
bool GetConVarBool(ulong handle) {
	return __dsdk_GetConVarBool(handle);
}
alias _GetConVarBool = extern (C) bool function(ulong handle);
export __gshared _GetConVarBool __dsdk_GetConVarBool = null;

/++
	Set ConVar int value

	Params:
		handle = 
		value = 
+/
void SetConVarInt(ulong handle, int value) {
	__dsdk_SetConVarInt(handle, value);
}
alias _SetConVarInt = extern (C) void function(ulong handle, int value);
export __gshared _SetConVarInt __dsdk_SetConVarInt = null;

/++
	Set ConVar float value

	Params:
		handle = 
		value = 
+/
void SetConVarFloat(ulong handle, float value) {
	__dsdk_SetConVarFloat(handle, value);
}
alias _SetConVarFloat = extern (C) void function(ulong handle, float value);
export __gshared _SetConVarFloat __dsdk_SetConVarFloat = null;

/++
	Set ConVar string value

	Params:
		handle = 
		value = 

	Returns:
		Return value
+/
bool SetConVarString(ulong handle, string value) {
	PlgS _var1 = (value);

	return __dsdk_SetConVarString(handle, _var1);
}
alias _SetConVarString = extern (C) bool function(ulong handle, const ref PlgS value);
export __gshared _SetConVarString __dsdk_SetConVarString = null;

