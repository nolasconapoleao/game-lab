//
// Created by nolasco on 27/06/20.
//

#pragma once

enum State : uint8_t {
  startWorld = 0,
  idleWorld,
  playerTurn,
  example,
  tutorial,
  attack,
  walk,
  skip,
  endTurn,
  shutdown,
};