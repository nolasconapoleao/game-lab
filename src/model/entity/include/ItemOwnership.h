//
// Created by nolasco on 19/06/20.
//

#pragma once

#include "common/GameTypes.h"

struct ItemOwnership {
  ResourceId resourceId;
  OwnerType ownerType;
  bool equipped = false;
};