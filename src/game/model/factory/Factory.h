//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <memory>

#include "datatypes/GameTypes.h"
#include "datatypes/entity/Info.h"
#include "datatypes/entity/Stats.h"
#include "datatypes/factory/AttackType.h"
#include "datatypes/factory/BuildingPrototype.h"
#include "datatypes/factory/CharacterPrototype.h"
#include "datatypes/factory/ConnectorPrototype.h"
#include "datatypes/factory/ConsumablePrototype.h"
#include "datatypes/factory/EquipmentPrototype.h"
#include "datatypes/factory/EventPrototype.h"
#include "datatypes/factory/ExteriorPrototype.h"
#include "datatypes/factory/QuestPrototype.h"
#include "datatypes/factory/Race.h"
#include "datatypes/factory/StaffPrototype.h"
#include "datatypes/factory/StructurePrototype.h"
#include "datatypes/factory/ThreatLevel.h"
#include "datatypes/factory/WeaponPrototype.h"

class World;

struct BuildingSpecs {
  Size size;
  Quantity floors;
};

namespace model {

// Forward declaration
class World;

class Factory {
public:
  Factory(const std::shared_ptr<World> &world);
  CharacterId createCharacter(const ThreatLevel threat, const AttackType weaponAffinity = AttackType::UNDEFINED,
                              const Race race = Race::UNDEFINED,
                              const CharacterPrototype type = CharacterPrototype::UNDEFINED);
  ItemId createEquipment(const EquipmentPrototype type = EquipmentPrototype::UNDEFINED);
  ItemId createStaff(const StaffPrototype type = StaffPrototype::UNDEFINED);
  ItemId createWeapon(const WeaponPrototype type = WeaponPrototype::UNDEFINED);
  ItemId createConsumable(const ConsumablePrototype type = ConsumablePrototype::UNDEFINED);
  LocationId createConnector(const ConnectorPrototype type = ConnectorPrototype::UNDEFINED);
  LocationId createBuilding(const BuildingPrototype type = BuildingPrototype::UNDEFINED);
  LocationId createLocation(const ExteriorPrototype type = ExteriorPrototype::UNDEFINED);
  StructureId createStructure(const StructurePrototype type = StructurePrototype::UNDEFINED);
  Stats growStats(ThreatLevel level, Stats stats);

private:
  Stats characterStats(const Info info, const ThreatLevel threat);
  Stats rampupByOccupation(const CharacterPrototype occupation, Stats stats);
  Stats rampupByClass(AttackType weaponAffinity, Stats stats);
  Stats rampupByRace(Race race, Stats stats);
  Stats randomizeStats(Stats stats);
  constexpr Stats minimalStats();

  Size structureSize(const StructurePrototype type);
  ResourceId entityCounter;
  std::shared_ptr<World> world;

  Size connectorSize(const ConnectorPrototype type);
  BuildingSpecs buildingSpecs(const BuildingPrototype type);
  Size exteriorSize(const ExteriorPrototype type);
};

} // namespace model
