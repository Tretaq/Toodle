#include "SpringPlatforms.hpp"
#include "Constants.hpp"

SpringPlatform::SpringPlatform(sf::Vector2f position, sf::Vector2f size):Platform(position,size), spring_({20.f, 12.f}) {
    spring_.setFillColor(sf::Color::Yellow);
    spring_.setPosition({position.x + size.x / 2.f - 10.f, position.y - 12.f});
}

void SpringPlatform::draw(sf::RenderTarget &target) const {
    Platform::draw(target);
    target.draw(spring_);
}

float SpringPlatform::bounceStrength() const {
    return cfg::kSpringMultiplayer;
}

