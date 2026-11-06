// Generated from dsdk.pplugin (group: keyvalues3)

export module dsdk.keyvalues3;
export import dsdk.enums;
export import dsdk.aliases;
export import dsdk.delegates;

import <cstdint>;
import <plg>;

#if defined(_WIN32)
#define PLUGIFY_EXPORT __declspec(dllexport)
#else
#define PLUGIFY_EXPORT __attribute__((visibility("default")))
#endif

export namespace dsdk {

  using _KV3Create = int64_t (*)();
  PLUGIFY_EXPORT _KV3Create __dsdk_KV3Create = nullptr;
  /**
   * @brief Allocate new KeyValues3 document
   * @return int64
   */

  int64_t KV3Create() {
    return __dsdk_KV3Create();
  }

  using _KV3Destroy = void (*)(int64_t);
  PLUGIFY_EXPORT _KV3Destroy __dsdk_KV3Destroy = nullptr;
  /**
   * @brief Free KeyValues3 document
   * @param kv3 (int64)
   */

  void KV3Destroy(int64_t kv3) {
    return __dsdk_KV3Destroy(kv3);
  }

  using _KV3SetString = void (*)(int64_t, const plg::string&, const plg::string&);
  PLUGIFY_EXPORT _KV3SetString __dsdk_KV3SetString = nullptr;
  /**
   * @brief Set string value in KeyValues3 document
   * @param kv3 (int64)
   * @param key (string)
   * @param value (string)
   */

  void KV3SetString(int64_t kv3, const plg::string& key, const plg::string& value) {
    return __dsdk_KV3SetString(kv3, key, value);
  }

  using _KV3SetBool = void (*)(int64_t, const plg::string&, bool);
  PLUGIFY_EXPORT _KV3SetBool __dsdk_KV3SetBool = nullptr;
  /**
   * @brief Set bool value in KeyValues3 document
   * @param kv3 (int64)
   * @param key (string)
   * @param value (bool)
   */

  void KV3SetBool(int64_t kv3, const plg::string& key, bool value) {
    return __dsdk_KV3SetBool(kv3, key, value);
  }

  using _KV3SetInt = void (*)(int64_t, const plg::string&, int32_t);
  PLUGIFY_EXPORT _KV3SetInt __dsdk_KV3SetInt = nullptr;
  /**
   * @brief Set int32 value in KeyValues3 document
   * @param kv3 (int64)
   * @param key (string)
   * @param value (int32)
   */

  void KV3SetInt(int64_t kv3, const plg::string& key, int32_t value) {
    return __dsdk_KV3SetInt(kv3, key, value);
  }

  using _KV3SetFloat = void (*)(int64_t, const plg::string&, float);
  PLUGIFY_EXPORT _KV3SetFloat __dsdk_KV3SetFloat = nullptr;
  /**
   * @brief Set float value in KeyValues3 document
   * @param kv3 (int64)
   * @param key (string)
   * @param value (float)
   */

  void KV3SetFloat(int64_t kv3, const plg::string& key, float value) {
    return __dsdk_KV3SetFloat(kv3, key, value);
  }

} // namespace dsdk
