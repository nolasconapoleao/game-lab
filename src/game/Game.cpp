//
// Created by nolasco on 09/05/20.
//

#include <iostream>

#include "Game.h"

Game::Game() : lastKeyPressed(0) {
  initGame();
  paint();
}

Game::~Game() {
  std::cout << "=========================" << std::endl;
  std::cout << "=========================" << std::endl;
  std::cout << "End game!" << std::endl;
}

void Game::updateGame() {}

void Game::initGame() {
  std::cout << "Begin game!" << std::endl;
  std::cout << "=========================" << std::endl;
  std::cout << "=========================" << std::endl;
}

void Game::readInput() {
  uint8_t input;
  do {
    std::cin >> input;
  } while (lastKeyPressed < 49 && lastKeyPressed > 52);
  lastKeyPressed = input - '0';
}

void Game::paint() {
  std::cout << "\033[2J\033[1;1H";
  std::cout << "Room description" << std::endl;
  std::cout << "=========================" << std::endl;
  std::cout << "1: Option 1" << std::endl;
  std::cout << "2: Option 2" << std::endl;
  std::cout << "3: Option 3" << std::endl;
  std::cout << "4: Exit" << std::endl;
}

bool Game::isOver() { return 4 == lastKeyPressed; }

void Game::updatePlayer() {}

void Game::updateNonPlayableCharacters() {}

void Game::updateEntities() {}

void Game::loop() {
  readInput();
  updateGame();
  paint();
}
