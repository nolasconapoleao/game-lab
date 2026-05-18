//
// Created by nolasco on 25/11/20.
//

#include "DecisionChecker.h"

#include "datatypes/controller/Decision.h"
#include "datatypes/lookup/ResourceEntry.h"

namespace controller {

// TODO(nn): complete all cases
bool DecisionChecker::isDecisionValid(const Snapshot &snapshot, const Decision &decision) {
  switch (decision.action) {
    case Action::SPECIAL_PICKPOCKET:
      return (snapshot.ownedBy.contains(decision.object));
    case Action::UNDEFINED:
      return false;
    default:
      return true;
  }
}
} // namespace controller
