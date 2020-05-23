//
// Created by nolasco on 17/05/20.
//

#include "Input.h"

#include <iostream>

uint8_t Input::readInput(uint8_t numOptions) {
  uint8_t input;
  do {
    std::cin >> input;
  } while ((input < '0' || input > ('1' + numOptions)) && input != 'e');

  if (input != 'e') {
    return (input - '0');
  }
  return input;
}