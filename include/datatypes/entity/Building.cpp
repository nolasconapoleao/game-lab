//
// Created by nolasco on 19/07/20.
//

#include "Building.h"

namespace entity {

Building::Building(const std::string &name, BuildingType type, const Size &size, Quantity floors)
    : Location(name, size)
    , type(type)
    , health(size.height * size.width)
    , floors(floors) {
}

} // namespace entity
