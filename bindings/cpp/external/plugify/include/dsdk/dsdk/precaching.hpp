#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: precaching)

namespace dsdk {

  using _PrecacheResource = void (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_PrecacheResource __dsdk_PrecacheResource;
namespace dsdk {
  /**
   * @brief Precache resource by VPK path
   * @param path (string)
   */
  inline void PrecacheResource(const plg::string& path) {
    return __dsdk_PrecacheResource(path);
  }

  using _PrecacheModel = void (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_PrecacheModel __dsdk_PrecacheModel;
namespace dsdk {
  /**
   * @brief Precache model resource
   * @param modelPath (string)
   */
  inline void PrecacheModel(const plg::string& modelPath) {
    return __dsdk_PrecacheModel(modelPath);
  }

} // namespace dsdk
