//
// Created by nolasco on 02/06/20.
//

#include "Printer.h"

#include <iostream>
#include <sstream>

#include "datatypes/logger/PrintConstants.h"
#include "model/lookup/Lookup.h"
#include "platform/platformconfig.h"
#include "view/stream/StreamConverter.h"
#include "view/stream/StreamFormatter.h"

using namespace view::stream;

namespace view {

Printer::Printer(const std::shared_ptr<model::Lookup> &lookup) : lookup(lookup) {
}

void Printer::printScreen(LogicState state) {
  printHud();
  printScene();
  printInputPrompt();
}

void Printer::addHistoryEntry(const std::string &entry) {
}

void Printer::clearScreen() {
#ifdef COMPILE_FOR_NON_UNIX
  std::system("cls");
#else
  std::system("clear");
#endif
}

void Printer::printScene() {
  std::cout << "Characters:\n";
  std::cout << stream::statsHeader() << stream::infoHeader() << "\n";
  for (const auto &it : lookup->closeByCharacters(1)) {
    std::cout << it.id << " " << it.entity << "\n";
  };

  std::cout << "Structures:\n";
  for (const auto &it : lookup->closeByStructures(1)) {
    std::cout << it.id << " " << it.entity << "\n";
  }

  std::cout << "Items:\n";
  std::cout << stream::itemHeader() << "\n";
  for (const auto &it : lookup->itemsIn(1)) {
    std::cout << it.id << " " << it.entity << "\n";
  }

  std::cout << "Neighbourhood:\n";
  for (const auto &it : lookup->closeByExteriors(1)) {
    std::cout << it.id << " " << it.entity << "\n";
  }
  for (const auto &it : lookup->closeByBuildings(1)) {
    std::cout << it.id << " " << it.entity << "\n";
  }
}

void Printer::printHud() {
}

void Printer::printInputPrompt() {
}

} // namespace view
