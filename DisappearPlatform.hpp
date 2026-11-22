#pragma once
#include "Platform.hpp"

class DisappearPlatform : public Platform{
public:
    DisappearPlatform(sf::Vector2f position, sf::Vector2f size);
    bool onLanded() override;
};


