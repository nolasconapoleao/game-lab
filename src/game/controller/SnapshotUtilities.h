//
// Created by nolasco on 25/11/20.
//

#pragma once

#include "datatypes/lookup/ResourceEntry.h"

namespace utils {

class SnapshotUtilities {
public:
  bool shopkeeperAvailable(const Snapshot &snapshot);
  bool phoneboothAvailable(const Snapshot &snapshot);
};

} // namespace utils
