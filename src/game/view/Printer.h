//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "datatypes/state/LogicState.h"

// Foward declaration
namespace model {
class Lookup;
}

namespace view {

class Printer {
public:
  void printScreen(const LogicState state);
  void addHistoryEntry(const std::string &entry);

private:
  void clearScreen();
  void printScene();
  void printHud();
  void printInputPrompt();
  std::vector<std::string> roundHistory;

  std::shared_ptr<model::Lookup> lookup;

public:
  Printer(const std::shared_ptr<model::Lookup> &lookup);
};

} // namespace view
