#pragma once

#include "shared.h"

extern void (*__dsdk_OnModifyCurrency_Register)(void*);

static void OnModifyCurrency_Register(void* callback) {
	__dsdk_OnModifyCurrency_Register(callback);
}

extern void (*__dsdk_OnModifyCurrency_Unregister)(void*);

static void OnModifyCurrency_Unregister(void* callback) {
	__dsdk_OnModifyCurrency_Unregister(callback);
}

extern void (*__dsdk_OnTakeDamage_Register)(void*);

static void OnTakeDamage_Register(void* callback) {
	__dsdk_OnTakeDamage_Register(callback);
}

extern void (*__dsdk_OnTakeDamage_Unregister)(void*);

static void OnTakeDamage_Unregister(void* callback) {
	__dsdk_OnTakeDamage_Unregister(callback);
}

extern void (*__dsdk_OnClientConnect_Register)(void*);

static void OnClientConnect_Register(void* callback) {
	__dsdk_OnClientConnect_Register(callback);
}

extern void (*__dsdk_OnClientConnect_Unregister)(void*);

static void OnClientConnect_Unregister(void* callback) {
	__dsdk_OnClientConnect_Unregister(callback);
}

extern void (*__dsdk_OnClientPutInServer_Register)(void*);

static void OnClientPutInServer_Register(void* callback) {
	__dsdk_OnClientPutInServer_Register(callback);
}

extern void (*__dsdk_OnClientPutInServer_Unregister)(void*);

static void OnClientPutInServer_Unregister(void* callback) {
	__dsdk_OnClientPutInServer_Unregister(callback);
}

extern void (*__dsdk_OnClientDisconnect_Register)(void*);

static void OnClientDisconnect_Register(void* callback) {
	__dsdk_OnClientDisconnect_Register(callback);
}

extern void (*__dsdk_OnClientDisconnect_Unregister)(void*);

static void OnClientDisconnect_Unregister(void* callback) {
	__dsdk_OnClientDisconnect_Unregister(callback);
}

extern void (*__dsdk_OnGameFrame_Register)(void*);

static void OnGameFrame_Register(void* callback) {
	__dsdk_OnGameFrame_Register(callback);
}

extern void (*__dsdk_OnGameFrame_Unregister)(void*);

static void OnGameFrame_Unregister(void* callback) {
	__dsdk_OnGameFrame_Unregister(callback);
}

extern void (*__dsdk_OnEntityCreated_Register)(void*);

static void OnEntityCreated_Register(void* callback) {
	__dsdk_OnEntityCreated_Register(callback);
}

extern void (*__dsdk_OnEntityCreated_Unregister)(void*);

static void OnEntityCreated_Unregister(void* callback) {
	__dsdk_OnEntityCreated_Unregister(callback);
}

extern void (*__dsdk_OnEntitySpawned_Register)(void*);

static void OnEntitySpawned_Register(void* callback) {
	__dsdk_OnEntitySpawned_Register(callback);
}

extern void (*__dsdk_OnEntitySpawned_Unregister)(void*);

static void OnEntitySpawned_Unregister(void* callback) {
	__dsdk_OnEntitySpawned_Unregister(callback);
}

extern void (*__dsdk_OnEntityDeleted_Register)(void*);

static void OnEntityDeleted_Register(void* callback) {
	__dsdk_OnEntityDeleted_Register(callback);
}

extern void (*__dsdk_OnEntityDeleted_Unregister)(void*);

static void OnEntityDeleted_Unregister(void* callback) {
	__dsdk_OnEntityDeleted_Unregister(callback);
}

extern void (*__dsdk_OnGameStateChanged_Register)(void*);

static void OnGameStateChanged_Register(void* callback) {
	__dsdk_OnGameStateChanged_Register(callback);
}

extern void (*__dsdk_OnGameStateChanged_Unregister)(void*);

static void OnGameStateChanged_Unregister(void* callback) {
	__dsdk_OnGameStateChanged_Unregister(callback);
}

extern void (*__dsdk_OnEntityAcceptInput_Register)(void*);

static void OnEntityAcceptInput_Register(void* callback) {
	__dsdk_OnEntityAcceptInput_Register(callback);
}

extern void (*__dsdk_OnEntityAcceptInput_Unregister)(void*);

static void OnEntityAcceptInput_Unregister(void* callback) {
	__dsdk_OnEntityAcceptInput_Unregister(callback);
}

extern void (*__dsdk_OnNpcSelectSchedule_Register)(void*);

static void OnNpcSelectSchedule_Register(void* callback) {
	__dsdk_OnNpcSelectSchedule_Register(callback);
}

extern void (*__dsdk_OnNpcSelectSchedule_Unregister)(void*);

static void OnNpcSelectSchedule_Unregister(void* callback) {
	__dsdk_OnNpcSelectSchedule_Unregister(callback);
}

extern void (*__dsdk_OnEntityFireOutput_Register)(void*);

static void OnEntityFireOutput_Register(void* callback) {
	__dsdk_OnEntityFireOutput_Register(callback);
}

extern void (*__dsdk_OnEntityFireOutput_Unregister)(void*);

static void OnEntityFireOutput_Unregister(void* callback) {
	__dsdk_OnEntityFireOutput_Unregister(callback);
}

extern void (*__dsdk_OnProcessUsercmds_Register)(void*);

static void OnProcessUsercmds_Register(void* callback) {
	__dsdk_OnProcessUsercmds_Register(callback);
}

extern void (*__dsdk_OnProcessUsercmds_Unregister)(void*);

static void OnProcessUsercmds_Unregister(void* callback) {
	__dsdk_OnProcessUsercmds_Unregister(callback);
}

extern void (*__dsdk_OnAbilityThink_Register)(void*);

static void OnAbilityThink_Register(void* callback) {
	__dsdk_OnAbilityThink_Register(callback);
}

extern void (*__dsdk_OnAbilityThink_Unregister)(void*);

static void OnAbilityThink_Unregister(void* callback) {
	__dsdk_OnAbilityThink_Unregister(callback);
}

extern void (*__dsdk_OnAddModifier_Register)(void*);

static void OnAddModifier_Register(void* callback) {
	__dsdk_OnAddModifier_Register(callback);
}

extern void (*__dsdk_OnAddModifier_Unregister)(void*);

static void OnAddModifier_Unregister(void* callback) {
	__dsdk_OnAddModifier_Unregister(callback);
}

extern void (*__dsdk_OnHeroInitialized_Register)(void*);

static void OnHeroInitialized_Register(void* callback) {
	__dsdk_OnHeroInitialized_Register(callback);
}

extern void (*__dsdk_OnHeroInitialized_Unregister)(void*);

static void OnHeroInitialized_Unregister(void* callback) {
	__dsdk_OnHeroInitialized_Unregister(callback);
}

extern void (*__dsdk_OnGameEvent_Register)(void*);

static void OnGameEvent_Register(void* callback) {
	__dsdk_OnGameEvent_Register(callback);
}

extern void (*__dsdk_OnGameEvent_Unregister)(void*);

static void OnGameEvent_Unregister(void* callback) {
	__dsdk_OnGameEvent_Unregister(callback);
}

