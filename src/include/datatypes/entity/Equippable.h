//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "datatypes/entity-aux/EquippableType.h"
#include "interface/entity/Item.h"

namespace entity {

class Equippable : public Item {
public:
  Equippable(const std::string &name, EquippableType type, const ItemEffect &effect, Quantity quantity,
             Number unitWeight, Number unitPrice, Number uses);

  EquippableType type;
  Number uses;
  bool equipped;
};

} // namespace entity
