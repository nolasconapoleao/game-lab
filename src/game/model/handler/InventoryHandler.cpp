//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "libs/math/gamemath.h"
#include "model/World.h"
#include "model/lookup/Lookup.h"

using namespace gamemath;

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
    if (!consumable.consumed) {
      consumable.consumed = true;
      applyItemEffect(itemId);
    }
  } else if (world->equipables.contains(itemId)) {
    auto &equipable = world->equipables.find(itemId)->second;
    if (equipable.equipped) {
      equipable.equipped = false;
      revertItemEffect(itemId);
    } else {
      equipable.equipped = true;
      applyItemEffect(itemId);
    }
  }
}

void Handler::depleteItem(const ItemId itemId) {
  if (world->consumables.contains(itemId)) {
    auto &consumable = world->consumables.find(itemId)->second;
    if (consumable.consumed) {
      consumable.duration--;
    }
    if (consumable.duration) {
      consumable.quantity--;
    }
  } else if (world->equipables.contains(itemId)) {
    auto &equipable = world->equipables.find(itemId)->second;
    if (equipable.equipped) {
      equipable.uses--;
    }
    if (equipable.uses) {
      equipable.quantity--;
    }
    equipable.equipped = !equipable.equipped;
  }

  if (getItem(itemId)->quantity == 0) {
    revertItemEffect(itemId);
    destroyItem(itemId);
  }
}

void Handler::characterItemDepletion(const CharacterId characterId) {
  for (auto &item : lookup->itemsIn(characterId)) {
    depleteItem(item.id);
  };
}

void Handler::applyItemEffect(ItemId itemId) {
  const auto itemOwner = world->possessions.find(itemId)->second;
  if (world->characters.contains(itemOwner)) {
    auto &character = world->characters.find(itemOwner)->second;
    character.temp = character.temp + getItem(itemId)->effect;
  }
}

void Handler::revertItemEffect(ItemId itemId) {
  const auto itemOwner = world->possessions.find(itemId)->second;
  if (world->characters.contains(itemOwner)) {
    auto &character = world->characters.find(itemOwner)->second;
    character.temp = character.temp - getItem(itemId)->effect;
  }
}

} // namespace model
