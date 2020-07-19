//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "Entity.h"
#include "datatypes/entity/ItemEffect.h"

namespace entity {

class Item : public Entity {
public:
  Item(std::string name, Number unitaryWeight, const ItemEffect &effect)
      : Entity(name), unitaryWeight(unitaryWeight), effect(effect) {
  }
  virtual void deplete(Number amount) = 0;

private:
  Number unitaryWeight;
  ItemEffect effect;
};

} // namespace entity
