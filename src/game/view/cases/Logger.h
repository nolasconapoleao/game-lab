//
// Created by nolasco on 16/07/20.
//

#pragma once
#include "datatypes/GameTypes.h"
#include "datatypes/logger/AttackResult.h"
#include "view/stream/StreamConverter.h"

void logBattle(const CharacterId attackerId, const CharacterId attackedId, const LocationId battleGroundId,
               const AttackResult result);
