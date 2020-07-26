//
// Created by nolasco on 27/06/20.
//

#pragma once

#include <string_view>

#include "Action.h"

struct PlayerState {
  Action action;
  char transition;
  std::string_view prompt;
  bool terminal = false;
};