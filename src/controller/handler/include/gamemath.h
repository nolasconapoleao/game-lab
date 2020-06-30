//
// Created by nolasco on 30/06/20.
//

#pragma once

#include "common/GameTypes.h"

namespace gamemath {

/**
 * @brief Floors the result of a subtraction.
 * @param minuend first subtraction operand
 * @param subtrahend second subtraction operand
 * @param lowerBound min allowed for result
 * @return clamped result for subtraction
 */
Quantity clamp_sub(Quantity minuend, Quantity subtrahend, Quantity lowerBound);

/**
 * @brief Ceils the result of an addition.
 * @param augend first addition operand
 * @param addend first addition operand
 * @param upperBound max allowed for result
 * @return clamped result of an addition
 */
Quantity clamp_add(Quantity augend, Quantity addend, Quantity upperBound);

/**
 * @brief Clamps the result of a sum.
 * @param num number to clamp
 * @param lowerBound min allowed for num
 * @param upperBound max allowed for num
 * @return clamped number
 */
Quantity clamp(Quantity num, Quantity lowerBound, Quantity upperBound);

Quantity difference(Quantity num1, Quantity num2);

}; // namespace gamemath
