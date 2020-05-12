//
// Created by nolasco on 11/05/20.
//

#pragma once

#include <memory>
#include <vector>

#include "../characters/BaseCharacter.h"
#include "../characters/Enemy.h"
//#include "../items/BaseItem.h"
#include "BaseRoom.h"

class Saloon : public BaseRoom {
public:
  Saloon();
  std::vector<std::shared_ptr<BaseCharacter>> npcs;
  Enemy enemy1;
  Enemy enemy2;
  //  std::vector<std::shared_ptr<BaseItem>> items;
};
