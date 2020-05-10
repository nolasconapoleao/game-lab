#include <iostream>
#include <memory>


#include "game/Game.h"

int main() {

    Game game = Game();


    game.initGame();
    game.paint();

    while(!game.isOver()) {
        game.loop();
    }

    return 0;
}
