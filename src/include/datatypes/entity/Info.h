//
// Created by nolasco on 12/06/20.
//

#pragma once

#include <cstdint>

#include "Ghost.h"
#include "datatypes/factory/AttackType.h"
#include "datatypes/factory/CharacterPrototype.h"
#include "datatypes/factory/Race.h"

struct Info {
  Ghost ghost;                   // Ghost
  Race race;                     // Race
  AttackType attackType;         // Attack Type
  CharacterPrototype occupation; // CharacterPrototype
};