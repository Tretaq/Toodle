#pragma once
#include <SFML/Graphics.hpp>

class Platform {
public:
    Platform(sf::Vector2f position, sf::Vector2f size);
    void draw(sf::RenderTarget& target) const;
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape shape_;
};