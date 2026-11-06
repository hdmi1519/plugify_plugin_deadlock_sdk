module imported.dsdk.sound;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Emit sound event from entity

	Params:
		entity = 
		soundName = 
		pitch = 
		volume = 
		delay = 
+/
void EmitSound(long entity, string soundName, int pitch, float volume, float delay) {
	PlgS _var1 = (soundName);

	__dsdk_EmitSound(entity, _var1, pitch, volume, delay);
}
alias _EmitSound = extern (C) void function(long entity, const ref PlgS soundName, int pitch, float volume, float delay);
export __gshared _EmitSound __dsdk_EmitSound = null;

/++
	Generate unique sound event GUID

	Returns:
		Return value
+/
uint TakeSoundEventGuid() {
	return __dsdk_TakeSoundEventGuid();
}
alias _TakeSoundEventGuid = extern (C) uint function();
export __gshared _TakeSoundEventGuid __dsdk_TakeSoundEventGuid = null;

