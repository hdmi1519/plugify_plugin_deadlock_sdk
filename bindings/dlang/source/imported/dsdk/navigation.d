module imported.dsdk.navigation;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Find nearest point on navmesh

	Params:
		x = 
		y = 
		z = 
		maxDistance = 
		hull = 

	Returns:
		Return value
+/
bool NavGetNearestPoint(float x, float y, float z, float maxDistance, int hull) {
	return __dsdk_NavGetNearestPoint(x, y, z, maxDistance, hull);
}
alias _NavGetNearestPoint = extern (C) bool function(float x, float y, float z, float maxDistance, int hull);
export __gshared _NavGetNearestPoint __dsdk_NavGetNearestPoint = null;

/++
	Get ground elevation from navmesh

	Params:
		x = 
		y = 
		z = 
		maxDistance = 
		hull = 

	Returns:
		Return value
+/
float NavGetGroundHeight(float x, float y, float z, float maxDistance, int hull) {
	return __dsdk_NavGetGroundHeight(x, y, z, maxDistance, hull);
}
alias _NavGetGroundHeight = extern (C) float function(float x, float y, float z, float maxDistance, int hull);
export __gshared _NavGetGroundHeight __dsdk_NavGetGroundHeight = null;

