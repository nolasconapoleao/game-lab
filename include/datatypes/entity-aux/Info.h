//
// Created by nolasco on 12/06/20.
//

#pragma once

#include <cstdint>

#include "AttackType.h"
#include "Ghost.h"
#include "Occupation.h"
#include "Race.h"

/// @brief Character information.
struct Info {
  /// @brief Money owned by character.
  Number cash;
  /// @brief Character control mechanics.
  Ghost ghost;
  /// @brief Race of character.
  Race race;
  /// @brief AttackType for character.
  AttackType attackType;
  /// @brief Occupation for character.
  Occupation occupation;
};
