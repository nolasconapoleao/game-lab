//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <datatypes/GameTypes.h>
#include <datatypes/controller/Decision.h>
#include <datatypes/lookup/ResourceEntry.h>

namespace controller::brain::player {

Decision think(const Snapshot &snap);

namespace // anonymous namespace
{
bool inventory(const Snapshot &snap);
} // namespace

} // namespace controller::brain::player
