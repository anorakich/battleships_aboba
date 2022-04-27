#ifndef BATTLESHIPS_GAME_H
#define BATTLESHIPS_GAME_H

#include "player.h"
#include <vector>

class Game {
public:
    Game();
    void startGame();
    void play();

private:
    inline static const std::vector<Ship::ShipType> commonShipSet = {Ship::ONEDECK,Ship::ONEDECK,Ship::ONEDECK,Ship::ONEDECK,
                                                                 Ship::TWODECK,Ship::TWODECK,Ship::TWODECK,
                                                                 Ship::THREEDECK,Ship::THREEDECK,
                                                                 Ship::FOURDECK};

    std::vector<Player> players;
    size_t alive_players_count;

    Player* getNextPlayer(const Player* current);

    void attack(Player* current, Player* next);
    void win(size_t player);
};

#endif //BATTLESHIPS_GAME_H