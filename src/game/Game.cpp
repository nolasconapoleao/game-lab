//
// Created by nolasco on 09/05/20.
//

#include "Game.h"

#include <iostream>
#include <magic_enum.hpp>

#include "common/InteractUtils.h"
#include "common/Match.h"
#include "generators/Generators.h"
#include "inteligence/Inteligence.h"
#include "utils/PrintUtils.h"

Game::Game() : lastInput(0) {
  renderer.start();
}

Game::~Game() {
  renderer.end();
}

void Game::initGame() {
  gameState = GameState::Menu;
  world = generator::createWorld(1);
}

void Game::loop() {
  updateOptions();
  updateHUD();
  updateRoom();
  renderer.paintScreen();
  lastInput = input.readInput(renderer.options.numOptions());
  handleInput();
  updateItems();
  updateGameState();
}

void Game::closeGame() {
}

bool Game::isGameOver() {
  std::ostringstream oss;
  if (world.player.isDead()) {
    oss << std::endl;
    oss << "Player said: " << world.player.sayBye << std::endl;
  } else if ('e' == lastInput) {
    oss << "Game terminated by user." << std::endl;
  }
  renderer.convos.emplace_back(oss.str());

  return ('e' == lastInput || world.player.isDead());
}

void Game::updateGameState() {
  switch (gameState) {
    case GameState::Menu:
      if ('b' != lastInput && 'e' != lastInput) {
        gameState = magic_enum::enum_cast<GameState>(renderer.options.options[lastInput].second).value();
      }
      break;

    case GameState::Attack:
      [[fallthrough]];
    case GameState::Inventory:
      updateNpcs();
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

void Game::updateNpcs() {
  for (auto &npc : world.rooms[world.currentRoom].npcs) {
    if (!npc.isDead()) {
      Inteligence::smallBrain(npc, world, renderer.convos);
    }
  }
}

void Game::updateHUD() {
  renderer.hud.emplace_back(printPlayer(world.player));
}

void Game::updateRoom() {
  std::ostringstream oss;
  oss << world.rooms[world.currentRoom];
  renderer.room.emplace_back(oss.str());
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
      oss << npc.talk() << std::endl;
      renderer.convos.emplace_back(oss.str());
      break;
    }

    case GameState::Attack: {
      Match::match(world.rooms[world.currentRoom], world.rooms[world.currentRoom].npcs[lastInput], world.player,
                   renderer.convos);
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
  renderer.options.clearOptions();

  switch (gameState) {
    case GameState::Menu:
      if (world.isAnyNpcAliveInThisRoom()) {
        renderer.options.addOption(magic_enum::enum_name(GameState::Attack).data());
      }
      renderer.options.addOption(magic_enum::enum_name(GameState::Talk).data());
      renderer.options.addOption(magic_enum::enum_name(GameState::Inventory).data());
      if (!world.isAnyNpcHostileInThisRoom()) {
        renderer.options.addOption(magic_enum::enum_name(GameState::Pickup).data());
        renderer.options.addOption(magic_enum::enum_name(GameState::Walk).data());
      }

      if (world.rooms[world.currentRoom].hasNpc("Shopkeeper")) {
        renderer.options.addOption(magic_enum::enum_name(GameState::Shop).data());
      }
      break;

    case GameState::Talk: {
      for (const auto &npc : world.rooms[world.currentRoom].npcs) {
        std::ostringstream oss;
        oss << "Speak to " << npc.name;
        renderer.options.addOption(oss.str());
      }
      break;
    }

    case GameState::Attack: {
      for (const auto &npc : world.rooms[world.currentRoom].npcs) {
        std::ostringstream oss;
        oss << "Attack " << npc.name;
        renderer.options.addOption(oss.str());
      }
      break;
    }

    case GameState::Inventory: {
      for (const auto &entry : world.player.pocket.entries) {
        renderer.options.addOption(printPocket(entry));
      }
      break;
    }

    case GameState::Walk: {
      for (const auto &room : world.rooms[world.currentRoom].adjacentRooms) {
        std::ostringstream oss;
        oss << "Go to " << world.rooms[room].name;
        renderer.options.addOption(oss.str());
      }
      break;
    }

    case GameState::Pickup: {
      for (const auto &entry : world.rooms[world.currentRoom].floor.entries) {
        renderer.options.addOption(printFloor(entry));
      }
      break;
    }

    case GameState::Shop: {
      for (const auto &entry : world.rooms[world.currentRoom].floor.entries) {
        renderer.options.addOption(printShop(entry));
      }
      break;
    }
  }
  renderer.options.addFooter();
}

void Game::updateItems() {
  world.player.pocket.spendEquipped(Effect::speed);
  for (auto npc : world.rooms[world.currentRoom].npcs) {
    npc.pocket.spendEquipped(Effect::speed);
  }
}
