//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "math/gamemath.h"
#include "model/World.h"

namespace model {

AttackResult Handler::attackCharacter(const CharacterId attackerId, const CharacterId attackedId) {
  const auto &attacker = mWorld->characters.find(attackerId)->second;
  auto &attacked = mWorld->characters.find(attackedId)->second;
  const auto fightResult = compare(attacker.stats().atk, attacked.stats().def);

  attacked.base.hp = gamemath::cSub(attacked.base.hp, fightResult);

  if (attacked.stats().hp == 0) {
    killCharacter(attackedId);
  }

  AttackResult result{AttackResult::Fail};
  if (fightResult > 0) {
    result = AttackResult::Hit;
  }
  return result;
}

void Handler::attackStructure(const CharacterId attackerId, const StructureId structureId) {
  const auto &attacker = mWorld->characters.find(attackerId)->second;
  auto &attacked = mWorld->structures.find(structureId)->second;
  attacked.health = gamemath::cSub(attacked.health, attacker.stats().atk);

  if (attacked.health == 0) {
    demolishStructure(structureId);
  }
}

void Handler::attackBuilding(const CharacterId attackerId, const LocationId buildingId) {
  const auto &attacker = mWorld->characters.find(attackerId)->second;
  auto &attacked = mWorld->buildings.find(buildingId)->second;
  attacked.health = gamemath::cSub(attacked.health, attacker.stats().atk);

  if (attacked.health == 0) {
    demolishBuilding(buildingId);
  }
}

} // namespace model
