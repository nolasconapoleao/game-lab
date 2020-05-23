//
// Created by nolasco on 16/05/20.
//

#pragma once

#include "characters/Character.h"
#include "common/Inventory.h"
#include "game/OptionList.h"
#include "items/Item.h"
#include "rooms/Room.h"

std::ostream &operator<<(std::ostream &os, const uint8_t &number);

std::ostream &operator<<(std::ostream &os, const Effect &property);

std::ostream &operator<<(std::ostream &os, const Item &item);

std::ostream &operator<<(std::ostream &os, const Inventory &inventory);

std::ostream &operator<<(std::ostream &os, const Character &character);

std::ostream &operator<<(std::ostream &os, const Room &room);
