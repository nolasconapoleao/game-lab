//
// Created by nolasco on 07/06/20.
//

#include "Item.h"
namespace entity {

void Item::spend(Quantity depletedAmount) {
  quantity -= depletedAmount;
}
void Item::addUses(Quantity addedAmount) {
  quantity += addedAmount;
}
void Item::addToStack(Quantity addedAmount) {
  quantity += addedAmount;
}

} // namespace entity
