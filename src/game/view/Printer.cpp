//
// Created by nolasco on 02/06/20.
//

#include "Printer.h"

#include <iomanip>
#include <iostream>

#include "PrintingUtilities.h"
#include "model/lookup/Lookup.h"
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
#ifdef __unix__
  std::system("clear");
#else
  std::system("cls");
#endif
}

void printScene(const Snapshot &snap) {
  std::cout << foreground::LightBlue << "Where am I?\n\t" << foreground::Blue << snap.location.entity->name << "\n";
  if (!snap.characters.empty()) {
    std::cout << foreground::LightMagenta << "Who's that guy?\n" << foreground::Magenta;
    for (const auto &it : snap.characters) {
      std::cout << "\t" << it.entity->name << " " << std::right << it.entity->stats().hp << "/" << std::left
                << it.entity->stats().mhp;
    };
    std::cout << "\n" << separator3 << "\n";
  }

  if (!snap.structures.empty() || !snap.buildings.empty()) {
    std::cout << foreground::LightGreen << "What's that over there?\n" << foreground::Green;
    for (const auto &it : snap.structures) {
      std::cout << "\t$" << it.entity->name << " ";
    }
    for (const auto &it : snap.buildings) {
      std::cout << "\t#" << it.entity->name << "#"
                << "\n";
    }
    std::cout << "\n" << separator3 << "\n";
  }

  if (!snap.floor.empty()) {
    std::cout << foreground::LightYellow << "What's that on the floor?\n" << foreground::Yellow;
    for (const auto &it : snap.floor) {
      std::cout << "\t#" << it.entity->name << "#"
                << "\n";
    }
  }
  std::cout << foreground::White << separator1 << "\n";
}

void printHud(const Snapshot &snap) {
  std::cout << foreground::Red << separator1 << "\n";
  std::cout << std::string(15, ' ') << stream::infoHeader() << "\n";
  std::cout << std::setw(9) << snap.character.entity->name << " " << std::right << snap.character.entity->stats().hp
            << "/" << std::left << snap.character.entity->stats().mhp << snap.character.entity->info << "\n";
  std::cout << separator2 << "\n";
}

} // namespace view::printer
