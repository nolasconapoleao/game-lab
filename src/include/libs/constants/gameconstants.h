//
// Created by nolasco on 30/06/20.
//

#pragma once

#include "datatypes/GameTypes.h"
#include "datatypes/controller/Action.h"
#include "datatypes/controller/PlayerState.h"
#include "datatypes/entity-aux/ItemEffect.h"
#include "datatypes/entity-aux/Stats.h"
#include "datatypes/factory/CreationSpecs.h"
#include "datatypes/factory/ThreatLevel.h"

namespace gameconstants {

constexpr Stats minimalStats();
constexpr CreationSpecs creationSpecs(ThreatLevel level);
constexpr PlayerState stateInfo(Action action);

}; // namespace gameconstants

#include "gameconstants.cpp"