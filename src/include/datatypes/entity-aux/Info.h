//
// Created by nolasco on 12/06/20.
//

#pragma once

#include <cstdint>

#include "AttackType.h"
#include "Ghost.h"
#include "Occupation.h"
#include "Race.h"

struct Info {
  Number cash;           // Money
  Ghost ghost;           // Ghost
  Race race;             // Race
  AttackType attackType; // Attack Type
  Occupation occupation; // Occupation
};