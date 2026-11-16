#include "Player.hpp"
namespace {

}

Player::Player(sf::Vector2f startPos) : shape_({40.f, 40.f}) {
    shape_.setFillColor(sf::Color::Green);
    shape_.setPosition(startPos);
}

void Player::update(float dt) {
    float fir = 0.f;

}
