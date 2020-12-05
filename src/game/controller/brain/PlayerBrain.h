//
// Created by nolasco on 10/06/20.
//

#pragma once

#include "interface/controller/IBrain.h"

/// @brief Player console input structure.
struct ConsoleIn {
  /// @brief Raw Player console input.
  Quantity raw;
  /// @brief Player input mapped to options.
  ResourceId parsed;
};

namespace controller {
class IMenuHandler;

namespace brain {

/// @brief Player behaviour handler.
class Player : public IBrain {
public:
  /// @brief Constructor.
  Player();

  /// @copydoc IBrain::think()
  Decision think(const Snapshot &snap) override;

private:
  DbEntry<entity::Item> &selectFromItems();
  template <typename T> ConsoleIn selectFromVector(const std::vector<T> &vector);
  Quantity selectItemQuantity(const Quantity upperBound);

  void selectSubmenu();
  void makeMenuConnection(Action startSubmenu, std::initializer_list<Action> const &endSubmenus);

  std::map<Action, Action> decisionTree;
  Action activeSubmenu;
  std::shared_ptr<IMenuHandler> mMenuHandler;
};

} // namespace brain
} // namespace controller
