//
// Created by nolasco on 02/06/20.
//

#include "Game.h"

#include <iostream>

#include "controller/Controller.h"

namespace model {

Game::Game() : mTerminateGame(false) {
  init();
}

const bool Game::isOver() {
  return mTerminateGame;
}

void Game::loop() {
  std::cout << "Enter a value between 1 and 5, or a base option (x,m):";

  const auto alphaNum = controller::Controller::readAlphaNumeric(5);
  if ('x' == alphaNum) {
    mTerminateGame = true;
  }
}

void Game::init() {
}

} // namespace model
