//
// Created by nolasco on 11/05/20.
//

#include "Potion.h"

Potion::Potion()
    : BaseItem("Potion", CharacterProperty::currentHealth, UseType::consumable, 3u),
      description("A basic potion, recovers 3 points health") {
}
