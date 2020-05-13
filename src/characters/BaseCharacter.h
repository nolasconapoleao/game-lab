//
// Created by nolasco on 10/05/20.
//

#pragma once

#include <cstdint>
#include <ostream>
#include <string>
#include <vector>

class BaseCharacter {
public:
  BaseCharacter(uint maxHealthPoints, uint attackPoints)
      : currentHealthPoints(maxHealthPoints), maxHealthPoints(maxHealthPoints), attackPoints(attackPoints) {
  }

  virtual std::string sayHi() = 0;
  virtual std::string sayBye() = 0;

  bool isDead() {
    return currentHealthPoints == 0;
  };

  void receiveAttack(uint attackPoints) {
    if (currentHealthPoints >= attackPoints) {
      currentHealthPoints -= attackPoints;
    } else {
      currentHealthPoints = 0;
    }
  };

  friend std::ostream &operator<<(std::ostream &os, const BaseCharacter &character) {
    os << "HP: " << character.currentHealthPoints << "/" << character.maxHealthPoints << std::endl;
    return os;
  }

  uint currentHealthPoints;
  uint maxHealthPoints;
  uint attackPoints;
};
