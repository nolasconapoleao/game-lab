//
// Created by nolasco on 02/06/20.
//

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "datatypes/controller/PlayerState.h"
#include "datatypes/lookup/ResourceEntry.h"

namespace view::input {

void playerMenu(const std::vector<PlayerState> &options);
void generic(const std::string_view &header, const std::vector<CharacterEntry> entities);
void travel(const Snapshot &snap);

} // namespace view::input
