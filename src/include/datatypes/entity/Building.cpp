//
// Created by nolasco on 19/07/20.
//

#include "Building.h"

namespace entity {

Building::Building(const std::string &name, const Size &size, Quantity floors)
    : Location(name, size), health(size.height * size.width), floors(floors) {
}

} // namespace entity
