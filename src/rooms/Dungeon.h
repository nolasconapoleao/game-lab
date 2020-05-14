//
// Created by nolasco on 12/05/20.
//

#pragma once

#include "BaseRoom.h"
#include "characters/Goblin.h"

class Dungeon : public BaseRoom {
public:
  Dungeon();

  Goblin goblin1;
  Goblin goblin2;
  Goblin goblin3;
};
