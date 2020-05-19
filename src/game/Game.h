//
// Created by nolasco on 09/05/20.
//
#include "characters/Player.h"
#include "input/Input.h"
#include "rooms/World.h"

#pragma once

enum class GameState {
  Menu,
  Talk,
  Attack,
  Inventory,
  Walk,
  Pickup,
  Shop,
};

class Game {
public:
  Game();
  ~Game();

  void initGame();
  void loop();
  void closeGame();
  bool isGameOver();

private:
  void updateGameState();
  void updatePlayer();
  void paintScreen();
  void paintHUD();
  void paintRoom();
  void paintOptions();
  void handleInput();
  void updateOptions();

  std::vector<std::string> options;
  uint8_t userInput;
  GameState gameState;
  World world;
  Input input;
  Player player;
};
