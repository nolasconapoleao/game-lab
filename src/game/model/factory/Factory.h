//
// Created by nolasco on 16/06/20.
//

#pragma once

#include "game/model/World.h"
#include "game/model/entity/include/Occupation.h"
#include "game/model/factory/include/ItemPrototype.h"
#include "game/model/factory/include/LocationPrototype.h"
#include "game/model/factory/include/StructurePrototype.h"

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
