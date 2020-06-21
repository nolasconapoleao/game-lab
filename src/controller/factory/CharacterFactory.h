//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <vector>

#include "model/entity/Character.h"
#include "model/entity/include/Occupation.h"

class CharacterFactory {
public:
  CharacterFactory();
  entity::Character generateCharacter();
  entity::Character createCharacter(const Occupation type);

private:
  std::vector<Occupation> occupationPool;
};
