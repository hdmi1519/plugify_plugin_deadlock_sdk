// Generated from dsdk.pplugin (group: tracing)

export module dsdk.tracing;
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

  using _LineTrace = bool (*)(float, float, float, float, float, float, uint32_t, int64_t);
  PLUGIFY_EXPORT _LineTrace __dsdk_LineTrace = nullptr;
  /**
   * @brief Perform physics raycast trace between start and end vectors
   * @param startX (float)
   * @param startY (float)
   * @param startZ (float)
   * @param endX (float)
   * @param endY (float)
   * @param endZ (float)
   * @param mask (uint32)
   * @param ignoreEntity (int64)
   * @return bool
   */

  bool LineTrace(float startX, float startY, float startZ, float endX, float endY, float endZ, uint32_t mask, int64_t ignoreEntity) {
    return __dsdk_LineTrace(startX, startY, startZ, endX, endY, endZ, mask, ignoreEntity);
  }

} // namespace dsdk
