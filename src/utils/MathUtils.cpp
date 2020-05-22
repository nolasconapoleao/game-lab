//
// Created by nolasco on 14/05/20.
//

#include "MathUtils.h"

#include <random>

uint8_t MathUtils::clamp_sub(uint8_t minuend, uint8_t subtrahend, uint8_t lowerBound) {
  if (minuend >= (subtrahend + lowerBound)) {
    return (minuend - subtrahend);
  } else {
    return lowerBound;
  };
}

uint8_t MathUtils::clamp_add(uint8_t augend, uint8_t addend, uint8_t upperBound) {
  if ((augend + addend) > upperBound) {
    return upperBound;
  } else {
    return (augend + addend);
  };
}

uint8_t MathUtils::clamp(uint8_t num, uint8_t lowerBound, uint8_t upperBound) {
  if (num > upperBound) {
    return upperBound;
  } else if (num < lowerBound) {
    return lowerBound;
  } else {
    return num;
  };
}

uint8_t MathUtils::random(uint8_t lowerBound, uint8_t upperBound) {
  std::random_device rd;

  // Initialize Mersenne Twister pseudo-random number generator
  std::mt19937 gen(rd());

  // Generate pseudo-random numbers uniformly distributed in range (1, 100)
  std::uniform_int_distribution<> dis(lowerBound, upperBound);

  return dis(gen);
}
