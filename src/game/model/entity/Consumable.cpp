//
// Created by nolasco on 19/07/20.
//

#include "Consumable.h"

namespace entity {

Consumable::Consumable(const std::string &name, Number weight, const ItemEffect &effect, Number quantity)
    : Item(name, weight, effect), quantity(quantity) {
}

void Consumable::deplete(Number amount) {
  quantity -= amount;
}

} // namespace entity
