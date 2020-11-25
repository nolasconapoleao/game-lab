//
// Created by nolasco on 25/11/20.
//

#pragma once

class Snapshot;
class Decision;

namespace controller {

class DecisionChecker {
public:
  /**
   * @brief Check if the decision is valid.
   * @param snapshot current world in view
   * @param decision player decision
   * @return true if decision is valid, false otherwise
   */
  bool isDecisionValid(const Snapshot &snapshot, const Decision &decision);
};

} // namespace controller
