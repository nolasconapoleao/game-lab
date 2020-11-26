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
constexpr auto separator2 = "=================================================================";
constexpr auto separator3 = "________________________________________________________________";

namespace view::printer {

void printScene(const Snapshot &snap);
void printActionScene(const Snapshot &snap, const Action &submenu);
void printHud(const Snapshot &snap);

void printScreen(const Snapshot &snap, const Action &submenu, const bool clearFirst) {
  if (clearFirst) {
    clearScreen();
  }
  printHud(snap);
  printActionScene(snap, submenu);
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

void printScene(const Snapshot &snap) {
  // Location
  std::cout << foreground::LightBlue << "Where am I?\n";
  std::cout << foreground::Blue << snap.location;
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

  // My items
  if (!snap.consumables.empty() || !snap.equippables.empty()) {
    std::cout << foreground::LightGray << "What's that on your pocket?";
    std::cout << foreground::DarkGray << snap.consumables;
    std::cout << foreground::DarkGray << snap.equippables;
    std::cout << "\n" << separator3 << "\n";
  }

  std::cout << foreground::White << "\n" << separator1 << "\n";
}

void printHud(const Snapshot &snap) {
  std::cout << foreground::White << separator1 << "\n";
  std::cout << foreground::LightRed << "Who I am?\n";
  std::cout << foreground::Red << snap.character.entity;
  std::cout << "\n" << separator2 << "\n";
}
void printActionScene(const Snapshot &snap, const Action &submenu) {
  switch (submenu) {
    case Action::SKIP_TURN:
      break;
    case Action::MENU:
      break;
    case Action::MENU_SAVE:
      break;
    case Action::MENU_TUTORIAL:
      break;
    case Action::MENU_TERMINATE:
      break;
    case Action::ATTACK:
      break;
    case Action::ATTACK_CHARACTER:
      break;
    case Action::ATTACK_BUILDING:
      break;
    case Action::ATTACK_STRUCTURE:
      break;
    case Action::INVENTORY:
      break;
    case Action::INVENTORY_PICKUP:
      break;
    case Action::INVENTORY_DROP:
      break;
    case Action::INVENTORY_USE:
      break;
    case Action::TEAM:
      break;
    case Action::TEAM_CREATE:
      break;
    case Action::TEAM_DISBAND:
      break;
    case Action::TEAM_TRADE:
      break;
    case Action::TEAM_KICK:
      break;
    case Action::TEAM_INVITE:
      break;
    case Action::SHOP:
      break;
    case Action::SHOP_BUY:
      break;
    case Action::SHOP_SELL:
      break;
    case Action::QUEST:
      break;
    case Action::QUEST_ABANDON:
      break;
    case Action::QUEST_FINISH:
      break;
    case Action::TRAVEL:
      break;
    case Action::TRAVEL_EXTERIOR:
      break;
    case Action::TRAVEL_INTERIOR:
      break;
    case Action::SPECIAL:
      break;
    case Action::SPECIAL_SUMMON:
      break;
    case Action::SPECIAL_PICKPOCKET:
      break;
    case Action::SPECIAL_POSSESS:
      break;
    case Action::SPECIAL_READ:
      break;
    case Action::SPECIAL_CALL:
      break;
    case Action::SPECIAL_CALL_REINFORCEMENT:
      break;
    case Action::SPECIAL_CALL_ENEMY:
      break;
    case Action::UNDEFINED:
      printScene(snap);
      break;
  }
}

} // namespace view::printer
