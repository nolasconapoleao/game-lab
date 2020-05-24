//
// Created by nolasco on 24/05/20.
//

#include "Match.h"

#include <utils/MathUtils.h>

const MatchResult Match::match(Character &attacked, Character &attacker) {
  MatchResult result;

  // Change of diplomacy
  if ("Player" == attacker.name && Diplomacy::hostile != attacked.relation) {
    attacked.relation = Diplomacy::hostile;
    result.diplomacyUpdate = true;
  }

  // Combat
  result.attacker = attack(attacked, attacker);

  // Retaliation
  if (!attacked.isDead()) {
    if (attacked.properties.speed > 2 * attacker.properties.speed) {
      result.attacked = attack(attacker, attacked);
      result.attackerDied = attacked.isDead();
    }
  } else {
    result.attackedDied = true;
  }

  return result;
}

const AttackResult Match::attack(Character &attacked, const Character &attacker) {
  AttackResult result;
  uint8_t attackPoints = attacker.properties.attack - attacker.properties.defense;
  const auto attackProbability = MathUtils::random(0, attacker.properties.attack);

  if (attackProbability > (2 * attacked.properties.defense)) {
    attacked.properties.health = MathUtils::clamp_sub(attacked.properties.health, 2 * attackPoints, 0);
    result = AttackResult::Critical;
  } else if (attackProbability > attacked.properties.defense) {
    attacked.properties.health = MathUtils::clamp_sub(attacked.properties.health, attackPoints, 0);
    result = AttackResult::Hit;
  } else {
    result = AttackResult::Fail;
  }
  return result;
}
