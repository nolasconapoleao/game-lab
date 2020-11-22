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

/// @brief Game entity finder.
class Lookup {
public:
  /**
   * @brief Constructor.
   * @param world game entity database.
   */
  explicit Lookup(std::shared_ptr<World> world);

  /**
   * @brief Returns list of items owned by character or located in location.
   * @param resourceId location of item.
   * @return list of items in position.
   */
  std::vector<ItemEntry> itemsIn(ResourceId resourceId);

  /**
   * @brief Returns list of consumables owned by character or located in location.
   * @param resourceId location of consumables.
   * @return list of consumables in position.
   */
  std::vector<ConsumableEntry> consumablesIn(ResourceId resourceId);

  /**
   * @brief Returns list of equippables owned by character or located in location.
   * @param resourceId location of equippable.
   * @return list of equippables in position.
   */
  std::vector<EquippableEntry> equippablesIn(ResourceId resourceId);

  /**
   * @brief Returns list of characters in location.
   * @param locationId location of character.
   * @return list of characters in position.
   */
  std::vector<CharacterEntry> charactersIn(LocationId locationId);

  /**
   * @brief Returns list of structures in location.
   * @param locationId location of structure.
   * @return list of structures in position.
   */
  std::vector<StructureEntry> structuresIn(LocationId locationId);

  /**
   * @brief Returns list of exterior neighbours to given location.
   * @param locationId location id to search.
   * @return list of neighbour exteriors.
   */
  std::vector<ExteriorEntry> neighbourExteriors(LocationId locationId);

  /**
   * @brief Returns list of building neighbours to given location.
   * @param locationId location id to search.
   * @return list of neighbour buildings.
   */
  std::vector<BuildingEntry> neighbourBuildings(LocationId locationId);

  /**
   * @brief Returns list of location neighbours to given location.
   * @param locationId location id to search.
   * @return list of neighbour locations.
   */
  std::vector<LocationEntry> neighbourLocations(LocationId locationId);

  /**
   * @brief Returns list of location that can reach given location.
   * @param locationId location id to search.
   * @return list of location exteriors.
   */
  std::vector<LocationEntry> neighboursEndingIn(LocationId locationId);

  /**
   * @brief Returns list of location that can be reached by given character.
   * @param characterId character id for search.
   * @return list of locations reachable by character.
   */
  [[maybe_unused]] std::vector<LocationEntry> closeByLocations(CharacterId characterId);

  /**
   * @brief Returns list of characters close to given character.
   * @param characterId character id for search.
   * @return list of characters close to character.
   */
  std::vector<CharacterEntry> closeByCharacters(CharacterId characterId);

  /**
   * @brief Returns list of structures close to given character.
   * @param characterId character id for search.
   * @return list of structures close to character.
   */
  std::vector<StructureEntry> closeByStructures(CharacterId characterId);

  /**
   * @brief Returns list of buildings close to given character.
   * @param characterId character id for search.
   * @return list of buildings close to character.
   */
  std::vector<BuildingEntry> closeByBuildings(CharacterId characterId);

  /**
   * @brief Returns list of exteriors close to given character.
   * @param characterId character id for search.
   * @return list of exteriors close to character.
   */
  std::vector<ExteriorEntry> closeByExteriors(CharacterId characterId);

  /**
   * @brief Returns character location.
   * @param characterId character id for search.
   * @return location entry for character.
   */
  LocationEntry whereIs(CharacterId characterId);

  /**
   * @brief Returns list of living and player controllable characters.
   * @return list of playable characters.
   */
  std::vector<CharacterEntry> playableCharacters();

  /**
   * @brief Returns Returns id for item of located in if the type matches the one provided.
   * @param resourceId location of item.
   * @param type consumable type for search.
   * @return id for consumable of queried type.
   */
  std::optional<ItemId> consumableTypeIn(ResourceId resourceId, ConsumableType type);

  /**
   * @brief Returns game entity type for provided id.
   * @param resourceId for search.
   * @return game entity type for provided id.
   */
  ResourceType type(ResourceId resourceId);

  /**
   * @brief Return writable entry to character with the provided id.
   * @param characterId character id to search.
   * @return character matching the provided id.
   */
  std::shared_ptr<entity::Character> character(CharacterId characterId);

  /**
   * @brief Return writable entry to item with the provided id.
   * @param itemId item id to search.
   * @return item matching the provided id.
   */
  std::shared_ptr<entity::Item> item(ItemId itemId);

  /**
   * @brief Return writable entry to location with the provided id.
   * @param locationId location id to search.
   * @return location matching the provided id.
   */
  std::shared_ptr<entity::Location> location(LocationId locationId);

  /**
   * Checks if character with provided id exists.
   * @param characterId character id for search.
   * @return true if character exists, false otherwise.
   */
  bool characterExists(CharacterId characterId);

private:
  std::shared_ptr<World> mWorld;
};

} // namespace model
