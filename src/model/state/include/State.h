//
// Created by nolasco on 27/06/20.
//

#pragma once

enum State : uint8_t {
  startWorld,
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