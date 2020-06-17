//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <string>

#include "LocationType.h"
#include "common/GameTypes.h"

class Location {
public:
private:
  LocationType type;
  std::string name;
  Size size;
};
