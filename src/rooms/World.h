//
// Created by nolasco on 12/05/20.
//

#pragma once

#include "Dungeon.h"
#include "Saloon.h"
#include "Shop.h"

/**
 * @brief World class defines a static room structure for the adventure.
 */
class World {
public:
  World();

  bool isAnyNpcHostileInThisRoom();
  bool isAnyNpcAliveInThisRoom();
  void goToNextRoom(uint option);

  Saloon s1;
  Saloon s2;
  Dungeon d1;
  Shop sh;

  std::shared_ptr<BaseRoom> currentRoom;
  uint roomIndex;
};
