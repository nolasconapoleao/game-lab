//
// Created by nolasco on 12/05/20.
//

#include "World.h"

#include "items/Potion.h"
#include "items/Sword.h"

World::World() {
  std::vector<uint> adjacentS1;
  adjacentS1.emplace_back(2u);
  adjacentS1.emplace_back(1u);
  s1.setAdjacentRooms(adjacentS1);
  s1.inventory.addItem(std::make_shared<Potion>(), 9);

  std::vector<uint> adjacentD1;
  adjacentD1.emplace_back(2u);
  adjacentD1.emplace_back(3u);
  sh.inventory.addItem(std::make_shared<Potion>(), 9);
  sh.inventory.addItem(std::make_shared<Sword>());
  d1.setAdjacentRooms(adjacentD1);

  std::vector<uint> adjacentS2;
  adjacentS2.emplace_back(0);
  s2.setAdjacentRooms(adjacentS2);

  std::vector<uint> adjacentSh;
  adjacentSh.emplace_back(1u);
  sh.setAdjacentRooms(adjacentSh);

  rooms.emplace_back(std::make_shared<Saloon>(s1));
  rooms.emplace_back(std::make_shared<Dungeon>(d1));
  rooms.emplace_back(std::make_shared<Saloon>(s2));
  rooms.emplace_back(std::make_shared<Shop>(sh));
  currentRoom = 0;
}

void World::goToNextRoom(uint option) {
  currentRoom = rooms.at(currentRoom)->adjacentRooms.at(option);
}

bool World::isAnyNpcAliveInThisRoom() {
  bool anyoneAlive = false;
  for (auto &npc : rooms.at(currentRoom)->npcs) {
    anyoneAlive |= !npc->isDead();
  }

  return anyoneAlive;
}

bool World::isAnyNpcHostileInThisRoom() {
  bool anyoneHostile = false;
  for (auto &npc : rooms.at(currentRoom)->npcs) {
    anyoneHostile |= CharacterRelation::hostile == npc->relation;
  }

  return anyoneHostile && isAnyNpcAliveInThisRoom();
}
