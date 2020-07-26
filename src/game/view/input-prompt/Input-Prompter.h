//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "datatypes/controller/PlayerState.h"
#include "datatypes/lookup/ResourceEntry.h"

namespace view::input {

constexpr auto separatorOpen = "<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
constexpr auto separatorClose = ">>>>>>>>>>>>>>>>>>>>>>>>>>>>";

void playerMenu(const std::vector<PlayerState> &options);
void invalid(const std::string_view &header);
void generic_character(const std::string_view &header, const std::vector<CharacterEntry> entities);
void travel_interior(const Snapshot &snap);
void travel_exterior(const Snapshot &snap);
template <typename T> void generic(const std::string_view &header, std::vector<T> entities) {
  std::cout << separatorClose << header << ":\n";
  auto k = 1;
  for (const auto &it : entities) {
    std::cout << "\t" << k << ": " << it.entity->name << "\n";
    k++;
  }
}

} // namespace view::input
