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
  void addToOptionHeader(const Verbose verbose, const std::string header);
  void addToOptions(Verbose verbose, char option, std::string optionDescription);
  void addToRoundReport(const Verbose verbose, const std::string reportEntry);

  // Print methods
  void directPrint(const std::string &message);
  void printScreen();
  void clearScreen();

private:
  void printScene();
  void printHud();
  void printOptions();
  void printRoundReport();
  void printAndClear(PrintList &printList);

  Verbose printerVerbose;
  static PrintList scene;
  static PrintList hud;
  static PrintList optionHeader;
  static PrintList options;
  static PrintList roundReport;
};

} // namespace view
