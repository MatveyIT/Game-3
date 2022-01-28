#pragma once
#include "SFML/Graphics.hpp"

class Bat {
protected:
    sf::RectangleShape rect;
    int width = 10;
    int height = 80;
    float speedy = 5.f;
public:
    Bat(float startx, float starty) {
        rect.setSize(sf::Vector2f(width, height));
        rect.setPosition(startx, starty);
        rect.setFillColor(sf::Color(255, 255, 255));
    }
    sf::RectangleShape getShape() { return rect; }
    sf::FloatRect getHitBox() { return rect.getGlobalBounds(); }
};