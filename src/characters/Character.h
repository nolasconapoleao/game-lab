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
  uint defensePoints = 0;
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
class Character {
public:
  Character(std::string name, std::string sayHi, std::string sayBye, uint maxHealthPoints, uint attackPoints,
            CharacterRelation relation)
      : name(name), sayHi(sayHi), sayBye(sayBye),
        properties(CharacterProperties{maxHealthPoints, maxHealthPoints, attackPoints}), relation(relation) {
  }

  Character add(const Item &item, uint quantity = 1) {
    inventory.addItem(item, quantity);
    return *this;
  }

  const bool isDead() const {
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

  void getPayment(uint value) {
    properties.money += value;
  }

  friend std::ostream &operator<<(std::ostream &os, const Character &character);

  Inventory inventory;
  CharacterProperties properties;
  CharacterRelation relation;
  std::string name;
  std::string sayHi;
  std::string sayBye;
};
