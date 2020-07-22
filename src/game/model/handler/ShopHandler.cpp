//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "model/World.h"

namespace model {

void Handler::buyItem(const ItemId itemId, const CharacterId buyerId, Quantity quantity) {
  const auto seller = world->possessions.find(itemId);
  if (0 == quantity) {
    quantity = maximumBuyable(buyerId, itemId);
  }

  transferItem(itemId, buyerId, quantity);
  const auto sumPrice = getItem(itemId)->unitPrice * quantity;
  transferMoney(buyerId, seller->first, sumPrice);
}

void Handler::sellItem(const ItemId itemId, const CharacterId sellerId, Quantity quantity) {
  const auto buyer = world->possessions.find(itemId);
  if (0 == quantity) {
    quantity = getItem(itemId)->quantity;
  }

  transferItem(itemId, sellerId, quantity);
  const auto sumPrice = getItem(itemId)->unitPrice * quantity;
  transferMoney(buyer->first, sellerId, sumPrice);
}

Quantity Handler::maximumBuyable(CharacterId characterId, ItemId itemId) {
  return world->characters.find(characterId)->second.info.cash / getItem(itemId)->unitPrice;
}

} // namespace model
