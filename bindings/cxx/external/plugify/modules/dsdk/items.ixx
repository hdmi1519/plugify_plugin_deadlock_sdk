// Generated from dsdk.pplugin (group: items)

export module dsdk.items;
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

  using _AddItem = int64_t (*)(int64_t, const plg::string&, int32_t);
  PLUGIFY_EXPORT _AddItem __dsdk_AddItem = nullptr;
  /**
   * @brief Add an item to player pawn
   * @param pawn (int64)
   * @param itemName (string)
   * @param upgradeTier (int32)
   * @return int64
   */

  int64_t AddItem(int64_t pawn, const plg::string& itemName, int32_t upgradeTier) {
    return __dsdk_AddItem(pawn, itemName, upgradeTier);
  }

  using _SellItem = bool (*)(int64_t, const plg::string&, bool, bool);
  PLUGIFY_EXPORT _SellItem __dsdk_SellItem = nullptr;
  /**
   * @brief Sell an item from pawn
   * @param pawn (int64)
   * @param itemName (string)
   * @param fullRefund (bool)
   * @param forceSellPrice (bool)
   * @return bool
   */

  bool SellItem(int64_t pawn, const plg::string& itemName, bool fullRefund, bool forceSellPrice) {
    return __dsdk_SellItem(pawn, itemName, fullRefund, forceSellPrice);
  }

  using _GetItemImbueEffects = int32_t (*)(const plg::string&);
  PLUGIFY_EXPORT _GetItemImbueEffects __dsdk_GetItemImbueEffects = nullptr;
  /**
   * @brief Get item imbue effect flags
   * @param itemName (string)
   * @return int32
   */

  int32_t GetItemImbueEffects(const plg::string& itemName) {
    return __dsdk_GetItemImbueEffects(itemName);
  }

  using _CanImbueAbility = bool (*)(int64_t, const plg::string&);
  PLUGIFY_EXPORT _CanImbueAbility __dsdk_CanImbueAbility = nullptr;
  /**
   * @brief Check if ability can receive imbue
   * @param targetAbility (int64)
   * @param itemName (string)
   * @return bool
   */

  bool CanImbueAbility(int64_t targetAbility, const plg::string& itemName) {
    return __dsdk_CanImbueAbility(targetAbility, itemName);
  }

  using _ImbueAbility = bool (*)(int64_t, int64_t);
  PLUGIFY_EXPORT _ImbueAbility __dsdk_ImbueAbility = nullptr;
  /**
   * @brief Imbue item onto target ability
   * @param item (int64)
   * @param targetAbility (int64)
   * @return bool
   */

  bool ImbueAbility(int64_t item, int64_t targetAbility) {
    return __dsdk_ImbueAbility(item, targetAbility);
  }

} // namespace dsdk
