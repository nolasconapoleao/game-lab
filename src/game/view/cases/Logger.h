//
// Created by nolasco on 16/07/20.
//

#pragma once

#include "game/model/handler/include/AttackResult.h"
#include "include/datatypes/GameTypes.h"

void logBattle(const CharacterId attackerId, const CharacterId attackedId, const LocationId battleGroundId,
               const AttackResult result);
