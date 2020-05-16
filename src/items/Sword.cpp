//
// Created by nolasco on 16/05/20.
//

#include "Sword.h"
Sword::Sword()
    : BaseItem("Sword", CharacterProperty::attack, UseType::equipable, 2),
      description("A rusty sword, gives 2 attack points to beholder") {
}
