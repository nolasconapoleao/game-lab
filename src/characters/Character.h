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
  uint8_t health = 2;
  uint8_t maxHealth = 2;
  uint8_t attack = 2;
  uint8_t defense = 0;
  uint8_t money = 0;
  uint8_t experience = 0;
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
  Character(std::string name, std::string charClass, std::string sayHi, std::string sayBye, uint8_t maxHealthPoints,
            uint8_t attackPoints, Diplomacy relation)
      : name(name), charClass(charClass), sayHi(sayHi), sayBye(sayBye),
        properties(Properties{maxHealthPoints, maxHealthPoints, attackPoints}), relation(relation) {
  }

  Character add(const Item &item, uint8_t quantity = 1) {
    inventory.addItem(item, quantity);
    return *this;
  }

  const bool isDead() const {
    return properties.health == 0;
  };

  void receiveAttack(uint8_t attackPoints) {
    properties.health = MathUtils::clamp_sub(properties.health, attackPoints, 0);
  };

  bool pay(uint8_t value) {
    if (properties.money > value) {
      properties.money -= value;
      return true;
    } else {
      return false;
    }
  }

  void getPayment(uint8_t value) {
    properties.money += value;
  }

  friend std::ostream &operator<<(std::ostream &os, const Character &character);

  Inventory inventory;
  Properties properties;
  Diplomacy relation;
  std::string name;
  std::string charClass;
  std::string sayHi;
  std::string sayBye;
};
