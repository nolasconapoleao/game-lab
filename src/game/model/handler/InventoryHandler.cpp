//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "model/World.h"
#include "model/lookup/Lookup.h"

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
  if (world->consumables.contains(itemId)) {
    auto &consumable = world->consumables.find(itemId)->second;
    consumable.consumed = true;
  } else if (world->equipables.contains(itemId)) {
    auto &equipable = world->equipables.find(itemId)->second;
    equipable.equipped = !equipable.equipped;
  }
}

} // namespace model
