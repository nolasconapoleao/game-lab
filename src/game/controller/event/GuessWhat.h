//
// Created by nolasco on 11/07/20.
//

#pragma once

#include "game/controller/event/include/KingCrab.h"

namespace controller {

class GuessWhat : public KingCrab {

public:
  GuessWhat(bool isMaze, CrabDifficulty difficulty, ResourceId origin, int8_t exitScore);

protected:
  void punish() override;
  void reward() override;
};

} // namespace controller
