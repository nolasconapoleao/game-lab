//
// Created by nolasco on 12/05/20.
//

#include "World.h"

#include "items/Potion.h"
#include "items/Sword.h"

World::World() {
  currentRoom = 0;
}

void World::goToNextRoom(uint option) {
  auto it = rooms.at(currentRoom)->adjacentRooms.begin();
  std::advance(it, option);
  currentRoom = *it;
}

bool World::isAnyNpcAliveInThisRoom() {
  for (auto &npc : rooms.at(currentRoom)->npcs) {
    if (!npc.isDead()) {
      return true;
    }
  }
  return false;
}

bool World::isAnyNpcHostileInThisRoom() {
  for (auto &npc : rooms.at(currentRoom)->npcs) {
    if (CharacterRelation::hostile == npc.relation && !npc.isDead()) {
      return true;
    }
  }
  return false;
}
