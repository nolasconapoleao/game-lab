//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "libs/math/gamemath.h"
#include "libs/random/Random.h"
#include "model/World.h"
#include "model/factory/Factory.h"
#include "model/lookup/Lookup.h"

namespace model {

void Handler::transferItem(const ItemId itemId, const ResourceId destinationId, Quantity quantity) {
  if (CONSUMABLE == lookup->type(itemId)) {
    auto &consumable = world->consumables.find(itemId)->second;
    if (consumable.consumed) {
      destroyItem(itemId);
    }
    stackConsumable(itemId, destinationId, quantity);
  } else if (EQUIPPABLE == lookup->type(itemId)) {
    auto &equipable = world->equippables.find(itemId)->second;
    equipable.equipped = false;
    world->locatedIn[itemId] = destinationId;
  }
}

void Handler::stackConsumable(const ItemId itemId, const ResourceId destinationId, Quantity quantity) {
  auto &consumable = world->consumables.find(itemId)->second;
  auto foundItemId = lookup->consumableTypeIn(destinationId, consumable.type);
  if (foundItemId.has_value()) {
    auto &foundItem = world->consumables.find(foundItemId.value())->second;
    foundItem.quantity = gamemath::cAdd(foundItem.quantity, quantity);
    if (consumable.quantity == quantity) {
      destroyItem(itemId);
    }
  } else {
    if (consumable.quantity == quantity) {
      world->locatedIn[itemId] = destinationId;
    } else {
      const auto newItemId = factory->createConsumable(consumable.type, quantity);
      world->locatedIn.emplace(newItemId, destinationId);
    }
  }
}

void Handler::transferMoney(const CharacterId originId, const CharacterId destinationId, Number amount) {
  auto &origin = world->characters.find(originId)->second;
  auto &destination = world->characters.find(destinationId)->second;
  origin.info.cash = gamemath::cSub(destination.info.cash, amount);
  destination.info.cash = gamemath::cAdd(destination.info.cash, amount);
}

} // namespace model
