#include "Player.hpp"

#include "Constants.hpp"

Player::Player(sf::Vector2f startPos) : shape_({40.f, 40.f}) {
    shape_.setFillColor(sf::Color::Green);
    shape_.setPosition(startPos);
}

bool Player::isLandingOn(const sf::FloatRect &platform) const {
    if (state_ == State::Jetpack) return false;
    sf::FloatRect player = shape_.getGlobalBounds();
    float currFeet = player.position.y + player.size.y;
    float platformTop = platform.position.y;
    float playerLeft = player.position.x;
    float playerRight = player.position.x + player.size.x;
    float platformLeft =  platform.position.x;
    float platformRight = platform.position.x + platform.size.x;
    return prevBottom_ <= platformTop && currFeet >= platformTop && playerLeft < platformRight && playerRight >platformLeft;
}

void Player::update(float dt) {
    float dir = 0.f;
    prevBottom_ = shape_.getGlobalBounds().position.y + shape_.getGlobalBounds().size.y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        dir -= 1.f;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        dir += 1.f;
    }if (state_ == State::Jetpack) {
        velocityY_ = -cfg::kJetpackSpeed;
        jetpackTimer_ -= dt;
        if (jetpackTimer_ <= 0.f) {
            state_ = State::Normal;
            shape_.setFillColor(sf::Color::Green);
        }
    } else {
        velocityY_ += cfg::kGravity * dt;
    }
    shape_.move({ dir * cfg::kMoveSpeed * dt, velocityY_ * dt });
    sf::Vector2f pos = shape_.getPosition();
    float w = shape_.getSize().x;
    if (pos.x > cfg::kWindowWidth){
        shape_.setPosition({-w , pos.y});
    } else if (pos.x + w < 0){
        shape_.setPosition({cfg::kWindowWidth , pos.y});
    }
}

void Player::draw(sf::RenderTarget& target) const{
    target.draw(shape_);
}

void Player::activeJetpack() {
    state_ = State::Jetpack;
    jetpackTimer_ = cfg::kJetpackDuration;
    shape_.setFillColor(sf::Color(255,140,0));
}

bool Player::isJetpacking() const {
    return state_ == State::Jetpack;
}

void Player::bounce(float multiplayer){
    velocityY_ = -cfg::kJumpSpeed * multiplayer;
}
sf::FloatRect Player::getBounds() const{
    return shape_.getGlobalBounds();
}
float Player::getVelocityY() const{
    return velocityY_;
}