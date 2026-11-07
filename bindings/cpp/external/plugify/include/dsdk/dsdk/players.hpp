#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: players)

namespace dsdk {

  using _GetPlayerController = int64_t (*)(int32_t);
}
extern "C" PLUGIN_API dsdk::_GetPlayerController __dsdk_GetPlayerController;
namespace dsdk {
  /**
   * @brief Get CBasePlayerController address for player slot
   * @param playerSlot (int32)
   * @return int64
   */
  inline int64_t GetPlayerController(int32_t playerSlot) {
    return __dsdk_GetPlayerController(playerSlot);
  }

  using _GetPlayerPawn = int64_t (*)(int32_t);
}
extern "C" PLUGIN_API dsdk::_GetPlayerPawn __dsdk_GetPlayerPawn;
namespace dsdk {
  /**
   * @brief Get CCitadelPlayerPawn address for player slot
   * @param playerSlot (int32)
   * @return int64
   */
  inline int64_t GetPlayerPawn(int32_t playerSlot) {
    return __dsdk_GetPlayerPawn(playerSlot);
  }

  using _GetPlayerSlot = int32_t (*)(int64_t);
}
extern "C" PLUGIN_API dsdk::_GetPlayerSlot __dsdk_GetPlayerSlot;
namespace dsdk {
  /**
   * @brief Get player slot from controller address
   * @param controller (int64)
   * @return int32
   */
  inline int32_t GetPlayerSlot(int64_t controller) {
    return __dsdk_GetPlayerSlot(controller);
  }

  using _GetPlayerName = plg::string (*)(int32_t);
}
extern "C" PLUGIN_API dsdk::_GetPlayerName __dsdk_GetPlayerName;
namespace dsdk {
  /**
   * @brief Get player display name
   * @param playerSlot (int32)
   * @return string
   */
  inline plg::string GetPlayerName(int32_t playerSlot) {
    return __dsdk_GetPlayerName(playerSlot);
  }

  using _GetSteamID = uint64_t (*)(int32_t);
}
extern "C" PLUGIN_API dsdk::_GetSteamID __dsdk_GetSteamID;
namespace dsdk {
  /**
   * @brief Get player 64-bit SteamID
   * @param playerSlot (int32)
   * @return uint64
   */
  inline uint64_t GetSteamID(int32_t playerSlot) {
    return __dsdk_GetSteamID(playerSlot);
  }

  using _IsClientAuthenticated = bool (*)(int32_t);
}
extern "C" PLUGIN_API dsdk::_IsClientAuthenticated __dsdk_IsClientAuthenticated;
namespace dsdk {
  /**
   * @brief Check if player Steam ticket is validated
   * @param playerSlot (int32)
   * @return bool
   */
  inline bool IsClientAuthenticated(int32_t playerSlot) {
    return __dsdk_IsClientAuthenticated(playerSlot);
  }

  using _IsClientConnected = bool (*)(int32_t);
}
extern "C" PLUGIN_API dsdk::_IsClientConnected __dsdk_IsClientConnected;
namespace dsdk {
  /**
   * @brief Check if client is connected
   * @param playerSlot (int32)
   * @return bool
   */
  inline bool IsClientConnected(int32_t playerSlot) {
    return __dsdk_IsClientConnected(playerSlot);
  }

  using _IsFakeClient = bool (*)(int32_t);
}
extern "C" PLUGIN_API dsdk::_IsFakeClient __dsdk_IsFakeClient;
namespace dsdk {
  /**
   * @brief Check if player is a bot/fake client
   * @param playerSlot (int32)
   * @return bool
   */
  inline bool IsFakeClient(int32_t playerSlot) {
    return __dsdk_IsFakeClient(playerSlot);
  }

  using _CreateFakeClient = int32_t (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_CreateFakeClient __dsdk_CreateFakeClient;
namespace dsdk {
  /**
   * @brief Create a fake client in the match
   * @param name (string)
   * @return int32
   */
  inline int32_t CreateFakeClient(const plg::string& name) {
    return __dsdk_CreateFakeClient(name);
  }

  using _DisconnectClient = void (*)(int32_t, int32_t);
}
extern "C" PLUGIN_API dsdk::_DisconnectClient __dsdk_DisconnectClient;
namespace dsdk {
  /**
   * @brief Disconnect a client with disconnection reason code
   * @param playerSlot (int32)
   * @param reason (int32)
   */
  inline void DisconnectClient(int32_t playerSlot, int32_t reason) {
    return __dsdk_DisconnectClient(playerSlot, reason);
  }

  using _KickClient = void (*)(int32_t, const plg::string&, int32_t);
}
extern "C" PLUGIN_API dsdk::_KickClient __dsdk_KickClient;
namespace dsdk {
  /**
   * @brief Kick client with message and code
   * @param playerSlot (int32)
   * @param reason (string)
   * @param code (int32)
   */
  inline void KickClient(int32_t playerSlot, const plg::string& reason, int32_t code) {
    return __dsdk_KickClient(playerSlot, reason, code);
  }

  using _ChangeTeam = void (*)(int64_t, int32_t, bool);
}
extern "C" PLUGIN_API dsdk::_ChangeTeam __dsdk_ChangeTeam;
namespace dsdk {
  /**
   * @brief Change team of player controller
   * @param controller (int64)
   * @param teamNum (int32)
   * @param keepHero (bool)
   */
  inline void ChangeTeam(int64_t controller, int32_t teamNum, bool keepHero) {
    return __dsdk_ChangeTeam(controller, teamNum, keepHero);
  }

  using _GetPlayerPing = int32_t (*)(int32_t);
}
extern "C" PLUGIN_API dsdk::_GetPlayerPing __dsdk_GetPlayerPing;
namespace dsdk {
  /**
   * @brief Get ping of player in milliseconds
   * @param playerSlot (int32)
   * @return int32
   */
  inline int32_t GetPlayerPing(int32_t playerSlot) {
    return __dsdk_GetPlayerPing(playerSlot);
  }

  using _GetPlayerTimeConnected = float (*)(int32_t);
}
extern "C" PLUGIN_API dsdk::_GetPlayerTimeConnected __dsdk_GetPlayerTimeConnected;
namespace dsdk {
  /**
   * @brief Get connection time of player in seconds
   * @param playerSlot (int32)
   * @return float
   */
  inline float GetPlayerTimeConnected(int32_t playerSlot) {
    return __dsdk_GetPlayerTimeConnected(playerSlot);
  }

} // namespace dsdk
