//
// Created by nolasco on 30/06/20.
//

#pragma once

#include <model/entity/include/ItemEffect.h>

#include "common/GameTypes.h"

// TODO: Remove gamemath namespace
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

/**
 * @brief Returns distance between two scalars.
 * @param num1 first scalar
 * @param num2 second scalar
 * @return absolute value of difference.
 */
Quantity difference(Quantity num1, Quantity num2);

/**
 * @brief Given level and experience, calculate accumulated experience.
 * @param lvl current level
 * @param xp current experience
 * @return accumulated experience
 */
Number accumulatedXp(Quantity lvl, Quantity xp);

}; // namespace gamemath

ItemEffect operator+(const ItemEffect &addend1, const ItemEffect &addend2);
ItemEffect operator-(const ItemEffect &effect, const ItemEffect &subtraction);