//
// Created by nolasco on 21/06/20.
//

#include "controller/factory/include/CharacterPrototype.h"
#include "controller/factory/include/ItemCategory.h"
#include "controller/factory/include/ItemPrototype.h"
#include "controller/factory/include/LocationCategory.h"
#include "controller/factory/include/LocationPrototype.h"
#include "controller/factory/include/StructurePrototype.h"
#include "model/World.h"
#include "model/entity/Character.h"
#include "model/entity/Item.h"
#include "model/entity/Location.h"
#include "model/entity/Structure.h"

std::ostream &operator<<(std::ostream &os, const Quantity &value);
std::ostream &operator<<(std::ostream &os, const Race &value);
std::ostream &operator<<(std::ostream &os, const GhostInTheShell &value);
std::ostream &operator<<(std::ostream &os, const CharacterAttack &value);
std::ostream &operator<<(std::ostream &os, const Occupation &value);
std::ostream &operator<<(std::ostream &os, const Passport &value);
std::ostream &operator<<(std::ostream &os, const Stats &value);
std::ostream &operator<<(std::ostream &os, const ItemEffect &value);
std::ostream &operator<<(std::ostream &os, const CharacterPrototype &value);
// TODO: use friend method from another namespace
// std::string minimalPrint(const entity::Character &value);
// std::string fullPrint(const entity::Character &value);

std::ostream &operator<<(std::ostream &os, const UseType &value);
std::ostream &operator<<(std::ostream &os, const OwnerType &value);
std::ostream &operator<<(std::ostream &os, const ItemOwnership &value);
std::ostream &operator<<(std::ostream &os, const ItemCategory &value);
std::ostream &operator<<(std::ostream &os, const ItemPrototype &value);
// std::string fullPrint(const entity::Item &value);
// std::string minimalPrint(const entity::Item &value);

std::ostream &operator<<(std::ostream &os, const Size &value);
std::ostream &operator<<(std::ostream &os, const LocationCategory &value);
std::ostream &operator<<(std::ostream &os, const LocationPrototype &value);
// std::string minimalPrint(const entity::Location &value);
// std::string fullPrint(const entity::Location &value);

std::ostream &operator<<(std::ostream &os, const StructurePrototype &value);
// std::string minimalPrint(const entity::Structure &value);
// std::string fullPrint(const entity::Structure &value);

// std::string printScene(World &world);