//
// Created by nolasco on 02/06/20.
//

#include "Input-Prompter.h"

#include <datatypes/lookup/ResourceEntry.h>

namespace view::input {

void playerMenu(const std::vector<PlayerState> &options) {
  for (const auto &it : options) {
    std::cout << "\t" << it.transition << ": " << it.prompt << "\n";
  }
}

void invalid(const std::string_view &header) {
  std::cout << "Cannot " << header << "\n";
}

void generic_character(const std::string_view &header, std::vector<CharacterEntry> entities) {
  std::cout << separatorClose << header << ":\n";
  if (!entities.empty()) {
    auto k = 1;
    for (const auto &it : entities) {
      std::cout << "\t" << k << ": " << it.entity->name << "\n";
      k++;
    }
  }
}

void travel_exterior(const Snapshot &snap) {
  std::cout << separatorClose << " Where to fellow traveller:\n";
  if (!snap.exteriors.empty()) {
    auto k = 1;
    for (const auto &it : snap.exteriors) {
      std::cout << "\t" << k << ": " << it.entity->name << "\n";
      k++;
    }
  }
}

void travel_interior(const Snapshot &snap) {
  std::cout << separatorClose << " Where to fellow traveller:\n";
  if (!snap.exteriors.empty()) {
    auto k = 1;
    for (const auto &it : snap.buildings) {
      std::cout << "\t" << k << ": " << it.entity->name << "\n";
      k++;
    }
  }
}

} // namespace view::input
