//
// Created by nolasco on 02/06/20.
//

#include "Input.h"

#include <iostream>

namespace input {

const bool isInputValid(const char input, const std::string options) {
  return options.find(input) != std::string::npos;
}

const std::string readSentence(bool flushFirst) {
  if (flushFirst) {
    std::cin.ignore();
  }
  std::string readFromConsole;
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

} // namespace input
