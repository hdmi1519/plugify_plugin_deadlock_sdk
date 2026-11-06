module imported.dsdk.schema;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Get byte offset of class field in schema

	Params:
		className = 
		fieldName = 

	Returns:
		Return value
+/
int GetSchemaFieldOffset(string className, string fieldName) {
	PlgS _var0 = (className);

	PlgS _var1 = (fieldName);

	return __dsdk_GetSchemaFieldOffset(_var0, _var1);
}
alias _GetSchemaFieldOffset = extern (C) int function(const ref PlgS className, const ref PlgS fieldName);
export __gshared _GetSchemaFieldOffset __dsdk_GetSchemaFieldOffset = null;

/++
	Notify network system of field modification

	Params:
		entity = 
		fieldOffset = 
		chainOffset = 
		networkStateChangedOffset = 
+/
void NotifyStateChanged(long entity, int fieldOffset, short chainOffset, int networkStateChangedOffset) {
	__dsdk_NotifyStateChanged(entity, fieldOffset, chainOffset, networkStateChangedOffset);
}
alias _NotifyStateChanged = extern (C) void function(long entity, int fieldOffset, short chainOffset, int networkStateChangedOffset);
export __gshared _NotifyStateChanged __dsdk_NotifyStateChanged = null;

/++
	Set string field in schema structure

	Params:
		entity = 
		className = 
		fieldName = 
		value = 
+/
void SetSchemaString(long entity, string className, string fieldName, string value) {
	PlgS _var1 = (className);

	PlgS _var2 = (fieldName);

	PlgS _var3 = (value);

	__dsdk_SetSchemaString(entity, _var1, _var2, _var3);
}
alias _SetSchemaString = extern (C) void function(long entity, const ref PlgS className, const ref PlgS fieldName, const ref PlgS value);
export __gshared _SetSchemaString __dsdk_SetSchemaString = null;

/++
	Get sizeof schema class

	Params:
		className = 

	Returns:
		Return value
+/
int GetSchemaClassSize(string className) {
	PlgS _var0 = (className);

	return __dsdk_GetSchemaClassSize(_var0);
}
alias _GetSchemaClassSize = extern (C) int function(const ref PlgS className);
export __gshared _GetSchemaClassSize __dsdk_GetSchemaClassSize = null;

