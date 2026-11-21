#pragma once
#include <SFML/Graphics.hpp>

class Platform {
public:
    Platform(sf::Vector2f position, sf::Vector2f size);
    virtual ~Platform() = default;
    virtual void update(float dt);
    virtual bool onLanded(){ return true ;};
    void draw(sf::RenderTarget& target) const;
    sf::FloatRect getBounds() const;
    bool isAlive() const;

protected:
    sf::RectangleShape shape_;
    bool alive_ = true;
};

