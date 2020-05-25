//
// Created by nolasco on 24/05/20.
//

#include "Match.h"

#include <utils/MathUtils.h>

#include "InteractUtils.h"

const MatchResult Match::match(Room &ring, Character &attacked, Character &attacker) {
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

      if (attacker.isDead()) {
        result.attackerDied = true;
        attacked.getPayment(attacker.properties.money);
        dropAll(ring, attacker);
      }
    }
  } else {
    result.attackedDied = true;
    attacker.getPayment(attacked.properties.money);
    dropAll(ring, attacked);
  }

  return result;
}

const AttackResult Match::attack(Character &attacked, const Character &attacker) {
  AttackResult result;
  uint8_t attackPoints = attacker.properties.attack - attacker.properties.defense;
  const auto attackProbability = MathUtils::random(0, attacker.properties.attack);
  const auto defenseProbability = MathUtils::random(1, attacked.properties.defense);

  if (attackProbability > (2 * defenseProbability)) {
    attacked.properties.health = MathUtils::clamp_sub(attacked.properties.health, 2 * attackPoints, 0);
    result = AttackResult::Critical;
  } else if (attackProbability > defenseProbability) {
    attacked.properties.health = MathUtils::clamp_sub(attacked.properties.health, attackPoints, 0);
    result = AttackResult::Hit;
  } else {
    result = AttackResult::Fail;
  }
  return result;
}

void Match::dropAll(Room &ring, Character &deadCharacter) {
  for (uint8_t itemId = 0; itemId < deadCharacter.pocket.entries.size(); itemId++) {
    uint8_t quantity = deadCharacter.pocket.entries[itemId].quantity;
    exchangeItem(deadCharacter.pocket, ring.floor, itemId, quantity);
  }
}
