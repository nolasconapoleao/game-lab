//
// Created by nolasco on 10/05/20.
//

#pragma once

#include <string>
#include <vector>

#include "common/Inventory.h"

struct Properties {
  uint8_t health = 0;
  uint8_t maxHealth = 0;
  uint8_t attack = 0;
  uint8_t defense = 0;
  uint8_t speed = 0;
  uint8_t money = 0;
  uint8_t experience = 0;
  uint8_t level = 0;
};

enum class Diplomacy {
  friendly,
  hostile,
  neutral,
};

/**
 * @brief Characters have a pocket.
 */
class Character {
public:
  Character();
  Character(std::string name, std::string charClass, std::string sayHi, std::string sayBye, Properties properties,
            Diplomacy diplomacy);

  Character add(const Item &item, uint8_t quantity = 1);
  const bool isDead() const;
  bool pay(uint8_t value);
  void getPayment(uint8_t value);
  const std::string talk() const;
  bool levelUp(uint8_t xp);

  std::string name;
  std::string charClass;
  std::string sayHi;
  std::string sayBye;
  Properties properties;
  Diplomacy relation;
  Inventory pocket;
};
