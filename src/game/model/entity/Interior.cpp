//
// Created by nolasco on 19/07/20.
//

#include "Interior.h"

namespace entity {

Interior::Interior(const std::string &name, const Size &size, Number floors) : Location(name, size), floors(floors) {
}

} // namespace entity
