//
// Created by nolasco on 02/06/20.
//

#include "Printer.h"

#include <iomanip>
#include <iostream>

#include "libs/constants/gameconstants.h"
#include "model/lookup/Lookup.h"
#include "view/stream/GeneralUtilities.h"
#include "view/stream/PrintingUtilities.h"
#include "view/stream/StreamConverter.h"

using namespace view::stream;

constexpr auto separator1 = "################################################################";
constexpr auto separator2 = "================================================================";
constexpr auto separator3 = "________________________________________________________________";

namespace view::printer {

void debugScene(const Snapshot &snap);
void printScene(const Snapshot &snap);
void printActionScene(const Snapshot &snap, const Action &submenu);
void printHud(const Snapshot &snap);

void printScreen(const Snapshot &snap, const Action &submenu, const bool clearFirst) {
  if (clearFirst) {
    clearScreen();
  }
  printHud(snap);
  std::cout << foreground::White << "\n" << separator1 << "\n" << separator1 << "\n";
  printActionScene(snap, submenu);
  std::cout << foreground::White << "\n" << separator1 << "\n";
}

void history(const std::vector<Decision> &history) {
  if (!history.empty()) {
    std::cout << foreground::White << "On the last episode:\n";
    auto k = 1;
    for (const auto &decision : history) {
      std::cout << "\tCharacter " << k << " used " << gameconstants::submenuInfo(decision.action).prompt << "\n";
      k++;
    }
  }
}

void clearScreen() {
#ifdef __unix__
  std::system("clear");
#else
  std::system("cls");
#endif
}

void debugScene(const Snapshot &snap) {
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

  // My items
  if (!snap.consumables.empty() || !snap.equippables.empty()) {
    std::cout << foreground::LightGray << "What's that on my pocket?";
    std::cout << foreground::DarkGray << snap.consumables;
    std::cout << foreground::DarkGray << snap.equippables;
    std::cout << "\n" << separator3 << "\n";
  }

  // Neighbourhood
  if (!snap.exteriors.empty()) {
    std::cout << foreground::LightMagenta << "Where can I travel to?";
    std::cout << foreground::Magenta << snap.exteriors;
    std::cout << "\n" << separator3 << "\n";
  }

  // Characters pockets
  if (!snap.ownedBy.empty()) {
    std::cout << foreground::LightGreen << "What's that on your pocket?\n";
    for (const auto &[id, items] : snap.ownedBy) {
      std::cout << foreground::Green << "Character " << id << " items: " << items;
      std::cout << "\n" << separator3 << "\n";
    }
  }
}

void printScene(const Snapshot &snap) {
  // Characters
  if (!snap.characters.empty()) {
    std::cout << foreground::LightMagenta << "Who's that guy?";
    std::cout << foreground::Magenta << print(snap.characters);
    std::cout << "\n" << separator3 << "\n";
  }

  // Landscape
  if (!snap.structures.empty() || !snap.buildings.empty()) {
    std::cout << foreground::LightGreen << "What's that over there?";
    std::cout << foreground::Green << print(snap.structures);
    std::cout << foreground::Green << print(snap.buildings);
    std::cout << "\n" << separator3 << "\n";
  }

  // Floor items
  if (!snap.floor.empty()) {
    std::cout << foreground::LightYellow << "What's that on the floor?";
    std::cout << foreground::Yellow << print(snap.floor);
    std::cout << "\n" << separator3 << "\n";
  }
}

void printHud(const Snapshot &snap) {
  // Player info
  std::cout << foreground::White << separator1 << "\n";
  std::cout << foreground::LightRed << "Who I am?\n";
  std::cout << foreground::Red << snap.character.entity;
  std::cout << "\n" << separator2 << "\n";

  // Location
  std::cout << foreground::LightBlue << "Where am I?\n";
  std::cout << foreground::Blue << snap.location;
  std::cout << "\n" << separator3 << "\n";
}

void printActionScene(const Snapshot &snap, const Action &submenu) {
  switch (submenu) {
    case Action::ATTACK_CHARACTER:
      std::cout << snap.characters << "\n";
      break;
    case Action::ATTACK_BUILDING:
      std::cout << snap.buildings << "\n";
      break;
    case Action::ATTACK_STRUCTURE:
      std::cout << snap.structures << "\n";
      break;
    case Action::INVENTORY_PICKUP:
      std::cout << snap.floor;
      break;
    case Action::INVENTORY_DROP:
      [[fallthrough]];
    case Action::INVENTORY_USE:
      std::cout << snap.consumables;
      std::cout << snap.equippables << "\n";
      break;
    case Action::TRAVEL_EXTERIOR:
      std::cout << snap.exteriors << "\n";
      break;
    case Action::TRAVEL_INTERIOR:
      std::cout << snap.buildings << "\n";
      break;
    default:
      printScene(snap);
      break;
  }
}

} // namespace view::printer
