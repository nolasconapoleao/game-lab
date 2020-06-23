//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "model/entity/Character.h"
#include "model/entity/Item.h"
#include "model/entity/Location.h"
#include "model/entity/Structure.h"
#include "model/map/WorldMap.h"
#include "utils/graph/UndirectedGraph.h"

class World {
public:
  static void changeFocusedCharacter();
  static void changeFocusedLocation();
  static void addCharacter(entity::Character character);
  static entity::Character character(const CharacterId id);
  static void addItem(entity::Item item);
  static entity::Item item(const ItemId id);
  static void addStructure(entity::Structure structure);
  static entity::Structure structure(const StructureId id);
  static void addLocation(const LocationId locationId, entity::Location location);
  static entity::Location location(const LocationId id);

  static CharacterId activeCharacter;
  static LocationId activeLocation;
  // FIXME: printScene is const but uses non const methods
  friend std::string printScene(World &world);

private:
  std::vector<entity::Item> itemsOfCharacter(CharacterId characterId);
  std::vector<entity::Item> itemsInLocation(LocationId locationId);
  std::vector<entity::Character> charactersInLocation(const LocationId locationId);
  std::vector<entity::Structure> structuresInLocation(const LocationId locationId);
  std::vector<entity::Location> adjcentLocations(const LocationId locationId);
  std::vector<entity::Location> activeLocations();

  // TODO: [nn] Exchange std::vector<T> by a more suitable resource container
  static std::vector<entity::Item> items;
  static std::vector<entity::Character> characters;
  static std::vector<entity::Structure> structures;
  static WorldMap worldMap;

  friend class EntityFactory;
  friend class EntityHandler;
};
