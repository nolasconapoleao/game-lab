//
// Created by nolasco on 27/06/20.
//

#pragma once

#include "ActionType.h"

struct Decision {
  ActionType type = ActionType::SKIP_TURN;
  ResourceId sender = 0;
  ResourceId receiver = 0;
  Quantity quantity = 0;
  std::string name = "";
};