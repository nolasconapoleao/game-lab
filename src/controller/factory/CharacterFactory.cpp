//
// Created by nolasco on 16/06/20.
//

#include "CharacterFactory.h"

#include "utils/random/Random.h"

CharacterFactory::CharacterFactory() {
  occupationPool.emplace_back(Occupation::BLACKSMITH);
  occupationPool.emplace_back(Occupation::BEGGAR);
}

entity::Character CharacterFactory::generateCharacter() {
  // TODO: [nn] Change access to random element of vector
  auto type = occupationPool.begin();
  std::advance(type, Random::fromTo(0, occupationPool.size() - 1));
  return createCharacter(*type);
}

entity::Character CharacterFactory::createCharacter(const Occupation type) {
  // TODO: replace by random generation based on class
  Stats stats{{1, 2, 3, 8}, 8, 0, 9, 12};
  Passport passport{"a", "b", Occupation::BEGGAR, Race::HUMAN, CharacterAttack::PHYSICAL};

  switch (type) {
    case Occupation::BLACKSMITH:
      return entity::Character("BlackSmith", stats, passport, GhostInTheShell::AI);
    case Occupation::BEGGAR:
      return entity::Character("Beggar", stats, passport, GhostInTheShell::AI);
  }
}
