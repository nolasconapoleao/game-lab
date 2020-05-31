//
// Created by nolasco on 17/05/20.
//

#pragma once

#include <cstdint>

class Input {
public:
  /**
   * @brief Reads input from console until a valid input is received and then converts it to a usable index.
   * @param numOptions maximum allowed value for input
   * @return char with the input given by player
   */
  const uint8_t readInput(const uint8_t numOptions);

private:
  const bool isValidLetter(const char input);
  const bool isValidNumber(const char input, const uint8_t options);
  uint8_t parseInput(const uint8_t input);
};
