//
// Created by nolasco on 12/05/20.
//

#include "World.h"

World::World() {
  currentRoom = 0;
}

void World::goToNextRoom(uint8_t option) {
  auto it = rooms[currentRoom].adjacentRooms.begin();
  std::advance(it, option);
  currentRoom = *it;
}

bool World::isAnyNpcAliveInThisRoom() {
  for (auto &npc : rooms[currentRoom].npcs) {
    if (!npc.isDead()) {
      return true;
    }
  }
  return false;
}

bool World::isAnyNpcHostileInThisRoom() {
  for (auto &npc : rooms[currentRoom].npcs) {
    if (Diplomacy::hostile == npc.relation && !npc.isDead()) {
      return true;
    }
  }
  return false;
}
