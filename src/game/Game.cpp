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
  std::cout << "Player said: " << player.sayHi() << std::endl;
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
  paintRoomDescription();
  paintHUD();
  paintOptions();
}

bool Game::isOver() {
  if (player.isDead()) {
    std::cout << "Player said: " << player.sayBye() << std::endl;
  } else if (4 == lastKeyPressed) {
    std::cout << "Game terminated by user." << std::endl;
  }
  return (4 == lastKeyPressed || player.isDead());
}

void Game::updatePlayer() {
  for (const auto &npc : saloon.npcs) {
    if (!npc->isDead()) {
      player.receiveAttack(npc->attackPoints);
    }
  }
}

void Game::updateNonPlayableCharacters() { saloon.npcs.at(lastKeyPressed - 1)->receiveAttack(player.attackPoints); }

void Game::updateEntities() {}

void Game::loop() {
  readInput();
  updateGame();
  paint();
}

void Game::paintRoomDescription() {
  std::cout << "\033[2J\033[1;1H";
  for (const auto &npc : saloon.npcs) {
    std::cout << "Enemy " << *npc.get();
  }
}

void Game::paintHUD() {
  std::cout << player;
  std::cout << "=========================" << std::endl;
}

void Game::paintOptions() {
  std::cout << "1: Attack first bot" << std::endl;
  std::cout << "2: Atack second bot." << std::endl;
  std::cout << "3: Atack even more!" << std::endl;
  std::cout << "4: Exit" << std::endl;
}
