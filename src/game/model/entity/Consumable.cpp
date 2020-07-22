//
// Created by nolasco on 19/07/20.
//

#include "Consumable.h"

namespace entity {

Consumable::Consumable(const std::string &name, const ItemEffect &effect, Number unitaryWeight, Number unitaryPrice,
                       Number quantity)
    : Item(name, effect, unitaryWeight, unitaryPrice), quantity(quantity) {
}

} // namespace entity
