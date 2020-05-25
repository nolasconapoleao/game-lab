//
// Created by nolasco on 24/05/20.
//

#include "Match.h"

#include <sstream>

#include "InteractUtils.h"
#include "utils/MathUtils.h"
#include "utils/PrintUtils.h"

void Match::match(Room &ring, Character &attacked, Character &attacker, std::vector<std::string> &convos) {
  std::ostringstream oss;

  // Change of diplomacy
  if ("Player" == attacker.name && Diplomacy::hostile != attacked.relation) {
    attacked.relation = Diplomacy::hostile;
    oss << attacker.name << " made a new enemy in " << attacked.name << std::endl;
  }

  // Combat
  AttackResult attackerR = attack(attacked, attacker);
  oss << attacker.name << " attack: " << attackerR << std::endl;

  // Retaliations
  if (!attacked.isDead()) {
    if (attacked.properties.speed > 2 * attacker.properties.speed) {
      AttackResult attackedR = attack(attacker, attacked);
      oss << attacked.name << " retaliation: " << attackedR << std::endl;

      if (attacker.isDead()) {
        oss << attacker.name << "'s last words: " << attacker.sayBye << std::endl;
        oss << attacked.name << " got " << attacker.properties.money << "$" << std::endl;
        attacked.getPayment(attacker.properties.money);
        dropAll(ring, attacker);
      }
    }
  } else {
    oss << attacked.name << "'s last words: " << attacked.sayBye << std::endl;
    attacker.getPayment(attacked.properties.money);
    oss << attacker.name << " got " << attacked.properties.money << "$" << std::endl;
    dropAll(ring, attacked);
  }

  convos.emplace_back(oss.str());
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
    if (!deadCharacter.pocket.entries[itemId].inUse) {
      exchangeItem(deadCharacter.pocket, ring.floor, itemId, quantity);
    }
  }
}
