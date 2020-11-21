//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <string>
#include <vector>

#include "datatypes/GameTypes.h"

namespace controller::input {

[[nodiscard]] std::string sentence(bool flushFirst = false);

/**
 *  Reads input from the console, reading must exist in the allowed options
 * @param options allowed options
 * @return consoleInput
 */
[[nodiscard]] char alphanum(const std::string &options);

[[nodiscard]] Quantity numeric(Quantity upperBound);

} // namespace controller::input
