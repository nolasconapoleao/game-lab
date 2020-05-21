//
// Created by nolasco on 12/05/20.
//

#pragma once

#include "rooms/Room.h"

/**
 * @brief World class defines a static room structure for the adventure.
 */
class World {
public:
  World();

  World add(const Room &room) {
    rooms.emplace_back(room);
    return *this;
  }

  bool isAnyNpcHostileInThisRoom();
  bool isAnyNpcAliveInThisRoom();
  void goToNextRoom(uint option);

  std::vector<Room> rooms;
  uint currentRoom;
};
