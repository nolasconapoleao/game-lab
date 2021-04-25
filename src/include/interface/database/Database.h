//
// Created by nolasco on 04/06/20.
//

#pragma once

#include <functional>
#include <iostream>
#include <vector>

using Id = id_t;

/// @brief Database template class.
template <class EntryInfo> class Database {

public:
  Database() = default;

  // CRUD operations
  /**
   * @brief Create entry in database.
   * @param entry information to input.
   * @return id to access the created entry.
   */
  [[nodiscard]] Id createEntry(const EntryInfo &entry);

  /**
   * @brief Retrieve read-only entry from database, throws exception if non existing id.
   * @param id for the database object.
   * @return object with provided id.
   */
  EntryInfo readEntry(Id id);

  /**
   * @brief Update existing object with new information, throws exception if non existing id.
   * @param id for existing object.
   * @param entry updated information for the database object.
   */
  void updateEntry(Id id, const EntryInfo &entry);

  /**
   * @brief Deletes entry with provided id.
   * @param id for entry to delete
   */
  void deleteEntry(Id id);

  /**
   * Number of entries on the database.
   * @return number of entries on the database.
   */
  size_t size();

protected:
  /// @brief Database content.
  std::vector<std::pair<Id, EntryInfo>> data;
};

// Method definition
template <class EntryInfo> Id Database<EntryInfo>::createEntry(const EntryInfo &entry) {

  std::hash<EntryInfo> hash_fn;
  Id entry_hash = hash_fn(entry);

  data.emplace_back(entry_hash, entry);
  return entry_hash;
}

template <class EntryInfo> EntryInfo Database<EntryInfo>::readEntry(const Id id) {

  const auto findById = [id](const auto entry) { return entry.first == id; };
  auto foundEntry = std::find_if(data.begin(), data.end(), findById);

  if (foundEntry == data.end()) {
    std::cerr << "Invalid database Id.\n";
    throw std::out_of_range("Invalid Id");
  }
  return foundEntry->second;
}

template <class EntryInfo> void Database<EntryInfo>::updateEntry(const Id id, const EntryInfo &entry) {

  const auto findById = [id](const auto entry) { return entry.first == id; };
  auto foundEntry = std::find_if(data.begin(), data.end(), findById);

  if (foundEntry == data.end()) {
    std::cerr << "Invalid database Id.\n";
    throw std::out_of_range("Invalid Id");
  }

  foundEntry->second = entry;
}

template <class EntryInfo> void Database<EntryInfo>::deleteEntry(const Id id) {

  const auto findById = [id](const auto entry) { return entry.first == id; };
  data.erase(std::remove_if(data.begin(), data.end(), findById), data.end());
}

template <class EntryInfo> size_t Database<EntryInfo>::size() {
  return data.size();
}
