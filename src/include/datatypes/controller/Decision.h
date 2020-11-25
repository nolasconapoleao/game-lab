//
// Created by nolasco on 27/06/20.
//

#pragma once

#include <datatypes/GameTypes.h>

#include "Action.h"

/// @brief Character decision.
struct Decision {
  /// @brief Decision action action.
  Action action = Action::SKIP_TURN;
  /// @brief Character identifier.
  ResourceId subject = 0;
  /// @brief Identifier for entity affected by action.
  ResourceId object = 0;
  /// @brief Quantity for action, when applicable.
  Quantity quantity = 0;
  /// @brief Sentence for action, when applicable.
  std::string sentence = "";
};
