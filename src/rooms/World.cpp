//
// Created by nolasco on 12/05/20.
//

#include "World.h"
World::World() : currentRoom(std::make_shared<BaseRoom>(s1)), roomIndex(1) {
  std::vector<std::shared_ptr<BaseRoom>> adjacentS1;
  adjacentS1.push_back(std::make_shared<Saloon>(s2));
  adjacentS1.push_back(std::make_shared<Dungeon>(d1));
  s1.setAdjacentRooms(adjacentS1);

  std::vector<std::shared_ptr<BaseRoom>> adjacentD1;
  adjacentS1.push_back(std::make_shared<Saloon>(s2));
  d1.setAdjacentRooms(adjacentD1);

  std::vector<std::shared_ptr<BaseRoom>> adjacentS2;
  adjacentS1.push_back(std::make_shared<Saloon>(s1));
  s2.setAdjacentRooms(adjacentS2);
}

void World::goToNextRoom(uint option) {
  if (roomIndex == 1) {
    if (option == 0) {
      roomIndex = 3;
      currentRoom = std::make_shared<BaseRoom>(s2);
    } else if (option == 1) {
      roomIndex = 2;
      currentRoom = std::make_shared<BaseRoom>(d1);
    }
  } else if (roomIndex == 2) {
    roomIndex = 3;
    currentRoom = std::make_shared<BaseRoom>(s2);
  } else if (roomIndex == 3) {
    roomIndex = 1;
    currentRoom = std::make_shared<BaseRoom>(s1);
  }
}
bool World::isAnyNpcAliveInThisRoom() {
  bool anyoneAlive = false;
  for (auto &npc : currentRoom->npcs) {
    anyoneAlive |= !npc->isDead();
  }

  return anyoneAlive;
}
