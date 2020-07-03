//
// Created by nolasco on 05/06/20.
//

#pragma once

#include <cstdint>
#include <unordered_set>
#include <vector>

namespace Random {
using Number = uint8_t;

/**
 * @brief Generates a random number between lowerBound and upperBound.
 * @param lowerBound for generation
 * @param upperBound for generation
 * @return random number
 */
[[nodiscard]] Number fromTo(Number lowerBound, Number upperBound);

/**
 * @brief Generates a set of non repeating number between lowerBound and upperBound.
 * @param lowerBound for generation
 * @param upperBound for generation
 * @return set of random numbers
 */
[[nodiscard]] std::unordered_set<Number> multipleNonRepeated(Number quantity, Number lowerBound, Number upperBound);

/**
 * @brief Generates a random number from the vector of given options.
 * @param valuePool for generation
 * @return random vector element
 */
template <class T>[[nodiscard]] T fromVec(const std::vector<T> &valuePool) {

  const auto upperBound = valuePool.size();
  const auto index = fromTo(0, upperBound - 1);

  return valuePool[index];
}

}; // namespace Random
