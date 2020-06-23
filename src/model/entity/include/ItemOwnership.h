//
// Created by nolasco on 19/06/20.
//

#pragma once

struct ItemOwnership {
  ResourceId resourceId;
  OwnerType ownerType;
  bool equipped = false;
};