#pragma once

#include "shared.h"

extern int64_t (*__dsdk_KV3Create)();

static int64_t KV3Create() {
	return __dsdk_KV3Create();
}

extern void (*__dsdk_KV3Destroy)(int64_t);

static void KV3Destroy(int64_t kv3) {
	__dsdk_KV3Destroy(kv3);
}

extern void (*__dsdk_KV3SetString)(int64_t, String*, String*);

static void KV3SetString(int64_t kv3, String* key, String* value) {
	__dsdk_KV3SetString(kv3, key, value);
}

extern void (*__dsdk_KV3SetBool)(int64_t, String*, bool);

static void KV3SetBool(int64_t kv3, String* key, bool value) {
	__dsdk_KV3SetBool(kv3, key, value);
}

extern void (*__dsdk_KV3SetInt)(int64_t, String*, int32_t);

static void KV3SetInt(int64_t kv3, String* key, int32_t value) {
	__dsdk_KV3SetInt(kv3, key, value);
}

extern void (*__dsdk_KV3SetFloat)(int64_t, String*, float);

static void KV3SetFloat(int64_t kv3, String* key, float value) {
	__dsdk_KV3SetFloat(kv3, key, value);
}

