//
// Created by nolasco on 21/06/20.
//

#include "model/entity/Character.h"

std::ostream &operator<<(std::ostream &os, const Quantity &value);
std::ostream &operator<<(std::ostream &os, const Race &value);
std::ostream &operator<<(std::ostream &os, const GhostInTheShell &value);
std::ostream &operator<<(std::ostream &os, const CharacterAttack &value);
std::ostream &operator<<(std::ostream &os, const Occupation &value);
std::ostream &operator<<(std::ostream &os, const entity::Passport &value);
std::ostream &operator<<(std::ostream &os, const entity::Stats &value);
std::ostream &operator<<(std::ostream &os, const entity::ItemEffect &value);
// TODO: use friend class from another namespace
// std::string minimalPrint(const entity::Character &character);
// std::string fullPrint(const entity::Character &character);