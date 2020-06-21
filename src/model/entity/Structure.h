//
// Created by nolasco on 20/06/20.
//

#pragma once

#include <string>

#include "common/GameTypes.h"

namespace entity {

class Structure {
public:
  Structure(const std::string &name, const Size &size);

private:
  std::string name;
  Size size;
  LocationId location;

public:
  LocationId getLocation() const;
  void setLocation(LocationId location);
};

} // namespace entity
