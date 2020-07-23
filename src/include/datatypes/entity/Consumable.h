//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "datatypes/entity-aux/ConsumableType.h"
#include "interface/entity/Item.h"

namespace entity {

class Consumable : public Item {
public:
  Consumable(const std::string &name, const ItemEffect &effect, Quantity quantity, Number unitWeight, Number unitPrice,
             ConsumableType type, Quantity duration);

  ConsumableType type;
  Quantity duration;
  bool consumed;
};

} // namespace entity
