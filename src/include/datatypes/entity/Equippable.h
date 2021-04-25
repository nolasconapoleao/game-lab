//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "datatypes/entity-aux/EquippableType.h"
#include "interface/entity/Item.h"

namespace entity {

/// @brief Equippable item, can be equipped and unequipped, has limited uses.
class Equippable : public Item {
public:
  /**
   * @brief Constructor.
   * @param name of equippable.
   * @param type of equippable.
   * @param effect of equippable.
   * @param quantity of equippable.
   * @param unitWeight weight for each consumable.
   * @param unitPrice price for each consumable.
   * @param uses of equippable.
   */
  Equippable(const std::string &name, EquippableType type, const ItemEffect &effect, Quantity quantity,
             Number unitWeight, Number unitPrice, Number uses);

  /// @brief Equippable action.
  EquippableType type;
  /// @brief number of uses for equippable item.
  Quantity uses;
  /// @brief is item equipped.
  bool equipped;
};

} // namespace entity
