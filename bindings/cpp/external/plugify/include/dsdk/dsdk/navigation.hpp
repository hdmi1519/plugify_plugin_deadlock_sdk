#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: navigation)

namespace dsdk {

  using _NavGetNearestPoint = bool (*)(float, float, float, float, int32_t);
}
extern "C" PLUGIN_API dsdk::_NavGetNearestPoint __dsdk_NavGetNearestPoint;
namespace dsdk {
  /**
   * @brief Find nearest point on navmesh
   * @param x (float)
   * @param y (float)
   * @param z (float)
   * @param maxDistance (float)
   * @param hull (int32)
   * @return bool
   */
  inline bool NavGetNearestPoint(float x, float y, float z, float maxDistance, int32_t hull) {
    return __dsdk_NavGetNearestPoint(x, y, z, maxDistance, hull);
  }

  using _NavGetGroundHeight = float (*)(float, float, float, float, int32_t);
}
extern "C" PLUGIN_API dsdk::_NavGetGroundHeight __dsdk_NavGetGroundHeight;
namespace dsdk {
  /**
   * @brief Get ground elevation from navmesh
   * @param x (float)
   * @param y (float)
   * @param z (float)
   * @param maxDistance (float)
   * @param hull (int32)
   * @return float
   */
  inline float NavGetGroundHeight(float x, float y, float z, float maxDistance, int32_t hull) {
    return __dsdk_NavGetGroundHeight(x, y, z, maxDistance, hull);
  }

} // namespace dsdk
