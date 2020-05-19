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

struct CharacterProperties {
  uint currentHealthPoints;
  uint maxHealthPoints;
  uint attackPoints;
  uint money = 0;
  uint experience = 0;
};

enum class CharacterRelation {
  friendly,
  hostile,
  neutral,
};

/**
 * @brief Base character, all derived characters have an inventory and are battle ready.
 */
class BaseCharacter {
public:
  BaseCharacter(std::string name, uint maxHealthPoints, uint attackPoints, CharacterRelation relation)
      : name(name), properties(CharacterProperties{maxHealthPoints, maxHealthPoints, attackPoints}),
        relation(relation) {
  }

  virtual std::string sayHi() = 0;
  virtual std::string sayBye() = 0;

  bool isDead() {
    return properties.currentHealthPoints == 0;
  };

  void receiveAttack(uint attackPoints) {
    properties.currentHealthPoints = MathUtils::clamp_sub(properties.currentHealthPoints, attackPoints, 0);
  };

  bool pay(uint value) {
    if (properties.money > value) {
      properties.money -= value;
      return true;
    } else {
      return false;
    }
  }

  void getPayed(uint value) {
    properties.money += value;
  }

  friend std::ostream &operator<<(std::ostream &os, const BaseCharacter &character);

  Inventory inventory;
  CharacterProperties properties;
  CharacterRelation relation;
  std::string name;
};
