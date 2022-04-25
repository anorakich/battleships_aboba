//
// Created by nikita on 25.04.22.
//

#ifndef BATTLESHIPS_GRAPHICUI_H
#define BATTLESHIPS_GRAPHICUI_H

#include "UI.h"
#include "SFML/Graphics.hpp"
#include "constants.h"

class GraphicUI : public UI {
private:
    sf::RenderWindow window;
    inline static const std::vector<sf::Color> colorFromCellState = {sf::Color::Red,sf::Color::Cyan,sf::Color::Blue,
                                                               sf::Color::White,sf::Color::Black};
public:
    GraphicUI();

    Position getAttackPosition(const Field& field) override {

    }

    void displayField(const Field& field, bool isEnemiesField) {
        for (int i = 0; i < size_of_board; ++i) {
            for (int j = 0; j < size_of_board; ++j) {
                sf::RectangleShape cell({(float)size_of_cell,(float)size_of_cell});
                cell.setPosition(app_width / 4 + j * (size_of_cell + 4), app_height / 4 + i * (size_of_cell + 4));
                cell.setFillColor(colorFromCellState[field[i][j].getState()]);
            }
        }
    }

    std::pair<Position, Position> getPositionToSetShip(const Field& field) {

    }
};


#endif //BATTLESHIPS_GRAPHICUI_H
