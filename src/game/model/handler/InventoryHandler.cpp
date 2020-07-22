//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "model/World.h"

namespace model {

void Handler::dropItem(const ItemId itemId, const ResourceId locationId, Quantity quantity) {
}

void Handler::pickupItem(const ItemId itemId, const CharacterId characterId, Quantity quantity) {
}

void Handler::useItem(const CharacterId characterId, const ItemId itemId) {
}

void Handler::transferItem(const ItemId itemId, const ResourceId resourceId, Quantity quantity) {
}

void Handler::transferMoney(const CharacterId origin, const CharacterId destination, Number quantity) {
}

Quantity Handler::compare(const Quantity attacker, const Quantity defender) {
}

} // namespace model
