#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: particles)

namespace dsdk {

  using _CreateParticle = int64_t (*)(const plg::string&, int32_t, int64_t);
}
extern "C" PLUGIN_API dsdk::_CreateParticle __dsdk_CreateParticle;
namespace dsdk {
  /**
   * @brief Create and dispatch particle effect
   * @param particleName (string)
   * @param attachType (int32)
   * @param entity (int64)
   * @return int64
   */
  inline int64_t CreateParticle(const plg::string& particleName, int32_t attachType, int64_t entity) {
    return __dsdk_CreateParticle(particleName, attachType, entity);
  }

  using _DestroyParticle = void (*)(int64_t, bool);
}
extern "C" PLUGIN_API dsdk::_DestroyParticle __dsdk_DestroyParticle;
namespace dsdk {
  /**
   * @brief Destroy active particle instance
   * @param particle (int64)
   * @param destroyImmediately (bool)
   */
  inline void DestroyParticle(int64_t particle, bool destroyImmediately) {
    return __dsdk_DestroyParticle(particle, destroyImmediately);
  }

} // namespace dsdk
