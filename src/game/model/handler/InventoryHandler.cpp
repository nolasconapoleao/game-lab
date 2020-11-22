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
    quantity = mLookup->item(itemId)->quantity;
  }

  transferItem(itemId, locationId, quantity);
}

void Handler::pickupItem(const CharacterId characterId, const ItemId itemId, Quantity quantity) {
  if (0 == quantity) {
    quantity = mLookup->item(itemId)->quantity;
  }

  transferItem(itemId, characterId, quantity);
}

void Handler::stealItem(const CharacterId roberId, const ItemId itemId) {
  const auto &robber = mWorld->characters.find(roberId)->second;
  const auto &robbedId = mWorld->locatedIn.find(itemId)->second;
  const auto &robbed = mWorld->characters.find(robbedId)->second;
  const auto robberyResult = compare(robber.stats().ste, robbed.stats().inte);

  if (robberyResult > 0) {
    transferItem(itemId, roberId, mLookup->item(itemId)->quantity);
  }
}

void Handler::useItem(const ItemId itemId) {
  if (CONSUMABLE == mLookup->type(itemId)) {
    auto &consumable = mWorld->consumables.find(itemId)->second;
    if (!consumable.consumed) {
      consumable.consumed = true;
      applyItemEffect(itemId);
    }
  } else if (EQUIPPABLE == mLookup->type(itemId)) {
    auto &equipable = mWorld->equippables.find(itemId)->second;
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
  if (CONSUMABLE == mLookup->type(itemId)) {
    auto &consumable = mWorld->consumables.find(itemId)->second;
    if (consumable.consumed) {
      consumable.duration--;
    }
    if (0 == consumable.duration) {
      consumable.quantity--;
    }
  } else if (EQUIPPABLE == mLookup->type(itemId)) {
    auto &equipable = mWorld->equippables.find(itemId)->second;
    if (equipable.equipped) {
      equipable.uses--;
    }
    if (0 == equipable.uses) {
      equipable.quantity--;
    }
    equipable.equipped = !equipable.equipped;
  }

  if (mLookup->item(itemId)->quantity == 0) {
    revertItemEffect(itemId);
    destroyItem(itemId);
  }
}

void Handler::characterItemDepletion(const CharacterId characterId) {
  for (const auto &item : mLookup->itemsIn(characterId)) {
    depleteItem(item.id);
  };
}

void Handler::applyItemEffect(ItemId itemId) {
  const auto itemOwner = mWorld->locatedIn.find(itemId)->second;
  if (mWorld->characters.contains(itemOwner)) {
    auto &character = mWorld->characters.find(itemOwner)->second;
    character.temp = character.temp + mLookup->item(itemId)->effect;
  }
}

void Handler::revertItemEffect(ItemId itemId) {
  const auto itemOwner = mWorld->locatedIn.find(itemId)->second;
  if (mWorld->characters.contains(itemOwner)) {
    auto &character = mWorld->characters.find(itemOwner)->second;
    character.temp = character.temp - mLookup->item(itemId)->effect;
  }
}

} // namespace model
