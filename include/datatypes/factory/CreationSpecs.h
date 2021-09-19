//
// Created by nolasco on 12/06/20.
//

#pragma once

#include "datatypes/GameTypes.h"

/// @brief Parameters for creation of entity objects.
struct CreationSpecs {
  /// @brief Multiplier for the minimal stats.
  Quantity stats_multiplier = 0;
  /// @brief Number of characters in location.
  Quantity num_characters = 0;
  /// @brief Number of consumables owned by character.
  Quantity num_character_consumables = 0;
  /// @brief Number of equippables owned by character.
  Quantity num_character_equippables = 0;
  /// @brief Number of consumables in exterior location.
  Quantity num_exterior_consumables = 0;
  /// @brief Number of equippables in exterior location.
  Quantity num_exterior_equippables = 0;
  /// @brief Number of neighbour exterior locations.
  Quantity num_exteriors = 0;
  /// @brief Number of buildings in exterior location.
  Quantity num_buildings = 0;
  /// @brief Number of structures in exterior location.
  Quantity num_structures = 0;
};
