//
// Created by nolasco on 16/06/20.
//

#pragma once

#include "model/entity/Character.h"
#include "CharacterType.h"

class CharacterFactory {
public:
  entity::Character generateCharacter();
  entity::Character createCharacter(const CharacterType type);

private:

};
