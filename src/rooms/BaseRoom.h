//
// Created by nolasco on 10/05/20.
//

#pragma once

#include <memory>
#include <ostream>
#include <string>
#include <vector>

#include "characters/BaseCharacter.h"

/**
 * @brief Base room, all derived rooms have an inventory of "dropped" items, a list of npcs and linked rooms.
 */
class BaseRoom {
public:
  BaseRoom(const std::string &name, const std::string &description) : name(name), description(description) {
  }

  BaseRoom &add(const std::shared_ptr<BaseCharacter> &npc) {
    npcs.emplace_back(npc);
    return *this;
  }

  BaseRoom &add(const std::shared_ptr<BaseItem> &item, uint quantity = 1) {
    inventory.addItem(item, quantity);
    return *this;
  }

  BaseRoom &addLink(const uint &adjacentRoom) {
    adjacentRooms.emplace_back(adjacentRoom);
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &os, const BaseRoom &room);

  std::string name;
  std::string description;
  Inventory inventory;
  std::vector<uint> adjacentRooms;
  std::vector<std::shared_ptr<BaseCharacter>> npcs;
};
