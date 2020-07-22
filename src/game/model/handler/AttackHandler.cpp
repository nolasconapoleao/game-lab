//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "model/World.h"

namespace model {

AttackResult Handler::attackCharacter(const CharacterId attackerId, const CharacterId attackedId) {
  return AttackResult::Critical;
}

void Handler::attackStructure(const CharacterId attackerId, const StructureId structureId) {
}

void Handler::attackBuilding(const CharacterId attackerId, const LocationId inLocationId) {
}

} // namespace model
