//
// Created by nolasco on 11/06/20.
//

#pragma once

#include "interface/state/Caterpillar.h"
#include "model/factory/Factory.h"

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
