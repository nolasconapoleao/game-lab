//
// Created by nolasco on 11/06/20.
//

#pragma once

#include "controller/state/include/KingCrab.h"

namespace controller {

// FIX: Define Splitter state for these
class Example : public KingCrab {
public:
  Example(bool isMaze, CrabDifficulty difficulty, ResourceId eventOriginer, int8_t exitScore);

protected:
  void punish() override;
  void reward() override;
};

} // namespace controller
