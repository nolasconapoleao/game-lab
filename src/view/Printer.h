//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <string>
#include <vector>

#include "Verbose.h"

namespace view {

using PrintList = std::vector<std::pair<Verbose, std::string>>;

class Printer {
public:
  Printer(const Verbose verbose = Verbose::INFO);
  void setVerboseLevel(Verbose verbose);

  // Insert entries to printed structures
  void addToScene(const Verbose verbose, const std::string sceneEntry);
  void addToHud(const Verbose verbose, const std::string hudEntry);
  void addToOptions(const Verbose verbose, const std::string option);
  void addToRoundReport(const Verbose verbose, const std::string reportEntry);

  // Print methods
  void printScene();
  void printHud();
  void printOptions();
  void printRoundReport();
  void clearScreen();

private:
  void printAndClear(PrintList &printList);

  Verbose printerVerbose;
  PrintList scene;
  PrintList hud;
  PrintList options;
  PrintList roundReport;
};

} // namespace view
