//
// Created by nolasco on 07/07/20.
//

#pragma once

#include "interface/state/Caterpillar.h"

namespace controller {

class UseItem : public Caterpillar {
public:
  UseItem();
  void execute() override;

protected:
  void fillStateOption() override;
  Handler controller;
};

} // namespace controller
