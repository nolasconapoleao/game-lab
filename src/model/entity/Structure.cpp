//
// Created by nolasco on 20/06/20.
//

#include "Structure.h"

namespace entity {

Structure::Structure(const std::string &name, const Size &size) : name(name), size(size) {
}

LocationId Structure::getLocation() const {
  return location;
}

void Structure::setLocation(LocationId location) {
  Structure::location = location;
}

} // namespace entity