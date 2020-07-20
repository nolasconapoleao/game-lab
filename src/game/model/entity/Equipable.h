//
// Created by nolasco on 19/07/20.
//

#pragma once

#include "interface/entity/Item.h"

namespace entity {

class Equipable : public Item {
public:
  Equipable(const std::string &name, Number weight, const ItemEffect &effect, Number uses, const bool equipped);
  void deplete(const Number amount) override;

  Number uses;
  bool equipped;
};

} // namespace entity
