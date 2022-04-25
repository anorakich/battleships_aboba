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
    void play();
    Game();
private:
    Stage stage;
    std::vector<Player> players;
    size_t alive_players_count;
    void attack(size_t current_player, size_t next_player);
    void win(size_t player);
};


#endif //BATTLESHIPS_GAME_H
