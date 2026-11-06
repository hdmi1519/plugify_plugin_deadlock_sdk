// Generated from dsdk.pplugin (group: navigation)

export module dsdk.navigation;
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

  using _NavGetNearestPoint = bool (*)(float, float, float, float, int32_t);
  PLUGIFY_EXPORT _NavGetNearestPoint __dsdk_NavGetNearestPoint = nullptr;
  /**
   * @brief Find nearest point on navmesh
   * @param x (float)
   * @param y (float)
   * @param z (float)
   * @param maxDistance (float)
   * @param hull (int32)
   * @return bool
   */

  bool NavGetNearestPoint(float x, float y, float z, float maxDistance, int32_t hull) {
    return __dsdk_NavGetNearestPoint(x, y, z, maxDistance, hull);
  }

  using _NavGetGroundHeight = float (*)(float, float, float, float, int32_t);
  PLUGIFY_EXPORT _NavGetGroundHeight __dsdk_NavGetGroundHeight = nullptr;
  /**
   * @brief Get ground elevation from navmesh
   * @param x (float)
   * @param y (float)
   * @param z (float)
   * @param maxDistance (float)
   * @param hull (int32)
   * @return float
   */

  float NavGetGroundHeight(float x, float y, float z, float maxDistance, int32_t hull) {
    return __dsdk_NavGetGroundHeight(x, y, z, maxDistance, hull);
  }

} // namespace dsdk
