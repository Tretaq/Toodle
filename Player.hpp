#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
     Player(sf::Vector2f startPos);

     void update(float dt);
     void draw(sf::RenderTarget& target) const;
     void bounce(float multiplayer = 1.f);
     sf::FloatRect getBounds() const;
     float getVelocityY() const;
    bool isLandingOn(const sf::FloatRect& platform) const;
    void activeJetpack();
    bool isJetpacking() const;
private:
    enum class State { Normal , Jetpack};
    State state_ = State::Normal;
    float jetpackTimer_ = 0.f;
     sf::RectangleShape shape_;
     float velocityY_ = 0.f;
    float prevBottom_ = 0.f;
};