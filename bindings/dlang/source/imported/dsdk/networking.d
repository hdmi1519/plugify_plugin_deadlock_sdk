module imported.dsdk.networking;

import plugify.internals;
public import plugify;
public import imported.dsdk.enums;
public import imported.dsdk.aliases;
public import imported.dsdk.delegates;
import std.exception : enforce;
import std.algorithm.mutation : swap;

/++
	Send protobuf network message to clients

	Params:
		msgId = 
		protoBytes = 
		recipientMask = 
		bufType = 
+/
void SendNetMessage(int msgId, ubyte[] protoBytes, ulong recipientMask, int bufType) {
	PlgA!ubyte _var1 = (protoBytes);

	__dsdk_SendNetMessage(msgId, _var1, recipientMask, bufType);
}
alias _SendNetMessage = extern (C) void function(int msgId, const ref PlgA!ubyte protoBytes, ulong recipientMask, int bufType);
export __gshared _SendNetMessage __dsdk_SendNetMessage = null;

/++
	Get registered network message name

	Params:
		msgId = 

	Returns:
		Return value
+/
string GetNetMessageName(int msgId) {
	return __dsdk_GetNetMessageName(msgId);
}
alias _GetNetMessageName = extern (C) PlgS function(int msgId);
export __gshared _GetNetMessageName __dsdk_GetNetMessageName = null;

