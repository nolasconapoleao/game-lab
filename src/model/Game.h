//
// Created by nolasco on 02/06/20.
//

#pragma once

namespace model {

class Game {

public:
  Game();
  const bool isOver();
  void loop();

private:
  void init();

  bool mTerminateGame;
};

} // namespace model
