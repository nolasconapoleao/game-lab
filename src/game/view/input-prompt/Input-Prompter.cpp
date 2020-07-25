//
// Created by nolasco on 02/06/20.
//

#include <datatypes/lookup/ResourceEntry.h>
#include <iostream>

#include "view/stream/StreamConverter.h"

using namespace view::stream;

namespace view::input {

constexpr auto separatorOpen = "<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
constexpr auto separatorClose = ">>>>>>>>>>>>>>>>>>>>>>>>>>>>";

void travel(const Snapshot &snap) {
  std::cout << separatorClose << " Where to fellow traveller:\n";
  if (!snap.exteriors.empty() || !snap.buildings.empty()) {
    auto k = 1;
    for (const auto &it : snap.exteriors) {
      std::cout << "\t\t" << k << ": " << it.entity->name << "\n";
      k++;
    }
    for (const auto &it : snap.buildings) {
      std::cout << "\t\t" << k << ": " << it.entity->name << "\n";
      k++;
    }
  }
}

} // namespace view::input
