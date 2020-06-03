//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <string>
#include <vector>

namespace controller {

class Controller {
public:
  [[nodiscard]] static const std::string readSentence();
  [[nodiscard]] static const char readAlphaNumeric(const uint8_t numberOfOptions);

private:
  static const bool isInputValid(const char input, const uint8_t numberOfOptions);
};

} // namespace controller
