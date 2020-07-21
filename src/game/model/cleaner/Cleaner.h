//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <datatypes/GameTypes.h>
#include <memory>

namespace model {

// Forward declaration
class World;

class Cleaner {
public:
  Cleaner(const std::shared_ptr<World> &world);
  CharacterId deleteCharacter(const CharacterId characterId);
  ItemId deleteEquipable(const ItemId equipableId);
  ItemId deleteConsumable(const ItemId consumableId);
  LocationId deleteLocation(const LocationId locationId);
  LocationId deleteBuilding(const LocationId buildingId);
  StructureId deleteStructure(const StructureId structureId);
  EventId deleteEvent(const EventId eventId);
  QuestId deleteQuest(const QuestId questId);

private:
  std::shared_ptr<World> world;
};

} // namespace model
