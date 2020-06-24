//
// Created by nolasco on 07/06/20.
//

#include "TravelHandler.h"

void TravelHandler::characterGoesTo(entity::Character &character, LocationId locationId) {
  character.setLocation(locationId);
}
