module imported.dsdk.zones;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Spawn a glowing laser beam entity between two world points

	Params:
		startX = 
		startY = 
		startZ = 
		endX = 
		endY = 
		endZ = 
		width = 
		r = 
		g = 
		b = 
		a = 

	Returns:
		Return value
+/
long CreateBeam(float startX, float startY, float startZ, float endX, float endY, float endZ, float width, ubyte r, ubyte g, ubyte b, ubyte a) {
	return __dsdk_CreateBeam(startX, startY, startZ, endX, endY, endZ, width, r, g, b, a);
}
alias _CreateBeam = extern (C) long function(float startX, float startY, float startZ, float endX, float endY, float endZ, float width, ubyte r, ubyte g, ubyte b, ubyte a);
export __gshared _CreateBeam __dsdk_CreateBeam = null;

/++
	Create a spatial trigger volume box

	Params:
		name = 
		minX = 
		minY = 
		minZ = 
		maxX = 
		maxY = 
		maxZ = 

	Returns:
		Return value
+/
long CreateZone(string name, float minX, float minY, float minZ, float maxX, float maxY, float maxZ) {
	PlgS _var0 = (name);

	return __dsdk_CreateZone(_var0, minX, minY, minZ, maxX, maxY, maxZ);
}
alias _CreateZone = extern (C) long function(const ref PlgS name, float minX, float minY, float minZ, float maxX, float maxY, float maxZ);
export __gshared _CreateZone __dsdk_CreateZone = null;

/++
	Destroy a spatial zone trigger

	Params:
		zoneId = 
+/
void DestroyZone(long zoneId) {
	__dsdk_DestroyZone(zoneId);
}
alias _DestroyZone = extern (C) void function(long zoneId);
export __gshared _DestroyZone __dsdk_DestroyZone = null;

