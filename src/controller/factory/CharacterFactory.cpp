//
// Created by nolasco on 16/06/20.
//

#include "Factory.h"
#include "utils/random/Random.h"

void Factory::generateCharacter() {
  const auto typeId = Random::fromVec(occupationPool);
  createCharacter(typeId);
}

void Factory::createCharacter(const Occupation type) {
  // TODO: replace by random generation based on class
  Stats stats{{4, 2, 3, 20}, 20, 8, 0, 9, 12};
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
  world.characters.rbegin()->second.setGhost(GhostInTheShell::Player);
  world.characters.rbegin()->second.setLocation(0);
}