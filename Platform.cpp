#include "Platform.hpp"

Platform::Platform(sf::Vector2f position, sf::Vector2f size)
{
    shape_.setPosition(position);
    shape_.setSize(size);
    shape_.setFillColor(sf::Color::Cyan);
}
void Platform::draw(sf::RenderTarget& target) const
{
    target.draw(shape_);
}
sf::FloatRect Platform::getBounds() const
{
    return shape_.getGlobalBounds();
}

void Platform::update(float dt) {}

bool Platform::isAlive() const {
    return alive_;
}

float Platform::bounceStrength() const {
    return 1.f;
}
