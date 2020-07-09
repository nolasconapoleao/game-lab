//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <map>
#include <queue>

#include "../../../../../../../usr/lib/gcc/x86_64-w64-mingw32/9.2-win32/include/c++/set"
#include "model/entity/Character.h"
#include "model/entity/Item.h"
#include "model/entity/Location.h"
#include "model/entity/Structure.h"
#include "model/map/WorldMap.h"
#include "utils/graph/UndirectedGraph.h"

using ItemEntry = std::pair<ItemId, entity::Item>;
using CharacterEntry = std::pair<CharacterId, entity::Character>;
using StructureEntry = std::pair<StructureId, entity::Structure>;

class World {
public:
  static void changeFocusedCharacter();
  static void addCharacter(entity::Character character);
  static entity::Character &character(const CharacterId id);
  static void addItem(entity::Item item);
  static entity::Item &item(const ItemId id);
  static void addStructure(entity::Structure structure);
  static entity::Structure &structure(const StructureId id);
  static void addLocation(entity::Location location);
  static size_t numberOfLocations();
  static void linkLocations(const LocationId begin, const LocationId end);
  static entity::Location location(const LocationId id);

  static CharacterId activeCharacter;
  static LocationId activeLocation;

  static std::vector<ItemId> itemsOfCharacter(CharacterId characterId);
  static std::vector<ItemId> itemsInLocation(LocationId locationId);
  static std::vector<CharacterId> charactersInLocation(const LocationId locationId);
  static std::vector<StructureId> structuresInLocation(const LocationId locationId);
  static std::unordered_set<LocationId> adjcentLocations(LocationId locationId);
  static std::set<LocationId> activeLocations();
  static void updateCharacterQueue();

private:
  static std::map<ItemId, entity::Item> items;
  static std::map<CharacterId, entity::Character> characters;
  static std::map<StructureId, entity::Structure> structures;
  static std::priority_queue<std::pair<int, CharacterId>> characterQueue;
  static WorldMap worldMap;

  friend class Factory;
  friend class Controller;
};
