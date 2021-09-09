//
// Created by nolasco on 25/11/20.
//

#pragma once

#include "interface/controller/ISnapshotUtilities.h"

class Snapshot;

namespace utils {
// TODO(nn): Refactor methods to be more generic

/// @brief Provides search utilities for snapshot class.
class SnapshotUtilities : public ISnapshotUtilities {
public:
  /// @copydoc ISnapshotUtilities::shopkeeperAvailable()
  bool shopkeeperAvailable(const Snapshot &snapshot) override;

  /// @copydoc ISnapshotUtilities::phoneboothAvailable()
  bool phoneboothAvailable(const Snapshot &snapshot) override;
};

} // namespace utils
