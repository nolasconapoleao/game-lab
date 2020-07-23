//
// Created by nolasco on 21/07/20.
//

#include "Handler.h"

#include "libs/random/Random.h"
#include "model/World.h"

namespace model {

Handler::Handler(const std::shared_ptr<World> &world, const std::shared_ptr<Factory> &factory,
                 const std::shared_ptr<Cleaner> &cleaner, std::shared_ptr<Lookup> lookup)
    : world(world), factory(factory), cleaner(cleaner), lookup(lookup) {
}

void Handler::travel(const CharacterId &characterId, const LocationId locationId) {
  world->locatedIn[characterId] = locationId;
}

void Handler::possess(const CharacterId mageId, const CharacterId possessedId) {
  const auto &mage = world->characters.find(mageId)->second;
  auto &possessed = world->characters.find(possessedId)->second;
  if (compare(mage.stats().mAtk, possessed.stats().mDef)) {
    possessed.info.ghost = Ghost::PLAYER;
  }
}

int Handler::compare(const Quantity attacker, const Quantity defender) {
  return Random::rand(attacker) - Random::rand(defender);
}

} // namespace model
