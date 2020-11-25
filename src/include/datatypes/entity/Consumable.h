//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "datatypes/entity-aux/ConsumableType.h"
#include "interface/entity/Item.h"

namespace entity {

/// @brief Consumable item, once consumed lasts for the duration of the item.
class Consumable : public Item {
public:
  /**
   * @brief Constructor.
   * @param name of consumable.
   * @param effect of consumable.
   * @param quantity of item.
   * @param unitWeight weight for each consumable.
   * @param unitPrice price for each consumable.
   * @param type of consumable.
   * @param duration of consumable.
   */
  Consumable(const std::string &name, const ItemEffect &effect, Quantity quantity, Number unitWeight, Number unitPrice,
             ConsumableType type, Quantity duration);

  /// @brief consumable action.
  ConsumableType type;
  /// @brief duration of consumable when consumed.
  Quantity duration;
  /// @brief is item consumed.
  bool consumed;
};

} // namespace entity
