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
    inline static const std::vector<Ship::ShipType> commonShipSet = {Ship::ONEDECK,//Ship::ONEDECK,Ship::ONEDECK,Ship::ONEDECK,
//                                                                 Ship::TWODECK,Ship::TWODECK,Ship::TWODECK,
//                                                                 Ship::THREEDECK,Ship::THREEDECK,
//                                                                 Ship::FOURDECK
                                                                 };
    std::vector<std::string> attackResult = {"Missed!", "Gun was jammed!", "Got it!", "Sunk it!"};

    std::vector<Player> players;
    size_t alive_players_count;

    Player* getNextPlayer(const Player* current);

    void attack(Player* current, Player* next);
    void win(Player* player);
};

#endif //BATTLESHIPS_GAME_H