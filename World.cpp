#include "World.hpp"
#include "Constants.hpp"
#include <algorithm>
namespace {
    constexpr float kPlatformWidth = 80.f;
    constexpr float kPlatformHeight = 15.f;
    constexpr float kMinGap = 60.f;
    constexpr float kMaxGap = cfg::kJumpHight * 0.65f;
    constexpr float kSpawnMargin = 100.f;
}
World::World() : rng_(std::random_device{}()) {
    platforms_.emplace_back(sf::Vector2f{0.f,780.f},sf::Vector2f{cfg::kWindowWidth, kPlatformHeight});
    highestY_ = 780.f;
}

void World::update(const sf::View &view) {
    const float top = view.getCenter().y - view.getSize().y /2.f;
    const float bottom = view.getCenter().y + view.getSize().y / 2.f;
    while (highestY_ < top) {
        spawnPlatform();
    }
    removeBelow(bottom);
}

void World::draw(sf::RenderTarget &target) const {
   for (const Platform& p : platforms_)
   {
       p.draw(target);
   }
}

const std::vector<Platform> &World::platforms() const {
    return platforms_;
}

void World::removeBelow(float bottomY) {
    platforms_.erase(
        std::remove_if(platforms_.begin(), platforms_.end(),
            [bottomY](const Platform& p) {
               return p.getBounds().position.y > bottomY;
            }),
    platforms_.end());
}

void World::spawnPlatform() {
    std::uniform_real_distribution<float> gapDist(kMinGap,kMaxGap);
    std::uniform_real_distribution<float> xDist(0.f,cfg::kWindowWidth - kPlatformWidth);
    highestY_ -= gapDist(rng_);
    platforms_.emplace_back(sf::Vector2f{xDist(rng_), highestY_},sf::Vector2f{kPlatformWidth,kPlatformHeight});

}
