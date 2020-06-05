//
// Created by nolasco on 02/06/20.
//

#include "Controller.h"

#include <iostream>

#include "Options.h"

namespace controller {

inline const bool isInputValid(const char input, const uint8_t numberOfOptions) {
  if (input > '0' && input <= (numberOfOptions + '0')) {
    return true;
  }

  return (menuOption == input || closeOption == input);
}

const std::string readSentence() {
  std::string readFromConsole;
  std::getline( std::cin, readFromConsole);
  return readFromConsole;
}

const char readAlphaNumeric(const uint8_t numberOfOptions) {
  char input;

  do {
    std::cin >> input;
    input = tolower(input);
  } while (!isInputValid(input, numberOfOptions));

  return input;
}

} // namespace controller
