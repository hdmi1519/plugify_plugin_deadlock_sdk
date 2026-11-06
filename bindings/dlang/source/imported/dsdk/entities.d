module imported.dsdk.entities;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Create entity instance by class name

	Params:
		className = 

	Returns:
		Return value
+/
long CreateEntityByName(string className) {
	PlgS _var0 = (className);

	return __dsdk_CreateEntityByName(_var0);
}
alias _CreateEntityByName = extern (C) long function(const ref PlgS className);
export __gshared _CreateEntityByName __dsdk_CreateEntityByName = null;

/++
	Queue entity spawn with optional entity keyvalues

	Params:
		entity = 
		ekv = 
+/
void QueueSpawnEntity(long entity, long ekv) {
	__dsdk_QueueSpawnEntity(entity, ekv);
}
alias _QueueSpawnEntity = extern (C) void function(long entity, long ekv);
export __gshared _QueueSpawnEntity __dsdk_QueueSpawnEntity = null;

/++
	Execute queued entity creation
+/
void ExecuteQueuedCreation() {
	__dsdk_ExecuteQueuedCreation();
}
alias _ExecuteQueuedCreation = extern (C) void function();
export __gshared _ExecuteQueuedCreation __dsdk_ExecuteQueuedCreation = null;

/++
	Remove/destroy entity

	Params:
		entity = 
+/
void RemoveEntity(long entity) {
	__dsdk_RemoveEntity(entity);
}
alias _RemoveEntity = extern (C) void function(long entity);
export __gshared _RemoveEntity __dsdk_RemoveEntity = null;

/++
	Get entity pointer by index

	Params:
		index = 

	Returns:
		Return value
+/
long GetEntityByIndex(int index) {
	return __dsdk_GetEntityByIndex(index);
}
alias _GetEntityByIndex = extern (C) long function(int index);
export __gshared _GetEntityByIndex __dsdk_GetEntityByIndex = null;

/++
	Resolve entity pointer from uint32 handle

	Params:
		handle = 

	Returns:
		Return value
+/
long GetEntityFromHandle(uint handle) {
	return __dsdk_GetEntityFromHandle(handle);
}
alias _GetEntityFromHandle = extern (C) long function(uint handle);
export __gshared _GetEntityFromHandle __dsdk_GetEntityFromHandle = null;

/++
	Get handle of entity

	Params:
		entity = 

	Returns:
		Return value
+/
uint GetEntityHandle(long entity) {
	return __dsdk_GetEntityHandle(entity);
}
alias _GetEntityHandle = extern (C) uint function(long entity);
export __gshared _GetEntityHandle __dsdk_GetEntityHandle = null;

/++
	Find entity by name

	Params:
		startEntity = 
		name = 

	Returns:
		Return value
+/
long FindEntityByName(long startEntity, string name) {
	PlgS _var1 = (name);

	return __dsdk_FindEntityByName(startEntity, _var1);
}
alias _FindEntityByName = extern (C) long function(long startEntity, const ref PlgS name);
export __gshared _FindEntityByName __dsdk_FindEntityByName = null;

/++
	Get designer name of entity

	Params:
		entity = 

	Returns:
		Return value
+/
string GetEntityDesignerName(long entity) {
	return __dsdk_GetEntityDesignerName(entity);
}
alias _GetEntityDesignerName = extern (C) PlgS function(long entity);
export __gshared _GetEntityDesignerName __dsdk_GetEntityDesignerName = null;

/++
	Get class name of entity

	Params:
		entity = 

	Returns:
		Return value
+/
string GetEntityClassname(long entity) {
	return __dsdk_GetEntityClassname(entity);
}
alias _GetEntityClassname = extern (C) PlgS function(long entity);
export __gshared _GetEntityClassname __dsdk_GetEntityClassname = null;

/++
	Teleport entity with position, angles and velocity

	Params:
		entity = 
		posX = 
		posY = 
		posZ = 
		angPitch = 
		angYaw = 
		angRoll = 
		velX = 
		velY = 
		velZ = 
+/
void Teleport(long entity, float posX, float posY, float posZ, float angPitch, float angYaw, float angRoll, float velX, float velY, float velZ) {
	__dsdk_Teleport(entity, posX, posY, posZ, angPitch, angYaw, angRoll, velX, velY, velZ);
}
alias _Teleport = extern (C) void function(long entity, float posX, float posY, float posZ, float angPitch, float angYaw, float angRoll, float velX, float velY, float velZ);
export __gshared _Teleport __dsdk_Teleport = null;

/++
	Set visual model of entity

	Params:
		entity = 
		modelName = 
+/
void SetModel(long entity, string modelName) {
	PlgS _var1 = (modelName);

	__dsdk_SetModel(entity, _var1);
}
alias _SetModel = extern (C) void function(long entity, const ref PlgS modelName);
export __gshared _SetModel __dsdk_SetModel = null;

/++
	Get model name of entity

	Params:
		entity = 

	Returns:
		Return value
+/
string GetModelName(long entity) {
	return __dsdk_GetModelName(entity);
}
alias _GetModelName = extern (C) PlgS function(long entity);
export __gshared _GetModelName __dsdk_GetModelName = null;

/++
	Set visual scale of entity

	Params:
		entity = 
		scale = 
+/
void SetScale(long entity, float scale) {
	__dsdk_SetScale(entity, scale);
}
alias _SetScale = extern (C) void function(long entity, float scale);
export __gshared _SetScale __dsdk_SetScale = null;

/++
	Set entity move type

	Params:
		entity = 
		moveType = 
+/
void SetMoveType(long entity, ubyte moveType) {
	__dsdk_SetMoveType(entity, moveType);
}
alias _SetMoveType = extern (C) void function(long entity, ubyte moveType);
export __gshared _SetMoveType __dsdk_SetMoveType = null;

/++
	Set entity gravity multiplier

	Params:
		entity = 
		scale = 
+/
void SetGravityScale(long entity, float scale) {
	__dsdk_SetGravityScale(entity, scale);
}
alias _SetGravityScale = extern (C) void function(long entity, float scale);
export __gshared _SetGravityScale __dsdk_SetGravityScale = null;

/++
	Check if entity class derives from base class name

	Params:
		entity = 
		baseClassName = 

	Returns:
		Return value
+/
bool EntityDerivesFrom(long entity, string baseClassName) {
	PlgS _var1 = (baseClassName);

	return __dsdk_EntityDerivesFrom(entity, _var1);
}
alias _EntityDerivesFrom = extern (C) bool function(long entity, const ref PlgS baseClassName);
export __gshared _EntityDerivesFrom __dsdk_EntityDerivesFrom = null;

