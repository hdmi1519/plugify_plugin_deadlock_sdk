#pragma once

#include "shared.h"

extern int64_t (*__dsdk_CreateEntityByName)(String*);

static int64_t CreateEntityByName(String* className) {
	return __dsdk_CreateEntityByName(className);
}

extern void (*__dsdk_QueueSpawnEntity)(int64_t, int64_t);

static void QueueSpawnEntity(int64_t entity, int64_t ekv) {
	__dsdk_QueueSpawnEntity(entity, ekv);
}

extern void (*__dsdk_ExecuteQueuedCreation)();

static void ExecuteQueuedCreation() {
	__dsdk_ExecuteQueuedCreation();
}

extern void (*__dsdk_RemoveEntity)(int64_t);

static void RemoveEntity(int64_t entity) {
	__dsdk_RemoveEntity(entity);
}

extern int64_t (*__dsdk_GetEntityByIndex)(int32_t);

static int64_t GetEntityByIndex(int32_t index) {
	return __dsdk_GetEntityByIndex(index);
}

extern int64_t (*__dsdk_GetEntityFromHandle)(uint32_t);

static int64_t GetEntityFromHandle(uint32_t handle) {
	return __dsdk_GetEntityFromHandle(handle);
}

extern uint32_t (*__dsdk_GetEntityHandle)(int64_t);

static uint32_t GetEntityHandle(int64_t entity) {
	return __dsdk_GetEntityHandle(entity);
}

extern int64_t (*__dsdk_FindEntityByName)(int64_t, String*);

static int64_t FindEntityByName(int64_t startEntity, String* name) {
	return __dsdk_FindEntityByName(startEntity, name);
}

extern String (*__dsdk_GetEntityDesignerName)(int64_t);

static String GetEntityDesignerName(int64_t entity) {
	return __dsdk_GetEntityDesignerName(entity);
}

extern String (*__dsdk_GetEntityClassname)(int64_t);

static String GetEntityClassname(int64_t entity) {
	return __dsdk_GetEntityClassname(entity);
}

extern void (*__dsdk_Teleport)(int64_t, float, float, float, float, float, float, float, float, float);

static void Teleport(int64_t entity, float posX, float posY, float posZ, float angPitch, float angYaw, float angRoll, float velX, float velY, float velZ) {
	__dsdk_Teleport(entity, posX, posY, posZ, angPitch, angYaw, angRoll, velX, velY, velZ);
}

extern void (*__dsdk_SetModel)(int64_t, String*);

static void SetModel(int64_t entity, String* modelName) {
	__dsdk_SetModel(entity, modelName);
}

extern String (*__dsdk_GetModelName)(int64_t);

static String GetModelName(int64_t entity) {
	return __dsdk_GetModelName(entity);
}

extern void (*__dsdk_SetScale)(int64_t, float);

static void SetScale(int64_t entity, float scale) {
	__dsdk_SetScale(entity, scale);
}

extern void (*__dsdk_SetMoveType)(int64_t, uint8_t);

static void SetMoveType(int64_t entity, uint8_t moveType) {
	__dsdk_SetMoveType(entity, moveType);
}

extern void (*__dsdk_SetGravityScale)(int64_t, float);

static void SetGravityScale(int64_t entity, float scale) {
	__dsdk_SetGravityScale(entity, scale);
}

extern bool (*__dsdk_EntityDerivesFrom)(int64_t, String*);

static bool EntityDerivesFrom(int64_t entity, String* baseClassName) {
	return __dsdk_EntityDerivesFrom(entity, baseClassName);
}

