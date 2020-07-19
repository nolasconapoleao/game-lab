//
// Created by nolasco on 16/06/20.
//

#include "Factory.h"
#include "libs/random/Random.h"

void Factory::generateCharacter() {
  const auto typeId = Random::fromVec(occupationPool);
  createCharacter(typeId);
}

void Factory::createCharacter(const Occupation type) {
  // TODO: replace by random generation based on class
  ItemEffect effect{4, 2, 3, 20};
  Stats stats{effect, 20, 8, 2, 1, 12};
  Info passport{"a", "b", Occupation::BEGGAR, Race::HUMAN, AttackType::PHYSICAL};

  entity::Character creation;
  switch (type) {
    case Occupation::BLACKSMITH:
      creation = entity::Character("BlackSmith", stats, passport, Ghost::AI);
      break;
    case Occupation::BEGGAR:
      creation = entity::Character("Beggar", stats, passport, Ghost::AI);
      break;
  }

  World::addCharacter(creation);
}

void Factory::createPlayer(const LocationId locationId) {
  generateCharacter();
  World::characters.rbegin()->second.setGhost(Ghost::Player);
  World::characters.rbegin()->second.setLocation(0);
}