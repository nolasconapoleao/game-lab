//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <string>
#include <vector>

#include "game/view/include/Verbose.h"

namespace view {

using PrintList = std::vector<std::pair<Verbose, std::string>>;

class Printer {
public:
  static void setVerboseLevel(Verbose verbose);

  // Insert entries to printed structures
  static void addToRoundReport(const Verbose verbose, const std::string reportEntry);
  static void addToScene(const Verbose verbose, const std::string sceneEntry);
  static void addToHud(const Verbose verbose, const std::string hudEntry);
  static void addToExtraInfo(Verbose verbose, std::string note);
  static void addToOptionHeader(const Verbose verbose, const std::string header);
  static void addToOptions(Verbose verbose, char option, std::string optionDescription);
  static void resetLists();

  // Print methods
  static void directPrint(const std::string &message);
  static void printScreen();
  static void clearScreen();

private:
  static void printRoundReport();
  static void printScene();
  static void printHud();
  static void printExtraInfo();
  static void printOptions();
  static void printAndClear(PrintList &printList);

  static Verbose printerVerbose;
  static PrintList roundReport;
  static PrintList scene;
  static PrintList hud;
  static PrintList extraInfo;
  static PrintList optionHeader;
  static PrintList options;
};

} // namespace view
