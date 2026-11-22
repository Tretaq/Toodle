#include "World.hpp"
#include "Constants.hpp"
#include <algorithm>

#include "MovingPlatform.hpp"

namespace {
    constexpr float kPlatformWidth = 80.f;
    constexpr float kPlatformHeight = 15.f;
    constexpr float kMinGap = 60.f;
    constexpr float kMaxGap = cfg::kJumpHight * 0.65f;
    constexpr float kSpawnMargin = 100.f;
    constexpr float kMinMoveSpeed = 60.f;
    constexpr float kMaxMoveSpeed = 160.f;
    enum class Type {Normal, Moving};
}
World::World() : rng_(std::random_device{}()) {
    platforms_.push_back(std::make_unique<Platform>(sf::Vector2f{0.f,780.f},sf::Vector2f{cfg::kWindowWidth, kPlatformHeight}));
    highestY_ = 780.f;
}

void World::update(const sf::View &view, float dt) {
    for (auto& p : platforms_) p->update(dt);
    const float top = view.getCenter().y - view.getSize().y /2.f;
    const float bottom = view.getCenter().y + view.getSize().y / 2.f;
    while (highestY_ > top - kSpawnMargin) {
        spawnPlatform();
    }
    removeBelow(bottom);
}

void World::draw(sf::RenderTarget &target) const {
   for (const auto& p : platforms_)
   {
       p->draw(target);
   }
}

const std::vector<std::unique_ptr<Platform>> &World::platforms() const {
    return platforms_;
}

void World::removeBelow(float bottomY) {
    platforms_.erase(
        std::remove_if(platforms_.begin(), platforms_.end(),
            [bottomY](const std::unique_ptr<Platform>& p) {
               return p->getBounds().position.y > bottomY;
            }),
    platforms_.end());
}

void World::spawnPlatform() {
    std::uniform_real_distribution<float> gapDist(kMinGap,kMaxGap);
    std::uniform_real_distribution<float> xDist(0.f,cfg::kWindowWidth - kPlatformWidth);
    std::uniform_real_distribution<float> speedDist(kMinMoveSpeed,kMaxMoveSpeed);
    std::bernoulli_distribution coinFlip(0.5);
    std::discrete_distribution<int> typeDist({80, 20});// each type has a weight (thats cooolllll)
    highestY_ -= gapDist(rng_);
    float x = xDist(rng_);
    const sf::Vector2f pos{x,highestY_};
    const sf::Vector2f size{kPlatformWidth,kPlatformHeight};
    switch (static_cast<Type>(typeDist(rng_))){
    case Type::Moving:{
            const float dir = coinFlip(rng_) ? 1.f : -1.f;
            platforms_.push_back(std::make_unique<MovingPlatform>(pos,size,dir * speedDist(rng_)));
            break;
        }
    case Type::Normal:
    default:
        platforms_.push_back(std::make_unique<Platform>(pos,size));
    }
}
