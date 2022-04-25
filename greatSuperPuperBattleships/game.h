//
// Created by nikita on 16.04.22.
//

#ifndef BATTLESHIPS_GAME_H
#define BATTLESHIPS_GAME_H
#include "player.h"
enum Turn {
    FIRST_PLAYER_TURN,
    SECOND_PLAYER_TURN,
};
class Game {
    Turn turn = FIRST_PLAYER_TURN;
    sf::RenderWindow window;
public:
    Player player1;
    Player player2;
    Game();
};


#endif //BATTLESHIPS_GAME_H
