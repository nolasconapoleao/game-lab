//
// Created by nolasco on 21/06/20.
//

#pragma once

#include <iostream>
namespace Input {

void signal_callback_handler(int signum) {
  std::cout << std::endl << "AH ye killed me you bastard! Caught signal: " << signum << std::endl;
  exit(signum);
}

}; // namespace Input
