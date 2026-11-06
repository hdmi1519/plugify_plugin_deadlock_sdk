#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: keyvalues3)

namespace dsdk {

  using _KV3Create = int64_t (*)();
}
extern "C" PLUGIN_API dsdk::_KV3Create __dsdk_KV3Create;
namespace dsdk {
  /**
   * @brief Allocate new KeyValues3 document
   * @return int64
   */
  inline int64_t KV3Create() {
    return __dsdk_KV3Create();
  }

  using _KV3Destroy = void (*)(int64_t);
}
extern "C" PLUGIN_API dsdk::_KV3Destroy __dsdk_KV3Destroy;
namespace dsdk {
  /**
   * @brief Free KeyValues3 document
   * @param kv3 (int64)
   */
  inline void KV3Destroy(int64_t kv3) {
    return __dsdk_KV3Destroy(kv3);
  }

  using _KV3SetString = void (*)(int64_t, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_KV3SetString __dsdk_KV3SetString;
namespace dsdk {
  /**
   * @brief Set string value in KeyValues3 document
   * @param kv3 (int64)
   * @param key (string)
   * @param value (string)
   */
  inline void KV3SetString(int64_t kv3, const plg::string& key, const plg::string& value) {
    return __dsdk_KV3SetString(kv3, key, value);
  }

  using _KV3SetBool = void (*)(int64_t, const plg::string&, bool);
}
extern "C" PLUGIN_API dsdk::_KV3SetBool __dsdk_KV3SetBool;
namespace dsdk {
  /**
   * @brief Set bool value in KeyValues3 document
   * @param kv3 (int64)
   * @param key (string)
   * @param value (bool)
   */
  inline void KV3SetBool(int64_t kv3, const plg::string& key, bool value) {
    return __dsdk_KV3SetBool(kv3, key, value);
  }

  using _KV3SetInt = void (*)(int64_t, const plg::string&, int32_t);
}
extern "C" PLUGIN_API dsdk::_KV3SetInt __dsdk_KV3SetInt;
namespace dsdk {
  /**
   * @brief Set int32 value in KeyValues3 document
   * @param kv3 (int64)
   * @param key (string)
   * @param value (int32)
   */
  inline void KV3SetInt(int64_t kv3, const plg::string& key, int32_t value) {
    return __dsdk_KV3SetInt(kv3, key, value);
  }

  using _KV3SetFloat = void (*)(int64_t, const plg::string&, float);
}
extern "C" PLUGIN_API dsdk::_KV3SetFloat __dsdk_KV3SetFloat;
namespace dsdk {
  /**
   * @brief Set float value in KeyValues3 document
   * @param kv3 (int64)
   * @param key (string)
   * @param value (float)
   */
  inline void KV3SetFloat(int64_t kv3, const plg::string& key, float value) {
    return __dsdk_KV3SetFloat(kv3, key, value);
  }

} // namespace dsdk
