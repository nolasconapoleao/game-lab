//
// Created by nolasco on 30/06/20.
//

#include "gamemath.h"

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

} // namespace gamemath