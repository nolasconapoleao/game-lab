//
// Created by nolasco on 21/06/20.
//

#pragma once

#include "EntityHandler.h"
#include "model/entity/Character.h"

class HiveMind {
public:
  // TODO: [nn] Implement this method
  void strategize(entity::Character &character);

private:
  EntityHandler entityHandler;
};
