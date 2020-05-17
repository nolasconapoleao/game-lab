//
// Created by nolasco on 12/05/20.
//

#include "Dungeon.h"

Dungeon::Dungeon() : BaseRoom("Dungeon", "A maze of dark hallways, scattered light and the smell of sulfur") {
  npcs.push_back(std::make_shared<Goblin>(goblin1));
  npcs.push_back(std::make_shared<Goblin>(goblin2));
  npcs.push_back(std::make_shared<Goblin>(goblin3));
}
