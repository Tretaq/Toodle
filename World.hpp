#pragma once
#include <random>
#include <SFML/Graphics.hpp>
#include "Platform.hpp"
#include <memory>
class World {
public:
    World();
    void update(const sf::View& view, float dt);
    void draw(sf::RenderTarget& target) const;
    const std::vector<std::unique_ptr<Platform>>& platforms() const;
private:
    void spawnPlatform();
    void removeBelow(float bottomY);
    std::vector<std::unique_ptr<Platform>> platforms_;
    std::mt19937 rng_;
    float highestY_;
};