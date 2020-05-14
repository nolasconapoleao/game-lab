//
// Created by nolasco on 12/05/20.
//

#pragma once

#include "Dungeon.h"
#include "Saloon.h"

class World {
public:
  World();

  bool isAnyNpcAliveInThisRoom();
  void goToNextRoom(uint option);

  Saloon s1;
  Saloon s2;
  Dungeon d1;

  std::shared_ptr<BaseRoom> currentRoom;
  uint roomIndex;
};
