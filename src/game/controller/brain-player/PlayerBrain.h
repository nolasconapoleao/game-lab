//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <datatypes/GameTypes.h>
#include <datatypes/controller/Decision.h>
#include <datatypes/lookup/ResourceEntry.h>

struct ConsoleIn {
  Quantity raw;
  ResourceId parsed;
};

namespace controller::brain {

class player {
public:
  player();
  Decision think(const Snapshot &snap);

private:
  Decision drop_item();
  Decision use_item();
  template <typename T> ConsoleIn selectFromVector(const std::vector<T> &vector);
  template <typename T> Quantity selectItemQuantity(const std::vector<T> &vector, ConsoleIn input);
  void selectSubstate();
  void makeBranch(Action start, std::initializer_list<Action> const &end);

  std::map<Action, Action> decisionTree;
  Action active;
  Snapshot snap;
};

} // namespace controller::brain
