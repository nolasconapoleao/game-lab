//
// Created by nolasco on 16/06/20.
//

#include "CharacterFactory.h"

entity::Character CharacterFactory::generateCharacter() {
  // TODO: Random generation
}

entity::Character CharacterFactory::createCharacter(CharacterType type) {
  entity::Property stats {1, 2, 3, 8, 8};

  switch (type) {
    case CharacterType::PLAYER:
      return entity::Character(entity::Property(), GhostInTheShell::Player, "Player");
    case CharacterType::ENEMY:
      return entity::Character(entity::Property(), GhostInTheShell::AI, "Enemy");
  }
}