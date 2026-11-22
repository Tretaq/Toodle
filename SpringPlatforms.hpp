#pragma once
#include "Platform.hpp"

class SpringPlatform : public Platform {
public:
    SpringPlatform(sf::Vector2f position, sf::Vector2f size);
    void draw(sf::RenderTarget& target) const override;
    float bounceStrength() const override;
private:
    sf::RectangleShape spring_;
};