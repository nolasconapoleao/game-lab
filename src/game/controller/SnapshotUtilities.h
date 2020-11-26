//
// Created by nolasco on 25/11/20.
//

#pragma once

#include "datatypes/lookup/ResourceEntry.h"

namespace utils {

/// @brief Provides search utiliities for snapshot class.
class SnapshotUtilities {
public:
  /**
   * @brief Checks if a shopkeeper exists.
   * @param snapshot slice of world to check
   * @return true if shopkeeper exists, false otherwise
   */
  bool shopkeeperAvailable(const Snapshot &snapshot);

  /**
   * @brief Checks if a phonebooth exists.
   * @param snapshot slice of world to check
   * @return true if phonebooth exists, false otherwise
   */
  bool phoneboothAvailable(const Snapshot &snapshot);
};

} // namespace utils
