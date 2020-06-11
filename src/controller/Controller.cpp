//
// Created by nolasco on 02/06/20.
//

#include "Controller.h"

#include <iostream>

#include "Options.h"

namespace controller {

inline const bool isInputValid(const char input, const std::string options) {

  if (options.find(input) != std::string::npos) {
    return true;
  }

  return (closeOption == input);
}

const std::string readSentence() {
  std::string readFromConsole;
  // TODO: [nn] ignore newline form previous input
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
