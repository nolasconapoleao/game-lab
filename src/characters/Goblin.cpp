//
// Created by nolasco on 14/05/20.
//

#include "Goblin.h"

Goblin::Goblin() : BaseCharacter(7, 1) {
}

std::string Goblin::sayHi() {
  return "Hey, I haven't seen you here before";
}

std::string Goblin::sayBye() {
  return "And I would have gotten away if it wasn't for those medley kids.";
}

std::ostream &operator<<(std::ostream &os, const Goblin &goblin) {
  os << "Goblin HP: " << goblin.currentHealthPoints << "/" << goblin.maxHealthPoints << std::endl;
  return os;
}
