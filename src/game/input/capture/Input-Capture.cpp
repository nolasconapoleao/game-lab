//
// Created by nolasco on 02/06/20.
//

#include "Input-Capture.h"

#include <iostream>

namespace controller::input {

constexpr char cInvalidCharInput{' '};
constexpr int cInvalidNumInput{std::numeric_limits<int>::max()};

bool isInputValid(const char input, const std::string &options) {
  return options.find(input) != std::string::npos;
}

std::string sentence(bool flushFirst) {
  if (flushFirst) {
    std::cin.ignore();
  }
  std::string readFromConsole;
  std::getline(std::cin, readFromConsole);
  return readFromConsole;
}

char alphanum(const std::string &options) {
  char input{cInvalidCharInput};

  do {
    std::cin >> input;
    input = static_cast<char>(tolower(input));
  } while (!isInputValid(input, options));

  return input;
}

Quantity numeric(const Quantity upperBound) {
  int input{cInvalidNumInput};

  do {
    std::cout << "\t";
    std::cin >> input;
  } while (input < 1 || input > upperBound);
  Quantity result = input;
  return result;
}

} // namespace controller::input
