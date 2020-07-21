//
// Created by nolasco on 21/07/20.
//

#include "Factory.h"

#include "libs/random/Random.h"
#include "model/World.h"

namespace model {

Factory::Factory(const std::shared_ptr<World> &world) : world(world), entityCounter(0) {
}

} // namespace model
