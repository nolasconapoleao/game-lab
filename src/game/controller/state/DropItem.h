//
// Created by nolasco on 18/07/20.
//

#pragma once

#include "game/controller/state/include/Caterpillar.h"

namespace controller {

class DropItem : public Caterpillar {
public:
  DropItem();
  void execute() override;

protected:
  void fillStateOption() override;
  Handler controller;
};

} // namespace controller
