//
// Created by nolasco on 12/05/20.
//

#pragma once

#include "BaseRoom.h"
#include "characters/Goblin.h"

/**
 * @brief Dungeon room, contains 3 goblins.
 */
class Dungeon : public BaseRoom {
public:
  Dungeon();

private:
  Goblin goblin1;
  Goblin goblin2;
  Goblin goblin3;
};
