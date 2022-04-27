#include "../game.h"
#include "../graphicUI.h"

Game::Game(): alive_players_count(player_count) {
    UI* ui = new GraphicUI();
    for (size_t i = 0; i < alive_players_count; ++i) {
        players.emplace_back(Player(i));
        (--players.end())->set_name("Player " + std::to_string(i+1));
        if (common_ui) (--players.end())->set_ui(ui);
        auto field = new Field(size_of_board);
        (--players.end())->set_field(field);
    }
}

void Game::startGame() {
    for (auto type : commonShipSet) {
        for (auto player : players) {
            player.setShip(type);
        }
    }
}

void Game::play() {
    Player* current = &players[0];
    while(alive_players_count > 1) {
        attack(current, getNextPlayer(current));
        current = getNextPlayer(current);
    }
//    win(current_player);
}

void Game::attack(Player* current, Player* next) {
    Position attack_position = current->attack(next->get_field());
    next->keep_attack(attack_position);
    current->get_ui()->displayField(*(next->get_field()), true);
    current->get_ui()->waitForNextTurn();
}

Player* Game::getNextPlayer(const Player* current) {
    size_t id = (current->getId() + 1) % player_count;
    while (players[id].is_losed()) {
        id = (id + 1) % player_count;
    }
    return &players[id];
}




