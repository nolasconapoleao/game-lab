//
// Created by nolasco on 09/05/20.
//

#include "Game.h"

#include <iostream>

#include "common/InteractUtil.h"

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
  interpretInput();
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
  } else if (5 == lastKeyPressed) {
    std::cout << "Game terminated by user." << std::endl;
  }
  return (5 == lastKeyPressed || player.isDead());
}

void Game::updatePlayer() {
  for (const auto &npc : world.currentRoom->npcs) {
    if (!npc->isDead()) {
      player.receiveAttack(npc->attackPoints);
    }
  }
}

void Game::interpretInput() {
  if (world.isAnyNpcAliveInThisRoom()) {
    if (lastKeyPressed <= 3) {
      world.currentRoom->npcs.at(lastKeyPressed - 1)->receiveAttack(player.attackPoints);
    } else if (lastKeyPressed == 4) {
      playerUsePotion(player, potion);
    }
  } else {
    if (lastKeyPressed <= 2) {
      world.goToNextRoom(lastKeyPressed - 1);
    } else if (lastKeyPressed == 4) {
      playerUsePotion(player, potion);
    }
  }
}

void Game::updateEntities() {
}

void Game::loop() {
  readInput();
  updateGame();
  paint();
}

void Game::paintRoomDescription() {
  std::cout << "\033[2J\033[1;1H";
  for (const auto &npc : world.currentRoom->npcs) {
    std::cout << "Enemy " << *npc.get();
  }
}

void Game::paintHUD() {
  std::cout << player;
  std::cout << "=========================" << std::endl;
}

void Game::paintOptions() {
  if (world.isAnyNpcAliveInThisRoom()) {
    std::cout << "1: Attack first bot" << std::endl;
    std::cout << "2: Attack second bot." << std::endl;
    std::cout << "3: Attack third bot." << std::endl;
    std::cout << "4: Use potion!" << std::endl;
    std::cout << "5: Exit" << std::endl;
  } else {
    std::cout << "1: Go right" << std::endl;
    std::cout << "2: Go left" << std::endl;
    std::cout << "3: Use potion!" << std::endl;
    std::cout << "4: Use mega potion." << std::endl;
    std::cout << "5: Exit" << std::endl;
  }
}
