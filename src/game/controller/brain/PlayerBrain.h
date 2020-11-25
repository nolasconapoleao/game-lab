//
// Created by nolasco on 10/06/20.
//

#pragma once

#include <controller/MenuHandler.h>

#include "IBrain.h"

/// @brief Player console input structure.
struct ConsoleIn {
  /// @brief Raw Player console input.
  Quantity raw;
  /// @brief Player input mapped to options.
  ResourceId parsed;
};

namespace controller::brain {

/// @brief Player behaviour handler.
class Player : public IBrain {
public:
  /// @brief Constructor.
  Player();

  /// @copydoc IBrain::think()
  Decision think(const Snapshot &snap) override;

private:
  Decision drop_item();
  Decision use_item();
  template <typename T> ConsoleIn selectFromVector(const std::vector<T> &vector);
  template <typename T> Quantity selectItemQuantity(const std::vector<T> &vector, ConsoleIn input);
  void selectSubmenu();
  void makeMenuConnection(Action startSubmenu, std::initializer_list<Action> const &endSubmenus);

  std::map<Action, Action> decisionTree;
  Action activeSubmenu;
  MenuHandler menuHandler;
};

} // namespace controller::brain
