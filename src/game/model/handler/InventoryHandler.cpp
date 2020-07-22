//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "model/World.h"

namespace model {

void Handler::dropItem(ItemId itemId, ResourceId locationId, Quantity quantity) {
}

void Handler::pickupItem(ItemId itemId, CharacterId characterId, Quantity quantity) {
}

void Handler::useItem(CharacterId characterId, ItemId itemId) {
}

void Handler::transferItem(ItemId itemId, ResourceId locationId, Quantity quantity) {
}

void Handler::transferMoney(CharacterId origin, CharacterId destination, Quantity quantity) {
}

Quantity Handler::compare(const Quantity attacker, const Quantity defender) {
}

} // namespace model
