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
  const std::string &getName() const;
  void setName(const std::string &name);
  const Size &getSize() const;
  void setSize(const Size &size);
  LocationId getLocation() const;
  void setLocation(LocationId location);

private:
  std::string name;
  Size size;
  LocationId location;
};

} // namespace entity
