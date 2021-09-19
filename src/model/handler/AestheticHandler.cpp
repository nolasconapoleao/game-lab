//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "model/World.h"

namespace model {

void Handler::renameCharacter(const CharacterId characterId, const std::string &newName) {
  mWorld->characters.find(characterId)->second.name = newName;
}

void Handler::renameTeam(const TeamId teamId, const std::string &newName) {
  mWorld->teams.find(teamId)->second.name = newName;
}

} // namespace model
