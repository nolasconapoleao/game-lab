//
// Created by nolasco on 21/07/20.
//

#include "Factory.h"
#include "libs/math/gamemath.h"
#include "libs/random/Random.h"
#include "model/World.h"
#include "model/entity/Character.h"

using namespace gamemath;

namespace model {

constexpr Quantity randomRange = 4;

CharacterId Factory::createCharacter(ThreatLevel threat, AttackType weaponAffinity, Race race,
                                     CharacterPrototype type) {
  if (type == CharacterPrototype::UNDEFINED) {
    type = CharacterPrototype{Random::rand(0, static_cast<Quantity>(CharacterPrototype::UNDEFINED))};
  }

  if (weaponAffinity == AttackType::UNDEFINED) {
    weaponAffinity = AttackType{Random::rand(0, static_cast<Quantity>(AttackType::UNDEFINED))};
  }

  if (race == Race::UNDEFINED) {
    race = Race{Random::rand(0, static_cast<Quantity>(Race::UNDEFINED))};
  }

  Info info{Ghost::COMPUTER, race, weaponAffinity, type};
  entity::Character creation(Random::fromVec(world->characterNames), characterStats(info, threat), info);

  world->characters.emplace(entityCounter++, creation);
  return entityCounter;
}

Stats Factory::rampupByOccupation(const CharacterPrototype occupation, Stats stats) {
  switch (occupation) {
    case CharacterPrototype::BEGGAR:
      stats.spd += 2;
      break;
    case CharacterPrototype::BLACKSMITH:
      stats.cst += 5;
      break;
    case CharacterPrototype::JESTER:
      stats.inte += 4;
      break;
    case CharacterPrototype::LIBRARIAN:
      stats.inte += 2;
      break;
    case CharacterPrototype::MERCENARY:
      stats.atk += 2;
      stats.def += 2;
      break;
    case CharacterPrototype::SHOPKEEPER:
      stats.atk += 10;
      break;
    case CharacterPrototype::THIEF:
      stats.ste += 2;
      break;
    case CharacterPrototype::TOURIST:
      stats.def += 2;
      break;
  }
  return stats;
}

Stats Factory::growStats(ThreatLevel level, Stats stats) {
  Quantity multiplier = 0;
  switch (level) {
    case ThreatLevel::ACE:
      multiplier = 5;
    case ThreatLevel::GOD:
      multiplier = 50;
    case ThreatLevel::MONSTER:
      multiplier = 20;
    case ThreatLevel::NOVICE:
      return stats;
    case ThreatLevel::SCARECROW:
      multiplier = 0;
    case ThreatLevel::VETERAN:
      multiplier = 10;
  }
  return stats * multiplier;
}

Stats Factory::rampupByClass(AttackType weaponAffinity, Stats stats) {
  switch (weaponAffinity) {
    case AttackType::CONJURING:
      stats.mana += 8;
      break;
    case AttackType::ELEMENTAL:
      stats.mana += 2;
      stats.mAtk += 2;
      stats.mDef += 3;
      break;
    case AttackType::MAGIC:
      stats.mana += 5;
      stats.mAtk += 2;
      stats.mDef += 1;
      break;
    case AttackType::PHYSICAL:
      stats.atk += 2;
      stats.def += 1;
      break;
    case AttackType::SUPPORT:
      stats.mana += 2;
      break;
  }
  return stats;
}

Stats Factory::rampupByRace(Race race, Stats stats) {
  switch (race) {
    case Race::DEMON:
      stats.mDef += 5;
      stats.mAtk += 5;
      break;
    case Race::DRAGON:
      stats.mDef += 8;
      stats.mAtk += 8;
      stats.cst += 8;
      break;
    case Race::ELF:
      stats.mDef += 2;
      stats.mAtk += 2;
      break;
    case Race::GIANT:
      stats.mDef += 10;
      stats.mAtk += 4;
      break;
    case Race::HUMAN:
      stats.spd += 5;
      break;
    case Race::ORC:
      stats.cst += 2;
      break;
    case Race::TROLL:
      stats.spd += 2;
      stats.cst += 2;
      break;
    case Race::GOBLIN:
      stats.spd += 5;
      break;
  }
  return stats;
}

Stats Factory::characterStats(Info info, const ThreatLevel threat) {
  Stats stats = minimalStats();
  stats = rampupByOccupation(info.occupation, stats);
  stats = rampupByClass(info.attackType, stats);
  stats = rampupByRace(info.race, stats);
  stats = growStats(threat, stats);
  return stats;
}

Stats Factory::randomizeStats(Stats stats) {
  stats.mhp = Random::rand(cSub(stats.mhp, randomRange), cAdd(stats.mhp, randomRange));
  stats.hp = Random::rand(cSub(stats.hp, randomRange), stats.mhp);
  stats.atk = Random::rand(cSub(stats.atk, randomRange), cAdd(stats.atk, randomRange));
  stats.def = Random::rand(cSub(stats.def, randomRange), cAdd(stats.def, randomRange));
  stats.mAtk = Random::rand(cSub(stats.mAtk, randomRange), cAdd(stats.mAtk, randomRange));
  stats.mDef = Random::rand(cSub(stats.mDef, randomRange), cAdd(stats.mDef, randomRange));
  stats.spd = Random::rand(cSub(stats.spd, randomRange), cAdd(stats.spd, randomRange));
  stats.inte = Random::rand(cSub(stats.inte, randomRange), cAdd(stats.inte, randomRange));
  stats.acc = Random::rand(cSub(stats.acc, randomRange), cAdd(stats.acc, randomRange));
  stats.ste = Random::rand(cSub(stats.ste, randomRange), cAdd(stats.ste, randomRange));
  stats.mana = Random::rand(cSub(stats.mana, randomRange), cAdd(stats.mana, randomRange));
  stats.cst = Random::rand(cSub(stats.cst, randomRange), cAdd(stats.cst, randomRange));
  return stats;
}

constexpr Stats Factory::minimalStats() {
  Stats result;
  result.hp = 8;
  result.atk = 0;
  result.def = 0;
  result.mAtk = 0;
  result.mDef = 0;
  result.spd = 2;
  result.inte = 3;
  result.acc = 2;
  result.ste = 0;
  result.mana = 0;
  result.mhp = 8;
  result.cst = 10;
  return result;
}

} // namespace model