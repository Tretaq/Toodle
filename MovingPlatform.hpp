#pragma once
#include "Platform.hpp"
class MovingPlatform : public Platform{
public:
    MovingPlatform(sf::Vector2f position, sf::Vector2f size);
    void update(float dt) override;
private:
    float speed_;
};

