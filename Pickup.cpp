#include "Pickup.hpp"

Pickup::Pickup(sf::Vector2f position) : shape_({24.f, 30.f}){
    shape_.setFillColor(sf::Color(255,140,0));
    shape_.setPosition(position);
;}

void Pickup::draw(sf::RenderTarget &target) const {
    target.draw(shape_);
}

sf::FloatRect Pickup::getBounds() const {
    return shape_.getGlobalBounds();
}

bool Pickup::isCollected() const{
    return  collected_;
}
void Pickup::collect() {
    collected_ = true;
}
