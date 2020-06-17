//
// Created by nolasco on 12/06/20.
//

#pragma once

#include <ostream>

#include "common/GameTypes.h"

namespace entity {

struct Property {
  friend std::ostream &operator<<(std::ostream &os, const Property &aProperty);
  Quantity atk = 0; // attack
  Quantity def = 0; // defense
  Quantity spd = 0; // speed
  Quantity hp = 0;  // health
  Quantity mhp = 0; // max health
};

} // namespace entity