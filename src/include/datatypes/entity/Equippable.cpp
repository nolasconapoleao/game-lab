//
// Created by nolasco on 19/07/20.
//

#include "Equippable.h"

namespace entity {

Equippable::Equippable(const std::string &name, const ItemEffect &effect, Quantity quantity, Number unitWeight,
                       Number unitPrice, Number uses)
    : Item(name, effect, quantity, unitWeight, unitPrice), uses(uses), equipped(false) {
}

} // namespace entity
