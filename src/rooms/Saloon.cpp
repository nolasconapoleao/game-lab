//
// Created by nolasco on 11/05/20.
//

#include "Saloon.h"

#include <memory>

#include "characters/Enemy.h"

Saloon::Saloon() : BaseRoom("Saloon", "Saloon with dark oak doors no windows and smoke in the air") {
  npcs.push_back(std::make_shared<Enemy>(enemy1));
  npcs.push_back(std::make_shared<Enemy>(enemy2));
}
