//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "libs/random/Random.h"
#include "model/World.h"

namespace model {

void Handler::dropItem(const ItemId itemId, const ResourceId locationId, Quantity quantity) {
  if (0 == quantity) {
    quantity = getItem(itemId)->quantity;
  }

  transferItem(itemId, locationId, quantity);
}

void Handler::pickupItem(const ItemId itemId, const CharacterId characterId, Quantity quantity) {
  if (0 == quantity) {
    quantity = getItem(itemId)->quantity;
  }

  transferItem(itemId, characterId, quantity);
}

void Handler::useItem(const CharacterId characterId, const ItemId itemId) {
}

void Handler::transferItem(const ItemId itemId, const ResourceId resourceId, Quantity quantity) {
}

void Handler::transferMoney(const CharacterId origin, const CharacterId destination, Number quantity) {
}

int Handler::compare(const Quantity attacker, const Quantity defender) {
  return Random::rand(attacker) - Random::rand(defender);
}

} // namespace model
