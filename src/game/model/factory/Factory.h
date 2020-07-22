//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <memory>

#include "datatypes/GameTypes.h"
#include "datatypes/entity-aux/AttackType.h"
#include "datatypes/entity-aux/Info.h"
#include "datatypes/entity-aux/Occupation.h"
#include "datatypes/entity-aux/Race.h"
#include "datatypes/entity-aux/Stats.h"
#include "datatypes/factory/BuildingPrototype.h"
#include "datatypes/factory/ConnectorPrototype.h"
#include "datatypes/factory/ConsumablePrototype.h"
#include "datatypes/factory/EquipmentPrototype.h"
#include "datatypes/factory/EventPrototype.h"
#include "datatypes/factory/ExteriorPrototype.h"
#include "datatypes/factory/QuestPrototype.h"
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
  CharacterId createCharacter(const ThreatLevel threat, AttackType weaponAffinity = AttackType::UNDEFINED,
                              Race race = Race::UNDEFINED, Occupation type = Occupation::UNDEFINED);
  ItemId createEquipment(EquipmentPrototype type = EquipmentPrototype::UNDEFINED);
  ItemId createStaff(StaffPrototype type = StaffPrototype::UNDEFINED);
  ItemId createWeapon(WeaponPrototype type = WeaponPrototype::UNDEFINED);
  ItemId createConsumable(ConsumablePrototype type = ConsumablePrototype::UNDEFINED, const Quantity quantity = 1);
  LocationId createConnector(ConnectorPrototype type = ConnectorPrototype::UNDEFINED);
  LocationId createBuilding(BuildingPrototype type = BuildingPrototype::UNDEFINED);
  LocationId createLocation(ExteriorPrototype type = ExteriorPrototype::UNDEFINED);
  StructureId createStructure(StructurePrototype type = StructurePrototype::UNDEFINED);
  Stats growStats(ThreatLevel level, Stats stats);

private:
  Stats characterStats(const Info info, const ThreatLevel threat);
  Stats rampupByOccupation(const Occupation occupation, Stats stats);
  Stats rampupByClass(const AttackType weaponAffinity, Stats stats);
  Stats rampupByRace(const Race race, Stats stats);
  Stats randomizeStats(Stats stats);
  constexpr Stats minimalStats();

  Size structureSize(const StructurePrototype type);
  ResourceId entityCounter;
  std::shared_ptr<World> world;

  Size connectorSize(const ConnectorPrototype type);
  BuildingSpecs buildingSpecs(const BuildingPrototype type);
  Size exteriorSize(const ExteriorPrototype type);

  ItemEffect equipmentSpecs(const EquipmentPrototype type);
  ItemEffect staffSpecs(const StaffPrototype type);
  ItemEffect weaponSpecs(const WeaponPrototype type);
  ItemEffect consumableSpecs(const ConsumablePrototype type);

  void initCharacterNames();
  void initLocationNames();
  void initTeamNames();
};

} // namespace model
