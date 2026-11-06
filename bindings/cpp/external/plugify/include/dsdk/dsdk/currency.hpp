#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from dsdk.pplugin (group: currency)

namespace dsdk {

  using _ModifyCurrency = void (*)(int64_t, ECurrencyType, int32_t, ECurrencySource, bool, bool, bool, int64_t, int64_t);
}
extern "C" PLUGIN_API dsdk::_ModifyCurrency __dsdk_ModifyCurrency;
namespace dsdk {
  /**
   * @brief Modify currency (souls/gold) for player pawn
   * @param pawn (int64)
   * @param currencyType (uint32)
   * @param amount (int32)
   * @param source (uint32)
   * @param silent (bool)
   * @param forceGain (bool)
   * @param spendOnly (bool)
   * @param sourceAbility (int64)
   * @param sourceEntity (int64)
   */
  inline void ModifyCurrency(int64_t pawn, ECurrencyType currencyType, int32_t amount, ECurrencySource source, bool silent, bool forceGain, bool spendOnly, int64_t sourceAbility, int64_t sourceEntity) {
    return __dsdk_ModifyCurrency(pawn, currencyType, amount, source, silent, forceGain, spendOnly, sourceAbility, sourceEntity);
  }

  using _GetCurrency = int32_t (*)(int64_t, ECurrencyType);
}
extern "C" PLUGIN_API dsdk::_GetCurrency __dsdk_GetCurrency;
namespace dsdk {
  /**
   * @brief Get current currency value of pawn
   * @param pawn (int64)
   * @param currencyType (uint32)
   * @return int32
   */
  inline int32_t GetCurrency(int64_t pawn, ECurrencyType currencyType) {
    return __dsdk_GetCurrency(pawn, currencyType);
  }

} // namespace dsdk
