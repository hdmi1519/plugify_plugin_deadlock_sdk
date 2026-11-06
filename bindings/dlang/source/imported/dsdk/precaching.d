module imported.dsdk.precaching;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Precache resource by VPK path

	Params:
		path = 
+/
void PrecacheResource(string path) {
	PlgS _var0 = (path);

	__dsdk_PrecacheResource(_var0);
}
alias _PrecacheResource = extern (C) void function(const ref PlgS path);
export __gshared _PrecacheResource __dsdk_PrecacheResource = null;

/++
	Precache model resource

	Params:
		modelPath = 
+/
void PrecacheModel(string modelPath) {
	PlgS _var0 = (modelPath);

	__dsdk_PrecacheModel(_var0);
}
alias _PrecacheModel = extern (C) void function(const ref PlgS modelPath);
export __gshared _PrecacheModel __dsdk_PrecacheModel = null;

