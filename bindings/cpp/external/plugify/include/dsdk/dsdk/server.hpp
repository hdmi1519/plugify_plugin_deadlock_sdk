#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: server)

namespace dsdk {

  using _GetMapName = plg::string (*)();
}
extern "C" PLUGIN_API dsdk::_GetMapName __dsdk_GetMapName;
namespace dsdk {
  /**
   * @brief Get currently loaded map name
   * @return string
   */
  inline plg::string GetMapName() {
    return __dsdk_GetMapName();
  }

  using _IsMapValid = bool (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_IsMapValid __dsdk_IsMapValid;
namespace dsdk {
  /**
   * @brief Check if map exists and can be loaded
   * @param map (string)
   * @return bool
   */
  inline bool IsMapValid(const plg::string& map) {
    return __dsdk_IsMapValid(map);
  }

  using _SetServerKeyValue = bool (*)(const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_SetServerKeyValue __dsdk_SetServerKeyValue;
namespace dsdk {
  /**
   * @brief Set Steam A2S rule key-value
   * @param key (string)
   * @param value (string)
   * @return bool
   */
  inline bool SetServerKeyValue(const plg::string& key, const plg::string& value) {
    return __dsdk_SetServerKeyValue(key, value);
  }

  using _ClearServerKeyValues = bool (*)();
}
extern "C" PLUGIN_API dsdk::_ClearServerKeyValues __dsdk_ClearServerKeyValues;
namespace dsdk {
  /**
   * @brief Clear Steam A2S rules
   * @return bool
   */
  inline bool ClearServerKeyValues() {
    return __dsdk_ClearServerKeyValues();
  }

  using _SetServerAddons = void (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_SetServerAddons __dsdk_SetServerAddons;
namespace dsdk {
  /**
   * @brief Set active server workshop addons
   * @param addons (string)
   */
  inline void SetServerAddons(const plg::string& addons) {
    return __dsdk_SetServerAddons(addons);
  }

  using _AddFileSystemSearchPath = bool (*)(const plg::string&, const plg::string&, int32_t);
}
extern "C" PLUGIN_API dsdk::_AddFileSystemSearchPath __dsdk_AddFileSystemSearchPath;
namespace dsdk {
  /**
   * @brief Add file search path
   * @param path (string)
   * @param pathId (string)
   * @param addType (int32)
   * @return bool
   */
  inline bool AddFileSystemSearchPath(const plg::string& path, const plg::string& pathId, int32_t addType) {
    return __dsdk_AddFileSystemSearchPath(path, pathId, addType);
  }

  using _HasCommandLineParm = bool (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_HasCommandLineParm __dsdk_HasCommandLineParm;
namespace dsdk {
  /**
   * @brief Check if command line argument exists
   * @param parm (string)
   * @return bool
   */
  inline bool HasCommandLineParm(const plg::string& parm) {
    return __dsdk_HasCommandLineParm(parm);
  }

  using _SetConnectRejectReason = void (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_SetConnectRejectReason __dsdk_SetConnectRejectReason;
namespace dsdk {
  /**
   * @brief Set reject reason for connection rejection
   * @param reason (string)
   */
  inline void SetConnectRejectReason(const plg::string& reason) {
    return __dsdk_SetConnectRejectReason(reason);
  }

  using _GetGlobalVars = int64_t (*)();
}
extern "C" PLUGIN_API dsdk::_GetGlobalVars __dsdk_GetGlobalVars;
namespace dsdk {
  /**
   * @brief Get CGlobalVars pointer
   * @return int64
   */
  inline int64_t GetGlobalVars() {
    return __dsdk_GetGlobalVars();
  }

  using _GetGameTime = float (*)();
}
extern "C" PLUGIN_API dsdk::_GetGameTime __dsdk_GetGameTime;
namespace dsdk {
  /**
   * @brief Get current engine game time in seconds
   * @return float
   */
  inline float GetGameTime() {
    return __dsdk_GetGameTime();
  }

  using _GetGameTickCount = int32_t (*)();
}
extern "C" PLUGIN_API dsdk::_GetGameTickCount __dsdk_GetGameTickCount;
namespace dsdk {
  /**
   * @brief Get current engine tick count
   * @return int32
   */
  inline int32_t GetGameTickCount() {
    return __dsdk_GetGameTickCount();
  }

} // namespace dsdk
