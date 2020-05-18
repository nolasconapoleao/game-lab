//
// Created by nolasco on 10/05/20.
//

#pragma once

#include <cstdint>
#include <ostream>
#include <string>
#include <vector>

#include "common/Inventory.h"
#include "utils/MathUtils.h"

/**
 * @brief Base character, all derived characters have an inventory and are battle ready.
 */
class BaseCharacter {
public:
  BaseCharacter(std::string name, uint maxHealthPoints, uint attackPoints)
      : name(name), currentHealthPoints(maxHealthPoints), maxHealthPoints(maxHealthPoints), attackPoints(attackPoints) {
  }

  virtual std::string sayHi() = 0;
  virtual std::string sayBye() = 0;

  bool isDead() {
    return currentHealthPoints == 0;
  };

  void receiveAttack(uint attackPoints) {
    currentHealthPoints = MathUtils::clamp_sub(currentHealthPoints, attackPoints, 0);
  };

  friend std::ostream &operator<<(std::ostream &os, const BaseCharacter &character);

  Inventory inventory;
  uint currentHealthPoints;
  uint maxHealthPoints;
  uint attackPoints;
  std::string name;
};
