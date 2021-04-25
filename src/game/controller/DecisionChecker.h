//
// Created by nolasco on 25/11/20.
//

#pragma once

#include <interface/controller/IDecisionChecker.h>

namespace controller {

/// @brief Checker for decisions.
class DecisionChecker : public IDecisionChecker {
public:
  /// @copydoc IDecisionChecker::isDecisionValid()
  bool isDecisionValid(const Snapshot &snapshot, const Decision &decision) override;
};

} // namespace controller
