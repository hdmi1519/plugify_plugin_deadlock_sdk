#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: entityio)

namespace dsdk {

  using _AcceptInput = void (*)(int64_t, const plg::string&, int64_t, int64_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_AcceptInput __dsdk_AcceptInput;
namespace dsdk {
  /**
   * @brief Fire input on target entity
   * @param entity (int64)
   * @param inputName (string)
   * @param activator (int64)
   * @param caller (int64)
   * @param value (string)
   */
  inline void AcceptInput(int64_t entity, const plg::string& inputName, int64_t activator, int64_t caller, const plg::string& value) {
    return __dsdk_AcceptInput(entity, inputName, activator, caller, value);
  }

} // namespace dsdk
