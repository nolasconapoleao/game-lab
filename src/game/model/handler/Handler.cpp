//
// Created by nolasco on 21/07/20.
//

#include "Handler.h"

#include "model/World.h"

namespace model {

Handler::Handler(const std::shared_ptr<World> &world, const std::shared_ptr<Factory> &factory,
                 const std::shared_ptr<Cleaner> &cleaner)
    : world(world), factory(factory), cleaner(cleaner) {
}

} // namespace model
