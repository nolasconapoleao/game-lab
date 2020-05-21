//
// Created by nolasco on 14/05/20.
//

#pragma once

#include <zconf.h>

namespace MathUtils {

/**
 * @brief Floors the result of a subtraction.
 * @param minuend first subtraction operand
 * @param subtrahend second subtraction operand
 * @param lowerBound min allowed for result
 * @return clamped result for subtraction
 */
uint clamp_sub(uint minuend, uint subtrahend, uint lowerBound);

/**
 * @brief Ceils the result of an addition.
 * @param augend first addition operand
 * @param addend first addition operand
 * @param upperBound max allowed for result
 * @return clamped result of an addition
 */
uint clamp_add(uint augend, uint addend, uint upperBound);

/**
 * @brief Clamps the result of a sum.
 * @param num number to clamp
 * @param lowerBound min allowed for num
 * @param upperBound max allowed for num
 * @return clamped number
 */
uint clamp(uint num, uint lowerBound, uint upperBound);

/**
 * @brief Generates a random number between lowerBound and upperBound.
 * @param lowerBound for generation
 * @param upperBound for generation
 * @return random number
 */
[[nodiscard]] uint random(uint lowerBound, uint upperBound);

}; // namespace MathUtils
