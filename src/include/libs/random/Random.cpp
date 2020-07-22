//
// Created by nolasco on 05/06/20.
//

#include "Random.h"

#include <chrono>
#include <iostream>
#include <random>

namespace Random {

Quantity rand(Quantity lowerBound, Quantity upperBound) {

  if (lowerBound > upperBound) {
    std::cerr << "Lower bound has to be smaller than upper bound.\n";
    throw std::runtime_error("Invalid bounds for random generation");
  }

  auto t = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::mt19937 generator;

  generator.seed(static_cast<unsigned int>(t));
  std::uniform_int_distribution<Quantity> distribution(lowerBound, upperBound);

  return distribution(generator);
}

Quantity rand_range(Quantity number, Quantity range) {
  Quantity lower = 0;
  Quantity upper = std::numeric_limits<Quantity>::max();
  if (number > range) {
    lower = number - range;
  }
  if (number + range < std::numeric_limits<Quantity>::max()) {
    upper = number + range;
  }
  return rand(lower, upper);
}

std::unordered_set<Quantity> multipleNonRepeated(Quantity quantity, Quantity lowerBound, Quantity upperBound) {

  if (lowerBound > upperBound) {
    std::cerr << "Lower bound has to be smaller than upper bound.\n";
    throw std::runtime_error("Invalid bounds for random generation");
  }

  Quantity range = upperBound - lowerBound;
  if (range < quantity) {
    std::cerr << "Cannot generate n distinct numbers from a pool with size less than n.\n";
    throw std::runtime_error("Invalid random generation");
  }

  auto t = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::mt19937 generator;

  generator.seed(static_cast<unsigned int>(t));
  std::uniform_int_distribution<Quantity> distribution(lowerBound, upperBound);

  std::unordered_set<Quantity> generated;
  while (generated.size() < quantity) {
    generated.insert(distribution(generator));
  }

  return generated;
}

} // namespace Random
