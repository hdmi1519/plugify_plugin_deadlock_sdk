#pragma once

#include "shared.h"

extern int64_t (*__dsdk_CreateDamageInfo)(int64_t, int64_t, int64_t, float, int32_t);

static int64_t CreateDamageInfo(int64_t inflictor, int64_t attacker, int64_t ability, float damage, int32_t damageType) {
	return __dsdk_CreateDamageInfo(inflictor, attacker, ability, damage, damageType);
}

extern void (*__dsdk_DestroyDamageInfo)(int64_t);

static void DestroyDamageInfo(int64_t info) {
	__dsdk_DestroyDamageInfo(info);
}

extern void (*__dsdk_TakeDamage)(int64_t, int64_t);

static void TakeDamage(int64_t victim, int64_t info) {
	__dsdk_TakeDamage(victim, info);
}

extern void (*__dsdk_ApplyDamage)(int64_t, int64_t);

static void ApplyDamage(int64_t victim, int64_t info) {
	__dsdk_ApplyDamage(victim, info);
}

extern int32_t (*__dsdk_GetMaxHealth)(int64_t);

static int32_t GetMaxHealth(int64_t entity) {
	return __dsdk_GetMaxHealth(entity);
}

extern int32_t (*__dsdk_Heal)(int64_t, float);

static int32_t Heal(int64_t entity, float amount) {
	return __dsdk_Heal(entity, amount);
}

