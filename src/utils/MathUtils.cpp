//
// Created by nolasco on 14/05/20.
//

#include "MathUtils.h"

#include <cstdlib>
#include <time.h>

uint MathUtils::clamp_sub(uint minuend, uint subtrahend, uint lowerBound) {
  if (minuend >= (subtrahend + lowerBound)) {
    return (minuend - subtrahend);
  } else {
    return lowerBound;
  };
}

uint MathUtils::clamp_add(uint augend, uint addend, uint upperBound) {
  if ((augend + addend) > upperBound) {
    return upperBound;
  } else {
    return (augend + addend);
  };
}

uint MathUtils::clamp(uint num, uint lowerBound, uint upperBound) {
  if (num > upperBound) {
    return upperBound;
  } else if (num < lowerBound) {
    return lowerBound;
  } else {
    return num;
  };
}

uint MathUtils::random(uint lowerBound, uint upperBound) {
  srand(time(NULL));
  return rand() % upperBound + lowerBound;
  ;
}
