//
// Created by nolasco on 02/06/20.
//

#include "InputPrompter.h"

#include "view/stream/EntityConverter.h"
#include "view/stream/PrintingUtilities.h"

using namespace view::stream;

namespace input::prompt {
void playerMenu(const std::vector<MenuState> &options) {
  std::cout << "What do you want to do?\n";
  for (const auto &it : options) {
    std::cout << "\t" << it.transition << ": " << it.prompt << "\n";
  }
}

void quantity(Quantity max) {
  std::cout << "How much do you want? Maximum is " << max << "\n";
}

void items(const std::string_view &header, const Snapshot &snapshot) {
  std::cout << separatorClose << " " << header << "\n";
  std::cout << separatorClose << "Select item:\n";
  auto k = 1;
  for (const auto &it : snapshot.equippables) {
    std::cout << "\t" << k << ": " << it.entity->name << "\n";
    k++;
  }
  for (const auto &it : snapshot.consumables) {
    std::cout << "\t" << k << ": " << it.entity->name << "\n";
    k++;
  }
}

} // namespace input::prompt
