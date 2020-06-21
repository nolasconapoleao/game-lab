//
// Created by nolasco on 12/06/20.
//

#pragma once

#include <cstdint>

#include "CharacterAttack.h"
#include "Occupation.h"
#include "Race.h"

namespace entity {

struct Passport {
  std::string faction = "";        // faction
  std::string party = "";          // party
  Occupation occupation;           // occupation
  Race race;                       // class
  CharacterAttack characterAttack; // class
};

} // namespace entity