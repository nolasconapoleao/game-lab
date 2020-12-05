//
// Created by nolasco on 25/11/20.
//

#pragma once

#include "datatypes/controller/Action.h"

class Snapshot;

namespace controller {

/// @brief Interface for handler of menu options
class IMenuHandler {

public:
  /**
   * @brief Check if the submenu should be displayed.
   * @param snapshot current world snapshot
   * @param submmenu entry to check
   * @return true if the menu should be displayed, false otherwise
   */
  virtual bool shouldDisplaySubmenu(const Snapshot &snapshot, const Action &submmenu) = 0;
};

} // namespace controller
