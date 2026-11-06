module imported.dsdk.npcs;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Direct AI NPC to move to goal location

	Params:
		npc = 
		x = 
		y = 
		z = 
		run = 
		tolerance = 
+/
void NpcMoveTo(long npc, float x, float y, float z, bool run, float tolerance) {
	__dsdk_NpcMoveTo(npc, x, y, z, run, tolerance);
}
alias _NpcMoveTo = extern (C) void function(long npc, float x, float y, float z, bool run, float tolerance);
export __gshared _NpcMoveTo __dsdk_NpcMoveTo = null;

/++
	Stop movement of AI NPC

	Params:
		npc = 
		instant = 
+/
void NpcStopMoving(long npc, bool instant) {
	__dsdk_NpcStopMoving(npc, instant);
}
alias _NpcStopMoving = extern (C) void function(long npc, bool instant);
export __gshared _NpcStopMoving __dsdk_NpcStopMoving = null;

/++
	Set target enemy entity of AI NPC

	Params:
		npc = 
		enemy = 
+/
void NpcSetEnemy(long npc, long enemy) {
	__dsdk_NpcSetEnemy(npc, enemy);
}
alias _NpcSetEnemy = extern (C) void function(long npc, long enemy);
export __gshared _NpcSetEnemy __dsdk_NpcSetEnemy = null;

/++
	Set NPC AI state

	Params:
		npc = 
		state = 
+/
void NpcSetState(long npc, int state) {
	__dsdk_NpcSetState(npc, state);
}
alias _NpcSetState = extern (C) void function(long npc, int state);
export __gshared _NpcSetState __dsdk_NpcSetState = null;

/++
	Spawn lane or neutral trooper NPC

	Params:
		posX = 
		posY = 
		posZ = 
		pitch = 
		yaw = 
		roll = 
		team = 
		type = 
		variant = 
		snapToGround = 

	Returns:
		Return value
+/
long NpcCreateTrooper(float posX, float posY, float posZ, float pitch, float yaw, float roll, int team, int type, int variant, bool snapToGround) {
	return __dsdk_NpcCreateTrooper(posX, posY, posZ, pitch, yaw, roll, team, type, variant, snapToGround);
}
alias _NpcCreateTrooper = extern (C) long function(float posX, float posY, float posZ, float pitch, float yaw, float roll, int team, int type, int variant, bool snapToGround);
export __gshared _NpcCreateTrooper __dsdk_NpcCreateTrooper = null;

