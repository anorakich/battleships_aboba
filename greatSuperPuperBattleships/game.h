//
// Created by nikita on 16.04.22.
//

#ifndef BATTLESHIPS_GAME_H
#define BATTLESHIPS_GAME_H
#include "player.h"
#include <vector>
#include <queue>

class Game {
public:
    enum Stage {
        START,
        FIGHT,
    };

    Game();
private:
    Stage stage;
    std::vector<Player> players;
};


#endif //BATTLESHIPS_GAME_H
