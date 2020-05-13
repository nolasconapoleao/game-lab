//
// Created by nolasco on 11/05/20.
//

#include "BaseItem.h"

BaseItem::BaseItem(const std::string &name, CharacterProperty modifier, UseType useType)
    : name(name), modifier(modifier), useType(useType) {
}
