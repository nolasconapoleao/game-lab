//
// Created by nolasco on 14/05/20.
//

#pragma once

#include <cstdint>

namespace MathUtils {

/**
 * @brief Floors the result of a subtraction.
 * @param minuend first subtraction operand
 * @param subtrahend second subtraction operand
 * @param lowerBound min allowed for result
 * @return clamped result for subtraction
 */
int clamp_sub(int minuend, int subtrahend, int lowerBound);

/**
 * @brief Ceils the result of an addition.
 * @param augend first addition operand
 * @param addend first addition operand
 * @param upperBound max allowed for result
 * @return clamped result of an addition
 */
int clamp_add(int augend, int addend, int upperBound);

/**
 * @brief Clamps the result of a sum.
 * @param num number to clamp
 * @param lowerBound min allowed for num
 * @param upperBound max allowed for num
 * @return clamped number
 */
int clamp(int num, int lowerBound, int upperBound);

/**
 * @brief Generates a random number between lowerBound and upperBound.
 * @param lowerBound for generation
 * @param upperBound for generation
 * @return random number
 */
[[nodiscard]] int random(int lowerBound, int upperBound);

}; // namespace MathUtils
