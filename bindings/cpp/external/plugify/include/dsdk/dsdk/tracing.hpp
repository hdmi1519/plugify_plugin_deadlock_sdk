#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: tracing)

namespace dsdk {

  using _LineTrace = bool (*)(float, float, float, float, float, float, uint32_t, int64_t);
}
extern "C" PLUGIN_API dsdk::_LineTrace __dsdk_LineTrace;
namespace dsdk {
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
  inline bool LineTrace(float startX, float startY, float startZ, float endX, float endY, float endZ, uint32_t mask, int64_t ignoreEntity) {
    return __dsdk_LineTrace(startX, startY, startZ, endX, endY, endZ, mask, ignoreEntity);
  }

} // namespace dsdk
