//
// Created by nolasco on 02/06/20.
//

#include "Printer.h"

#include <iomanip>
#include <iostream>

#include "model/lookup/Lookup.h"
#include "platform/platformconfig.h"
#include "view/stream/StreamConverter.h"
#include "view/stream/StreamFormatter.h"

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
#ifdef COMPILE_FOR_NON_UNIX
  std::system("cls");
#else
  std::system("clear");
#endif
}

void printScene(const Snapshot &snap) {
  std::cout << "You are at: " << /*snap.<<*/ "\n"; // TODO
  if (!snap.characters.empty()) {
    std::cout << "Who's that guy?\n";
    for (const auto &it : snap.characters) {
      std::cout << "\t\t" << it.entity->name << " " << std::right << it.entity->stats().hp << "/" << std::left
                << it.entity->stats().mhp;
    };
    std::cout << "\n" << separator3 << "\n";
  }

  if (!snap.structures.empty() || !snap.buildings.empty()) {
    std::cout << "What's that over there?\n";
    for (const auto &it : snap.structures) {
      std::cout << "\t\t$" << it.entity->name << " ";
    }
    for (const auto &it : snap.buildings) {
      std::cout << "\t\t#" << it.entity->name << "#"
                << "\n";
    }
    std::cout << "\n" << separator3 << "\n";
  }

  if (!snap.consumables.empty() || !snap.equippables.empty()) {
    std::cout << "What's that on the floor?\n";
  }
  std::cout << separator1 << "\n";
}

void printHud(const Snapshot &snap) {
  std::cout << separator1 << "\n";
  std::cout << std::string(15, ' ') << stream::infoHeader() << "\n";
  std::cout << std::setw(9) << snap.character.entity->name << " " << std::right << snap.character.entity->stats().hp
            << "/" << std::left << snap.character.entity->stats().mhp << snap.character.entity->info << "\n";
  std::cout << separator2 << "\n";
}

} // namespace view::printer
