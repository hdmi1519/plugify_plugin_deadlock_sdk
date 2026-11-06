module imported.dsdk.particles;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Create and dispatch particle effect

	Params:
		particleName = 
		attachType = 
		entity = 

	Returns:
		Return value
+/
long CreateParticle(string particleName, int attachType, long entity) {
	PlgS _var0 = (particleName);

	return __dsdk_CreateParticle(_var0, attachType, entity);
}
alias _CreateParticle = extern (C) long function(const ref PlgS particleName, int attachType, long entity);
export __gshared _CreateParticle __dsdk_CreateParticle = null;

/++
	Destroy active particle instance

	Params:
		particle = 
		destroyImmediately = 
+/
void DestroyParticle(long particle, bool destroyImmediately) {
	__dsdk_DestroyParticle(particle, destroyImmediately);
}
alias _DestroyParticle = extern (C) void function(long particle, bool destroyImmediately);
export __gshared _DestroyParticle __dsdk_DestroyParticle = null;

