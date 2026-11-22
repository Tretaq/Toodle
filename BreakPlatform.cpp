#include "BreakPlatform.hpp"

BreakPlatform::BreakPlatform(sf::Vector2f position, sf::Vector2f size): Platform(position,size) {
    shape_.setFillColor(sf::Color::White);
}

bool BreakPlatform::onLanded() {
    shape_.setFillColor(sf::Color(30,30,40));
    alive_ = false;
    return false;
}
