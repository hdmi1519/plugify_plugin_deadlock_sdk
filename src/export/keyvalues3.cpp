#include "pch.hpp"
#include <tier1/keyvalues3.h>

extern "C" {

PLUGIN_API int64_t KV3Create() {
    KeyValues3 *kv = new KeyValues3();
    return reinterpret_cast<int64_t>(kv);
}

PLUGIN_API void KV3Destroy(int64_t kv3) {
    if (!kv3) return;
    delete reinterpret_cast<KeyValues3 *>(kv3);
}

PLUGIN_API void KV3SetString(int64_t kv3, const plg::string &key, const plg::string &value) {
    if (!kv3 || key.empty()) return;
    auto *kv = reinterpret_cast<KeyValues3 *>(kv3);
    kv->SetMemberString(CKV3MemberName::Make(key.c_str()), value.c_str());
}

PLUGIN_API void KV3SetBool(int64_t kv3, const plg::string &key, bool value) {
    if (!kv3 || key.empty()) return;
    auto *kv = reinterpret_cast<KeyValues3 *>(kv3);
    kv->SetMemberBool(CKV3MemberName::Make(key.c_str()), value);
}

PLUGIN_API void KV3SetInt(int64_t kv3, const plg::string &key, int32_t value) {
    if (!kv3 || key.empty()) return;
    auto *kv = reinterpret_cast<KeyValues3 *>(kv3);
    kv->SetMemberInt(CKV3MemberName::Make(key.c_str()), value);
}

PLUGIN_API void KV3SetFloat(int64_t kv3, const plg::string &key, float value) {
    if (!kv3 || key.empty()) return;
    auto *kv = reinterpret_cast<KeyValues3 *>(kv3);
    kv->SetMemberFloat(CKV3MemberName::Make(key.c_str()), value);
}

}
