#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: zones)

namespace dsdk {

  using _CreateBeam = int64_t (*)(float, float, float, float, float, float, float, uint8_t, uint8_t, uint8_t, uint8_t);
}
extern "C" PLUGIN_API dsdk::_CreateBeam __dsdk_CreateBeam;
namespace dsdk {
  /**
   * @brief Spawn a glowing laser beam entity between two world points
   * @param startX (float)
   * @param startY (float)
   * @param startZ (float)
   * @param endX (float)
   * @param endY (float)
   * @param endZ (float)
   * @param width (float)
   * @param r (uint8)
   * @param g (uint8)
   * @param b (uint8)
   * @param a (uint8)
   * @return int64
   */
  inline int64_t CreateBeam(float startX, float startY, float startZ, float endX, float endY, float endZ, float width, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    return __dsdk_CreateBeam(startX, startY, startZ, endX, endY, endZ, width, r, g, b, a);
  }

  using _CreateZone = int64_t (*)(const plg::string&, float, float, float, float, float, float);
}
extern "C" PLUGIN_API dsdk::_CreateZone __dsdk_CreateZone;
namespace dsdk {
  /**
   * @brief Create a spatial trigger volume box
   * @param name (string)
   * @param minX (float)
   * @param minY (float)
   * @param minZ (float)
   * @param maxX (float)
   * @param maxY (float)
   * @param maxZ (float)
   * @return int64
   */
  inline int64_t CreateZone(const plg::string& name, float minX, float minY, float minZ, float maxX, float maxY, float maxZ) {
    return __dsdk_CreateZone(name, minX, minY, minZ, maxX, maxY, maxZ);
  }

  using _DestroyZone = void (*)(int64_t);
}
extern "C" PLUGIN_API dsdk::_DestroyZone __dsdk_DestroyZone;
namespace dsdk {
  /**
   * @brief Destroy a spatial zone trigger
   * @param zoneId (int64)
   */
  inline void DestroyZone(int64_t zoneId) {
    return __dsdk_DestroyZone(zoneId);
  }

} // namespace dsdk
