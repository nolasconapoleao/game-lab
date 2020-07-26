//
// Created by nolasco on 02/06/20.
//

#include "Input.h"

#include <iostream>

namespace controller::input {

const bool isInputValid(const char input, const std::string options) {
  return options.find(input) != std::string::npos;
}

const std::string sentence(bool flushFirst) {
  if (flushFirst) {
    std::cin.ignore();
  }
  std::string readFromConsole;
  std::getline(std::cin, readFromConsole);
  return readFromConsole;
}

const char alphanum(const std::string options) {
  char input;

  do {
    std::cin >> input;
    input = tolower(input);
  } while (!isInputValid(input, options));

  return input;
}

const Quantity numeric(const Quantity upperBound) {
  int input;

  do {
    std::cout << "\t";
    std::cin >> input;
  } while (input < 1 || input > upperBound);
  Quantity result = input;
  return result;
}

} // namespace controller::input
