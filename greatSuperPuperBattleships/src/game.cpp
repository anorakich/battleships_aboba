#include "../game.h"
#include "../graphicUI.h"

Game::Game(): alive_players_count(player_count) {
    stage = START;
    UI* ui = new GraphicUI();
    for (size_t i = 0; i < alive_players_count; ++i) {
        players.emplace_back(Player());
        (--players.end())->set_name("Player " + std::to_string(i+1));
        if (common_ui) (--players.end())->set_ui(ui);
        auto field = new Field(size_of_board);
        (--players.end())->set_field(field);
    }
}
void Game::play() {
    for (auto type : commonShipSet) {
        for (auto player : players) {
            player.setShip(type);
            player.get_ui()->waitForNextTurn();
        }
    }
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
        current_player = next_player;
    }
//    win(current_player);
}

void Game::attack(size_t current_player, size_t next_player) {
    players[current_player].get_ui()->displayField(*(players[next_player].get_field()), true);
    Position attack_position = players[current_player].get_ui()->getPosition();
    players[next_player].keep_attack(players[next_player].get_field()->at(
            attack_position.y, attack_position.x));
    players[current_player].get_ui()->displayField(*(players[next_player].get_field()), true);
    players[current_player].get_ui()->waitForNextTurn();
}


