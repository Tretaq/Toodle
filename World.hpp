#pragma once
#include <random>
#include <SFML/Graphics.hpp>
#include "Platform.hpp"
class World {
public:
    World();
    void update(const sf::View& view);
    void draw(sf::RenderTarget& target) const;
    const std::vector<Platform>& platforms() const;
private:
    void spawnPlatform();
    void removeBelow(float bottomY);
    std::vector<Platform> platforms_;
    std::mt19937 rng_;
    float highestY_;
};