//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "interface/entity/Item.h"

namespace entity {

class Equippable : public Item {
public:
  Equippable(const std::string &name, const ItemEffect &effect, Quantity quantity, Number unitWeight, Number unitPrice,
             Number uses);

  Number uses;
  bool equipped;
};

} // namespace entity
