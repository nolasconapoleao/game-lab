//
// Created by nolasco on 07/06/20.
//

#include "Character.h"

#include "libs/math/gamemath.h"

using namespace gamemath;

namespace entity {

Character::Character(const std::string &name, const Stats &baseStats, const Info &info)
    : Entity(name), base(baseStats), info(info) {
}

Stats Character::stats() const {
  Stats result;
  result.mhp = base.mhp;
  result.cst = base.cst;
  result.lvl = base.lvl;
  result.xp = base.xp;
  result.hp = cAdd(base.hp, temp.hp);
  result.atk = cAdd(base.atk, temp.atk);
  result.def = cAdd(base.def, temp.def);
  result.mAtk = cAdd(base.mAtk, temp.mAtk);
  result.mDef = cAdd(base.mDef, temp.mDef);
  result.spd = cAdd(base.spd, temp.spd);
  result.inte = cAdd(base.inte, temp.inte);
  result.acc = cAdd(base.acc, temp.acc);
  result.ste = cAdd(base.ste, temp.ste);
  result.mana = cAdd(base.mana, temp.mana);
  return result;
}

} // namespace entity
