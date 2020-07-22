//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "interface/entity/Item.h"

namespace entity {

class Consumable : public Item {
public:
  Consumable(const std::string &name, const ItemEffect &effect, Number unitaryWeight, Number unitaryPrice,
             Number quantity);

  Number quantity;
};

} // namespace entity
