//
// Created by nolasco on 10/05/20.
//

#pragma once

#include <string>
#include <vector>

#include "common/Inventory.h"

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
  Character();
  Character(std::string name, std::string charClass, std::string sayHi, std::string sayBye, uint8_t maxHealthPoints,
            uint8_t attackPoints, Diplomacy relation);

  Character add(const Item &item, uint8_t quantity = 1);
  const bool isDead() const;
  [[nodiscard]] bool attackedBy(const Character &attacker);
  bool pay(uint8_t value);
  void getPayment(uint8_t value);

  std::string name;
  std::string charClass;
  std::string sayHi;
  std::string sayBye;
  Properties properties;
  Diplomacy relation;
  Inventory inventory;
};
