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

std::ostream &operator<<(std::ostream &os, const GhostInTheShell &value) {
  os << magic_enum::enum_name(value).data();
  return os;
}

std::ostream &operator<<(std::ostream &os, const CharacterAttack &value) {
  os << magic_enum::enum_name(value).data();
  return os;
}

std::ostream &operator<<(std::ostream &os, const Occupation &value) {
  os << magic_enum::enum_name(value).data();
  return os;
}

std::ostream &operator<<(std::ostream &os, const Passport &value) {
  os << "faction: " << value.faction << " party: " << value.party << " occupation: " << value.occupation
     << " race: " << value.race << " characterAttack: " << value.characterAttack;
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

std::string entity::minimalPrint(const entity::Character &character) {
  std::ostringstream os;
  os << character.name << " " << character.getStats().hp << "/" << (character.getStats().mhp);
  return os.str();
}

std::string entity::fullPrint(const entity::Character &character) {
  std::ostringstream os;
  os << character.name << " stats: " << character.getStats() << " ghost: " << character.ghost
     << "\n\t\tpassport: " << character.passport;
  return os.str();
}

std::ostream &operator<<(std::ostream &os, const CharacterPrototype &value) {
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

std::ostream &operator<<(std::ostream &os, const ItemPrototype &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::string entity::minimalPrint(const entity::Item &value) {
  std::ostringstream os;
  os << value.name;
  return os.str();
}

std::string entity::fullPrint(const entity::Item &value) {
  std::ostringstream os;
  os << value.name << " useType: " << value.useType << " weight: " << value.weight << " quantity: " << value.quantity
     << " effect: " << value.effect << " ownership: " << value.ownership;
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

std::ostream &operator<<(std::ostream &os, const LocationPrototype &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::string entity::minimalPrint(const entity::Location &value) {
  std::ostringstream os;
  os << value.name << " (" << value.type << ")";
  return os.str();
}

std::string entity::fullPrint(const entity::Location &value) {
  std::ostringstream os;
  os << value.name << " type: " << value.type << " size: " << value.size << " floors: " << value.floors;
  return os.str();
}

std::ostream &operator<<(std::ostream &os, const StructurePrototype &value) {
  os << magic_enum::enum_name(value);
  return os;
}

std::string entity::minimalPrint(const entity::Structure &value) {
  std::ostringstream os;
  os << value.name;
  return os.str();
}

std::string entity::fullPrint(const entity::Structure &value) {
  std::ostringstream os;
  os << value.name << " size: " << value.size << " location: " << value.location;
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
