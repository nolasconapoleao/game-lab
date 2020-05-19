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
  /**
   * Room network:
   * s1 -> (s2, d1)
   * s2 -> (s1)
   * sh -> (d1)
   * d1 -> (s2, sh)
   */
  World();

  bool isAnyNpcHostileInThisRoom();
  bool isAnyNpcAliveInThisRoom();
  void goToNextRoom(uint option);

  Saloon s1;
  Dungeon d1;
  Saloon s2;
  Shop sh;

  std::vector<std::shared_ptr<BaseRoom>> rooms;
  uint currentRoom;
};
