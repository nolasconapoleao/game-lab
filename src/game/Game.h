//
// Created by nolasco on 09/05/20.
//
#include "../characters/Enemy.h"
#include "../characters/Player.h"

#pragma once

class Game {
public:
  Game();

  virtual ~Game();

  void updateGame();
  void initGame();
  void readInput();
  void paint();
  void loop();

  bool isOver();

private:
  void updatePlayer();
  void updateNonPlayableCharacters();
  void updateEntities();
  void paintHUD();
  void paintRoomDescription();
  void paintOptions();

  uint8_t lastKeyPressed;
  Player player;
  Enemy enemy;
};
