//
// Created by nolasco on 07/06/20.
//

#pragma once

#include <string>

// Entity
using Number = uint16_t;
using Quantity = uint8_t;

/// @brief Size of location.
struct Size {
  /// @brief Width of entity.
  uint8_t width = 0;
  /// @brief Height of entity.
  uint8_t height = 0;
};
using Distance = uint8_t;

// Database
using EntityId = uint16_t;
using CharacterId = uint16_t;
using ItemId = uint16_t;
using LocationId = uint16_t;
using ResourceId = uint16_t;
using StructureId = uint16_t;
using TeamId = uint16_t;
using EventId = uint16_t;
using QuestId = uint16_t;
