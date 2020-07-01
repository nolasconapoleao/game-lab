//
// Created by nolasco on 16/06/20.
//

#include "Factory.h"
#include "utils/random/Random.h"

void Factory::generateCharacter() {
  // TODO: [nn] Change access to random element of vector
  auto type = occupationPool.begin();
  std::advance(type, Random::fromTo(0, occupationPool.size() - 1));
  createCharacter(*type);
}

void Factory::createCharacter(const Occupation type) {
  // TODO: replace by random generation based on class
  Stats stats{{1, 2, 3, 8}, 8, 0, 9, 12};
  Passport passport{"a", "b", Occupation::BEGGAR, Race::HUMAN, CharacterAttack::PHYSICAL};

  entity::Character creation;
  switch (type) {
    case Occupation::BLACKSMITH:
      creation = entity::Character("BlackSmith", stats, passport, GhostInTheShell::AI);
      break;
    case Occupation::BEGGAR:
      creation = entity::Character("Beggar", stats, passport, GhostInTheShell::AI);
      break;
  }

  world.addCharacter(creation);
}

void Factory::createPlayer(const LocationId locationId) {
  generateCharacter();
  // TODO: [nn] change to random creation
  world.characters.back().setGhost(GhostInTheShell::Player);
  world.characters.back().setLocation(0);
}