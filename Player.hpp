#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
     Player(sf::Vector2f startPos);

     void update(float dt);
     void draw(sf::RenderTarget& target) const;
     void bounce();
     sf::FloatRect getBounds() const;
     float getVelocityY() const;
private:
     sf::RectangleShape shape_;
     float velocityY_ = 0.f;
};