#include "SFML/Graphics.hpp"
#include <string>
#pragma once
class CustomText {
private:
    sf::Text text_object;
public:
    CustomText(const std::string& text, const sf::Font& font, int position_x, int position_y);
    void draw(sf::RenderWindow& app) const;
    void setColor(const sf::Color& color);
};
