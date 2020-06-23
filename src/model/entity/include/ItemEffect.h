//
// Created by nolasco on 12/06/20.
//

#pragma once

#include <ostream>

#include "common/GameTypes.h"

struct ItemEffect {
  Quantity atk = 0; // attack
  Quantity def = 0; // defense
  Quantity spd = 0; // speed
  Quantity hp = 0;  // health
};
