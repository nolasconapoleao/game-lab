//
// Created by nolasco on 10/05/20.
//

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "../items/BaseItem.h"

class BaseCharacter {
public:
  BaseCharacter(uint maxHealthPoints, uint attackPoints)
      : currentHealthPoints(maxHealthPoints), maxHealthPoints(maxHealthPoints), attackPoints(attackPoints) {}
  virtual std::string sayHi() = 0;
  virtual void receiveAttack(uint attackPoints) = 0;
  virtual std::string sayBye() = 0;

  bool isDead() { return currentHealthPoints == 0; };

  uint currentHealthPoints;
  uint maxHealthPoints;
  uint attackPoints;
};
