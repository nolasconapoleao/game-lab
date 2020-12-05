//
// Created by nolasco on 08/12/20.
//

#pragma once

namespace testHelper {

const auto cCharacter = entity::Character{"character", Stats{}, Info{}};
const auto cLocation = entity::Location{"location", Size{1, 2}};
const auto cExterior = entity::Exterior{"location", Size{1, 2}};
const auto cBuilding = entity::Building{"building", BuildingType::UNDEFINED, Size{1, 2}, 0};
const auto cConsumable = entity::Consumable{"consumable", ConsumableType::UNDEFINED, ItemEffect{}, 1, 0, 0, 0};
const auto cEquipable = entity::Equippable{"equipable", EquippableType::UNDEFINED, ItemEffect{}, 1, 0, 0, 0};
const auto cStructure = entity::Structure{"structure", StructureType::UNDEFINED, Size{1, 2}};
const auto cItem = entity::Item{"item", ItemEffect{}, 1, 0, 0};
const auto cTeam = entity::Team{"team"};

ResourceId cCharacterId{1};
ResourceId cCharacter2Id{2};
ResourceId cLocationId{3};
ResourceId cExteriorId{4};
ResourceId cExterior2Id{5};
ResourceId cBuildingId{6};
ResourceId cConsumableId{7};
ResourceId cEquipableId{8};
ResourceId cEquipable2Id{9};
ResourceId cStructureId{10};
ResourceId cTeamId{11};
ResourceId cItemId{12};

const auto characterEntry = DbEntry<entity::Character>{cCharacterId, std::make_shared<entity::Character>(cCharacter)};
const auto locationEntry = DbEntry<entity::Location>{cLocationId, std::make_shared<entity::Location>(cLocation)};
const auto consumablesEntry
    = DbEntry<entity::Consumable>{cConsumableId, std::make_shared<entity::Consumable>(cConsumable)};
const auto equipablesEntry
    = DbEntry<entity::Equippable>{cEquipableId, std::make_shared<entity::Equippable>(cEquipable)};
const auto structuresEntry = DbEntry<entity::Structure>{cStructureId, std::make_shared<entity::Structure>(cStructure)};
const auto buildingsEntry = DbEntry<entity::Building>{cBuildingId, std::make_shared<entity::Building>(cBuilding)};
const auto exteriorsEntry = DbEntry<entity::Exterior>{cExteriorId, std::make_shared<entity::Exterior>(cExterior)};
const auto floorEntry = DbEntry<entity::Item>{cItemId, std::make_shared<entity::Item>(cItem)};
const auto ownedByEntry = std::map<CharacterId, std::vector<DbEntry<entity::Item>>>{{cCharacter2Id, {floorEntry}}};

} // namespace testHelper
