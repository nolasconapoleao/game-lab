//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "model/World.h"

namespace model {

AttackResult Handler::attackCharacter(CharacterId attackerId, CharacterId attackedId) {
  return AttackResult::Critical;
}

void Handler::attackStructure(CharacterId attackerId, StructureId structureId) {
}

void Handler::attackBuilding(CharacterId attackerId, LocationId inLocationId) {
}

} // namespace model
