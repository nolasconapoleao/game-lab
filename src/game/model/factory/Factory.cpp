//
// Created by nolasco on 21/07/20.
//

#include "Factory.h"

#include "model/World.h"

namespace model {

Factory::Factory(const std::shared_ptr<World> &world) : IFactory(std::move(world)) {
  initCharacterNames();
  initLocationNames();
  initTeamNames();
}

void Factory::initCharacterNames() {
  mWorld->characterNames.emplace_back("Charles");
  mWorld->characterNames.emplace_back("Cornelius");
  mWorld->characterNames.emplace_back("Fred");
  mWorld->characterNames.emplace_back("Gilliam");
  mWorld->characterNames.emplace_back("Jake");
  mWorld->characterNames.emplace_back("Louis");
  mWorld->characterNames.emplace_back("Mike");
  mWorld->characterNames.emplace_back("Peter");
  mWorld->characterNames.emplace_back("Philip");
  mWorld->characterNames.emplace_back("Robert");
  mWorld->characterNames.emplace_back("Zachary");
}

void Factory::initLocationNames() {
  mWorld->locationNames.emplace_back("Alligator");
  mWorld->locationNames.emplace_back("Big Boulder");
  mWorld->locationNames.emplace_back("Buddy");
  mWorld->locationNames.emplace_back("Dark abyss");
  mWorld->locationNames.emplace_back("Finegan");
  mWorld->locationNames.emplace_back("Furiosa");
  mWorld->locationNames.emplace_back("Interstice");
  mWorld->locationNames.emplace_back("Lord of The Flies");
  mWorld->locationNames.emplace_back("Lordelo");
  mWorld->locationNames.emplace_back("Obelisk");
  mWorld->locationNames.emplace_back("Outta here");
  mWorld->locationNames.emplace_back("St. Marianus");
  mWorld->locationNames.emplace_back("Stingify");
}

void Factory::initTeamNames() {
  mWorld->teamNames.emplace_back("Alternate");
  mWorld->teamNames.emplace_back("Carp Dividers");
  mWorld->teamNames.emplace_back("Dark Ravens");
  mWorld->teamNames.emplace_back("Destruction");
  mWorld->teamNames.emplace_back("Everythingers");
  mWorld->teamNames.emplace_back("Obstruct");
}

} // namespace model
