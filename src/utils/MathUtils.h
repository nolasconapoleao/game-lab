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
uint8_t clamp_sub(uint8_t minuend, uint8_t subtrahend, uint8_t lowerBound);

/**
 * @brief Ceils the result of an addition.
 * @param augend first addition operand
 * @param addend first addition operand
 * @param upperBound max allowed for result
 * @return clamped result of an addition
 */
uint8_t clamp_add(uint8_t augend, uint8_t addend, uint8_t upperBound);

/**
 * @brief Clamps the result of a sum.
 * @param num number to clamp
 * @param lowerBound min allowed for num
 * @param upperBound max allowed for num
 * @return clamped number
 */
uint8_t clamp(uint8_t num, uint8_t lowerBound, uint8_t upperBound);

/**
 * @brief Generates a random number between lowerBound and upperBound.
 * @param lowerBound for generation
 * @param upperBound for generation
 * @return random number
 */
[[nodiscard]] uint8_t random(uint8_t lowerBound, uint8_t upperBound);

}; // namespace MathUtils
