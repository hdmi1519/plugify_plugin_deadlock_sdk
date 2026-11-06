// Generated from dsdk.pplugin (group: sound)

export module dsdk.sound;
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

  using _EmitSound = void (*)(int64_t, const plg::string&, int32_t, float, float);
  PLUGIFY_EXPORT _EmitSound __dsdk_EmitSound = nullptr;
  /**
   * @brief Emit sound event from entity
   * @param entity (int64)
   * @param soundName (string)
   * @param pitch (int32)
   * @param volume (float)
   * @param delay (float)
   */

  void EmitSound(int64_t entity, const plg::string& soundName, int32_t pitch, float volume, float delay) {
    return __dsdk_EmitSound(entity, soundName, pitch, volume, delay);
  }

  using _TakeSoundEventGuid = uint32_t (*)();
  PLUGIFY_EXPORT _TakeSoundEventGuid __dsdk_TakeSoundEventGuid = nullptr;
  /**
   * @brief Generate unique sound event GUID
   * @return uint32
   */

  uint32_t TakeSoundEventGuid() {
    return __dsdk_TakeSoundEventGuid();
  }

} // namespace dsdk
