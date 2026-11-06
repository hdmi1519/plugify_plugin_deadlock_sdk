#pragma once

#include "shared.h"

extern void (*__dsdk_NpcMoveTo)(int64_t, float, float, float, bool, float);

static void NpcMoveTo(int64_t npc, float x, float y, float z, bool run, float tolerance) {
	__dsdk_NpcMoveTo(npc, x, y, z, run, tolerance);
}

extern void (*__dsdk_NpcStopMoving)(int64_t, bool);

static void NpcStopMoving(int64_t npc, bool instant) {
	__dsdk_NpcStopMoving(npc, instant);
}

extern void (*__dsdk_NpcSetEnemy)(int64_t, int64_t);

static void NpcSetEnemy(int64_t npc, int64_t enemy) {
	__dsdk_NpcSetEnemy(npc, enemy);
}

extern void (*__dsdk_NpcSetState)(int64_t, int32_t);

static void NpcSetState(int64_t npc, int32_t state) {
	__dsdk_NpcSetState(npc, state);
}

extern int64_t (*__dsdk_NpcCreateTrooper)(float, float, float, float, float, float, int32_t, int32_t, int32_t, bool);

static int64_t NpcCreateTrooper(float posX, float posY, float posZ, float pitch, float yaw, float roll, int32_t team, int32_t type_, int32_t variant, bool snapToGround) {
	return __dsdk_NpcCreateTrooper(posX, posY, posZ, pitch, yaw, roll, team, type_, variant, snapToGround);
}

