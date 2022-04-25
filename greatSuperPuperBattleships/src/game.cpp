//
// Created by nikita on 16.04.22.
//
#include "SFML/Graphics.hpp"
#include "../game.h"
#include "../constants.h"
#include "../UI.h"


Game::Game() {
    stage = START
    UI* ui = new UI();
    for (size_t i = 0; i < player_count; ++i) {
        players.push_back(Player());
    }

    //TODO set ships and field;

    stage = FIGHT;

    size_t current_player = 0;
    while(true) {
        size_t next_player = 
        Position attack_position;
        current_player = (current_player + 1) % player_count;
    }



}
