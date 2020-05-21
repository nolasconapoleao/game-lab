//
// Created by nolasco on 10/05/20.
//

#pragma once

#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

#include "characters/Character.h"

/**
 * @brief Room has an inventory of "dropped" items.csv, a list of npcs and linked rooms.
 */
class Room {
public:
  Room(const std::string &name, const std::string &description) : name(name), description(description) {
  }

  Room &add(const Character &npc) {
    npcs.emplace_back(npc);
    return *this;
  }

  Room &add(const std::shared_ptr<BaseItem> &item, uint quantity = 1) {
    inventory.addItem(item, quantity);
    return *this;
  }

  Room &addLink(const uint &adjacentRoom) {
    adjacentRooms.insert(adjacentRoom);
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &os, const Room &room);

  std::string name;
  std::string description;
  Inventory inventory;
  std::set<uint> adjacentRooms;
  std::vector<Character> npcs;
};
