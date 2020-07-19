//
// Created by nolasco on 19/07/20.
//

#include "Equipable.h"

namespace entity {

Equipable::Equipable(const std::string &name, Number weight, const ItemEffect &effect, Number uses, bool equipped)
    : Item(name, weight, effect), uses(uses), equipped(equipped) {
}

void Equipable::deplete(Number amount) {
  uses -= amount;
}

} // namespace entity
