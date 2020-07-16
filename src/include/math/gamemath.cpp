//
// Created by nolasco on 30/06/20.
//

#include "gamemath.h"

#include <cmath>

namespace gamemath {

Quantity clamp_sub(Quantity minuend, Quantity subtrahend, Quantity lowerBound) {
  if (minuend >= (subtrahend + lowerBound)) {
    return (minuend - subtrahend);
  } else {
    return lowerBound;
  };
}

Quantity clamp_add(Quantity augend, Quantity addend, Quantity upperBound) {
  if ((augend + addend) > upperBound) {
    return upperBound;
  } else {
    return (augend + addend);
  };
}

Quantity clamp(Quantity num, Quantity lowerBound, Quantity upperBound) {
  if (num > upperBound) {
    return upperBound;
  } else if (num < lowerBound) {
    return lowerBound;
  } else {
    return num;
  };
}

Quantity difference(Quantity num1, Quantity num2) {
  return abs(num1 - num2);
}

Number accumulatedXp(Quantity lvl, Quantity xp) {
  auto result = (std::pow(lvl, 2) + lvl) / 2 + xp;
  return result;
}

} // namespace gamemath

ItemEffect operator+(const ItemEffect &addend1, const ItemEffect &addend2) {
  ItemEffect result{static_cast<Quantity>(addend1.atk + addend2.atk), static_cast<Quantity>(addend1.def + addend2.def),
                    static_cast<Quantity>(addend1.spd + addend2.spd), static_cast<Quantity>(addend1.hp + addend2.hp)};
  return result;
}

ItemEffect operator-(const ItemEffect &effect, const ItemEffect &subtraction) {
  ItemEffect result{
      gamemath::clamp_sub(effect.atk, subtraction.atk, 0), gamemath::clamp_sub(effect.def, subtraction.def, 0),
      gamemath::clamp_sub(effect.spd, subtraction.spd, 0), gamemath::clamp_sub(effect.hp, subtraction.hp, 0)};
  return result;
}

Stats operator+(const Stats &base, const ItemEffect &temp) {
  Stats result{
      {static_cast<Quantity>(base.atk + temp.atk), static_cast<Quantity>(base.def + temp.def),
       static_cast<Quantity>(base.spd + temp.spd), static_cast<Quantity>(base.hp + temp.hp)},
      base.mhp,
      base.cst,
      base.lvl,
      base.xp,
      base.cash,
  };
  return result;
}