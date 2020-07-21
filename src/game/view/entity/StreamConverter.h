//
// Created by nolasco on 21/06/20.
//

#include "datatypes/entity/ItemType.h"
#include "datatypes/factory/ConnectorPrototype.h"
#include "datatypes/factory/ConsumablePrototype.h"
#include "datatypes/factory/StructurePrototype.h"
#include "datatypes/factory/ThreatLevel.h"
#include "interface/entity/Item.h"
#include "interface/entity/Location.h"
#include "model/World.h"
#include "model/entity/Character.h"
#include "model/entity/Structure.h"

std::ostream &operator<<(std::ostream &os, const Quantity &value);
std::ostream &operator<<(std::ostream &os, const Race &value);
std::ostream &operator<<(std::ostream &os, const Ghost &value);
std::ostream &operator<<(std::ostream &os, const AttackType &value);
std::ostream &operator<<(std::ostream &os, const Occupation &value);
std::ostream &operator<<(std::ostream &os, const Info &value);
std::ostream &operator<<(std::ostream &os, const Stats &value);
std::ostream &operator<<(std::ostream &os, const ItemEffect &value);
std::ostream &operator<<(std::ostream &os, const ThreatLevel &value);
std::string minimalPrint(const entity::Character &value);
std::string fullPrint(const entity::Character &value);

std::ostream &operator<<(std::ostream &os, const ItemType &value);
std::ostream &operator<<(std::ostream &os, const ConsumablePrototype &value);
std::string fullPrint(const entity::Item &value);
std::string minimalPrint(const entity::Item &value);

std::ostream &operator<<(std::ostream &os, const Size &value);
std::ostream &operator<<(std::ostream &os, const ConnectorPrototype &value);
std::string minimalPrint(const entity::Location &value);
std::string fullPrint(const entity::Location &value);

std::ostream &operator<<(std::ostream &os, const StructurePrototype &value);
std::string minimalPrint(const entity::Structure &value);
std::string fullPrint(const entity::Structure &value);

// FIXME: printScene should be const but can't because it uses non const methods
std::string printScene();