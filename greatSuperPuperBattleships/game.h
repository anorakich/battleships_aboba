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
    void play();
private:
    Stage stage;
    std::vector<Player> players;
    bool attack(size_t current_player, size_t next_player);
};


#endif //BATTLESHIPS_GAME_H
