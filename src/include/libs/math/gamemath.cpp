//
// Created by nolasco on 30/06/20.
//

#include "gamemath.h"

#include <cmath>

namespace gamemath {

Quantity cSub(Quantity minuend, Quantity subtrahend, Quantity lowerBound) {
  if (minuend >= (subtrahend + lowerBound)) {
    return (minuend - subtrahend);
  } else {
    return lowerBound;
  };
}

Quantity cAdd(Quantity augend, Quantity addend, Quantity upperBound) {
  if ((augend + addend) > upperBound) {
    return upperBound;
  } else {
    return (augend + addend);
  };
}

Quantity cMult(Quantity num, Quantity mult, Quantity upperBound) {
  if ((num * mult) > upperBound) {
    return upperBound;
  } else {
    return (num * mult);
  };
}

Quantity cNum(Quantity num, Quantity lowerBound, Quantity upperBound) {
  if (num > upperBound) {
    return upperBound;
  } else if (num < lowerBound) {
    return lowerBound;
  } else {
    return num;
  };
}

Quantity diff(Quantity num1, Quantity num2) {
  return abs(num1 - num2);
}

ItemEffect operator+(ItemEffect &a1, const ItemEffect &a2) {
  a1.hp = cAdd(a1.hp, a2.hp);
  a1.atk = cAdd(a1.atk, a2.atk);
  a1.def = cAdd(a1.def, a2.def);
  a1.mAtk = cAdd(a1.mAtk, a2.mAtk);
  a1.mDef = cAdd(a1.mDef, a2.mDef);
  a1.spd = cAdd(a1.spd, a2.spd);
  a1.inte = cAdd(a1.inte, a2.inte);
  a1.acc = cAdd(a1.acc, a2.acc);
  a1.ste = cAdd(a1.ste, a2.ste);
  a1.ran = cAdd(a1.ran, a2.ran);
  a1.mana = cAdd(a1.mana, a2.mana);
  return a1;
}

ItemEffect operator-(ItemEffect &effect, const ItemEffect &subtraction) {
  ItemEffect result;
  result.hp = cSub(effect.hp, subtraction.hp);
  result.atk = cSub(effect.atk, subtraction.atk);
  result.def = cSub(effect.def, subtraction.def);
  result.mAtk = cSub(effect.mAtk, subtraction.mAtk);
  result.mDef = cSub(effect.mDef, subtraction.mDef);
  result.spd = cSub(effect.spd, subtraction.spd);
  result.inte = cSub(effect.inte, subtraction.inte);
  result.acc = cSub(effect.acc, subtraction.acc);
  result.ste = cSub(effect.ste, subtraction.ste);
  result.ran = cSub(effect.ran, subtraction.ran);
  result.mana = cSub(effect.mana, subtraction.mana);
  return result;
}

Stats operator*(Stats &base, Quantity multiplier) {
  base.mhp = cMult(base.mhp, multiplier);
  base.cst = cMult(base.cst, multiplier);
  base.hp = cMult(base.hp, multiplier);
  base.atk = cMult(base.atk, multiplier);
  base.def = cMult(base.def, multiplier);
  base.mAtk = cMult(base.mAtk, multiplier);
  base.mDef = cMult(base.mDef, multiplier);
  base.spd = cMult(base.spd, multiplier);
  base.inte = cMult(base.inte, multiplier);
  base.acc = cMult(base.acc, multiplier);
  base.ste = cMult(base.ste, multiplier);
  base.ran = cMult(base.ran, multiplier);
  base.mana = cMult(base.mana, multiplier);
  return base;
}

Number accumulatedXp(Quantity lvl, Quantity xp) {
  auto result = (std::pow(lvl, 2) + lvl) / 2 + xp;
  return result;
}

} // namespace gamemath