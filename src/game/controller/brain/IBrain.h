//
// Created by nolasco on 25/11/20.
//

#pragma once

#include "datatypes/controller/Decision.h"
#include "datatypes/lookup/ResourceEntry.h"

namespace controller::brain {
// TODO(nn): History should be stored in the brain

/// @brief Brain interface.
class IBrain {
public:
  /**
   * @brief Handle creation of player decisions.
   * @param snap current visible world.
   * @return decision made by player.
   */
  virtual Decision think(const Snapshot &snap) = 0;

protected:
  /// @brief Current snapshot
  Snapshot snap;
};

} // namespace controller::brain
