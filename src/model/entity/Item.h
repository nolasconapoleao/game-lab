//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "Property.h"
#include "UseType.h"

namespace entity {

class Item {
public:
  void spend(Quantity depletedAmount = 1);
  void addUses(Quantity addedAmount = 1);
  void addToStack(Quantity addedAmount = 1);

private:
  Quantity quantity;
  UseType useType;
  Property effect;
  ResourceId owner;
};

} // namespace entity
