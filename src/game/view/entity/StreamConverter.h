//
// Created by nolasco on 21/06/20.
//

#include "datatypes/factory/CharacterPrototype.h"
#include "datatypes/factory/ItemCategory.h"
#include "datatypes/factory/ItemPrototype.h"
#include "datatypes/factory/LocationCategory.h"
#include "datatypes/factory/LocationPrototype.h"
#include "datatypes/factory/StructurePrototype.h"
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
std::string minimalPrint(const entity::Character &value);
std::string fullPrint(const entity::Character &value);

std::ostream &operator<<(std::ostream &os, const UseType &value);
std::ostream &operator<<(std::ostream &os, const OwnerType &value);
std::ostream &operator<<(std::ostream &os, const ItemOwnership &value);
std::ostream &operator<<(std::ostream &os, const ItemCategory &value);
std::ostream &operator<<(std::ostream &os, const ItemPrototype &value);
std::string fullPrint(const entity::Item &value);
std::string minimalPrint(const entity::Item &value);

std::ostream &operator<<(std::ostream &os, const Size &value);
std::ostream &operator<<(std::ostream &os, const LocationCategory &value);
std::ostream &operator<<(std::ostream &os, const LocationPrototype &value);
std::string minimalPrint(const entity::Location &value);
std::string fullPrint(const entity::Location &value);

std::ostream &operator<<(std::ostream &os, const StructurePrototype &value);
std::string minimalPrint(const entity::Structure &value);
std::string fullPrint(const entity::Structure &value);

// FIXME: printScene should be const but can't because it uses non const methods
std::string printScene();