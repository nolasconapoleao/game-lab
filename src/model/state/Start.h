//
// Created by nolasco on 11/06/20.
//

#pragma once

#include "controller/factory/Factory.h"
#include "model/state/include/Caterpillar.h"

namespace model::state {

class Start : public Caterpillar {
public:
  Start();
  void execute() override;

protected:
  void fillStateOption() override;
  Factory mFactory;
};

} // namespace model::state
