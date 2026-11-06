#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: damage)

namespace dsdk {

  using _CreateDamageInfo = int64_t (*)(int64_t, int64_t, int64_t, float, int32_t);
}
extern "C" PLUGIN_API dsdk::_CreateDamageInfo __dsdk_CreateDamageInfo;
namespace dsdk {
  /**
   * @brief Create CTakeDamageInfo instance
   * @param inflictor (int64)
   * @param attacker (int64)
   * @param ability (int64)
   * @param damage (float)
   * @param damageType (int32)
   * @return int64
   */
  inline int64_t CreateDamageInfo(int64_t inflictor, int64_t attacker, int64_t ability, float damage, int32_t damageType) {
    return __dsdk_CreateDamageInfo(inflictor, attacker, ability, damage, damageType);
  }

  using _DestroyDamageInfo = void (*)(int64_t);
}
extern "C" PLUGIN_API dsdk::_DestroyDamageInfo __dsdk_DestroyDamageInfo;
namespace dsdk {
  /**
   * @brief Free CTakeDamageInfo instance
   * @param info (int64)
   */
  inline void DestroyDamageInfo(int64_t info) {
    return __dsdk_DestroyDamageInfo(info);
  }

  using _TakeDamage = void (*)(int64_t, int64_t);
}
extern "C" PLUGIN_API dsdk::_TakeDamage __dsdk_TakeDamage;
namespace dsdk {
  /**
   * @brief Inflict damage on victim entity
   * @param victim (int64)
   * @param info (int64)
   */
  inline void TakeDamage(int64_t victim, int64_t info) {
    return __dsdk_TakeDamage(victim, info);
  }

  using _ApplyDamage = void (*)(int64_t, int64_t);
}
extern "C" PLUGIN_API dsdk::_ApplyDamage __dsdk_ApplyDamage;
namespace dsdk {
  /**
   * @brief Apply damage bypassing damage filters
   * @param victim (int64)
   * @param info (int64)
   */
  inline void ApplyDamage(int64_t victim, int64_t info) {
    return __dsdk_ApplyDamage(victim, info);
  }

  using _GetMaxHealth = int32_t (*)(int64_t);
}
extern "C" PLUGIN_API dsdk::_GetMaxHealth __dsdk_GetMaxHealth;
namespace dsdk {
  /**
   * @brief Get maximum health of entity
   * @param entity (int64)
   * @return int32
   */
  inline int32_t GetMaxHealth(int64_t entity) {
    return __dsdk_GetMaxHealth(entity);
  }

  using _Heal = int32_t (*)(int64_t, float);
}
extern "C" PLUGIN_API dsdk::_Heal __dsdk_Heal;
namespace dsdk {
  /**
   * @brief Heal entity by amount
   * @param entity (int64)
   * @param amount (float)
   * @return int32
   */
  inline int32_t Heal(int64_t entity, float amount) {
    return __dsdk_Heal(entity, amount);
  }

} // namespace dsdk
