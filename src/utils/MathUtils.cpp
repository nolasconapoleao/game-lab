//
// Created by nolasco on 14/05/20.
//

#include "MathUtils.h"

#include <chrono>
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
  auto t = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::mt19937 e;

  e.seed(static_cast<unsigned int>(t)); //Seed engine with timed value.
  std::uniform_int_distribution<uint8_t> dis(lowerBound, upperBound);

  return dis(e);
}
