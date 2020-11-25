//
// Created by nolasco on 25/11/20.
//

#pragma once

#include <datatypes/controller/Action.h>
#include <datatypes/lookup/ResourceEntry.h>

namespace controller {

/// @brief Handles menu options
class MenuHandler {

public:
  bool shouldDisplaySubmenu(const Snapshot &snapshot, const Action &action);

private:
  bool ongoingCombat(const Snapshot &snapshot);
  bool shopkeeperAvailable(const Snapshot &snapshot);
};

} // namespace controller
