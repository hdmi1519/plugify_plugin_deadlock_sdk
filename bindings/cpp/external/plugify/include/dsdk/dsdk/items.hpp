#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: items)

namespace dsdk {

  using _AddItem = int64_t (*)(int64_t, const plg::string&, int32_t);
}
extern "C" PLUGIN_API dsdk::_AddItem __dsdk_AddItem;
namespace dsdk {
  /**
   * @brief Add an item to player pawn
   * @param pawn (int64)
   * @param itemName (string)
   * @param upgradeTier (int32)
   * @return int64
   */
  inline int64_t AddItem(int64_t pawn, const plg::string& itemName, int32_t upgradeTier) {
    return __dsdk_AddItem(pawn, itemName, upgradeTier);
  }

  using _SellItem = bool (*)(int64_t, const plg::string&, bool, bool);
}
extern "C" PLUGIN_API dsdk::_SellItem __dsdk_SellItem;
namespace dsdk {
  /**
   * @brief Sell an item from pawn
   * @param pawn (int64)
   * @param itemName (string)
   * @param fullRefund (bool)
   * @param forceSellPrice (bool)
   * @return bool
   */
  inline bool SellItem(int64_t pawn, const plg::string& itemName, bool fullRefund, bool forceSellPrice) {
    return __dsdk_SellItem(pawn, itemName, fullRefund, forceSellPrice);
  }

  using _GetItemImbueEffects = int32_t (*)(const plg::string&);
}
extern "C" PLUGIN_API dsdk::_GetItemImbueEffects __dsdk_GetItemImbueEffects;
namespace dsdk {
  /**
   * @brief Get item imbue effect flags
   * @param itemName (string)
   * @return int32
   */
  inline int32_t GetItemImbueEffects(const plg::string& itemName) {
    return __dsdk_GetItemImbueEffects(itemName);
  }

  using _CanImbueAbility = bool (*)(int64_t, const plg::string&);
}
extern "C" PLUGIN_API dsdk::_CanImbueAbility __dsdk_CanImbueAbility;
namespace dsdk {
  /**
   * @brief Check if ability can receive imbue
   * @param targetAbility (int64)
   * @param itemName (string)
   * @return bool
   */
  inline bool CanImbueAbility(int64_t targetAbility, const plg::string& itemName) {
    return __dsdk_CanImbueAbility(targetAbility, itemName);
  }

  using _ImbueAbility = bool (*)(int64_t, int64_t);
}
extern "C" PLUGIN_API dsdk::_ImbueAbility __dsdk_ImbueAbility;
namespace dsdk {
  /**
   * @brief Imbue item onto target ability
   * @param item (int64)
   * @param targetAbility (int64)
   * @return bool
   */
  inline bool ImbueAbility(int64_t item, int64_t targetAbility) {
    return __dsdk_ImbueAbility(item, targetAbility);
  }

} // namespace dsdk
