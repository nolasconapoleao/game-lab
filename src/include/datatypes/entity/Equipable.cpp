//
// Created by nolasco on 19/07/20.
//

#include "Equipable.h"

namespace entity {

Equipable::Equipable(const std::string &name, const ItemEffect &effect, Quantity quantity, Number unitWeight,
                     Number unitPrice, Number uses)
    : Item(name, effect, quantity, unitWeight, unitPrice), uses(uses), equipped(false) {
}

} // namespace entity
