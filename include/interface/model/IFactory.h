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

namespace model {

// Forward declaration
class World;

/// @brief Interface for handler of game entity creation.
class IFactory {
public:
  /// @brief Default constructor.
  IFactory() = default;

  /**
   * @brief Constructor.
   * @param world game entity database.
   * @param entityCounter number of starting entities
   */
  IFactory(const std::shared_ptr<World> &world, const ResourceId entityCounter = 0)
      : mWorld(std::move(world))
      , entityCounter(entityCounter){};

  /**
   * @brief @brief Create character.
   * @param threat level for character.
   * @param weaponAffinity character weapon affinity.
   * @param race of character.
   * @param occupation of character.
   * @return Id for created character.
   */
  virtual CharacterId createCharacter(ThreatLevel threat, AttackType weaponAffinity = AttackType::UNDEFINED,
                                      Race race = Race::UNDEFINED, Occupation occupation = Occupation::UNDEFINED)
      = 0;

  /**
   * @brief Create equipment.
   * @param type of equipment.
   * @return Id for created equipment.
   */
  virtual ItemId createEquipment(EquipmentType type = EquipmentType::UNDEFINED) = 0;

  /**
   * @brief Create staff.
   * @param type of staff.
   * @return Id for created staff.
   */
  virtual ItemId createStaff(StaffType type = StaffType::UNDEFINED) = 0;

  /**
   * @brief Create weapon.
   * @param type of weapon.
   * @return Id for created weapon.
   */
  virtual ItemId createWeapon(WeaponType type = WeaponType::UNDEFINED) = 0;

  /**
   * @brief Create equippable.
   * @param type of equippable.
   * @return Id for created equippable.
   */
  virtual ItemId createEquippable(EquippableType type = EquippableType::UNDEFINED) = 0;

  /**
   * @brief Create consumable.
   * @param type of consumable.
   * @param quantity of consumable.
   * @return Id for created consumable.
   */
  virtual ItemId createConsumable(ConsumableType type = ConsumableType::UNDEFINED, Quantity quantity = 0) = 0;

  /**
   * @brief Create connector.
   * @param type of connector.
   * @return Id for created connector.
   */
  virtual LocationId createConnector(ConnectorType type = ConnectorType::UNDEFINED) = 0;

  /**
   * @brief Create building.
   * @param type of building.
   * @return Id for created building.
   */
  virtual LocationId createBuilding(BuildingType type = BuildingType::UNDEFINED) = 0;

  /**
   * @brief Create exterior.
   * @param type of exterior.
   * @return Id for created exterior.
   */
  virtual LocationId createLocation(ExteriorType type = ExteriorType::UNDEFINED) = 0;

  /**
   * @brief Create structure.
   * @param type of structure.
   * @return Id for created structure.
   */
  virtual StructureId createStructure(StructureType type = StructureType::UNDEFINED) = 0;

protected:
  /// @brief Database of game entities.
  std::shared_ptr<World> mWorld;
  /// @brief Current number of game entities.
  ResourceId entityCounter;
};

} // namespace model
