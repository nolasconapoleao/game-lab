//
// Created by nolasco on 21/07/20.
//

#include "Handler.h"

#include "libs/random/Random.h"
#include "model/World.h"

namespace model {

Handler::Handler(const std::shared_ptr<World> &world, const std::shared_ptr<Factory> &factory,
                 const std::shared_ptr<Cleaner> &cleaner, const std::shared_ptr<Lookup> &lookup)
    : mWorld(world), mFactory(factory), mCleaner(cleaner), mLookup(lookup) {
}

void Handler::travel(const CharacterId &characterId, const LocationId locationId) {
  mWorld->locatedIn[characterId] = locationId;
}

void Handler::possess(const CharacterId mageId, const CharacterId possessedId) {
  const auto &mage = mWorld->characters.find(mageId)->second;
  auto &possessed = mWorld->characters.find(possessedId)->second;
  if (0 < compare(mage.stats().mAtk, possessed.stats().mDef)) {
    possessed.info.ghost = Ghost::PLAYER;
  }
}

int Handler::compare(const Quantity attacker, const Quantity defender) {
  return Random::rand(attacker) - Random::rand(defender);
}

} // namespace model
