//
// Created by nolasco on 27/06/20.
//

#pragma once

#include <string_view>

#include "Action.h"

/// @brief Menu state for console print.
struct MenuState {
  /// @brief Action.
  Action action;
  /// @brief Key for action selection.
  char transition;
  /// @brief Action description.
  std::string_view prompt;
  /// @brief Is the menu entry terminal (leaf node).
  bool terminal = false;
};
