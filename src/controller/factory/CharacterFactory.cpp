//
// Created by nolasco on 16/06/20.
//

#include "CharacterFactory.h"

#include "utils/random/Random.h"

CharacterFactory::CharacterFactory() {
  occupationPool.emplace_back(Occupation::PLAYER);
  occupationPool.emplace_back(Occupation::BEGGAR);
}

entity::Character CharacterFactory::generateCharacter() {
  // TODO: [nn] Change access to random element of vector
  auto type = occupationPool.begin();
  std::advance(type, Random::fromTo(0, occupationPool.size() - 1));
  return createCharacter(*type);
}

entity::Character CharacterFactory::createCharacter(Occupation type) {
  // TODO: replace by random generation based on class
  entity::Stats stats{1, 2, 3, 8, 8};

  switch (type) {
    case Occupation::PLAYER:
      return entity::Character("Player", stats, GhostInTheShell::Player);
    case Occupation::BEGGAR:
      return entity::Character("Beggar", stats, GhostInTheShell::AI);
  }
}
