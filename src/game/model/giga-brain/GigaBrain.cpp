//
// Created by nolasco on 21/07/20.
//

#include "GigaBrain.h"

#include "libs/random/Random.h"
#include "model/World.h"
#include "model/lookup/Lookup.h"

using namespace Random;

namespace model {

GigaBrain::GigaBrain(const std::shared_ptr<model::Handler> &handler, const std::shared_ptr<model::Lookup> &lookup)
    : handler(std::move(handler)), lookup(std::move(lookup)) {
}

void GigaBrain::characterThink(const CharacterId characterId) {
  const auto &character = lookup->character(characterId);
  switch (character->info.occupation) {
    case Occupation::BEGGAR:
      break;
    case Occupation::BLACKSMITH:
      break;
    case Occupation::JESTER:
      if (inventoryThought(characterId))
        return;
      break;
    case Occupation::LIBRARIAN:
      break;
    case Occupation::MERCENARY:
      if (inventoryThought(characterId))
        return;
      if (attackThought(characterId))
        return;
      break;
    case Occupation::SHOPKEEPER:
      break;
    case Occupation::THIEF:
      if (thiefThought(characterId))
        return;
      break;
    case Occupation::TOURIST:
      if (thiefThought(characterId))
        return;
      break;
  }
  if (touristThought(characterId))
    return;
  if (attackThought(characterId))
    return;
  if (inventoryThought(characterId))
    return;
}

bool GigaBrain::attackThought(const CharacterId characterId) {
  if (rand(0, 5) == 0) {
    const auto attackedId = fromVec(lookup->closeByCharacters(characterId)).id;
    handler->attackCharacter(characterId, attackedId);
    return true;
  } else if (rand(0, 7) == 0) {
    const auto attackedId = fromVec(lookup->closeByStructures(characterId)).id;
    handler->attackStructure(characterId, attackedId);
    return true;
  } else if (rand(0, 15) == 0) {
    const auto attackedId = fromVec(lookup->closeByBuildings(characterId)).id;
    handler->attackBuilding(characterId, attackedId);
    return true;
  }
  return false;
}

bool GigaBrain::inventoryThought(const CharacterId characterId) {
  if (rand(0, 2) == 0) {
    const auto item = fromVec(lookup->consumablesIn(characterId));
    handler->useItem(item.id, characterId);
    return true;
  } else if (rand(0, 5) == 0) {
    const auto item = fromVec(lookup->equippablesIn(characterId));
    if (item.entity->equipped) {
      handler->useItem(item.id, characterId);
      return true;
    }
  }
  return false;
}

bool GigaBrain::thiefThought(const CharacterId characterId) {
  if (rand(0, 5) == 0) {
    const auto stealFrom = fromVec(lookup->closeByCharacters(characterId)).id;
    const auto itemId = fromVec(lookup->itemsIn(stealFrom)).id;
    handler->stealItem(itemId, characterId);
    return true;
  }
  return false;
}

bool GigaBrain::touristThought(const CharacterId characterId) {
  if (rand(0, 15) == 0) {
    const auto locationId = fromVec(lookup->withinWalkingDistance(characterId)).id;
    handler->travel(characterId, locationId);
    return true;
  }
  return false;
}

} // namespace model
