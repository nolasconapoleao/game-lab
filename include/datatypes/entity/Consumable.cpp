//
// Created by nolasco on 19/07/20.
//

#include "Consumable.h"

namespace entity {

Consumable::Consumable(const std::string &name, ConsumableType type, const ItemEffect &effect, Quantity quantity,
                       Number unitWeight, Number unitPrice, Quantity duration)
    : Item(name, effect, quantity, unitWeight, unitPrice)
    , type(type)
    , duration(duration)
    , consumed(false) {
}
} // namespace entity
