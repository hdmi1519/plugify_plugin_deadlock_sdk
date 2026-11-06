#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: networking)

namespace dsdk {

  using _SendNetMessage = void (*)(int32_t, const plg::vector<uint8_t>&, uint64_t, int32_t);
}
extern "C" PLUGIN_API dsdk::_SendNetMessage __dsdk_SendNetMessage;
namespace dsdk {
  /**
   * @brief Send protobuf network message to clients
   * @param msgId (int32)
   * @param protoBytes (uint8[])
   * @param recipientMask (uint64)
   * @param bufType (int32)
   */
  inline void SendNetMessage(int32_t msgId, const plg::vector<uint8_t>& protoBytes, uint64_t recipientMask, int32_t bufType) {
    return __dsdk_SendNetMessage(msgId, protoBytes, recipientMask, bufType);
  }

  using _GetNetMessageName = plg::string (*)(int32_t);
}
extern "C" PLUGIN_API dsdk::_GetNetMessageName __dsdk_GetNetMessageName;
namespace dsdk {
  /**
   * @brief Get registered network message name
   * @param msgId (int32)
   * @return string
   */
  inline plg::string GetNetMessageName(int32_t msgId) {
    return __dsdk_GetNetMessageName(msgId);
  }

} // namespace dsdk
