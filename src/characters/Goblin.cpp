//
// Created by nolasco on 14/05/20.
//

#include "Goblin.h"

Goblin::Goblin() : BaseCharacter("Goblin", 7, 1, CharacterRelation::hostile) {
}

std::string Goblin::sayHi() {
  return "Hey, I haven't seen you here before";
}

std::string Goblin::sayBye() {
  return "And I would have gotten away if it wasn't for those medley kids.";
}
