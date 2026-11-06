#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: npcs)

namespace dsdk {

  using _NpcMoveTo = void (*)(int64_t, float, float, float, bool, float);
}
extern "C" PLUGIN_API dsdk::_NpcMoveTo __dsdk_NpcMoveTo;
namespace dsdk {
  /**
   * @brief Direct AI NPC to move to goal location
   * @param npc (int64)
   * @param x (float)
   * @param y (float)
   * @param z (float)
   * @param run (bool)
   * @param tolerance (float)
   */
  inline void NpcMoveTo(int64_t npc, float x, float y, float z, bool run, float tolerance) {
    return __dsdk_NpcMoveTo(npc, x, y, z, run, tolerance);
  }

  using _NpcStopMoving = void (*)(int64_t, bool);
}
extern "C" PLUGIN_API dsdk::_NpcStopMoving __dsdk_NpcStopMoving;
namespace dsdk {
  /**
   * @brief Stop movement of AI NPC
   * @param npc (int64)
   * @param instant (bool)
   */
  inline void NpcStopMoving(int64_t npc, bool instant) {
    return __dsdk_NpcStopMoving(npc, instant);
  }

  using _NpcSetEnemy = void (*)(int64_t, int64_t);
}
extern "C" PLUGIN_API dsdk::_NpcSetEnemy __dsdk_NpcSetEnemy;
namespace dsdk {
  /**
   * @brief Set target enemy entity of AI NPC
   * @param npc (int64)
   * @param enemy (int64)
   */
  inline void NpcSetEnemy(int64_t npc, int64_t enemy) {
    return __dsdk_NpcSetEnemy(npc, enemy);
  }

  using _NpcSetState = void (*)(int64_t, int32_t);
}
extern "C" PLUGIN_API dsdk::_NpcSetState __dsdk_NpcSetState;
namespace dsdk {
  /**
   * @brief Set NPC AI state
   * @param npc (int64)
   * @param state (int32)
   */
  inline void NpcSetState(int64_t npc, int32_t state) {
    return __dsdk_NpcSetState(npc, state);
  }

  using _NpcCreateTrooper = int64_t (*)(float, float, float, float, float, float, int32_t, int32_t, int32_t, bool);
}
extern "C" PLUGIN_API dsdk::_NpcCreateTrooper __dsdk_NpcCreateTrooper;
namespace dsdk {
  /**
   * @brief Spawn lane or neutral trooper NPC
   * @param posX (float)
   * @param posY (float)
   * @param posZ (float)
   * @param pitch (float)
   * @param yaw (float)
   * @param roll (float)
   * @param team (int32)
   * @param type (int32)
   * @param variant (int32)
   * @param snapToGround (bool)
   * @return int64
   */
  inline int64_t NpcCreateTrooper(float posX, float posY, float posZ, float pitch, float yaw, float roll, int32_t team, int32_t type, int32_t variant, bool snapToGround) {
    return __dsdk_NpcCreateTrooper(posX, posY, posZ, pitch, yaw, roll, team, type, variant, snapToGround);
  }

} // namespace dsdk
