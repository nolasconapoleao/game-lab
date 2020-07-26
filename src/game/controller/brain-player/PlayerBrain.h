//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <datatypes/GameTypes.h>
#include <datatypes/controller/Decision.h>
#include <datatypes/lookup/ResourceEntry.h>

namespace controller::brain {

class player {
public:
  player();
  Decision think(const Snapshot &snap);

private:
  Decision travel();
  Decision attack_characters();
  void selectSubstate();
  void makeBranch(Action start, std::initializer_list<Action> const &end);

  std::map<Action, Action> decisionTree;
  Action active;
  Snapshot snap;
};

} // namespace controller::brain
