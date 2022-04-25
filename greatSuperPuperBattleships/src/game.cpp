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


    //TODO set ships and field;

    stage = FIGHT;

    size_t current_player = 0;
    while(alive_players_count > 1) {
        size_t next_player = (current_player + 1) % player_count;
        while (players[next_player].is_losed()) {
            next_player = (current_player + 1) % player_count;
        }
        attack(current_player, next_player);
        current_player = next_player;
        while (players[current_player].is_losed()) {
            current_player = (current_player + 1) % player_count;
        }
    }
    win(current_player);
}

void Game::attack(size_t current_player, size_t next_player) {
    players[current_player].get_ui()->displayField(*(players[next_player].get_field()), true);
    Position attack_position = players[current_player].get_ui()->getPosition();
    players[next_player].keep_attack(players[next_player].get_field()->at(
            attack_position.x, attack_position.y));
    players[current_player].get_ui()->displayField(*(players[next_player].get_field()), true);
    players[current_player].get_ui()->waitForNextTurn();
}


