//
// Created by nolasco on 11/06/20.
//

#pragma once

#include "game/controller/state/include/Caterpillar.h"
#include "game/model/factory/Factory.h"

namespace controller {

class Start : public Caterpillar {
public:
  Start();
  void execute() override;

protected:
  void fillStateOption() override;
  Factory mFactory;
};

} // namespace controller
