//
// Created by nikita on 16.04.22.
//
#include "SFML/Graphics.hpp"
#include "../game.h"
#include "../constants.h"
#include "../UI.h"
#include "../graphicUI.h"

void Game::play() {
    stage = START;
    UI* ui = new GraphicUI;
    for (size_t i = 0; i < player_count; ++i) {
        players.push_back(Player());
    }

    //TODO set ships and field;

    stage = FIGHT;

    size_t current_player = 0;
    while(true) {
        size_t next_player = (current_player + 1) % player_count;

        current_player = (current_player + 1) % player_count;
    }
}

bool Game::attack(size_t current_player, size_t next_player) {
    players[current_player].get_ui()->displayField(*(players[next_player].get_field()), true);
    Position attack_position = players[current_player].get_ui()->getPosition();

    return false;
}
