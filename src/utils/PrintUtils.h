//
// Created by nolasco on 16/05/20.
//

#pragma once

#include "characters/Character.h"
#include "common/Inventory.h"
#include "common/Match.h"
#include "graphics/OptionList.h"
#include "items/Item.h"
#include "rooms/Room.h"

template <class T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  for (const auto ii : v) {
    os << std::endl << ii;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const uint8_t &number);

std::ostream &operator<<(std::ostream &os, const Effect &effect);
std::ostream &operator<<(std::ostream &os, const UseType &useType);
std::ostream &operator<<(std::ostream &os, const Item &item);

std::string printFloor(const Entry &entry);
std::string printPocket(const Entry &entry);
std::string printShop(const Entry &entry);

std::string printPlayer(const Character &player);

std::ostream &operator<<(std::ostream &os, const Diplomacy &diplomacy);
std::ostream &operator<<(std::ostream &os, const Character &character);

std::ostream &operator<<(std::ostream &os, const Room &room);

std::ostream &operator<<(std::ostream &os, const AttackResult &room);
