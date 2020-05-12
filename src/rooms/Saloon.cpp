//
// Created by nolasco on 11/05/20.
//

#include "Saloon.h"

#include <memory>

#include "../characters/Enemy.h"
//#include "../items/Potion.h"

Saloon::Saloon() : BaseRoom("Saloon with dark oak doors no windows and smoke in the air") {
  npcs.push_back(std::make_shared<Enemy>(enemy1));
  npcs.push_back(std::make_shared<Enemy>(enemy2));

  //  Potion potion;
  //  items.push_back(std::make_shared<Potion>(potion));
}
