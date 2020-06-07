//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <string>
#include <vector>

namespace controller {

[[nodiscard]] const std::string readSentence();

/**
 *  Reads input from the console, reading must exist in the allowed options
 * @param options allowed options
 * @return consoleInput
 */
[[nodiscard]] const char readAlphaNum(const std::string options);

} // namespace controller
