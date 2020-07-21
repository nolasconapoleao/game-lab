//
// Created by nolasco on 16/06/20.
//

#pragma once

#include <memory>

#include "datatypes/GameTypes.h"
#include "datatypes/entity/Occupation.h"
#include "datatypes/factory/BuildingPrototype.h"
#include "datatypes/factory/ConnectorPrototype.h"
#include "datatypes/factory/ConsumablePrototype.h"
#include "datatypes/factory/EquipmentPrototype.h"
#include "datatypes/factory/EventPrototype.h"
#include "datatypes/factory/ExteriorPrototype.h"
#include "datatypes/factory/QuestPrototype.h"
#include "datatypes/factory/StaffPrototype.h"
#include "datatypes/factory/StructurePrototype.h"
#include "datatypes/factory/ThreatLevel.h"
#include "datatypes/factory/WeaponPrototype.h"

class World;

namespace model {

// Forward declaration
class World;

class Factory {
public:
  Factory(const std::shared_ptr<World> &world);
  CharacterId createCharacter(const ThreatLevel level, const Occupation occupation = Occupation::UNDEFINED);
  ItemId createEquipment(const EquipmentPrototype type = EquipmentPrototype::UNDEFINED);
  ItemId createStaff(const StaffPrototype type = StaffPrototype::UNDEFINED);
  ItemId createWeapon(const WeaponPrototype type = WeaponPrototype::UNDEFINED);
  ItemId createConsumable(const ConsumablePrototype type = ConsumablePrototype::UNDEFINED);
  LocationId createConnector(const ConnectorPrototype type = ConnectorPrototype::UNDEFINED);
  LocationId createBuilding(const BuildingPrototype type = BuildingPrototype::UNDEFINED);
  LocationId createLocation(const ExteriorPrototype type = ExteriorPrototype::UNDEFINED);
  StructureId createStructure(const StructurePrototype type = StructurePrototype::UNDEFINED);
  EventId createEvent(const EventPrototype type = EventPrototype::UNDEFINED);
  QuestId createQuest(const QuestPrototype type = QuestPrototype::UNDEFINED);

private:
  std::shared_ptr<World> world;
};

} // namespace model
