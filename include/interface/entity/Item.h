//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "Entity.h"
#include "datatypes/entity-aux/ItemEffect.h"

namespace entity {

/// @brief Item entity.
class Item : public Entity {
public:
  /**
   * @brief Constructor.
   * @param name of item
   * @param effect for item.
   * @param quantity number of items
   * @param unitWeight weight for each item.
   * @param unitPrice price for each item.
   */
  Item(const std::string &name, const ItemEffect &effect, Quantity quantity, Quantity unitWeight, Quantity unitPrice)
      : Entity(name)
      , effect(effect)
      , quantity(quantity)
      , unitWeight(unitWeight)
      , unitPrice(unitPrice) {
  }

  /// @brief Item effect.
  ItemEffect effect;
  /// @brief Item quantity.
  Quantity quantity;
  /// @brief Weight for each item.
  Quantity unitWeight;
  /// @brief Price for each item.
  Quantity unitPrice;
};

} // namespace entity
