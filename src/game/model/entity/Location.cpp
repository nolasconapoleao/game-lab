//
// Created by nolasco on 07/06/20.
//

#include "Location.h"

namespace entity {

Location::Location(const std::string &name, LocationCategory type, const Size &size, Number floors)
    : name(name), type(type), size(size) {
}

const std::string &Location::getName() const {
  return name;
}

void Location::setName(const std::string &name) {
  Location::name = name;
}

LocationCategory Location::getType() const {
  return type;
}

const Size &Location::getSize() const {
  return size;
}

Number Location::getFloors() const {
  return floors;
}

void Location::setFloors(Number floors) {
  Location::floors = floors;
}

} // namespace entity
