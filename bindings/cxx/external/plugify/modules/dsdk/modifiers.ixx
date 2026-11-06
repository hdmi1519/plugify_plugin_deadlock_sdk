// Generated from dsdk.pplugin (group: modifiers)

export module dsdk.modifiers;
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

  using _AddModifier = int64_t (*)(int64_t, const plg::string&, int64_t, int64_t, int64_t, int32_t);
  PLUGIFY_EXPORT _AddModifier __dsdk_AddModifier = nullptr;
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

  int64_t AddModifier(int64_t entity, const plg::string& modifierName, int64_t kv3, int64_t caster, int64_t ability, int32_t team) {
    return __dsdk_AddModifier(entity, modifierName, kv3, caster, ability, team);
  }

  using _RemoveModifier = bool (*)(int64_t, int64_t);
  PLUGIFY_EXPORT _RemoveModifier __dsdk_RemoveModifier = nullptr;
  /**
   * @brief Remove modifier instance from entity
   * @param entity (int64)
   * @param modifier (int64)
   * @return bool
   */

  bool RemoveModifier(int64_t entity, int64_t modifier) {
    return __dsdk_RemoveModifier(entity, modifier);
  }

} // namespace dsdk
