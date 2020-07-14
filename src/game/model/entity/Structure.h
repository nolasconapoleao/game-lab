//
// Created by nolasco on 20/06/20.
//

#pragma once

#include <string>

#include "datatypes/GameTypes.h"

namespace entity {

class Structure {
public:
  Structure() = default;
  Structure(const std::string &name, const Size &size);
  LocationId getLocation() const;
  void setLocation(LocationId location);

  friend std::string minimalPrint(const Structure &value);
  friend std::string fullPrint(const Structure &value);

private:
  std::string name;
  Size size;
  LocationId location;
};

} // namespace entity
