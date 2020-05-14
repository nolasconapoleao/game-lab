//
// Created by nolasco on 12/05/20.
//

#pragma once

#include "../characters/Goblin.h"
#include "BaseRoom.h"

class Dungeon : public BaseRoom {
public:
  Dungeon();

  Goblin goblin1;
  Goblin goblin2;
  Goblin goblin3;
};
