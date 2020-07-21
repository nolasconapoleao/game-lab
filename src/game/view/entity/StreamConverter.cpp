//
// Created by nolasco on 21/06/20.
//

#include "StreamConverter.h"

#include <magic_enum/include/magic_enum.hpp>
#include <sstream>

std::ostream &operator<<(std::ostream &os, const Quantity &value) {
  os << std::to_string(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Race &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const Ghost &value) {
  os << magic_enum::enum_name(value).data();
  return os;
}

std::ostream &operator<<(std::ostream &os, const AttackType &value) {
  os << magic_enum::enum_name(value).data();
  return os;
}

std::ostream &operator<<(std::ostream &os, const Occupation &value) {
  os << magic_enum::enum_name(value).data();
  return os;
}

std::ostream &operator<<(std::ostream &os, const Info &value) {
  os << "faction: " << value.faction << " party: " << value.party << " occupation: " << value.occupation
     << " race: " << value.race << " attackType: " << value.attackType;
  return os;
}

std::ostream &operator<<(std::ostream &os, const Stats &value) {
  os << " mhp: " << value.mhp << " cst: " << value.cst << " lvl: " << value.lvl << " xp: " << value.xp
     << " cash: " << value.cash << "\n\t\tatk: " << value.atk << " def: " << value.def << " spd: " << value.spd
     << " hp: " << value.hp;
  return os;
}

std::ostream &operator<<(std::ostream &os, const ItemEffect &value) {
  os << " atk: " << value.atk << " def: " << value.def << " spd: " << value.spd << " hp: " << value.hp;
  return os;
}

std::string minimalPrint(const entity::Character &character) {
  std::ostringstream os;
  os << character.getName() << " " << character.getStats().hp << "/" << (character.getStats().mhp);
  return os.str();
}

std::string fullPrint(const entity::Character &character) {
  std::ostringstream os;
  os << character.getName() << " stats: " << character.getStats() << " ghost: " << character.getGhost()
     << "\n\t\tpassport: " << character.getPassport();
  return os.str();
}

std::ostream &operator<<(std::ostream &os, const ThreatLevel &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const UseType &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const OwnerType &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const ItemOwnership &value) {
  os << "resourceId: " << value.resourceId << " ownerType: " << value.ownerType;
  if (OwnerType::CHARACTER == value.ownerType) {
    os << " equipped: " << value.equipped;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const ItemCategory &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const ConsumablePrototype &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::string minimalPrint(const entity::Item &value) {
  std::ostringstream os;
  os << value.getName();
  return os.str();
}

std::string fullPrint(const entity::Item &value) {
  std::ostringstream os;
  os << value.getName() << " useType: " << value.getUseType() << " weight: " << value.getWeight()
     << " quantity: " << value.getQuantity() << " effect: " << value.getEffect()
     << " ownership: " << value.getOwnership();
  return os.str();
}

std::ostream &operator<<(std::ostream &os, const Size &value) {
  os << "width: " << value.width << "height: " << value.height;
  return os;
}

std::ostream &operator<<(std::ostream &os, const LocationCategory &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::ostream &operator<<(std::ostream &os, const ConnectorPrototype &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::string minimalPrint(const entity::Location &value) {
  std::ostringstream os;
  os << value.getName() << " (" << value.getType() << ")";
  return os.str();
}

std::string fullPrint(const entity::Location &value) {
  std::ostringstream os;
  os << value.getName() << " type: " << value.getType() << " size: " << value.getSize()
     << " floors: " << value.getFloors();
  return os.str();
}

std::ostream &operator<<(std::ostream &os, const StructurePrototype &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::string minimalPrint(const entity::Structure &value) {
  std::ostringstream os;
  os << value.getName();
  return os.str();
}

std::string fullPrint(const entity::Structure &value) {
  std::ostringstream os;
  os << value.getName() << " size: " << value.getSize() << " location: " << value.getLocation();
  return os.str();
}

std::string printScene() {
  std::ostringstream os;
  os << "Characters:";
  for (const auto characterId : World::charactersInLocation(World::activeLocation)) {
    os << " " << minimalPrint(World::character(characterId));
  }

  os << "\nStructures:";
  for (const auto structureId : World::structuresInLocation(World::activeLocation)) {
    os << " " << minimalPrint(World::structure(structureId));
  }

  os << "\nItems:";
  for (const auto itemId : World::itemsInLocation(World::activeLocation)) {
    os << " " << minimalPrint(World::item(itemId));
  }

  os << "\nNeighbourhood:";
  for (const auto locationId : World::adjcentLocations(World::activeLocation)) {
    os << " " << minimalPrint(World::location(locationId));
  }

  return os.str();
}
