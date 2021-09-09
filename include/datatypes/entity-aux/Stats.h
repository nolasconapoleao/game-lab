//
// Created by nolasco on 19/06/20.
//

#pragma once

#include "ItemEffect.h"

/// @brief Character status.
struct Stats : ItemEffect {
  /// @brief Max health.
  Quantity mhp = 0;
  /// @brief Constitution.
  Quantity cst = 0;
  /// @brief Level.
  Quantity lvl = 0;
  /// @brief Experience.
  Quantity xp = 0;
};
