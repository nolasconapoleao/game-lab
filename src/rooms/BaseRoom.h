//
// Created by nolasco on 10/05/20.
//

#pragma once

#include <memory>
#include <ostream>
#include <string>
#include <vector>

#include "characters/BaseCharacter.h"

class BaseRoom {
public:
  BaseRoom(const std::string &name, const std::string &description) : name(name), description(description) {
  }

  void setAdjacentRooms(const std::vector<std::shared_ptr<BaseRoom>> &adjacentRooms) {
    BaseRoom::adjacentRooms = adjacentRooms;
  }

  friend std::ostream &operator<<(std::ostream &os, const BaseRoom &room);

  std::string description;
  std::string name;
  Inventory inventory;
  std::vector<std::shared_ptr<BaseRoom>> adjacentRooms;
  std::vector<std::shared_ptr<BaseCharacter>> npcs;
};
