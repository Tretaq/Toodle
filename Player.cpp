#include "Player.hpp"
namespace {
    constexpr float kGravity = 2000.f;
    constexpr float kJumpSpeed = 1000.f;
    constexpr float kMoveSpeed = 1000.f;
    constexpr float kWindowWidth = 480.f;

}

Player::Player(sf::Vector2f startPos) : shape_({40.f, 40.f}) {
    shape_.setFillColor(sf::Color::Green);
    shape_.setPosition(startPos);
}

void Player::update(float dt) {
    float dir = 0.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        dir -= 1.f;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        dir += 1.f;
    }
    velocityY_ += kGravity * dt;
    shape_.move({ dir * kMoveSpeed * dt, velocityY_ * dt });
    sf::Vector2f pos = shape_.getPosition();
    float w = shape_.getSize().x;
    if (pos.x > kWindowWidth){
        shape_.setPosition({-w , pos.y});
    } else if (pos.x + w < 0){
        shape_.setPosition({kWindowWidth , pos.y});
    }
}

void Player::draw(sf::RenderTarget& target) const{
    target.draw(shape_);
}

void Player::bounce(){
    velocityY_ = -kJumpSpeed;
}
sf::FloatRect Player::getBounds() const{
    return shape_.getGlobalBounds();
}
float Player::getVelocityY() const{
    return velocityY_;
}