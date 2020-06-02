//
// Created by nolasco on 14/05/20.
//

#include "MathUtils.h"

#include <chrono>
#include <random>

int MathUtils::clamp_sub(int minuend, int subtrahend, int lowerBound) {
  if (minuend >= (subtrahend + lowerBound)) {
    return (minuend - subtrahend);
  } else {
    return lowerBound;
  };
}

int MathUtils::clamp_add(int augend, int addend, int upperBound) {
  if ((augend + addend) > upperBound) {
    return upperBound;
  } else {
    return (augend + addend);
  };
}

int MathUtils::clamp(int num, int lowerBound, int upperBound) {
  if (num > upperBound) {
    return upperBound;
  } else if (num < lowerBound) {
    return lowerBound;
  } else {
    return num;
  };
}

int MathUtils::random(int lowerBound, int upperBound) {
  auto t = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::mt19937 e;

  e.seed(static_cast<unsigned int>(t)); //Seed engine with timed value.
  std::uniform_int_distribution<int> dis(lowerBound, upperBound);

  return dis(e);
}
