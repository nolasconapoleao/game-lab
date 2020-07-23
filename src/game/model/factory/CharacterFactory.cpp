//
// Created by nolasco on 21/07/20.
//

#include "Factory.h"
#include "datatypes/entity/Character.h"
#include "libs/math/gamemath.h"
#include "libs/random/Random.h"
#include "model/World.h"

using namespace gamemath;

namespace model {

constexpr Quantity randomRange = 4;

CharacterId Factory::createCharacter(const ThreatLevel threat, AttackType weaponAffinity, Race race, Occupation type) {
  if (type == Occupation::UNDEFINED) {
    type = Occupation{Random::rand(0, static_cast<Quantity>(Occupation::UNDEFINED) - 1)};
  }

  if (weaponAffinity == AttackType::UNDEFINED) {
    weaponAffinity = AttackType{Random::rand(0, static_cast<Quantity>(AttackType::UNDEFINED) - 1)};
  }

  if (race == Race::UNDEFINED) {
    race = Race{Random::rand(0, static_cast<Quantity>(Race::UNDEFINED) - 1)};
  }

  Info info{0, Ghost::COMPUTER, race, weaponAffinity, type};
  entity::Character creation(Random::fromVec(world->characterNames), characterStats(info, threat), info);

  world->characters.emplace(++entityCounter, creation);
  return entityCounter;
}

Stats Factory::rampupByOccupation(const Occupation occupation, Stats stats) {
  switch (occupation) {
    case Occupation::BEGGAR:
      stats.spd += 2;
      break;
    case Occupation::BLACKSMITH:
      stats.cst += 5;
      break;
    case Occupation::JESTER:
      stats.inte += 4;
      break;
    case Occupation::LIBRARIAN:
      stats.inte += 2;
      break;
    case Occupation::MERCENARY:
      stats.atk += 2;
      stats.def += 2;
      break;
    case Occupation::SHOPKEEPER:
      stats.atk += 10;
      break;
    case Occupation::THIEF:
      stats.ste += 2;
      break;
    case Occupation::TOURIST:
      stats.def += 2;
      break;
  }
  return stats;
}

Stats Factory::growStats(ThreatLevel level, Stats stats) {
  return stats * static_cast<Quantity>(level);
}

Stats Factory::rampupByClass(const AttackType weaponAffinity, Stats stats) {
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

Stats Factory::rampupByRace(const Race race, Stats stats) {
  switch (race) {
    case Race::DEMON:
      stats.mDef += 5;
      stats.mAtk += 5;
      break;
    case Race::DRAGON:
      stats.mDef += 8;
      stats.mAtk += 8;
      stats.cst += 8;
      stats.ran += 5;
      break;
    case Race::ELF:
      stats.mDef += 2;
      stats.mAtk += 2;
      break;
    case Race::GIANT:
      stats.mDef += 10;
      stats.mAtk += 4;
      stats.ran += 1;
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

Stats Factory::characterStats(const Info info, const ThreatLevel threat) {
  Stats stats = minimalStats();
  stats = rampupByOccupation(info.occupation, stats);
  stats = rampupByClass(info.attackType, stats);
  stats = rampupByRace(info.race, stats);
  stats = growStats(threat, stats);
  stats = randomizeStats(stats);
  return stats;
}

Stats Factory::randomizeStats(Stats stats) {
  stats.mhp = Random::rand_range(stats.mhp, randomRange);
  stats.hp = Random::rand(cSub(stats.hp, randomRange), stats.mhp);
  stats.atk = Random::rand_range(stats.atk, randomRange);
  stats.def = Random::rand_range(stats.def, randomRange);
  stats.mAtk = Random::rand_range(stats.mAtk, randomRange);
  stats.mDef = Random::rand_range(stats.mDef, randomRange);
  stats.spd = Random::rand_range(stats.spd, randomRange);
  stats.inte = Random::rand_range(stats.inte, randomRange);
  stats.acc = Random::rand_range(stats.acc, randomRange);
  stats.ste = Random::rand_range(stats.ste, randomRange);
  stats.ran = Random::rand_range(stats.ran, randomRange);
  stats.mana = Random::rand_range(stats.mana, randomRange);
  stats.cst = Random::rand_range(stats.cst, randomRange);
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
  result.ran = 1;
  result.mana = 0;
  result.mhp = 8;
  result.cst = 10;
  return result;
}

} // namespace model
