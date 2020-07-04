//
// Created by nolasco on 27/06/20.
//

#pragma once

enum Substate : uint8_t {
  IDLE,
  TERMINATED,
  Cancel,
  EXECUTE,
  SELECT_CHARACTER,
  SELECT_STRUCTURE,
  SELECT_LOCATION,
  SELECT_ITEM,
  SELECT_QUANTITY,
};