// Generated from dsdk.pplugin (group: configuration)

export module dsdk.configuration;
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

  using _GetConfigString = plg::string (*)(const plg::string&, const plg::string&);
  PLUGIFY_EXPORT _GetConfigString __dsdk_GetConfigString = nullptr;
  /**
   * @brief Read string from settings.jsonc
   * @param key (string)
   * @param defaultValue (string)
   * @return string
   */

  plg::string GetConfigString(const plg::string& key, const plg::string& defaultValue) {
    return __dsdk_GetConfigString(key, defaultValue);
  }

  using _GetConfigInt = int32_t (*)(const plg::string&, int32_t);
  PLUGIFY_EXPORT _GetConfigInt __dsdk_GetConfigInt = nullptr;
  /**
   * @brief Read int from settings.jsonc
   * @param key (string)
   * @param defaultValue (int32)
   * @return int32
   */

  int32_t GetConfigInt(const plg::string& key, int32_t defaultValue) {
    return __dsdk_GetConfigInt(key, defaultValue);
  }

  using _GetConfigBool = bool (*)(const plg::string&, bool);
  PLUGIFY_EXPORT _GetConfigBool __dsdk_GetConfigBool = nullptr;
  /**
   * @brief Read bool from settings.jsonc
   * @param key (string)
   * @param defaultValue (bool)
   * @return bool
   */

  bool GetConfigBool(const plg::string& key, bool defaultValue) {
    return __dsdk_GetConfigBool(key, defaultValue);
  }

  using _GetConfigFloat = float (*)(const plg::string&, float);
  PLUGIFY_EXPORT _GetConfigFloat __dsdk_GetConfigFloat = nullptr;
  /**
   * @brief Read float from settings.jsonc
   * @param key (string)
   * @param defaultValue (float)
   * @return float
   */

  float GetConfigFloat(const plg::string& key, float defaultValue) {
    return __dsdk_GetConfigFloat(key, defaultValue);
  }

} // namespace dsdk
