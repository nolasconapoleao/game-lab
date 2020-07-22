//
// Created by nolasco on 19/07/20.
//

#include "Building.h"

namespace entity {

Building::Building(const std::string &name, const Size &size, Quantity floors) : Location(name, size), floors(floors) {
}

} // namespace entity
