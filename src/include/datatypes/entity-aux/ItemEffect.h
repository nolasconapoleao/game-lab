//
// Created by nolasco on 12/06/20.
//

#pragma once

#include <ostream>

#include "datatypes/GameTypes.h"

struct ItemEffect {
  Quantity hp = 0;   // Health
  Quantity atk = 0;  // Attack
  Quantity def = 0;  // Defense
  Quantity mAtk = 0; // Magic attack
  Quantity mDef = 0; // Magic defense
  Quantity spd = 0;  // Speed
  Quantity inte = 0; // Intelligence
  Quantity acc = 0;  // Accuracy
  Quantity ste = 0;  // Stealth
  Quantity mana = 0; // Mana
  Quantity ran = 0;  // Range
};
