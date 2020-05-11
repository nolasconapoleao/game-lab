//
// Created by nolasco on 09/05/20.
//

#include "Game.h"

#include <iostream>

Game::Game() : lastKeyPressed(0) {
  initGame();
  paint();
}

Game::~Game() {
  std::cout << "=========================" << std::endl;
  std::cout << "=========================" << std::endl;
  std::cout << "End game!" << std::endl;
}

void Game::updateGame() {
  updatePlayer();
  updateNonPlayableCharacters();
}

void Game::initGame() {
  std::cout << "Begin game!" << std::endl;
  std::cout << "=========================" << std::endl;
  std::cout << "=========================" << std::endl;
  std::cout << "Enemy said: " << enemy.sayHi() << std::endl;
}

void Game::readInput() {
  uint8_t input;
  do {
    std::cin >> input;
  } while (lastKeyPressed < 49 && lastKeyPressed > 52);
  lastKeyPressed = input - '0';
}

void Game::paint() {
  paintRoomDescription();
  paintHUD();
  paintOptions();
}

bool Game::isOver() {
  if (enemy.isDead())
    std::cout << "Enemy said: " << enemy.sayBye() << std::endl;
  return (4 == lastKeyPressed) || player.isDead() || enemy.isDead();
}

void Game::updatePlayer() { player.receiveAttack(enemy.attackPoints); }

void Game::updateNonPlayableCharacters() { enemy.receiveAttack(player.attackPoints); }

void Game::updateEntities() {}

void Game::loop() {
  readInput();
  updateGame();
  paint();
}

void Game::paintRoomDescription() {
  std::cout << "\033[2J\033[1;1H";
  std::cout << "Enemy HP: " << enemy.maxHealthPoints << "/" << enemy.currentHealthPoints << std::endl;
}

void Game::paintHUD() {
  std::cout << "Player HP: " << player.maxHealthPoints << "/" << player.currentHealthPoints << std::endl;
  std::cout << "=========================" << std::endl;
}

void Game::paintOptions() {
  std::cout << "1: Attack" << std::endl;
  std::cout << "2: Atack again." << std::endl;
  std::cout << "3: Atack even more!" << std::endl;
  std::cout << "4: Exit" << std::endl;
}
