//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "model/World.h"
#include "model/lookup/Lookup.h"

namespace model {

void Handler::buyItem(const CharacterId buyerId, const ItemId itemId, Quantity quantity) {
  const auto &seller = world->locatedIn.find(itemId);
  if (0 == quantity) {
    quantity = maximumBuyable(buyerId, itemId);
  }

  transferItem(itemId, buyerId, quantity);
  const auto sumPrice = lookup->item(itemId)->unitPrice * quantity;
  transferMoney(buyerId, seller->first, sumPrice);
}

void Handler::sellItem(const CharacterId sellerId, const ItemId itemId, Quantity quantity) {
  const auto &buyer = world->locatedIn.find(itemId);
  if (0 == quantity) {
    quantity = lookup->item(itemId)->quantity;
  }

  transferItem(itemId, sellerId, quantity);
  const auto sumPrice = lookup->item(itemId)->unitPrice * quantity;
  transferMoney(buyer->first, sellerId, sumPrice);
}

Quantity Handler::maximumBuyable(CharacterId characterId, ItemId itemId) {
  return world->characters.find(characterId)->second.info.cash / lookup->item(itemId)->unitPrice;
}

} // namespace model
