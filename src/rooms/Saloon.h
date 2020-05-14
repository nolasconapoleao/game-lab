//
// Created by nolasco on 11/05/20.
//

#pragma once

#include <memory>
#include <vector>

#include "../characters/BaseCharacter.h"
#include "../characters/Enemy.h"
#include "BaseRoom.h"

class Saloon : public BaseRoom {
public:
  Saloon();
  Enemy enemy1;
  Enemy enemy2;
};
