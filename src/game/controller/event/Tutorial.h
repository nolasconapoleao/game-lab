//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "game/controller/event/include/KingCrab.h"

namespace controller {

class Tutorial : public KingCrab {

public:
  Tutorial(bool isMaze, CrabDifficulty difficulty, ResourceId origin, int8_t exitScore);

private:
  void punish() override;
  void reward() override;

  std::vector<std::string> failOutput;
};

} // namespace controller
