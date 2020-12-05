//
// Created by nolasco on 25/11/20.
//

#pragma once

class Snapshot;

namespace utils {
// TODO(nn): Refactor methods to be more generic

/// @brief Interface for provider of search utiliities in snapshot instances.
class ISnapshotUtilities {
public:
  /**
   * @brief Checks if a shopkeeper exists.
   * @param snapshot slice of world to check
   * @return true if shopkeeper exists, false otherwise
   */
  virtual bool shopkeeperAvailable(const Snapshot &snapshot) = 0;

  /**
   * @brief Checks if a phonebooth exists.
   * @param snapshot slice of world to check
   * @return true if phonebooth exists, false otherwise
   */
  virtual bool phoneboothAvailable(const Snapshot &snapshot) = 0;
};

} // namespace utils
