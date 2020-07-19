//
// Created by nolasco on 11/06/20.
//

#pragma once

#include "interface/state/Caterpillar.h"

namespace controller {

class IdleWorld : public Caterpillar {
public:
  IdleWorld();
  void execute() override;

protected:
  void fillStateOption() override;
  void strategize(const CharacterId characterId);
  Handler controller;
};

} // namespace controller
