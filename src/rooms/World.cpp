//
// Created by nolasco on 12/05/20.
//

#include "World.h"

#include "items/Potion.h"
#include "items/Sword.h"

World::World() {
  s1.addLink(2u)
      .addLink(1u)
      .add(std::make_shared<Potion>(), 5)
      .add(std::make_shared<Sword>())
      .add(std::make_shared<Enemy>())
      .add(std::make_shared<Enemy>());
  d1.addLink(2u)
      .addLink(3u)
      .add(std::make_shared<Potion>(), 9)
      .add(std::make_shared<Goblin>())
      .add(std::make_shared<Goblin>())
      .add(std::make_shared<Goblin>());
  s2.addLink(0u).add(std::make_shared<Enemy>()).add(std::make_shared<Enemy>());
  sh.addLink(1u).add(std::make_shared<Shopkeeper>()).add(std::make_shared<Sword>());

  add(std::make_shared<Saloon>(s1));
  add(std::make_shared<Dungeon>(d1));
  add(std::make_shared<Saloon>(s2));
  add(std::make_shared<Shop>(sh));
  currentRoom = 0;
}

void World::goToNextRoom(uint option) {
  currentRoom = rooms.at(currentRoom)->adjacentRooms.at(option);
}

bool World::isAnyNpcAliveInThisRoom() {
  for (auto &npc : rooms.at(currentRoom)->npcs) {
    if (!npc->isDead()) {
      return true;
    }
  }
  return false;
}

bool World::isAnyNpcHostileInThisRoom() {
  for (auto &npc : rooms.at(currentRoom)->npcs) {
    if (CharacterRelation::hostile == npc->relation && !npc->isDead()) {
      return true;
    }
  }
  return false;
}
