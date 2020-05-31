//
// Created by nolasco on 09/05/20.
//
#include <common/Match.h>

#include "graphics/Renderer.h"
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
  void updateNpcs();
  void updateItems();
  void handleInput();
  void updateHUD();
  void updateRoom();
  void updateOptions();

  GameState gameState;
  Renderer renderer;
  World world;
  Input input;
  uint8_t lastInput;
};
