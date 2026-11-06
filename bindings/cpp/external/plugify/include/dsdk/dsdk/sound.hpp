#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: sound)

namespace dsdk {

  using _EmitSound = void (*)(int64_t, const plg::string&, int32_t, float, float);
}
extern "C" PLUGIN_API dsdk::_EmitSound __dsdk_EmitSound;
namespace dsdk {
  /**
   * @brief Emit sound event from entity
   * @param entity (int64)
   * @param soundName (string)
   * @param pitch (int32)
   * @param volume (float)
   * @param delay (float)
   */
  inline void EmitSound(int64_t entity, const plg::string& soundName, int32_t pitch, float volume, float delay) {
    return __dsdk_EmitSound(entity, soundName, pitch, volume, delay);
  }

  using _TakeSoundEventGuid = uint32_t (*)();
}
extern "C" PLUGIN_API dsdk::_TakeSoundEventGuid __dsdk_TakeSoundEventGuid;
namespace dsdk {
  /**
   * @brief Generate unique sound event GUID
   * @return uint32
   */
  inline uint32_t TakeSoundEventGuid() {
    return __dsdk_TakeSoundEventGuid();
  }

} // namespace dsdk
