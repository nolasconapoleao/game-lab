//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "interface/entity/Item.h"

namespace entity {

class Consumable : public Item {
public:
  Consumable(const std::string &name, Number weight, const ItemEffect &effect, Number quantity);
  void deplete(const Number amount) override;

private:
  Number quantity;
};

} // namespace entity
