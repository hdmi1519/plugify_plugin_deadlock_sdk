#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: heroes)

namespace dsdk {

  using _SelectHero = void (*)(int64_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_SelectHero __dsdk_SelectHero;
namespace dsdk {
  /**
   * @brief Select a hero for controller
   * @param controller (int64)
   * @param heroName (string)
   */
  inline void SelectHero(int64_t controller, const plg::string& heroName) {
    return __dsdk_SelectHero(controller, heroName);
  }

  using _ResetHero = void (*)(int64_t, bool);
}
extern "C" PLUGIN_API dsdk::_ResetHero __dsdk_ResetHero;
namespace dsdk {
  /**
   * @brief Reset hero state on pawn
   * @param pawn (int64)
   * @param reset (bool)
   */
  inline void ResetHero(int64_t pawn, bool reset) {
    return __dsdk_ResetHero(pawn, reset);
  }

  using _PrecacheHero = void (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_PrecacheHero __dsdk_PrecacheHero;
namespace dsdk {
  /**
   * @brief Precache hero assets
   * @param heroName (string)
   */
  inline void PrecacheHero(const plg::string& heroName) {
    return __dsdk_PrecacheHero(heroName);
  }

  using _ForceRespawn = void (*)(int64_t, bool);
}
extern "C" PLUGIN_API dsdk::_ForceRespawn __dsdk_ForceRespawn;
namespace dsdk {
  /**
   * @brief Force immediate hero pawn respawn
   * @param pawn (int64)
   * @param releaseButtons (bool)
   */
  inline void ForceRespawn(int64_t pawn, bool releaseButtons) {
    return __dsdk_ForceRespawn(pawn, releaseButtons);
  }

  using _GetHeroData = int64_t (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_GetHeroData __dsdk_GetHeroData;
namespace dsdk {
  /**
   * @brief Lookup hero definition pointer
   * @param heroName (string)
   * @return int64
   */
  inline int64_t GetHeroData(const plg::string& heroName) {
    return __dsdk_GetHeroData(heroName);
  }

  using _GetHeroName = plg::string (*)(int64_t);
}
extern "C" PLUGIN_API dsdk::_GetHeroName __dsdk_GetHeroName;
namespace dsdk {
  /**
   * @brief Get name of hero for pawn
   * @param pawn (int64)
   * @return string
   */
  inline plg::string GetHeroName(int64_t pawn) {
    return __dsdk_GetHeroName(pawn);
  }

} // namespace dsdk
