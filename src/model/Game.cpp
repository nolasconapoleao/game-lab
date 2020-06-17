//
// Created by nolasco on 02/06/20.
//

#include "Game.h"

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
  // FIXME: This generation should be handled in the creation of the world
  factory.createCharacter(CharacterType::ENEMY);
  factory.createCharacter(CharacterType::ENEMY);
  factory.createCharacter(CharacterType::ENEMY);
  factory.createCharacter(CharacterType::PLAYER);
}

void Game::shutdown() {
  mPrinter.directPrint("Game over.");
}

} // namespace model
