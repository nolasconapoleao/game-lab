//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <string>
#include <vector>

namespace controller {

  [[nodiscard]] const std::string readSentence();
  [[nodiscard]] const char readAlphaNumeric(const uint8_t numberOfOptions);

} // namespace controller
