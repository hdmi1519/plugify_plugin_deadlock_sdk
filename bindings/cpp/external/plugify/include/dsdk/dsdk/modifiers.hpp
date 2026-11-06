#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: modifiers)

namespace dsdk {

  using _AddModifier = int64_t (*)(int64_t, const plg::string&, int64_t, int64_t, int64_t, int32_t);
}
extern "C" PLUGIN_API dsdk::_AddModifier __dsdk_AddModifier;
namespace dsdk {
  /**
   * @brief Add modifier to entity
   * @param entity (int64)
   * @param modifierName (string)
   * @param kv3 (int64)
   * @param caster (int64)
   * @param ability (int64)
   * @param team (int32)
   * @return int64
   */
  inline int64_t AddModifier(int64_t entity, const plg::string& modifierName, int64_t kv3, int64_t caster, int64_t ability, int32_t team) {
    return __dsdk_AddModifier(entity, modifierName, kv3, caster, ability, team);
  }

  using _RemoveModifier = bool (*)(int64_t, int64_t);
}
extern "C" PLUGIN_API dsdk::_RemoveModifier __dsdk_RemoveModifier;
namespace dsdk {
  /**
   * @brief Remove modifier instance from entity
   * @param entity (int64)
   * @param modifier (int64)
   * @return bool
   */
  inline bool RemoveModifier(int64_t entity, int64_t modifier) {
    return __dsdk_RemoveModifier(entity, modifier);
  }

} // namespace dsdk
