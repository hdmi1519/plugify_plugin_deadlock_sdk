module imported.dsdk.delegates;

public import imported.dsdk.enums;
public import imported.dsdk.aliases;

/++
	Params:
		playerSlot = 
		args = 

	Returns:
		Return value
+/
alias CommandCallback = extern (C) void function(int playerSlot, const ref PlgA!string args);

/++
	Returns:
		Return value
+/
alias TimerCallback = extern (C) void function();

/++
	Params:
		pawn = 
		currencyType = 
		amount = 
		source = 
		silent = 
		forceGain = 
		spendOnly = 
		sourceAbility = 
		sourceEntity = 

	Returns:
		Return value
+/
alias ModifyCurrencyCallback = extern (C) HookResult function(long pawn, ECurrencyType currencyType, int amount, ECurrencySource source, bool silent, bool forceGain, bool spendOnly, long sourceAbility, long sourceEntity);

/++
	Params:
		victim = 
		damageInfo = 

	Returns:
		Return value
+/
alias TakeDamageCallback = extern (C) HookResult function(long victim, long damageInfo);

/++
	Params:
		playerSlot = 
		name = 
		steamId = 

	Returns:
		Return value
+/
alias ClientConnectCallback = extern (C) bool function(int playerSlot, const ref PlgS name, ulong steamId);

/++
	Params:
		playerSlot = 

	Returns:
		Return value
+/
alias ClientPutInServerCallback = extern (C) void function(int playerSlot);

/++
	Params:
		playerSlot = 
		reason = 

	Returns:
		Return value
+/
alias ClientDisconnectCallback = extern (C) void function(int playerSlot, int reason);

/++
	Params:
		simulating = 
		firstTick = 
		lastTick = 

	Returns:
		Return value
+/
alias GameFrameCallback = extern (C) void function(bool simulating, bool firstTick, bool lastTick);

/++
	Params:
		entity = 

	Returns:
		Return value
+/
alias EntityCallback = extern (C) void function(long entity);

/++
	Params:
		newState = 

	Returns:
		Return value
+/
alias GameStateChangedCallback = extern (C) void function(EGameState newState);

/++
	Params:
		className = 
		inputName = 
		entity = 
		activator = 
		caller = 
		value = 

	Returns:
		Return value
+/
alias EntityIOCallback = extern (C) HookResult function(const ref PlgS className, const ref PlgS inputName, long entity, long activator, long caller, const ref PlgS value);

/++
	Params:
		npc = 
		chosenId = 

	Returns:
		Return value
+/
alias NpcSelectScheduleCallback = extern (C) ref PlgS function(long npc, const ref PlgS chosenId);

/++
	Params:
		callerClass = 
		outputName = 
		activator = 
		caller = 
		delay = 

	Returns:
		Return value
+/
alias EntityOutputCallback = extern (C) HookResult function(const ref PlgS callerClass, const ref PlgS outputName, long activator, long caller, float delay);

/++
	Params:
		playerSlot = 
		numCmds = 
		paused = 

	Returns:
		Return value
+/
alias ProcessUsercmdsCallback = extern (C) void function(int playerSlot, int numCmds, bool paused);

/++
	Params:
		playerSlot = 
		pawn = 

	Returns:
		Return value
+/
alias AbilityThinkCallback = extern (C) void function(int playerSlot, long pawn);

/++
	Params:
		modifierProp = 
		caster = 
		ability = 
		team = 

	Returns:
		Return value
+/
alias AddModifierCallback = extern (C) HookResult function(long modifierProp, long caster, uint ability, int team);

/++
	Params:
		pawn = 

	Returns:
		Return value
+/
alias HeroInitializedCallback = extern (C) void function(long pawn);

/++
	Params:
		eventName = 
		event = 

	Returns:
		Return value
+/
alias GameEventCallback = extern (C) void function(const ref PlgS eventName, long event);

