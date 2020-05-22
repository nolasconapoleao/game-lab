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

struct Properties {
  uint health;
  uint maxHealth;
  uint attack;
  uint defense = 0;
  uint money = 0;
  uint experience = 0;
};

enum class Diplomacy {
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
            Diplomacy relation)
      : name(name), sayHi(sayHi), sayBye(sayBye),
        properties(Properties{maxHealthPoints, maxHealthPoints, attackPoints}), relation(relation) {
  }

  Character add(const Item &item, uint quantity = 1) {
    inventory.addItem(item, quantity);
    return *this;
  }

  const bool isDead() const {
    return properties.health == 0;
  };

  void receiveAttack(uint attackPoints) {
    properties.health = MathUtils::clamp_sub(properties.health, attackPoints, 0);
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
  Properties properties;
  Diplomacy relation;
  std::string name;
  std::string sayHi;
  std::string sayBye;
};
