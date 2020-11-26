//
// Created by nolasco on 25/11/20.
//

#pragma once

#include "SnapshotUtilities.h"
#include "datatypes/controller/Action.h"
#include "datatypes/lookup/ResourceEntry.h"

namespace controller {

/// @brief Handles menu options
class MenuHandler {

public:
  /**
   * @brief Check if the submenu should be displayed.
   * @param snapshot current world snapshot
   * @param submmenu entry to check
   * @return true if the menu should be displayed, false otherwise
   */
  bool shouldDisplaySubmenu(const Snapshot &snapshot, const Action &submmenu);

private:
  bool ongoingCombat(const Snapshot &snapshot);
  utils::SnapshotUtilities snapshotUtilities;
};

} // namespace controller
