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
  if (CONSUMABLE == mLookup->type(itemId)) {
    auto &consumable = mWorld->consumables.find(itemId)->second;
    if (consumable.consumed) {
      destroyItem(itemId);
    }
    stackConsumable(itemId, destinationId, quantity);
  } else if (EQUIPPABLE == mLookup->type(itemId)) {
    auto &equipable = mWorld->equippables.find(itemId)->second;
    equipable.equipped = false;
    mWorld->locatedIn[itemId] = destinationId;
  }
}

void Handler::stackConsumable(const ItemId itemId, const ResourceId destinationId, Quantity quantity) {
  auto &consumable = mWorld->consumables.find(itemId)->second;
  auto foundItemId = mLookup->consumableTypeIn(destinationId, consumable.type);
  if (foundItemId.has_value()) {
    auto &foundItem = mWorld->consumables.find(foundItemId.value())->second;
    foundItem.quantity = gamemath::cAdd(foundItem.quantity, quantity);
    if (consumable.quantity == quantity) {
      destroyItem(itemId);
    }
  } else {
    if (consumable.quantity == quantity) {
      mWorld->locatedIn[itemId] = destinationId;
    } else {
      const auto newItemId = mFactory->createConsumable(consumable.type, quantity);
      mWorld->locatedIn.emplace(newItemId, destinationId);
      consumable.quantity -= quantity;
    }
  }
}

void Handler::transferMoney(const CharacterId originId, const CharacterId destinationId, Number amount) {
  auto &origin = mWorld->characters.find(originId)->second;
  auto &destination = mWorld->characters.find(destinationId)->second;
  origin.info.cash = gamemath::cSub(destination.info.cash, amount);
  destination.info.cash = gamemath::cAdd(destination.info.cash, amount);
}

} // namespace model
