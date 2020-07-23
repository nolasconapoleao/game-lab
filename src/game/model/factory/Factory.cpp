//
// Created by nolasco on 21/07/20.
//

#include "Factory.h"

#include "model/World.h"

namespace model {

Factory::Factory(const std::shared_ptr<World> &world) : world(std::move(world)), entityCounter(0) {
  initCharacterNames();
  initLocationNames();
  initTeamNames();
}

void Factory::initCharacterNames() {
  world->characterNames.emplace_back("Charles");
  world->characterNames.emplace_back("Cornelius");
  world->characterNames.emplace_back("Fred");
  world->characterNames.emplace_back("Gilliam");
  world->characterNames.emplace_back("Jake");
  world->characterNames.emplace_back("Louis");
  world->characterNames.emplace_back("Mike");
  world->characterNames.emplace_back("Peter");
  world->characterNames.emplace_back("Philip");
  world->characterNames.emplace_back("Robert");
  world->characterNames.emplace_back("Zachary");
}

void Factory::initLocationNames() {
  world->locationNames.emplace_back("Alligator");
  world->locationNames.emplace_back("Big Boulder");
  world->locationNames.emplace_back("Buddy");
  world->locationNames.emplace_back("Dark abyss");
  world->locationNames.emplace_back("Finegan");
  world->locationNames.emplace_back("Furiosa");
  world->locationNames.emplace_back("Interstice");
  world->locationNames.emplace_back("Lord of The Flies");
  world->locationNames.emplace_back("Lordelo");
  world->locationNames.emplace_back("Obelisk");
  world->locationNames.emplace_back("Outta here");
  world->locationNames.emplace_back("St. Marianus");
  world->locationNames.emplace_back("Stingify");
}

void Factory::initTeamNames() {
  world->teamNames.emplace_back("Alternate");
  world->teamNames.emplace_back("Carp Dividers");
  world->teamNames.emplace_back("Dark Ravens");
  world->teamNames.emplace_back("Destruction");
  world->teamNames.emplace_back("Everythingers");
  world->teamNames.emplace_back("Obstruct");
}

} // namespace model
