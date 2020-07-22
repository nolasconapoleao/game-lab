//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "model/World.h"

namespace model {

void Handler::renameCharacter(CharacterId characterId, const std::string &newName) {
  world->characters[characterId].name = newName;
}

void Handler::renameTeam(TeamId teamId, const std::string &newName) {
  world->teams[teamId].name = newName;
}

} // namespace model
