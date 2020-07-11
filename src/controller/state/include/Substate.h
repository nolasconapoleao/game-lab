//
// Created by nolasco on 27/06/20.
//

#pragma once

enum Substate : uint8_t {
  IDLE = 0,
  TERMINATED = 1,
  Cancel = 2,
  EXECUTE = 3,
  SELECT_CHARACTER = 4,
  SELECT_STRUCTURE = 5,
  SELECT_LOCATION = 6,
  SELECT_ITEM = 7,
  SELECT_QUANTITY = 8,

  PUNISH = 9,
  REWARD = 10,
};