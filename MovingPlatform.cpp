#include "MovingPlatform.hpp"
#include "Constants.hpp"
#include <cmath>

namespace {
    constexpr float kSpeed = 100.f;
}

MovingPlatform::MovingPlatform(sf::Vector2f position, sf::Vector2f size): Platform(position,size), speed_(kSpeed) {
    shape_.setFillColor(sf::Color::Blue);
}

void MovingPlatform::update(float dt) {
    shape_.move({speed_ * dt, 0.f});
    const sf::Vector2f pos = shape_.getPosition();
    const float width = shape_.getSize().x;

    if (pos.x  < 0.f) {
        shape_.setPosition({0.f,pos.y});
        speed_ = std::abs(speed_);
    } else if (pos.x + width > cfg::kWindowHeight) {
        shape_.setPosition({cfg::kWindowWidth - width, pos.y});
        speed_ = -std::abs(speed_);
    }
}
