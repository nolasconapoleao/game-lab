//
// Created by nolasco on 07/06/20.
//

#include "Controller.h"

void Controller::characterGoesTo(const CharacterId &characterId, const LocationId locationId) {
  world.character(characterId).setLocation(locationId);
}
