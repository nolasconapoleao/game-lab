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

/// @brief Building information structure.
struct BuildingSpecs {
  /// @brief Size of building.
  Size size;
  /// @brief Number of floors in building.
  Quantity floors = 0;
};

namespace model {

// Forward declaration
class World;

/// @brief Handles game entity creation.
class Factory {
public:
  /**
   * @brief Constructor.
   * @param world game entity database.
   */
  explicit Factory(const std::shared_ptr<World> &world);

  /**
   * @brief @brief Create character.
   * @param threat level for character.
   * @param weaponAffinity character weapon affinity.
   * @param race of character.
   * @param occupation of character.
   * @return Id for created character.
   */
  CharacterId createCharacter(ThreatLevel threat, AttackType weaponAffinity = AttackType::UNDEFINED,
                              Race race = Race::UNDEFINED, Occupation occupation = Occupation::UNDEFINED);

  /**
   * @brief Create equipment.
   * @param type of equipment.
   * @return Id for created equipment.
   */
  [[maybe_unused]] ItemId createEquipment(EquipmentType type = EquipmentType::UNDEFINED);

  /**
   * @brief Create staff.
   * @param type of staff.
   * @return Id for created staff.
   */
  ItemId createStaff(StaffType type = StaffType::UNDEFINED);

  /**
   * @brief Create weapon.
   * @param type of weapon.
   * @return Id for created weapon.
   */
  ItemId createWeapon(WeaponType type = WeaponType::UNDEFINED);

  /**
   * @brief Create equippable.
   * @param type of equippable.
   * @return Id for created equippable.
   */
  ItemId createEquippable(EquippableType type = EquippableType::UNDEFINED);

  /**
   * @brief Create consumable.
   * @param type of consumable.
   * @param quantity of consumable.
   * @return Id for created consumable.
   */
  ItemId createConsumable(ConsumableType type = ConsumableType::UNDEFINED, Quantity quantity = 1);

  /**
   * @brief Create connector.
   * @param type of connector.
   * @return Id for created connector.
   */
  LocationId createConnector(ConnectorType type = ConnectorType::UNDEFINED);

  /**
   * @brief Create building.
   * @param type of building.
   * @return Id for created building.
   */
  LocationId createBuilding(BuildingType type = BuildingType::UNDEFINED);

  /**
   * @brief Create exterior.
   * @param type of exterior.
   * @return Id for created exterior.
   */
  LocationId createLocation(ExteriorType type = ExteriorType::UNDEFINED);

  /**
   * @brief Create structure.
   * @param type of structure.
   * @return Id for created structure.
   */
  StructureId createStructure(StructureType type = StructureType::UNDEFINED);

private:
  /**
   * @brief Grow game entity stats.
   * @param level threat level for game entity.
   * @param stats to grow.
   * @return stats after modification.
   */
  static Stats growStats(ThreatLevel level, Stats stats);
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

  std::shared_ptr<World> mWorld;
  ResourceId entityCounter;
};

} // namespace model
