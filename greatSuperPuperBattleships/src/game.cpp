//
// Created by nikita on 16.04.22.
//
#include "SFML/Graphics.hpp"
#include "../game.h"
#include "../constants.h"
#include "../graphicUI.h"

Game::Game(): alive_players_count(player_count) {
    stage = START;
    UI* ui = new GraphicUI();
}
void Game::play() {


    for (auto type : commonShipSet) {
        for (auto player : players)
            player.setShip(type);
    }
    size_t current_player = 0;
    while(true) {
        size_t next_player = (current_player + 1) % player_count;
        attack(current_player, next_player);
        if (players[next_player].is_losed()) {
//            win();
        }
        current_player = next_player;
    }
}

void Game::attack(size_t current_player, size_t next_player) {
    players[current_player].get_ui()->displayField(*(players[next_player].get_field()), true);
    Position attack_position = players[current_player].get_ui()->getPosition();
    players[next_player].keep_attack(players[next_player].get_field()->at(
            attack_position.x, attack_position.y));
    players[current_player].get_ui()->displayField(*(players[next_player].get_field()), true);
    players[current_player].get_ui()->waitForNextTurn();
}


