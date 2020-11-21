//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <memory>

#include "datatypes/GameTypes.h"
#include "datatypes/entity-aux/AttackType.h"
#include "datatypes/entity-aux/BuildingType.h"
#include "datatypes/entity-aux/ConsumableType.h"
#include "datatypes/entity-aux/EquippableType.h"
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
  Quantity floors = 0;
};

namespace model {

// Forward declaration
class World;

class Factory {
public:
  explicit Factory(const std::shared_ptr<World> &world);
  CharacterId createCharacter(ThreatLevel threat, AttackType weaponAffinity = AttackType::UNDEFINED,
                              Race race = Race::UNDEFINED, Occupation type = Occupation::UNDEFINED);
  [[maybe_unused]] ItemId createEquipment(EquipmentType type = EquipmentType::UNDEFINED);
  ItemId createStaff(StaffType type = StaffType::UNDEFINED);
  ItemId createWeapon(WeaponType type = WeaponType::UNDEFINED);
  ItemId createEquippable(EquippableType type = EquippableType::UNDEFINED);
  ItemId createConsumable(ConsumableType type = ConsumableType::UNDEFINED, Quantity quantity = 1);
  LocationId createConnector(ConnectorType type = ConnectorType::UNDEFINED);
  LocationId createBuilding(BuildingType type = BuildingType::UNDEFINED);
  LocationId createLocation(ExteriorType type = ExteriorType::UNDEFINED);
  StructureId createStructure(StructureType type = StructureType::UNDEFINED);
  static Stats growStats(ThreatLevel level, Stats stats);

private:
  Stats characterStats(Info info, ThreatLevel threat);
  constexpr Stats rampupByOccupation(Occupation occupation, Stats stats);
  constexpr Stats rampupByClass(AttackType weaponAffinity, Stats stats);
  constexpr Stats rampupByRace(Race race, Stats stats);
  static Stats randomizeStats(Stats stats);

  Size structureSize(const StructureType type);
  constexpr Size connectorSize(ConnectorType type);
  constexpr BuildingSpecs buildingSpecs(BuildingType type);
  constexpr Size exteriorSize(ExteriorType type);

  constexpr ItemEffect equipmentSpecs(EquipmentType type);
  constexpr ItemEffect staffSpecs(StaffType type);
  constexpr ItemEffect weaponSpecs(WeaponType type);
  constexpr ItemEffect consumableSpecs(ConsumableType type);

  void initCharacterNames();
  void initLocationNames();
  void initTeamNames();

  std::shared_ptr<World> world;
  ResourceId entityCounter;
};

} // namespace model
