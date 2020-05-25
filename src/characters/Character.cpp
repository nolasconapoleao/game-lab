//
// Created by nolasco on 10/05/20.
//

#include "Character.h"

#include <sstream>

#include "utils/MathUtils.h"

Character::Character() {
}

Character::Character(std::string name, std::string charClass, std::string sayHi, std::string sayBye,
                     Properties properties, Diplomacy diplomacy)
    : name(name), charClass(charClass), sayHi(sayHi), sayBye(sayBye), properties(Properties{properties}),
      relation(diplomacy) {
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

const std::string Character::talk() const {
  std::ostringstream os;
  os << name << " said: " << (isDead() ? sayBye : sayHi);
  return os.str();
}

bool Character::levelUp(uint8_t xp) {
  do {
    uint8_t xpToNextLvl = properties.level - properties.experience;

    if (xp > xpToNextLvl) {
      properties.level++;
      xp = xp - xpToNextLvl;
      properties.experience = 0;
    } else {
      properties.experience = xp;
      break;
    }
  } while (true);
}
