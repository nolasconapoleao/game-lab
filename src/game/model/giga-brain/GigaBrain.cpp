//
// Created by nolasco on 21/07/20.
//

#include "GigaBrain.h"

#include "model/World.h"

namespace model {

GigaBrain::GigaBrain(const std::shared_ptr<model::Handler> &handler, const std::shared_ptr<model::Lookup> &lookup)
    : handler(handler), lookup(lookup) {
}

} // namespace model
