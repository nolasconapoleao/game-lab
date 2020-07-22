//
// Created by nolasco on 22/07/20.
//

#include "Handler.h"
#include "libs/math/gamemath.h"
#include "model/World.h"

namespace model {

AttackResult Handler::attackCharacter(const CharacterId attackerId, const CharacterId attackedId) {
  auto attacker = world->characters.find(attackerId)->second;
  auto attacked = world->characters.find(attackedId)->second;
  const auto fightResult = compare(attacker.stats().atk, attacked.stats().def);

  attacked.base.hp = gamemath::cSub(attacked.base.hp, fightResult);

  if (attacked.base.hp == 0) {
    attacked.effects.emplace(StatusEffect::DEAD);
  }

  AttackResult result;
  if (fightResult > 0) {
    result = AttackResult::Hit;
  } else if (fightResult < 0) {
    result = AttackResult::Fail;
  }
  return result;
}

void Handler::attackStructure(const CharacterId attackerId, const StructureId structureId) {
  auto attacker = world->characters.find(attackerId)->second;
  auto attacked = world->structures.find(structureId)->second;
  attacked.health = gamemath::cSub(attacked.health, attacker.stats().atk);

  if (attacked.health == 0) {
    demolishStructure(structureId);
  }
}

void Handler::attackBuilding(const CharacterId attackerId, const LocationId buildingId) {
  auto attacker = world->characters.find(attackerId)->second;
  auto attacked = world->buildings.find(buildingId)->second;
  attacked.health = gamemath::cSub(attacked.health, attacker.stats().atk);

  if (attacked.health == 0) {
    demolishBuilding(buildingId);
  }
}

} // namespace model
