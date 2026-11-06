#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: configuration)

namespace dsdk {

  using _GetConfigString = plg::string (*)(const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_GetConfigString __dsdk_GetConfigString;
namespace dsdk {
  /**
   * @brief Read string from settings.jsonc
   * @param key (string)
   * @param defaultValue (string)
   * @return string
   */
  inline plg::string GetConfigString(const plg::string& key, const plg::string& defaultValue) {
    return __dsdk_GetConfigString(key, defaultValue);
  }

  using _GetConfigInt = int32_t (*)(const plg::string&, int32_t);
}
extern "C" PLUGIN_API dsdk::_GetConfigInt __dsdk_GetConfigInt;
namespace dsdk {
  /**
   * @brief Read int from settings.jsonc
   * @param key (string)
   * @param defaultValue (int32)
   * @return int32
   */
  inline int32_t GetConfigInt(const plg::string& key, int32_t defaultValue) {
    return __dsdk_GetConfigInt(key, defaultValue);
  }

  using _GetConfigBool = bool (*)(const plg::string&, bool);
}
extern "C" PLUGIN_API dsdk::_GetConfigBool __dsdk_GetConfigBool;
namespace dsdk {
  /**
   * @brief Read bool from settings.jsonc
   * @param key (string)
   * @param defaultValue (bool)
   * @return bool
   */
  inline bool GetConfigBool(const plg::string& key, bool defaultValue) {
    return __dsdk_GetConfigBool(key, defaultValue);
  }

  using _GetConfigFloat = float (*)(const plg::string&, float);
}
extern "C" PLUGIN_API dsdk::_GetConfigFloat __dsdk_GetConfigFloat;
namespace dsdk {
  /**
   * @brief Read float from settings.jsonc
   * @param key (string)
   * @param defaultValue (float)
   * @return float
   */
  inline float GetConfigFloat(const plg::string& key, float defaultValue) {
    return __dsdk_GetConfigFloat(key, defaultValue);
  }

} // namespace dsdk
