//
// Created by nolasco on 21/07/20.
//

#include "Handler.h"

#include "libs/random/Random.h"
#include "model/World.h"

namespace model {

Handler::Handler(const std::shared_ptr<World> &world, const std::shared_ptr<IFactory> &factory,
                 const std::shared_ptr<ICleaner> &cleaner, const std::shared_ptr<ILookup> &lookup)
    : IHandler(std::move(world), std::move(factory), std::move(cleaner), std::move(lookup)) {
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
