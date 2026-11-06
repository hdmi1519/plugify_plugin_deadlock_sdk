// Generated from dsdk.pplugin (group: precaching)

export module dsdk.precaching;
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

  using _PrecacheResource = void (*)(const plg::string&);
  PLUGIFY_EXPORT _PrecacheResource __dsdk_PrecacheResource = nullptr;
  /**
   * @brief Precache resource by VPK path
   * @param path (string)
   */

  void PrecacheResource(const plg::string& path) {
    return __dsdk_PrecacheResource(path);
  }

  using _PrecacheModel = void (*)(const plg::string&);
  PLUGIFY_EXPORT _PrecacheModel __dsdk_PrecacheModel = nullptr;
  /**
   * @brief Precache model resource
   * @param modelPath (string)
   */

  void PrecacheModel(const plg::string& modelPath) {
    return __dsdk_PrecacheModel(modelPath);
  }

} // namespace dsdk
