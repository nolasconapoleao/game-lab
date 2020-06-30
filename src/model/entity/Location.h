//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <string>

#include "common/GameTypes.h"
#include "controller/factory/include/LocationCategory.h"

namespace entity {

class Location {
public:
  Location() = default;
  Location(const std::string &name, LocationCategory type, const Size &size, Number floors = 1);
  const std::string &getName() const;
  void setName(const std::string &name);
  LocationCategory getType() const;
  const Size &getSize() const;
  Number getFloors() const;
  void setFloors(Number floors);

  friend std::string minimalPrint(const Location &value);
  friend std::string fullPrint(const Location &value);

private:
  std::string name;
  LocationCategory type;
  Size size;
  Number floors;
};

} // namespace entity
