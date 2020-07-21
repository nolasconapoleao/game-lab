//
// Created by nolasco on 19/07/20.
//

#include "Equipable.h"

namespace entity {

Equipable::Equipable(const std::string &name, const ItemEffect &effect, Number unitaryWeight, Number unitaryPrice,
                     Number uses, bool equipped)
    : Item(name, effect, unitaryWeight, unitaryPrice), uses(uses), equipped(equipped) {
}

void Equipable::deplete(Number amount) {
  uses -= amount;
}

} // namespace entity
