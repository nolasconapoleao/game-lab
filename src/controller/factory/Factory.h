//
// Created by nolasco on 16/06/20.
//

#pragma once

#include "controller/factory/include/ItemPrototype.h"
#include "controller/factory/include/LocationPrototype.h"
#include "controller/factory/include/StructurePrototype.h"
#include "model/World.h"
#include "model/entity/include/Occupation.h"

class World;

class Factory {
public:
  Factory();
  void generateCharacter();
  void createCharacter(const Occupation type);
  void createPlayer(const LocationId locationId);
  void generateItem(const UseType type);
  void createItem(const ItemPrototype type);
  void generateStructure();
  void createStructure(const StructurePrototype type);
  void generateLocation(const LocationCategory type);
  void createLocation(const LocationPrototype type);
  void fillLocation(LocationId locationId);
  void fillInventory(CharacterId characterId);
  void createWorld();

private:
  std::vector<LocationPrototype> interiorPool;
  std::vector<LocationPrototype> exteriorPool;
  std::vector<LocationPrototype> connectorPool;

  std::vector<Occupation> occupationPool;

  std::vector<ItemPrototype> equipPool;
  std::vector<ItemPrototype> singleUsePool;

  std::vector<StructurePrototype> structurePool;
};
