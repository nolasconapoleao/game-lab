//
// Created by nolasco on 02/06/20.
//

#include "Game.h"

#include "controller/Controller.h"

namespace model {

Game::Game() : mTerminateGame(false) {
  init();
}

Game::~Game() {
  shutdown();
}

const bool Game::isOver() {
  return gameEngine.isTerminated();
}

void Game::loop() {
  gameEngine.whatsUp();
}

void Game::init() {
}

void Game::shutdown() {
  mPrinter.directPrint("Game over.");
}

} // namespace model
