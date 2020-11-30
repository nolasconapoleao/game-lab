//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <memory>
#include <vector>

#include "datatypes/lookup/ResourceEntry.h"

namespace model {

// Forward declaration
class World;

/// @brief Interface for game entity finder.
class ILookup {
public:
  /// @brief Default constructor.
  ILookup() = default;

  /**
   * @brief Constructor.
   * @param world game entity database.
   */
  explicit ILookup(const std::shared_ptr<World> &world) : mWorld(std::move(world)){};

  /**
   * @brief Returns list of items owned by character or located in location.
   * @param resourceId location of item.
   * @return list of items in position.
   */
  virtual std::vector<DbEntry<entity::Item>> itemsIn(ResourceId resourceId) = 0;

  /**
   * @brief Returns list of consumables owned by character or located in location.
   * @param resourceId location of consumables.
   * @return list of consumables in position.
   */
  virtual std::vector<DbEntry<entity::Consumable>> consumablesIn(ResourceId resourceId) = 0;

  /**
   * @brief Returns list of equippables owned by character or located in location.
   * @param resourceId location of equippable.
   * @return list of equippables in position.
   */
  virtual std::vector<DbEntry<entity::Equippable>> equippablesIn(ResourceId resourceId) = 0;

  /**
   * @brief Returns list of characters in location.
   * @param locationId location of character.
   * @return list of characters in position.
   */
  virtual std::vector<DbEntry<entity::Character>> charactersIn(LocationId locationId) = 0;

  /**
   * @brief Returns list of structures in location.
   * @param locationId location of structure.
   * @return list of structures in position.
   */
  virtual std::vector<DbEntry<entity::Structure>> structuresIn(LocationId locationId) = 0;

  /**
   * @brief Returns list of exterior neighbours to given location.
   * @param locationId location id to search.
   * @return list of neighbour exteriors.
   */
  virtual std::vector<DbEntry<entity::Exterior>> neighbourExteriors(LocationId locationId) = 0;

  /**
   * @brief Returns list of building neighbours to given location.
   * @param locationId location id to search.
   * @return list of neighbour buildings.
   */
  virtual std::vector<DbEntry<entity::Building>> neighbourBuildings(LocationId locationId) = 0;

  /**
   * @brief Returns list of location neighbours to given location.
   * @param locationId location id to search.
   * @return list of neighbour locations.
   */
  virtual std::vector<DbEntry<entity::Location>> neighbourLocations(LocationId locationId) = 0;

  /**
   * @brief Returns list of location that can reach given location.
   * @param locationId location id to search.
   * @return list of location exteriors.
   */
  virtual std::vector<DbEntry<entity::Location>> neighboursEndingIn(LocationId locationId) = 0;

  /**
   * @brief Returns list of location that can be reached by given character.
   * @param characterId character id for search.
   * @return list of locations reachable by character.
   */
  virtual std::vector<DbEntry<entity::Location>> closeByLocations(CharacterId characterId) = 0;

  /**
   * @brief Returns list of characters close to given character.
   * @param characterId character id for search.
   * @return list of characters close to character.
   */
  virtual std::vector<DbEntry<entity::Character>> closeByCharacters(CharacterId characterId) = 0;

  /**
   * @brief Returns list of structures close to given character.
   * @param characterId character id for search.
   * @return list of structures close to character.
   */
  virtual std::vector<DbEntry<entity::Structure>> closeByStructures(CharacterId characterId) = 0;

  /**
   * @brief Returns list of buildings close to given character.
   * @param characterId character id for search.
   * @return list of buildings close to character.
   */
  virtual std::vector<DbEntry<entity::Building>> closeByBuildings(CharacterId characterId) = 0;

  /**
   * @brief Returns list of exteriors close to given character.
   * @param characterId character id for search.
   * @return list of exteriors close to character.
   */
  virtual std::vector<DbEntry<entity::Exterior>> closeByExteriors(CharacterId characterId) = 0;

  /**
   * @brief Returns character location.
   * @param characterId character id for search.
   * @return location entry for character.
   */
  virtual DbEntry<entity::Location> whereIs(CharacterId characterId) = 0;

  /**
   * @brief Returns list of living and player controllable characters.
   * @return list of playable characters.
   */
  virtual std::vector<DbEntry<entity::Character>> playableCharacters() = 0;

  /**
   * @brief Returns Returns id for item of located in if the action matches the one provided.
   * @param resourceId location of item.
   * @param type consumable action for search.
   * @return id for consumable of queried action.
   */
  virtual std::optional<ItemId> consumableTypeIn(ResourceId resourceId, ConsumableType type) = 0;

  /**
   * @brief Returns game entity action for provided id.
   * @param resourceId for search.
   * @return game entity action for provided id.
   */
  virtual ResourceType type(ResourceId resourceId) = 0;

  /**
   * @brief Return writable entry to character with the provided id.
   * @param characterId character id to search.
   * @return character matching the provided id.
   */
  virtual std::shared_ptr<entity::Character> character(CharacterId characterId) = 0;

  /**
   * @brief Return writable entry to item with the provided id.
   * @param itemId item id to search.
   * @return item matching the provided id.
   */
  virtual std::shared_ptr<entity::Item> item(ItemId itemId) = 0;

  /**
   * @brief Return writable entry to location with the provided id.
   * @param locationId location id to search.
   * @return location matching the provided id.
   */
  virtual std::shared_ptr<entity::Location> location(LocationId locationId) = 0;

  /**
   * Checks if character with provided id exists.
   * @param characterId character id for search.
   * @return true if character exists, false otherwise.
   */
  virtual bool characterExists(CharacterId characterId) = 0;

protected:
  /// @brief Database of game entities.
  std::shared_ptr<World> mWorld;
};

} // namespace model
