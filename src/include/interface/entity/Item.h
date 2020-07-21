//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "Entity.h"
#include "datatypes/entity/ItemEffect.h"

namespace entity {

class Item : public Entity {
public:
  Item(const std::string &name, const ItemEffect &effect, Number unitaryWeight, Number unitaryPrice)
      : Entity(name), effect(effect), unitaryWeight(unitaryWeight), unitaryPrice(unitaryPrice) {
  }
  virtual void deplete(Number amount) = 0;

private:
  ItemEffect effect;
  Number unitaryWeight;
  Number unitaryPrice;
};

} // namespace entity
