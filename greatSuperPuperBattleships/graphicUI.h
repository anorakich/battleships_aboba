//
// Created by nikita on 25.04.22.
//

#ifndef BATTLESHIPS_GRAPHICUI_H
#define BATTLESHIPS_GRAPHICUI_H

#include "UI.h"
#include "SFML/Graphics.hpp"
#include "constants.h"
#include <iostream>
#include "customText.h"

class GraphicUI : public UI {
private:
    sf::RenderWindow window;
    inline static const std::vector<sf::Color> colorFromCellState = {sf::Color::Red, sf::Color::Cyan, sf::Color::Blue,
                                                                     sf::Color::White, sf::Color::Black};
public:
    GraphicUI() : window(sf::RenderWindow(sf::VideoMode(app_width, app_height),
                                          "battleships")) {}

    Position getPosition() override {
        int leftTopX = app_width / 2 - 6 * size_of_cell;
        int leftTopY = app_height / 4;
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::MouseButtonPressed) {

                    int mousePositionX = sf::Mouse::getPosition(window).x;
                    int mousePositionY = sf::Mouse::getPosition(window).y;

                    return {(mousePositionX - leftTopX) / size_of_cell,
                            (mousePositionY - leftTopY) / size_of_cell};
                }
            }
        }
    }


    void displayField(const Field& field, bool isEnemiesField) {
        window.clear(sf::Color::Blue);
        if (isEnemiesField) {
            sf::Font font;
            font.loadFromFile("../src/fonts/OpenSans-SemiBoldItalic.ttf");
            CustomText play_text("ATTACK!", font, app_width * 9 / 20, 2 * app_height / 15);
            play_text.draw(window);
        }

        for (int i = 0; i < size_of_board; ++i) {
            for (int j = 0; j < size_of_board; ++j) {
                sf::RectangleShape cell({(float) size_of_cell, (float) size_of_cell});
                cell.setPosition(app_width / 2 - 6 * size_of_cell + j * (size_of_cell),
                                 app_height / 4 + i * (size_of_cell));
                cell.setOutlineColor(sf::Color::Black);
                cell.setOutlineThickness(4);
                Cell::CellState state = field.at(i, j).getState();
                if (!isEnemiesField) {
                    cell.setFillColor(colorFromCellState[state]);
                } else {
                    if (state == Cell::DEAD || state == Cell::INJURED) {
                        cell.setFillColor(colorFromCellState[state]);
                    } else {
                        if (field.at(i, j).getIsHited())
                            cell.setFillColor(colorFromCellState[2]);
                        else
                            cell.setFillColor(sf::Color::White);
                    }

                }
                window.draw(cell);
            }
        }
        window.display();
    }

    void waitForNextTurn() override {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                    return;
            }
        }
    }
};


#endif //BATTLESHIPS_GRAPHICUI_H
