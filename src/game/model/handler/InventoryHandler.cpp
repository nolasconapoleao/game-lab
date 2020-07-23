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
    quantity = lookup->item(itemId)->quantity;
  }

  transferItem(itemId, locationId, quantity);
}

void Handler::pickupItem(const ItemId itemId, const CharacterId characterId, Quantity quantity) {
  if (0 == quantity) {
    quantity = lookup->item(itemId)->quantity;
  }

  transferItem(itemId, characterId, quantity);
}

void Handler::stealItem(const ItemId itemId, const CharacterId roberId) {
  const auto &robber = world->characters.find(roberId)->second;
  const auto &robbedId = world->possessions.find(itemId)->second;
  const auto &robbed = world->characters.find(robbedId)->second;
  const auto robberyResult = compare(robber.stats().ste, robbed.stats().inte);

  if (robberyResult > 0) {
    transferItem(itemId, roberId, lookup->item(itemId)->quantity);
  }
}

void Handler::useItem(const CharacterId characterId, const ItemId itemId) {
  if (lookup->isConsumable(itemId)) {
    auto &consumable = world->consumables.find(itemId)->second;
    if (!consumable.consumed) {
      consumable.consumed = true;
      applyItemEffect(itemId);
    }
  } else if (lookup->isEquippable(itemId)) {
    auto &equipable = world->equippables.find(itemId)->second;
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
  if (lookup->isConsumable(itemId)) {
    auto &consumable = world->consumables.find(itemId)->second;
    if (consumable.consumed) {
      consumable.duration--;
    }
    if (consumable.duration) {
      consumable.quantity--;
    }
  } else if (lookup->isEquippable(itemId)) {
    auto &equipable = world->equippables.find(itemId)->second;
    if (equipable.equipped) {
      equipable.uses--;
    }
    if (equipable.uses) {
      equipable.quantity--;
    }
    equipable.equipped = !equipable.equipped;
  }

  if (lookup->item(itemId)->quantity == 0) {
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
    character.temp = character.temp + lookup->item(itemId)->effect;
  }
}

void Handler::revertItemEffect(ItemId itemId) {
  const auto itemOwner = world->possessions.find(itemId)->second;
  if (world->characters.contains(itemOwner)) {
    auto &character = world->characters.find(itemOwner)->second;
    character.temp = character.temp - lookup->item(itemId)->effect;
  }
}

} // namespace model
