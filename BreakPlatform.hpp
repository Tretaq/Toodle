#pragma once
#include "Platform.hpp"
class BreakPlatform : public Platform{
public:
    BreakPlatform(sf::Vector2f position, sf::Vector2f size);
    bool onLanded() override;
};