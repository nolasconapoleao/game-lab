//
// Created by nolasco on 07/07/20.
//

#pragma once

#include "model/state/include/Caterpillar.h"

namespace model::state {

class UseItem : public Caterpillar {
public:
  UseItem();
  void execute() override;

protected:
  void fillStateOption() override;
  Controller controller;
};

} // namespace model::state