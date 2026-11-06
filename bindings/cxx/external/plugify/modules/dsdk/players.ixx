// Generated from dsdk.pplugin (group: players)

export module dsdk.players;
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

  using _GetPlayerController = int64_t (*)(int32_t);
  PLUGIFY_EXPORT _GetPlayerController __dsdk_GetPlayerController = nullptr;
  /**
   * @brief Get CBasePlayerController address for player slot
   * @param playerSlot (int32)
   * @return int64
   */

  int64_t GetPlayerController(int32_t playerSlot) {
    return __dsdk_GetPlayerController(playerSlot);
  }

  using _GetPlayerPawn = int64_t (*)(int32_t);
  PLUGIFY_EXPORT _GetPlayerPawn __dsdk_GetPlayerPawn = nullptr;
  /**
   * @brief Get CCitadelPlayerPawn address for player slot
   * @param playerSlot (int32)
   * @return int64
   */

  int64_t GetPlayerPawn(int32_t playerSlot) {
    return __dsdk_GetPlayerPawn(playerSlot);
  }

  using _GetPlayerSlot = int32_t (*)(int64_t);
  PLUGIFY_EXPORT _GetPlayerSlot __dsdk_GetPlayerSlot = nullptr;
  /**
   * @brief Get player slot from controller address
   * @param controller (int64)
   * @return int32
   */

  int32_t GetPlayerSlot(int64_t controller) {
    return __dsdk_GetPlayerSlot(controller);
  }

  using _GetPlayerName = plg::string (*)(int32_t);
  PLUGIFY_EXPORT _GetPlayerName __dsdk_GetPlayerName = nullptr;
  /**
   * @brief Get player display name
   * @param playerSlot (int32)
   * @return string
   */

  plg::string GetPlayerName(int32_t playerSlot) {
    return __dsdk_GetPlayerName(playerSlot);
  }

  using _GetSteamID = uint64_t (*)(int32_t);
  PLUGIFY_EXPORT _GetSteamID __dsdk_GetSteamID = nullptr;
  /**
   * @brief Get player 64-bit SteamID
   * @param playerSlot (int32)
   * @return uint64
   */

  uint64_t GetSteamID(int32_t playerSlot) {
    return __dsdk_GetSteamID(playerSlot);
  }

  using _IsClientAuthenticated = bool (*)(int32_t);
  PLUGIFY_EXPORT _IsClientAuthenticated __dsdk_IsClientAuthenticated = nullptr;
  /**
   * @brief Check if player Steam ticket is validated
   * @param playerSlot (int32)
   * @return bool
   */

  bool IsClientAuthenticated(int32_t playerSlot) {
    return __dsdk_IsClientAuthenticated(playerSlot);
  }

  using _IsClientConnected = bool (*)(int32_t);
  PLUGIFY_EXPORT _IsClientConnected __dsdk_IsClientConnected = nullptr;
  /**
   * @brief Check if client is connected
   * @param playerSlot (int32)
   * @return bool
   */

  bool IsClientConnected(int32_t playerSlot) {
    return __dsdk_IsClientConnected(playerSlot);
  }

  using _IsFakeClient = bool (*)(int32_t);
  PLUGIFY_EXPORT _IsFakeClient __dsdk_IsFakeClient = nullptr;
  /**
   * @brief Check if player is a bot/fake client
   * @param playerSlot (int32)
   * @return bool
   */

  bool IsFakeClient(int32_t playerSlot) {
    return __dsdk_IsFakeClient(playerSlot);
  }

  using _CreateFakeClient = int32_t (*)(const plg::string&);
  PLUGIFY_EXPORT _CreateFakeClient __dsdk_CreateFakeClient = nullptr;
  /**
   * @brief Create a fake client in the match
   * @param name (string)
   * @return int32
   */

  int32_t CreateFakeClient(const plg::string& name) {
    return __dsdk_CreateFakeClient(name);
  }

  using _DisconnectClient = void (*)(int32_t, int32_t);
  PLUGIFY_EXPORT _DisconnectClient __dsdk_DisconnectClient = nullptr;
  /**
   * @brief Disconnect a client with disconnection reason code
   * @param playerSlot (int32)
   * @param reason (int32)
   */

  void DisconnectClient(int32_t playerSlot, int32_t reason) {
    return __dsdk_DisconnectClient(playerSlot, reason);
  }

  using _KickClient = void (*)(int32_t, const plg::string&, int32_t);
  PLUGIFY_EXPORT _KickClient __dsdk_KickClient = nullptr;
  /**
   * @brief Kick client with message and code
   * @param playerSlot (int32)
   * @param reason (string)
   * @param code (int32)
   */

  void KickClient(int32_t playerSlot, const plg::string& reason, int32_t code) {
    return __dsdk_KickClient(playerSlot, reason, code);
  }

  using _ChangeTeam = void (*)(int64_t, int32_t, bool);
  PLUGIFY_EXPORT _ChangeTeam __dsdk_ChangeTeam = nullptr;
  /**
   * @brief Change team of player controller
   * @param controller (int64)
   * @param teamNum (int32)
   * @param keepHero (bool)
   */

  void ChangeTeam(int64_t controller, int32_t teamNum, bool keepHero) {
    return __dsdk_ChangeTeam(controller, teamNum, keepHero);
  }

  using _GetPlayerPing = int32_t (*)(int32_t);
  PLUGIFY_EXPORT _GetPlayerPing __dsdk_GetPlayerPing = nullptr;
  /**
   * @brief Get ping of player in milliseconds
   * @param playerSlot (int32)
   * @return int32
   */

  int32_t GetPlayerPing(int32_t playerSlot) {
    return __dsdk_GetPlayerPing(playerSlot);
  }

} // namespace dsdk
