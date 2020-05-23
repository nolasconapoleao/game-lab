//
// Created by nolasco on 09/05/20.
//
#include "OptionList.h"
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
  void clearScreen();
  void paintHUD();
  void paintConvos();
  void paintRoom();
  void paintOptions();
  void handleInput();
  void updateOptions();

  std::vector<std::string> convos;
  GameState gameState;
  OptionList optionList;
  World world;
  Input input;
  uint8_t lastInput;

  std::string sepatator = "=====================================================================";
  std::string sepatator2 = "---------------------------------------------------------------------";
};
