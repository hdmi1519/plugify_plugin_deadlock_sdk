#pragma once

#include "shared.h"

extern void (*__dsdk_SendNetMessage)(int32_t, Vector*, uint64_t, int32_t);

static void SendNetMessage(int32_t msgId, Vector* protoBytes, uint64_t recipientMask, int32_t bufType) {
	__dsdk_SendNetMessage(msgId, protoBytes, recipientMask, bufType);
}

extern String (*__dsdk_GetNetMessageName)(int32_t);

static String GetNetMessageName(int32_t msgId) {
	return __dsdk_GetNetMessageName(msgId);
}

