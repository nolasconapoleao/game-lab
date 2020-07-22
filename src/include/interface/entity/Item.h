//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "Entity.h"
#include "datatypes/entity/ItemEffect.h"

namespace entity {

class Item : public Entity {
public:
  Item(const std::string &name, const ItemEffect &effect, Number unitWeight, Number unitPrice)
      : Entity(name), effect(effect), unitWeight(unitWeight), unitPrice(unitPrice) {
  }
  ItemEffect effect;
  Quantity quantity;
  Number unitWeight;
  Number unitPrice;
};

} // namespace entity
