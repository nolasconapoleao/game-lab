//
// Created by nolasco on 19/06/20.
//

#pragma once

#include "ItemEffect.h"

struct Stats : ItemEffect {
  Quantity mhp = 0; // max health
  Quantity cst = 0; // constitution
  Quantity lvl = 0; // level
  Quantity xp = 0;  // experience
};
