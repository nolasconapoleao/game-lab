//
// Created by nolasco on 17/05/20.
//

#include "Input.h"

#include <iostream>

const uint8_t Input::readInput(uint8_t numOptions) {
  char input;
  do {
    std::cin >> input;
  } while (!isValidLetter(input) && !isValidNumber(input, numOptions));

  return parseInput(input);
}

const bool Input::isValidLetter(const char input) {
  switch (input) {
    case 'b':
      [[fallthrough]];
    case 'e':
      return true;
    default:
      return false;
  }
}

const bool Input::isValidNumber(const char input, const uint8_t options) {
  return (input > '0' && input < ('1' + options));
}

uint8_t Input::parseInput(uint8_t input) {
  if (isValidLetter(input)) {
    return input;
  } else {
    return (input - '0');
  }
}
