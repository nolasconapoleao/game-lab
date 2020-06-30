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
  void addToRoundReport(const Verbose verbose, const std::string reportEntry);
  void addToScene(const Verbose verbose, const std::string sceneEntry);
  void addToHud(const Verbose verbose, const std::string hudEntry);
  void addToExtraInfo(Verbose verbose, std::string note);
  void addToOptionHeader(const Verbose verbose, const std::string header);
  void addToOptions(Verbose verbose, char option, std::string optionDescription);
  void resetLists();

  // Print methods
  void directPrint(const std::string &message);
  void printScreen();
  void clearScreen();

private:
  void printRoundReport();
  void printScene();
  void printHud();
  void printExtraInfo();
  void printOptions();
  void printAndClear(PrintList &printList);

  Verbose printerVerbose;
  static PrintList roundReport;
  static PrintList scene;
  static PrintList hud;
  static PrintList extraInfo;
  static PrintList optionHeader;
  static PrintList options;
};

} // namespace view
