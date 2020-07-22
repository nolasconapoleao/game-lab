//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <memory>

#include "datatypes/GameTypes.h"
#include "datatypes/entity-aux/AttackType.h"
#include "datatypes/entity-aux/BuildingType.h"
#include "datatypes/entity-aux/ConsumableType.h"
#include "datatypes/entity-aux/EventType.h"
#include "datatypes/entity-aux/Info.h"
#include "datatypes/entity-aux/Occupation.h"
#include "datatypes/entity-aux/QuestType.h"
#include "datatypes/entity-aux/Race.h"
#include "datatypes/entity-aux/Stats.h"
#include "datatypes/entity-aux/StructureType.h"
#include "datatypes/factory/ConnectorType.h"
#include "datatypes/factory/EquipmentType.h"
#include "datatypes/factory/ExteriorType.h"
#include "datatypes/factory/StaffType.h"
#include "datatypes/factory/ThreatLevel.h"
#include "datatypes/factory/WeaponType.h"

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
  ItemId createEquipment(EquipmentType type = EquipmentType::UNDEFINED);
  ItemId createStaff(StaffType type = StaffType::UNDEFINED);
  ItemId createWeapon(WeaponType type = WeaponType::UNDEFINED);
  ItemId createConsumable(ConsumableType type = ConsumableType::UNDEFINED, const Quantity quantity = 1);
  LocationId createConnector(ConnectorType type = ConnectorType::UNDEFINED);
  LocationId createBuilding(BuildingType type = BuildingType::UNDEFINED);
  LocationId createLocation(ExteriorType type = ExteriorType::UNDEFINED);
  StructureId createStructure(StructureType type = StructureType::UNDEFINED);
  Stats growStats(ThreatLevel level, Stats stats);

private:
  Stats characterStats(const Info info, const ThreatLevel threat);
  Stats rampupByOccupation(const Occupation occupation, Stats stats);
  Stats rampupByClass(const AttackType weaponAffinity, Stats stats);
  Stats rampupByRace(const Race race, Stats stats);
  Stats randomizeStats(Stats stats);
  constexpr Stats minimalStats();

  Size structureSize(const StructureType type);
  ResourceId entityCounter;
  std::shared_ptr<World> world;

  Size connectorSize(const ConnectorType type);
  BuildingSpecs buildingSpecs(const BuildingType type);
  Size exteriorSize(const ExteriorType type);

  ItemEffect equipmentSpecs(const EquipmentType type);
  ItemEffect staffSpecs(const StaffType type);
  ItemEffect weaponSpecs(const WeaponType type);
  ItemEffect consumableSpecs(const ConsumableType type);

  void initCharacterNames();
  void initLocationNames();
  void initTeamNames();
};

} // namespace model
