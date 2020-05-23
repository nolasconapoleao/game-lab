//
// Created by nolasco on 09/05/20.
//

#include "Game.h"

#include <iostream>
#include <magic_enum.hpp>

#include "common/InteractUtils.h"
#include "config/cmakeconfig.h"
#include "generators/Generators.h"
#include "utils/PrintUtils.h"

Game::Game() : lastInput(0) {
  std::cout << "Begin game!" << std::endl;
  std::cout << sepatator << std::endl;
  std::cout << sepatator << std::endl;
}

Game::~Game() {
  std::cout << std::endl;
  std::cout << sepatator << std::endl;
  std::cout << sepatator << std::endl;
  std::cout << "Game ended!" << std::endl;
}

void Game::initGame() {
  gameState = GameState::Menu;
  world = generator::createWorld(1);
}

void Game::loop() {
  updateOptions();
  paintScreen();
  lastInput = input.readInput(optionList.numOptions());
  handleInput();
  updateGameState();
}

void Game::closeGame() {
}

bool Game::isGameOver() {
  if (world.player.isDead()) {
    std::cout << std::endl;
    std::cout << "Player said: " << world.player.sayBye << std::endl;
  } else if ('e' == lastInput) {
    std::cout << "Game terminated by user." << std::endl;
  }
  return ('e' == lastInput || world.player.isDead());
}

void Game::updateGameState() {
  switch (gameState) {
    case GameState::Menu:
      if ('b' != lastInput && 'e' != lastInput) {
        gameState = magic_enum::enum_cast<GameState>(optionList.options[lastInput - 1].second).value();
      }
      break;

    case GameState::Attack:
      [[fallthrough]];
    case GameState::Inventory:
      updatePlayer();
      gameState = GameState::Menu;
      break;

    case GameState::Walk:
      [[fallthrough]];
    case GameState::Pickup:
      [[fallthrough]];
    case GameState::Shop:
      gameState = GameState::Menu;
      break;

    case GameState::Talk:
      // Talking does not advance the round
      break;
  }
}

void Game::updatePlayer() {
  for (const auto npc : world.rooms[world.currentRoom].npcs) {
    if (!npc.isDead() && Diplomacy::hostile == npc.relation) {
      world.player.receiveAttack(npc.properties.attack - npc.properties.defense);
    }
  }
}

void Game::paintScreen() {
  clearScreen();
  paintConvos();
  std::cout << sepatator << std::endl;
  paintRoom();
  paintHUD();
  std::cout << sepatator2 << std::endl;
  paintOptions();
  std::cout << "What do you wanna do? ";
}

void Game::clearScreen() {
#ifdef COMPILE_FOR_NON_UNIX
  std::system("cls");
#else
  std::system("clear");
#endif
};

void Game::paintConvos() {
  for (const auto &talk : convos) {
    std::cout << talk;
  }
  convos.clear();
}

void Game::paintHUD() {
  std::cout << world.player << std::endl;
}

void Game::paintRoom() {
  std::cout << "You are at: " << world.rooms[world.currentRoom];
}

void Game::paintOptions() {
  std::cout << optionList;
}

void Game::handleInput() {
  if ('b' == lastInput || 'e' == lastInput) {
    gameState = GameState::Menu;
  }

  switch (gameState) {
    case GameState::Menu:
      break;

    case GameState::Talk: {
      const auto npc = world.rooms[world.currentRoom].npcs[lastInput - 1];
      std::ostringstream oss;
      oss << npc.name << " said: " << (npc.isDead() ? npc.sayBye : npc.sayHi) << std::endl;
      convos.emplace_back(oss.str());
      break;
    }

    case GameState::Attack:
      world.rooms[world.currentRoom].npcs[lastInput - 1].receiveAttack(world.player.properties.attack
                                                                       - world.player.properties.defense);
      break;

    case GameState::Inventory: {
      {
        const auto item = world.player.inventory.getItem(lastInput);
        entityUseItem(world.player, item);
        world.player.inventory.useItem(lastInput);
      }
      break;
    }

    case GameState::Pickup: {
      {
        exchangeItem(world.rooms[world.currentRoom].inventory, world.player.inventory, lastInput);
      }
      break;
    }

    case GameState::Walk:
      world.goToNextRoom(lastInput - 1);
      break;

    case GameState::Shop:
      const auto item = world.player.inventory.getItem(lastInput);
      exchangeItem(world.rooms[world.currentRoom].inventory, world.player.inventory, lastInput);
      world.player.pay(item.price);
      break;
  }
}

void Game::updateOptions() {
  optionList.clearOptions();

  switch (gameState) {
    case GameState::Menu:
      if (world.isAnyNpcAliveInThisRoom()) {
        optionList.addOption(magic_enum::enum_name(GameState::Attack).data());
      }
      optionList.addOption(magic_enum::enum_name(GameState::Talk).data());
      optionList.addOption(magic_enum::enum_name(GameState::Inventory).data());
      if (!world.isAnyNpcHostileInThisRoom()) {
        optionList.addOption(magic_enum::enum_name(GameState::Pickup).data());
        optionList.addOption(magic_enum::enum_name(GameState::Walk).data());
      }

      if (world.rooms[world.currentRoom].hasNpc("Shopkeeper")) {
        optionList.addOption(magic_enum::enum_name(GameState::Shop).data());
      }
      break;

    case GameState::Talk: {
      for (const auto &npc : world.rooms[world.currentRoom].npcs) {
        std::ostringstream oss;
        oss << "Speak to " << npc.name;
        optionList.addOption(oss.str());
      }
      break;
    }

    case GameState::Attack: {
      for (const auto &npc : world.rooms[world.currentRoom].npcs) {
        std::ostringstream oss;
        oss << "Attack " << npc.name;
        optionList.addOption(oss.str());
      }
      break;
    }

    case GameState::Inventory: {
      std::ostringstream oss;
      oss << world.player.inventory;
      std::istringstream ss(oss.str());
      std::string option;

      while (std::getline(ss, option, '\n')) {
        optionList.addOption(option);
      }
      break;
    }

    case GameState::Walk: {
      for (const auto &room : world.rooms[world.currentRoom].adjacentRooms) {
        std::ostringstream oss;
        oss << "Go to " << world.rooms[room].name;
        optionList.addOption(oss.str());
      }
      break;
    }

    case GameState::Pickup: {
      std::ostringstream oss;
      oss << world.rooms[world.currentRoom].inventory;
      std::istringstream ss(oss.str());
      std::string option;

      while (std::getline(ss, option, '\n')) {
        optionList.addOption(option);
      }
      break;
    }

    case GameState::Shop: {
      for (uint8_t it = 1; it <= world.rooms[world.currentRoom].inventory.totalItems(); it++) {
        auto item = world.rooms[world.currentRoom].inventory.getItem(it);
        std::ostringstream oss;
        oss << "Buy " << item.name << "(" << item.price << ")";
        optionList.addOption(oss.str());
      }
      break;
    }
  }
  optionList.addFooter();
}
