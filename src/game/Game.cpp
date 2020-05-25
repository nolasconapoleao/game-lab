//
// Created by nolasco on 09/05/20.
//

#include "Game.h"

#include <iostream>
#include <magic_enum.hpp>

#include "common/InteractUtils.h"
#include "common/Match.h"
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
        gameState = magic_enum::enum_cast<GameState>(optionList.options[lastInput].second).value();
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
  for (auto &npc : world.rooms[world.currentRoom].npcs) {
    if (!npc.isDead() && Diplomacy::hostile == npc.relation) {
      const auto result = Match::match(world.rooms[world.currentRoom], world.player, npc);
      updateConvos(result, world.player, npc);
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
  std::cout << printPlayer(world.player);
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
      const auto npc = world.rooms[world.currentRoom].npcs[lastInput];
      std::ostringstream oss;
      oss << npc.name << " said: " << (npc.isDead() ? npc.sayBye : npc.sayHi) << std::endl;
      convos.emplace_back(oss.str());
      break;
    }

    case GameState::Attack: {
      const auto result
          = Match::match(world.rooms[world.currentRoom], world.rooms[world.currentRoom].npcs[lastInput], world.player);
      updateConvos(result, world.rooms[world.currentRoom].npcs[lastInput], world.player);
      break;
    }

    case GameState::Inventory: {
      {
        const auto item = world.player.pocket.getItem(lastInput);
        entityUseItem(world.player, item);
        world.player.pocket.useItem(lastInput);
      }
      break;
    }

    case GameState::Pickup: {
      uint8_t quantity = world.rooms[world.currentRoom].floor.entries[lastInput].quantity;
      exchangeItem(world.rooms[world.currentRoom].floor, world.player.pocket, lastInput, quantity);
      break;
    }

    case GameState::Walk:
      world.goToNextRoom(lastInput);
      break;

    case GameState::Shop:
      exchangeItem(world.rooms[world.currentRoom].floor, world.player.pocket, lastInput);
      const auto item = world.rooms[world.currentRoom].floor.getItem(lastInput);
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
      for (const auto &entry : world.player.pocket.entries) {
        optionList.addOption(printPocket(entry));
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
      for (const auto &entry : world.rooms[world.currentRoom].floor.entries) {
        optionList.addOption(printFloor(entry));
      }
      break;
    }

    case GameState::Shop: {
      for (const auto &entry : world.rooms[world.currentRoom].floor.entries) {
        optionList.addOption(printShop(entry));
      }
      break;
    }
  }
  optionList.addFooter();
}

void Game::updateConvos(MatchResult result, const Character attacked, const Character attacker) {
  std::ostringstream oss;
  if (result.diplomacyUpdate) {
    oss << attacker.name << " made a new enemy." << std::endl;
  }

  oss << attacker.name << " attack: " << result.attacker << std::endl;

  if (result.attackedDied) {
    oss << attacked.name << "'s last words: " << attacked.sayBye << std::endl;
  }
  convos.emplace_back(oss.str());
}
