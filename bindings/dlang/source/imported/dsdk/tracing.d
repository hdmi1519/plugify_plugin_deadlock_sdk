module imported.dsdk.tracing;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Perform physics raycast trace between start and end vectors

	Params:
		startX = 
		startY = 
		startZ = 
		endX = 
		endY = 
		endZ = 
		mask = 
		ignoreEntity = 

	Returns:
		Return value
+/
bool LineTrace(float startX, float startY, float startZ, float endX, float endY, float endZ, uint mask, long ignoreEntity) {
	return __dsdk_LineTrace(startX, startY, startZ, endX, endY, endZ, mask, ignoreEntity);
}
alias _LineTrace = extern (C) bool function(float startX, float startY, float startZ, float endX, float endY, float endZ, uint mask, long ignoreEntity);
export __gshared _LineTrace __dsdk_LineTrace = null;

