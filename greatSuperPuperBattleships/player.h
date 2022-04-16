//
// Created by nikita on 16.04.22.
//

#ifndef BATTLESHIPS_PLAYER_H
#define BATTLESHIPS_PLAYER_H

#include "SFML/Graphics.hpp"
#include "ship.h"
class Player {
private:
    sf::RenderWindow window;
    std::vector<Ship> ships;
};


#endif //BATTLESHIPS_PLAYER_H
