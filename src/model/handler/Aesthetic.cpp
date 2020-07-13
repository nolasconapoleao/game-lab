//
// Created by nolasco on 04/07/20.
//

#include "Controller.h"

void Controller::changePlayerName(const CharacterId characterId, const std::string &newName) {
  World::character(characterId).setName(newName);
}