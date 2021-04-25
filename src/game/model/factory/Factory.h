//
// Created by nolasco on 16/06/20.
//

#pragma once

#include "interface/model/IFactory.h"

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
class Factory : public IFactory {
public:
  Factory() = delete;
  /**
   * @brief Constructor.
   * @param world game entity database.
   * @param entityCounter number of starting entities
   * @param entityCounter number of starting entities
   */
  explicit Factory(const std::shared_ptr<World> &world);
  /// @copydoc IFactory::createCharacter()
  CharacterId createCharacter(ThreatLevel threat, AttackType weaponAffinity = AttackType::UNDEFINED,
                              Race race = Race::UNDEFINED, Occupation occupation = Occupation::UNDEFINED) override;
  /// @copydoc IFactory::createEquipment()
  [[maybe_unused]] ItemId createEquipment(EquipmentType type = EquipmentType::UNDEFINED) override;
  /// @copydoc IFactory::createStaff()
  ItemId createStaff(StaffType type = StaffType::UNDEFINED) override;
  /// @copydoc IFactory::createWeapon()
  ItemId createWeapon(WeaponType type = WeaponType::UNDEFINED) override;
  /// @copydoc IFactory::createEquippable()
  ItemId createEquippable(EquippableType type = EquippableType::UNDEFINED) override;
  /// @copydoc IFactory::createConsumable()
  ItemId createConsumable(ConsumableType type = ConsumableType::UNDEFINED, Quantity quantity = 0) override;
  /// @copydoc IFactory::createConnector()
  LocationId createConnector(ConnectorType type = ConnectorType::UNDEFINED) override;
  /// @copydoc IFactory::createBuilding()
  LocationId createBuilding(BuildingType type = BuildingType::UNDEFINED) override;
  /// @copydoc IFactory::createLocation()
  LocationId createLocation(ExteriorType type = ExteriorType::UNDEFINED) override;
  /// @copydoc IFactory::createStructure()
  StructureId createStructure(StructureType type = StructureType::UNDEFINED) override;

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
};

} // namespace model
