//
// Created by nolasco on 25/11/20.
//

#include "SnapshotUtilities.h"

#include "datatypes/lookup/ResourceEntry.h"

namespace utils {
bool SnapshotUtilities::shopkeeperAvailable(const Snapshot &snapshot) {
  for (const auto &character : snapshot.characters) {
    if (Occupation::SHOPKEEPER == character.entity->info.occupation) {
      return true;
    }
  }
  return false;
}

bool SnapshotUtilities::phoneboothAvailable(const Snapshot &snapshot) {
  for (const auto &structure : snapshot.structures) {
    if (StructureType::PHONEBOOTH == structure.entity->type) {
      return true;
    }
  }
  return false;
}

} // namespace utils
