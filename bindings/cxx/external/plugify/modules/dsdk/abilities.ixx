// Generated from dsdk.pplugin (group: abilities)

export module dsdk.abilities;
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

  using _AddAbility = int64_t (*)(int64_t, const plg::string&, uint16_t);
  PLUGIFY_EXPORT _AddAbility __dsdk_AddAbility = nullptr;
  /**
   * @brief Add an ability to player pawn
   * @param pawn (int64)
   * @param abilityName (string)
   * @param slot (uint16)
   * @return int64
   */

  int64_t AddAbility(int64_t pawn, const plg::string& abilityName, uint16_t slot) {
    return __dsdk_AddAbility(pawn, abilityName, slot);
  }

  using _RemoveAbility = bool (*)(int64_t, const plg::string&);
  PLUGIFY_EXPORT _RemoveAbility __dsdk_RemoveAbility = nullptr;
  /**
   * @brief Remove ability by name from pawn
   * @param pawn (int64)
   * @param abilityName (string)
   * @return bool
   */

  bool RemoveAbility(int64_t pawn, const plg::string& abilityName) {
    return __dsdk_RemoveAbility(pawn, abilityName);
  }

  using _RemoveAbilityByEntity = bool (*)(int64_t, int64_t);
  PLUGIFY_EXPORT _RemoveAbilityByEntity __dsdk_RemoveAbilityByEntity = nullptr;
  /**
   * @brief Remove ability by entity pointer
   * @param pawn (int64)
   * @param ability (int64)
   * @return bool
   */

  bool RemoveAbilityByEntity(int64_t pawn, int64_t ability) {
    return __dsdk_RemoveAbilityByEntity(pawn, ability);
  }

  using _FindAbilityByName = int64_t (*)(int64_t, const plg::string&);
  PLUGIFY_EXPORT _FindAbilityByName __dsdk_FindAbilityByName = nullptr;
  /**
   * @brief Find ability in ability component
   * @param abilityComponent (int64)
   * @param abilityName (string)
   * @return int64
   */

  int64_t FindAbilityByName(int64_t abilityComponent, const plg::string& abilityName) {
    return __dsdk_FindAbilityByName(abilityComponent, abilityName);
  }

  using _GetAbilityBySlot = int64_t (*)(int64_t, int16_t);
  PLUGIFY_EXPORT _GetAbilityBySlot __dsdk_GetAbilityBySlot = nullptr;
  /**
   * @brief Get ability at slot index
   * @param abilityComponent (int64)
   * @param slot (int16)
   * @return int64
   */

  int64_t GetAbilityBySlot(int64_t abilityComponent, int16_t slot) {
    return __dsdk_GetAbilityBySlot(abilityComponent, slot);
  }

  using _ExecuteAbility = int32_t (*)(int64_t, int64_t, bool, uint8_t);
  PLUGIFY_EXPORT _ExecuteAbility __dsdk_ExecuteAbility = nullptr;
  /**
   * @brief Cast/execute an ability
   * @param abilityComponent (int64)
   * @param ability (int64)
   * @param altCast (bool)
   * @param flags (uint8)
   * @return int32
   */

  int32_t ExecuteAbility(int64_t abilityComponent, int64_t ability, bool altCast, uint8_t flags) {
    return __dsdk_ExecuteAbility(abilityComponent, ability, altCast, flags);
  }

  using _ToggleActivate = void (*)(int64_t, bool);
  PLUGIFY_EXPORT _ToggleActivate __dsdk_ToggleActivate = nullptr;
  /**
   * @brief Toggle ability active status
   * @param ability (int64)
   * @param activate (bool)
   */

  void ToggleActivate(int64_t ability, bool activate) {
    return __dsdk_ToggleActivate(ability, activate);
  }

  using _ResetAbilityCooldown = void (*)(int64_t);
  PLUGIFY_EXPORT _ResetAbilityCooldown __dsdk_ResetAbilityCooldown = nullptr;
  /**
   * @brief Reset ability cooldown and refill charges
   * @param ability (int64)
   */

  void ResetAbilityCooldown(int64_t ability) {
    return __dsdk_ResetAbilityCooldown(ability);
  }

  using _GetAbilityMaxCharges = int32_t (*)(int64_t);
  PLUGIFY_EXPORT _GetAbilityMaxCharges __dsdk_GetAbilityMaxCharges = nullptr;
  /**
   * @brief Get maximum charges of an ability
   * @param ability (int64)
   * @return int32
   */

  int32_t GetAbilityMaxCharges(int64_t ability) {
    return __dsdk_GetAbilityMaxCharges(ability);
  }

  using _SetUpgradeBits = void (*)(int64_t, int32_t);
  PLUGIFY_EXPORT _SetUpgradeBits __dsdk_SetUpgradeBits = nullptr;
  /**
   * @brief Set upgrade bits on ability
   * @param ability (int64)
   * @param newBits (int32)
   */

  void SetUpgradeBits(int64_t ability, int32_t newBits) {
    return __dsdk_SetUpgradeBits(ability, newBits);
  }

} // namespace dsdk
