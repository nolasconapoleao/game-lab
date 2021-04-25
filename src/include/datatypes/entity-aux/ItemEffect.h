//
// Created by nolasco on 12/06/20.
//

#pragma once

#include <ostream>

#include "datatypes/GameTypes.h"

/// @brief Properties for character or item.
struct ItemEffect {
  /// @brief Health.
  Quantity hp = 0;
  /// @brief Attack.
  Quantity atk = 0;
  /// @brief Defense.
  Quantity def = 0;
  /// @brief Magic attack.
  Quantity mAtk = 0;
  /// @brief Magic defense.
  Quantity mDef = 0;
  /// @brief Speed.
  Quantity spd = 0;
  /// @brief Intelligence.
  Quantity inte = 0;
  /// @brief Accuracy.
  Quantity acc = 0;
  /// @brief Stealth.
  Quantity ste = 0;
  /// @brief Mana.
  Quantity mana = 0;
  /// @brief Range.
  Quantity ran = 0;
};
