//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <string>
#include <vector>

#include "datatypes/GameTypes.h"

namespace controller::input {

[[nodiscard]] const std::string sentence(bool flushFirst = false);

/**
 *  Reads input from the console, reading must exist in the allowed options
 * @param options allowed options
 * @return consoleInput
 */
[[nodiscard]] const char alphanum(const std::string options);

[[nodiscard]] const Quantity numeric(const Quantity upperBound);

} // namespace controller::input
