#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: schema)

namespace dsdk {

  using _GetSchemaFieldOffset = int32_t (*)(const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_GetSchemaFieldOffset __dsdk_GetSchemaFieldOffset;
namespace dsdk {
  /**
   * @brief Get byte offset of class field in schema
   * @param className (string)
   * @param fieldName (string)
   * @return int32
   */
  inline int32_t GetSchemaFieldOffset(const plg::string& className, const plg::string& fieldName) {
    return __dsdk_GetSchemaFieldOffset(className, fieldName);
  }

  using _NotifyStateChanged = void (*)(int64_t, int32_t, int16_t, int32_t);
}
extern "C" PLUGIN_API dsdk::_NotifyStateChanged __dsdk_NotifyStateChanged;
namespace dsdk {
  /**
   * @brief Notify network system of field modification
   * @param entity (int64)
   * @param fieldOffset (int32)
   * @param chainOffset (int16)
   * @param networkStateChangedOffset (int32)
   */
  inline void NotifyStateChanged(int64_t entity, int32_t fieldOffset, int16_t chainOffset, int32_t networkStateChangedOffset) {
    return __dsdk_NotifyStateChanged(entity, fieldOffset, chainOffset, networkStateChangedOffset);
  }

  using _SetSchemaString = void (*)(int64_t, const plg::string&, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_SetSchemaString __dsdk_SetSchemaString;
namespace dsdk {
  /**
   * @brief Set string field in schema structure
   * @param entity (int64)
   * @param className (string)
   * @param fieldName (string)
   * @param value (string)
   */
  inline void SetSchemaString(int64_t entity, const plg::string& className, const plg::string& fieldName, const plg::string& value) {
    return __dsdk_SetSchemaString(entity, className, fieldName, value);
  }

  using _GetSchemaClassSize = int32_t (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_GetSchemaClassSize __dsdk_GetSchemaClassSize;
namespace dsdk {
  /**
   * @brief Get sizeof schema class
   * @param className (string)
   * @return int32
   */
  inline int32_t GetSchemaClassSize(const plg::string& className) {
    return __dsdk_GetSchemaClassSize(className);
  }

} // namespace dsdk
