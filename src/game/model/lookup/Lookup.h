//
// Created by nolasco on 07/06/20.
//

#pragma once

#include "interface/model/ILookup.h"

namespace model {

// Forward declaration
class World;

/// @brief Game entity finder.
class Lookup : public ILookup {
public:
  /**
   * @brief Constructor.
   * @param world game entity database.
   */
  explicit Lookup(std::shared_ptr<World> world);

  /// @copydoc ILookup::itemsIn()
  std::vector<DbEntry<entity::Item>> itemsIn(ResourceId resourceId) override;
  /// @copydoc ILookup::consumablesIn()
  std::vector<DbEntry<entity::Consumable>> consumablesIn(ResourceId resourceId) override;
  /// @copydoc ILookup::equippablesIn()
  std::vector<DbEntry<entity::Equippable>> equippablesIn(ResourceId resourceId) override;
  /// @copydoc ILookup::charactersIn()
  std::vector<DbEntry<entity::Character>> charactersIn(LocationId locationId) override;
  /// @copydoc ILookup::structuresIn()
  std::vector<DbEntry<entity::Structure>> structuresIn(LocationId locationId) override;
  /// @copydoc ILookup::neighbourExteriors()
  std::vector<DbEntry<entity::Exterior>> neighbourExteriors(LocationId locationId) override;
  /// @copydoc ILookup::neighbourBuildings()
  std::vector<DbEntry<entity::Building>> neighbourBuildings(LocationId locationId) override;
  /// @copydoc ILookup::neighbourLocations()
  std::vector<DbEntry<entity::Location>> neighbourLocations(LocationId locationId) override;
  /// @copydoc ILookup::neighboursEndingIn()
  std::vector<DbEntry<entity::Location>> neighboursEndingIn(LocationId locationId) override;
  /// @copydoc ILookup::closeByLocations()
  [[maybe_unused]] std::vector<DbEntry<entity::Location>> closeByLocations(CharacterId characterId) override;
  /// @copydoc ILookup::closeByCharacters()
  std::vector<DbEntry<entity::Character>> closeByCharacters(CharacterId characterId) override;
  /// @copydoc ILookup::closeByStructures()
  std::vector<DbEntry<entity::Structure>> closeByStructures(CharacterId characterId) override;
  /// @copydoc ILookup::closeByBuildings()
  std::vector<DbEntry<entity::Building>> closeByBuildings(CharacterId characterId) override;
  /// @copydoc ILookup::closeByExteriors()
  std::vector<DbEntry<entity::Exterior>> closeByExteriors(CharacterId characterId) override;
  /// @copydoc ILookup::whereIs()
  DbEntry<entity::Location> whereIs(CharacterId characterId) override;
  /// @copydoc ILookup::playableCharacters()
  std::vector<DbEntry<entity::Character>> playableCharacters() override;
  /// @copydoc ILookup::consumableTypeIn()
  std::optional<ItemId> consumableTypeIn(ResourceId resourceId, ConsumableType type) override;
  /// @copydoc ILookup::type()
  ResourceType type(ResourceId resourceId) override;
  /// @copydoc ILookup::character()
  std::shared_ptr<entity::Character> character(CharacterId characterId) override;
  /// @copydoc ILookup::item()
  std::shared_ptr<entity::Item> item(ItemId itemId) override;
  /// @copydoc ILookup::location()
  std::shared_ptr<entity::Location> location(LocationId locationId) override;
  /// @copydoc ILookup::characterExists()
  bool characterExists(CharacterId characterId) override;

private:
  std::shared_ptr<World> mWorld;
};

} // namespace model
