//
// Created by nolasco on 07/06/20.
//

#include "Character.h"

namespace entity {

Character::Character(const std::string &name, const Stats &baseStats, const ItemEffect &tempStats, const Info &info)
    : Entity(name), baseStats(baseStats), tempStats(tempStats), info(info) {
}

} // namespace entity
