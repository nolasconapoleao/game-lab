//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <datatypes/GameTypes.h>
#include <datatypes/controller/Decision.h>
#include <datatypes/lookup/ResourceEntry.h>

namespace controller::brain::computer {

Decision think(const Snapshot &snap);

namespace // anonymous namespace
{
// TODO: investigate how to export this
// Decision attack(const Snapshot &snap);
// Decision inventory(const Snapshot &snap);
// Decision tourist(const Snapshot &snap);
} // namespace

}; // namespace controller::brain::computer
