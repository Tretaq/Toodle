#pragma once
#include <SFML/Graphics.hpp>

class Pickup {
public:
    explicit Pickup(sf::Vector2f position);
    void draw(sf::RenderTarget& target) const;
    sf::FloatRect getBounds() const;
    bool isCollected() const;
    void collect();
private:
    sf::RectangleShape shape_;
    bool collected_ = false;
};