// Generated from dsdk.pplugin (group: particles)

export module dsdk.particles;
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

  using _CreateParticle = int64_t (*)(const plg::string&, int32_t, int64_t);
  PLUGIFY_EXPORT _CreateParticle __dsdk_CreateParticle = nullptr;
  /**
   * @brief Create and dispatch particle effect
   * @param particleName (string)
   * @param attachType (int32)
   * @param entity (int64)
   * @return int64
   */

  int64_t CreateParticle(const plg::string& particleName, int32_t attachType, int64_t entity) {
    return __dsdk_CreateParticle(particleName, attachType, entity);
  }

  using _DestroyParticle = void (*)(int64_t, bool);
  PLUGIFY_EXPORT _DestroyParticle __dsdk_DestroyParticle = nullptr;
  /**
   * @brief Destroy active particle instance
   * @param particle (int64)
   * @param destroyImmediately (bool)
   */

  void DestroyParticle(int64_t particle, bool destroyImmediately) {
    return __dsdk_DestroyParticle(particle, destroyImmediately);
  }

} // namespace dsdk
