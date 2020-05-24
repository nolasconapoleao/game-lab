//
// Created by nolasco on 10/05/20.
//

#include "Character.h"

#include "utils/MathUtils.h"

Character::Character() {
}

Character::Character(std::string name, std::string charClass, std::string sayHi, std::string sayBye,
                     uint8_t maxHealthPoints, uint8_t attackPoints, Diplomacy diplomacy)
    : name(name), charClass(charClass), sayHi(sayHi), sayBye(sayBye),
      properties(Properties{maxHealthPoints, maxHealthPoints, attackPoints}), relation(diplomacy) {
}

Character Character::add(const Item &item, uint8_t quantity) {
  pocket.addItem(item, quantity);
  return *this;
}

const bool Character::isDead() const {
  return properties.health == 0;
};

bool Character::pay(uint8_t value) {
  if (properties.money > value) {
    properties.money -= value;
    return true;
  } else {
    return false;
  }
}

void Character::getPayment(uint8_t value) {
  properties.money += value;
}
