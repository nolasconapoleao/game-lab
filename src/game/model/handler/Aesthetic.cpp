//
// Created by nolasco on 04/07/20.
//

#include "Handler.h"

void Handler::changePlayerName(const CharacterId characterId, const std::string &newName) {
  World::character(characterId).setName(newName);
}