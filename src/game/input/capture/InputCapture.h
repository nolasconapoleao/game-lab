//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <string>
#include <vector>

#include "datatypes/GameTypes.h"

namespace controller::input {

/**
 * @brief Reads sentence from the console.
 * @param flushFirst if true, flushes the previous input
 * @return Sentence read from console
 */
[[nodiscard]] std::string sentence(bool flushFirst = false);

/**
 * @brief Reads alphanumerical input from the console, input must exist in the allowed options.
 * @param options allowed
 * @return Alphanumerical character read from console
 */
[[nodiscard]] char alphanum(const std::string &options);

/**
 * @brief Reads numerical input from the console, input must be smaller than the upper bound.
 * @param upperBound maximum allowed input
 * @return Numerical character read from console
 */
[[nodiscard]] Quantity numeric(Quantity upperBound);

} // namespace controller::input
