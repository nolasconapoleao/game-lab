//
// Created by nolasco on 12/06/20.
//

#pragma once

#include <cstdint>

#include "AttackType.h"
#include "Occupation.h"
#include "Race.h"

struct Info {
  Ghost ghost;           // Ghost
  Race race;             // Race
  AttackType attackType; // Attack Type
  Occupation occupation; // Occupation
};