//
// Created by nolasco on 12/05/20.
//

#include "World.h"

#include "items/Potion.h"
#include "items/Sword.h"

World::World() {
  std::vector<std::shared_ptr<BaseRoom>> adjacentS1;
  adjacentS1.emplace_back(std::make_shared<Saloon>(s2));
  adjacentS1.emplace_back(std::make_shared<Dungeon>(d1));
  s1.setAdjacentRooms(adjacentS1);
  s1.inventory.addItem(std::make_shared<Potion>(), 9);

  std::vector<std::shared_ptr<BaseRoom>> adjacentD1;
  adjacentD1.emplace_back(std::make_shared<Saloon>(s2));
  adjacentD1.emplace_back(std::make_shared<Shop>(sh));
  sh.inventory.addItem(std::make_shared<Potion>(), 9);
  sh.inventory.addItem(std::make_shared<Sword>());
  d1.setAdjacentRooms(adjacentD1);

  std::vector<std::shared_ptr<BaseRoom>> adjacentS2;
  adjacentS2.emplace_back(std::make_shared<Saloon>(s1));
  s2.setAdjacentRooms(adjacentS2);

  std::vector<std::shared_ptr<BaseRoom>> adjacentSh;
  adjacentSh.emplace_back(std::make_shared<Dungeon>(d1));
  sh.setAdjacentRooms(adjacentSh);

  currentRoom = std::make_shared<Saloon>(s1);
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
    if (option == 0) {
      roomIndex = 2;
      currentRoom = std::make_shared<BaseRoom>(s2);
    } else if (option == 1) {
      roomIndex = 4;
      currentRoom = std::make_shared<BaseRoom>(d1);
    }
  } else if (roomIndex == 3) {
    roomIndex = 1;
    currentRoom = std::make_shared<BaseRoom>(s1);
  } else if (roomIndex == 4) {
    roomIndex = 2;
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

bool World::isAnyNpcHostileInThisRoom() {
  bool anyoneHostile = false;
  for (auto &npc : currentRoom->npcs) {
    anyoneHostile |= CharacterRelation::hostile == npc->relation;
  }

  return anyoneHostile && isAnyNpcAliveInThisRoom();
}
