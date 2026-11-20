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

MovingPlatform::MovingPlatform(sf::Vector2f position, sf::Vector2f size):Platform({position},{size}), speed_(150.0f){
    shape_.setFillColor(sf::Color::Blue);

}
