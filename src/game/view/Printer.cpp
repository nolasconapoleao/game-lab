//
// Created by nolasco on 02/06/20.
//

#include "Printer.h"

#include <iostream>
#include <sstream>

#include "datatypes/logger/PrintConstants.h"
#include "platform/platformconfig.h"

namespace view {

PrintList Printer::roundReport;
PrintList Printer::scene;
PrintList Printer::hud;
PrintList Printer::extraInfo;
PrintList Printer::options;
PrintList Printer::optionHeader;
Verbose Printer::printerVerbose;

void Printer::setVerboseLevel(const Verbose verbose) {
  Printer::printerVerbose = verbose;
}

void Printer::addToRoundReport(Verbose verbose, std::string reportEntry) {
  roundReport.emplace_back(verbose, reportEntry);
}

void Printer::addToScene(Verbose verbose, std::string sceneEntry) {
  scene.emplace_back(verbose, sceneEntry);
}

void Printer::addToHud(Verbose verbose, std::string hudEntry) {
  hud.emplace_back(verbose, hudEntry);
}

void Printer::addToExtraInfo(Verbose verbose, std::string note) {
  extraInfo.emplace_back(verbose, note);
}

void Printer::addToOptionHeader(Verbose verbose, std::string header) {
  optionHeader.emplace_back(verbose, header);
}

void Printer::addToOptions(Verbose verbose, char option, std::string optionDescription) {
  std::ostringstream os;
  os << option << ": " << optionDescription;
  options.emplace_back(verbose, os.str());
}

void Printer::resetLists() {
  scene.clear();
  hud.clear();
  optionHeader.clear();
  extraInfo.clear();
  options.clear();
}

void Printer::directPrint(const std::string &message) {
  std::cout << message << "\n";
}

void Printer::printScreen() {
  clearScreen();
  printRoundReport();
  printScene();
  printHud();
  printExtraInfo();
  printOptions();
}

void Printer::printScene() {
  printAndClear(scene);
  std::cout << separator1 << "\n";
}

void Printer::printHud() {
  printAndClear(hud);
  std::cout << separator2 << "\n";
}

void Printer::printOptions() {
  printAndClear(optionHeader);
  printAndClear(options);
  std::cout << separator3 << "\n";
}

void Printer::printRoundReport() {
  printAndClear(roundReport);
  std::cout << separator2 << "\n";
}

void Printer::clearScreen() {
#ifdef COMPILE_FOR_NON_UNIX
  std::system("cls");
#else
  std::system("clear");
#endif
}

void Printer::printExtraInfo() {
  printAndClear(extraInfo);
  std::cout << separator1 << "\n";
}

void Printer::printAndClear(PrintList &printList) {
  for (const auto entry : printList) {
    if (entry.first >= printerVerbose)
      std::cout << entry.second << "\n";
  }

  printList.clear();
}

} // namespace view