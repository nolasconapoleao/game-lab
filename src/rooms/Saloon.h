//
// Created by nolasco on 11/05/20.
//

#pragma once

#include <memory>
#include <vector>

#include "BaseRoom.h"
#include "characters/BaseCharacter.h"
#include "characters/Enemy.h"

class Saloon : public BaseRoom {
public:
  Saloon();
  Enemy enemy1;
  Enemy enemy2;
};
