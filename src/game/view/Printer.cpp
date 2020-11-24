//
// Created by nolasco on 02/06/20.
//

#include "Printer.h"

#include <iomanip>
#include <iostream>

#include "model/lookup/Lookup.h"
#include "view/stream/GeneralUtilities.h"
#include "view/stream/PrintConstants.h"
#include "view/stream/PrintingUtilities.h"
#include "view/stream/StreamConverter.h"

using namespace view::stream;

constexpr auto separator1 = "################################################################";
constexpr auto separator2 = "=================================================================";
constexpr auto separator3 = "________________________________________________________________";

namespace view::printer {

void clearScreen();
void printScene(const Snapshot &snap);
void printHud(const Snapshot &snap);

void printScreen(const Snapshot &snap) {
  clearScreen();
  printHud(snap);
  printScene(snap);
}

void clearScreen() {
#ifdef __unix__
  std::system("clear");
#else
  std::system("cls");
#endif
}

void printScene(const Snapshot &snap) {
  // Location
  std::cout << foreground::LightBlue << "Where am I?\n";
  std::cout << foreground::Blue << "\t" << snap.location.entity->name;
  std::cout << "\n" << separator3 << "\n";

  // Characters
  if (!snap.characters.empty()) {
    std::cout << foreground::LightMagenta << "Who's that guy?";
    std::cout << foreground::Magenta << snap.characters;
    std::cout << "\n" << separator3 << "\n";
  }

  // Landscape
  if (!snap.structures.empty() || !snap.buildings.empty()) {
    std::cout << foreground::LightGreen << "What's that over there?";
    std::cout << foreground::Green << snap.structures;
    std::cout << foreground::Green << snap.buildings;
    std::cout << "\n" << separator3 << "\n";
  }

  // Floor items
  if (!snap.floor.empty()) {
    std::cout << foreground::LightYellow << "What's that on the floor?";
    std::cout << foreground::Yellow << snap.floor;
    std::cout << "\n" << separator3 << "\n";
  }

  std::cout << foreground::White << "\n" << separator1 << "\n";
}

void printHud(const Snapshot &snap) {
  const auto ch = snap.character.entity;
  std::cout << foreground::Red << separator1 << "\n";
  std::cout << cMinimalStatsHeader << "\n";
  std::cout << std::setw(9) << ch->name << "\t\t\t" << ch->stats().hp << "/" << ch->stats().mhp << ch->info;
  std::cout << "\n" << separator2 << "\n";
}

} // namespace view::printer
