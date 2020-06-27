//
// Created by nolasco on 27/06/20.
//

#pragma once

enum Substate : uint8_t {
  IDLE = 11,
  TERMINATED = 12,
  USER_TERMINATED = 14,
  EXECUTE = 15,
};