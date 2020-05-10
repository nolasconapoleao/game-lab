//
// Created by nolasco on 09/05/20.
//

#pragma once

class Game {
public:
    Game();

    virtual ~Game();

    void updateGame();
    void initGame();
    void readInput();
    void paint();
    void loop();

    bool isOver();

private:
    void updatePlayer();
    void updateNonPlayableCharacters();
    void updateEntities();

    uint8_t lastKeyPressed;
};
