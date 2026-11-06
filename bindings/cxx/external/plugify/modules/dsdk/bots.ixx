// Generated from dsdk.pplugin (group: bots)

export module dsdk.bots;
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

  using _BotCreate = int64_t (*)(const plg::string&, int32_t, float, float, float, bool);
  PLUGIFY_EXPORT _BotCreate __dsdk_BotCreate = nullptr;
  /**
   * @brief Spawn a bot hero into the match
   * @param heroName (string)
   * @param team (int32)
   * @param posX (float)
   * @param posY (float)
   * @param posZ (float)
   * @param assignLane (bool)
   * @return int64
   */

  int64_t BotCreate(const plg::string& heroName, int32_t team, float posX, float posY, float posZ, bool assignLane) {
    return __dsdk_BotCreate(heroName, team, posX, posY, posZ, assignLane);
  }

  using _BotGetBrain = int64_t (*)(int64_t);
  PLUGIFY_EXPORT _BotGetBrain __dsdk_BotGetBrain = nullptr;
  /**
   * @brief Get brain entity pointer for player bot pawn
   * @param pawn (int64)
   * @return int64
   */

  int64_t BotGetBrain(int64_t pawn) {
    return __dsdk_BotGetBrain(pawn);
  }

  using _BotGetPawn = int64_t (*)(int64_t);
  PLUGIFY_EXPORT _BotGetPawn __dsdk_BotGetPawn = nullptr;
  /**
   * @brief Get pawn entity controlled by bot brain
   * @param brain (int64)
   * @return int64
   */

  int64_t BotGetPawn(int64_t brain) {
    return __dsdk_BotGetPawn(brain);
  }

  using _BotSetLane = bool (*)(int64_t, int32_t);
  PLUGIFY_EXPORT _BotSetLane __dsdk_BotSetLane = nullptr;
  /**
   * @brief Assign lane index to bot
   * @param pawn (int64)
   * @param lane (int32)
   * @return bool
   */

  bool BotSetLane(int64_t pawn, int32_t lane) {
    return __dsdk_BotSetLane(pawn, lane);
  }

  using _BotGetLane = int32_t (*)(int64_t);
  PLUGIFY_EXPORT _BotGetLane __dsdk_BotGetLane = nullptr;
  /**
   * @brief Get assigned lane index of bot
   * @param pawn (int64)
   * @return int32
   */

  int32_t BotGetLane(int64_t pawn) {
    return __dsdk_BotGetLane(pawn);
  }

} // namespace dsdk
