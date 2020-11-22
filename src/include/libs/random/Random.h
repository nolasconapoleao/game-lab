//
// Created by nolasco on 05/06/20.
//

#pragma once

#include <cstdint>
#include <unordered_set>
#include <vector>

#include "datatypes/GameTypes.h"

namespace Random {

/**
 * @brief Generates a random number between lowerBound and upperBound.
 * @param lowerBound for generation
 * @param upperBound for generation
 * @return random number
 */
[[nodiscard]] Quantity rand(Quantity lowerBound = std::numeric_limits<Quantity>::min(),
                            Quantity upperBound = std::numeric_limits<Quantity>::max());

/**
 * @brief Generates a random number around a number.
 * @param number for generation
 * @param range for generation
 * @return random number
 */
[[nodiscard]] Quantity rand_range(Quantity number, Quantity range);

/**
 * @brief Generates a set of non repeating number between lowerBound and upperBound.
 * @param quantity amount of generated numbers
 * @param lowerBound for generation
 * @param upperBound for generation
 * @return set of random numbers
 */
[[nodiscard]] std::unordered_set<Quantity> multipleNonRepeated(Quantity quantity, Quantity lowerBound,
                                                               Number upperBound);

/**
 * @brief Generates a random number from the vector of given options.
 * @param valuePool for generation
 * @return random vector element
 */
template <class T>[[nodiscard]] T fromVec(const std::vector<T> &valuePool) {

  const auto upperBound = valuePool.size();
  const auto index = rand(0, upperBound - 1);

  return valuePool[index];
}

}; // namespace Random
