//
// Created by nolasco on 25/11/20.
//

#pragma once

#include <memory>

#include "interface/controller/IMenuHandler.h"

class Snapshot;

namespace utils {
// Forward declaration
class ISnapshotUtilities;
} // namespace utils

namespace controller {

/// @brief Handles menu options
class MenuHandler : public IMenuHandler {

public:
  /// @brief Constructor.
  MenuHandler();
  /// @copydoc IMenuHandler::shouldDisplaySubmenu()
  bool shouldDisplaySubmenu(const Snapshot &snapshot, const Action &submmenu) override;

private:
  bool ongoingCombat(const Snapshot &snapshot);
  std::shared_ptr<utils::ISnapshotUtilities> snapshotUtilities;
};

} // namespace controller
