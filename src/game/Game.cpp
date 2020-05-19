//
// Created by nolasco on 09/05/20.
//

#include "Game.h"

#include <iostream>
#include <sstream>

#include "common/InteractUtils.h"
#include "items/Potion.h"
#include "items/Sword.h"

Game::Game() : userInput(0) {
  std::cout << "Begin game!" << std::endl;
  std::cout << "=====================================================================" << std::endl;
  std::cout << "=====================================================================" << std::endl;
}

Game::~Game() {
  std::cout << std::endl;
  std::cout << "=====================================================================" << std::endl;
  std::cout << "=====================================================================" << std::endl;
  std::cout << "Game ended!" << std::endl;
}

void Game::initGame() {
  gameState = GameState::Menu;

  player.inventory.addItem(std::make_shared<BaseItem>(Potion{}), 12);
  player.inventory.addItem(std::make_shared<BaseItem>(Sword{}));

  updateOptions();
}

void Game::loop() {
  updateOptions();
  paintScreen();
  userInput = input.readInput(options.size() - 3);
  handleInput();
  updateGameState();
}

void Game::closeGame() {
}

bool Game::isGameOver() {
  if (player.isDead()) {
    std::cout << "Player said: " << player.sayBye << std::endl;
  } else if ('e' == userInput) {
    std::cout << "Game terminated by user." << std::endl;
  }
  return ('e' == userInput || player.isDead());
}

void Game::updateGameState() {
  switch (gameState) {
  case GameState::Menu:
    if (world.isAnyNpcHostileInThisRoom()) {
      if (userInput == 1) {
        gameState = GameState::Attack;
      } else if (userInput == 2) {
        gameState = GameState::Talk;
      } else if (userInput == 3) {
        gameState = GameState::Inventory;
      }
    } else {
      if (userInput == 1) {
        gameState = GameState::Walk;
      } else if (userInput == 2) {
        gameState = GameState::Pickup;
      } else if (userInput == 3) {
        gameState = GameState::Inventory;
      } else if (userInput == 4) {
        gameState = GameState::Shop;
      }
    }
    break;
  case GameState::Talk:
    // Talking does not advance the round
    break;
  case GameState::Attack:
    gameState = GameState::Menu;
    updatePlayer();
    break;
  case GameState::Inventory:
    gameState = GameState::Menu;
    updatePlayer();
    break;
  case GameState::Walk:
    gameState = GameState::Menu;
    break;
  case GameState::Pickup:
    gameState = GameState::Menu;
    break;
  case GameState::Shop:
    gameState = GameState::Menu;
    break;
  }
}

void Game::updatePlayer() {
  for (const auto &npc : world.rooms.at(world.currentRoom)->npcs) {
    if (!npc->isDead() && CharacterRelation::hostile == npc->relation) {
      player.receiveAttack(npc->properties.attackPoints);
    }
  }
}

void Game::paintScreen() {
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "=====================================================================" << std::endl;
  paintRoom();
  paintHUD();
  std::cout << "---------------------------------------------------------------------" << std::endl;
  paintOptions();
  std::cout << "What do you wanna do? ";
}

void Game::paintHUD() {
  std::cout << player << std::endl;
}

void Game::paintRoom() {
  std::cout << "\033[2J\033[1;1H";
  std::cout << *world.rooms.at(world.currentRoom).get();
}

void Game::paintOptions() {
  for (const auto &option : options) {
    std::cout << option << std::endl;
  }
}

void Game::handleInput() {
  if (userInput == 0) {
    gameState = GameState::Menu;
  }

  switch (gameState) {
  case GameState::Menu:
    break;

  case GameState::Talk: {
    const auto npc = world.rooms.at(world.currentRoom)->npcs.at(userInput - 1);
    std::cout << npc->name << " said: " << (npc->isDead() ? npc->sayBye : npc->sayHi) << std::endl;
    break;
  }

  case GameState::Attack:
    world.rooms.at(world.currentRoom)->npcs.at(userInput - 1)->receiveAttack(player.properties.attackPoints);
    break;

  case GameState::Inventory: {
    {
      const auto item = player.inventory.getItem(userInput);
      entityUseItem(player, item);
      player.inventory.useItem(userInput);
    }
    break;
  }

  case GameState::Pickup: {
    {
      exchangeItem(world.rooms.at(world.currentRoom)->inventory, player.inventory, userInput);
    }
    break;
  }

  case GameState::Walk:
    world.goToNextRoom(userInput - 1);
    break;

  case GameState::Shop:
    const auto item = player.inventory.getItem(userInput);
    exchangeItem(world.rooms.at(world.currentRoom)->inventory, player.inventory, userInput);
    player.pay(item->price);
    break;
  }
}

void Game::updateOptions() {
  options.clear();

  switch (gameState) {
  case GameState::Menu:
    if (world.isAnyNpcHostileInThisRoom()) {
      options.emplace_back("1: Attack");
      options.emplace_back("2: Talk");
      options.emplace_back("3: Inventory");
    } else {
      options.emplace_back("1: Walk");
      options.emplace_back("2: Pickup");
      options.emplace_back("3: Inventory");
      if ("Shop" == world.rooms.at(world.currentRoom)->name) {
        options.emplace_back("4: Shop");
      }
    }
    break;

  case GameState::Talk: {
    uint it = 0;
    for (const auto &npc : world.rooms.at(world.currentRoom)->npcs) {
      it++;
      std::ostringstream oss;
      oss << "" << it << ": Speak to " << npc->name;
      options.emplace_back(oss.str());
    }
    break;
  }

  case GameState::Attack: {
    uint it = 0;
    for (const auto &npc : world.rooms.at(world.currentRoom)->npcs) {
      it++;
      std::ostringstream oss;
      oss << "" << it << ": Attack " << npc->name;
      options.emplace_back(oss.str());
    }
    break;
  }

  case GameState::Inventory: {
    std::ostringstream oss;
    oss << player.inventory;
    std::istringstream ss(oss.str());
    std::string option;

    while (std::getline(ss, option, '\n')) {
      options.emplace_back(option);
    }
    break;
  }

  case GameState::Walk: {
    uint it = 1;
    for (const auto &room : world.rooms.at(world.currentRoom)->adjacentRooms) {
      std::ostringstream oss;
      oss << "" << it << ": Go to room " << world.rooms.at(room)->name;
      options.emplace_back(oss.str());
      it++;
    }
    break;
  }

  case GameState::Pickup: {
    std::ostringstream oss;
    oss << world.rooms.at(world.currentRoom)->inventory;
    std::istringstream ss(oss.str());
    std::string option;

    while (std::getline(ss, option, '\n')) {
      options.emplace_back(option);
    }
    break;
  }

  case GameState::Shop: {

    for (uint it = 1; it <= world.rooms.at(world.currentRoom)->inventory.totalItems(); it++) {
      auto item = world.rooms.at(world.currentRoom)->inventory.getItem(it);
      std::ostringstream oss;
      oss << "" << it << ": Buy " << item->name << "(" << item->price << ")";
      options.emplace_back(oss.str());
    }
    break;
  }
  }
  options.emplace_back("0: Back");
  options.emplace_back("e: Exit");
}
