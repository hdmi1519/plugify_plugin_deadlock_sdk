module imported.dsdk.timers;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Create a one-shot or repeating timer

	Params:
		interval = 
		callback = 
		repeating = 

	Returns:
		Return value
+/
long CreateTimer(float interval, TimerCallback callback, bool repeating) {
	return __dsdk_CreateTimer(interval, callback, repeating);
}
alias _CreateTimer = extern (C) long function(float interval, TimerCallback callback, bool repeating);
export __gshared _CreateTimer __dsdk_CreateTimer = null;

/++
	Stop and delete an active timer

	Params:
		timerId = 

	Returns:
		Return value
+/
bool KillTimer(long timerId) {
	return __dsdk_KillTimer(timerId);
}
alias _KillTimer = extern (C) bool function(long timerId);
export __gshared _KillTimer __dsdk_KillTimer = null;

