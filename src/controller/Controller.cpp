//
// Created by nolasco on 02/06/20.
//

#include "Controller.h"

#include <iostream>

#include "Options.h"

namespace controller {

const bool isInputValid(const char input, const std::string options) {
  return options.find(input) != std::string::npos;
}

const std::string readSentence() {
  std::string readFromConsole;
  // TODO: [nn] ignore newline from previous input
  std::getline(std::cin, readFromConsole);
  return readFromConsole;
}

const char readAlphaNum(const std::string options) {
  char input;

  do {
    std::cin >> input;
    input = tolower(input);
  } while (!isInputValid(input, options));

  return input;
}

} // namespace controller
