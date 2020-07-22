//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "libs/math/gamemath.h"
#include "libs/random/Random.h"
#include "model/World.h"
#include "model/factory/Factory.h"

namespace model {

// TODO: consumables should stack
void Handler::transferItem(const ItemId itemId, const ResourceId resourceId, Quantity quantity) {
  if (world->consumables.contains(itemId)) {
    auto &consumable = world->consumables.find(itemId)->second;
    if (consumable.consumed) {
      destroyItem(itemId);
    }

    if (consumable.quantity == quantity) {
      world->possessions[itemId] = resourceId;
    } else {
      // TODO: add type to parameters
      // factory->createConsumable(consumable.type, quantity);
      consumable.quantity = gamemath::cSub(consumable.quantity, quantity);
    }
  } else if (world->equipables.contains(itemId)) {
    auto &equipable = world->equipables.find(itemId)->second;
    equipable.equipped = false;
    world->possessions[itemId] = resourceId;
  }
}

void Handler::transferMoney(const CharacterId originId, const CharacterId destinationId, Number amount) {
  auto &origin = world->characters.find(originId)->second;
  auto &destination = world->characters.find(destinationId)->second;
  origin.info.cash = gamemath::cSub(destination.info.cash, amount);
  destination.info.cash = gamemath::cAdd(destination.info.cash, amount);
}

} // namespace model
