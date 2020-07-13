//
// Created by nolasco on 07/06/20.
//

#include "Controller.h"

void Controller::characterGoesTo(const CharacterId &characterId, const LocationId locationId) {
  World::character(characterId).setLocation(locationId);
}
