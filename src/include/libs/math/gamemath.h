//
// Created by nolasco on 30/06/20.
//

#pragma once

#include "datatypes/GameTypes.h"
#include "datatypes/entity/ItemEffect.h"
#include "datatypes/entity/Stats.h"

// TODO: Remove gamemath namespace
namespace gamemath {

/**
 * @brief Floors the result of a subtraction.
 * @param minuend first subtraction operand
 * @param subtrahend second subtraction operand
 * @param lowerBound min allowed for result
 * @return clamped result for subtraction
 */
Quantity cSub(Quantity minuend, Quantity subtrahend, Quantity lowerBound = std::numeric_limits<Quantity>::min());

/**
 * @brief Ceils the result of an addition.
 * @param augend first addition operand
 * @param addend first addition operand
 * @param upperBound max allowed for result
 * @return clamped result of an addition
 */
Quantity cAdd(Quantity augend, Quantity addend, Quantity upperBound = std::numeric_limits<Quantity>::max());

/**
 * @brief Ceils the result of a multiplication.
 * @param num first addition operand
 * @param mult first addition operand
 * @param upperBound max allowed for result
 * @return clamped result of a multiplication
 */
Quantity cMult(Quantity num, Quantity mult, Quantity upperBound = std::numeric_limits<Quantity>::max());

/**
 * @brief Returns distance between two scalars.
 * @param num1 first scalar
 * @param num2 second scalar
 * @return absolute value of diff.
 */
Quantity diff(Quantity num1, Quantity num2);

ItemEffect operator+(const ItemEffect &a1, ItemEffect &a2);
ItemEffect operator-(const ItemEffect &effect, ItemEffect &subtraction);
Stats operator+(const Stats &base, const ItemEffect &temp);
Stats operator*(Stats &base, Quantity multiplier);

/**
 * @brief Given level and experience, calculate accumulated experience.
 * @param lvl current level
 * @param xp current experience
 * @return accumulated experience
 */
Number accumulatedXp(Quantity lvl, Quantity xp);

}; // namespace gamemath
