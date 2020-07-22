//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "interface/entity/Item.h"

namespace entity {

class Consumable : public Item {
public:
  Consumable(const std::string &name, const ItemEffect &effect, Quantity quantity, Number unitWeight, Number unitPrice,
             Quantity duration);

  Quantity duration;
  bool consumed;
};

} // namespace entity
