//
// Created by nolasco on 16/06/20.
//

#pragma once

#include "IBrain.h"

namespace controller::brain {

/// @brief Non player behaviour handler.
class Computer : public IBrain {
public:
  /// @copydoc IBrain::think()
  Decision think(const Snapshot &snap) override;

private:
  Decision attack(const Snapshot &snap);
  Decision inventory(const Snapshot &snap);
  Decision tourist(const Snapshot &snap);
};

}; // namespace controller::brain
