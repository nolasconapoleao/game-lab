//
// Created by nolasco on 07/06/20.
//

#include "Handler.h"

void Handler::characterGoesTo(const CharacterId &characterId, const LocationId locationId) {
  World::character(characterId).setLocation(locationId);
}
