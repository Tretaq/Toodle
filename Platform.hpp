#pragma once
#include <SFML/Graphics.hpp>

class Platform {
public:
    Platform(sf::Vector2f position, sf::Vector2f size);
    virtual ~Platform() = default;
    virtual void update(float dt);
    virtual void onLanded();
    void draw(sf::RenderTarget& target) const;
    sf::FloatRect getBounds() const;
    bool isAlive() const;

protected:
    sf::RectangleShape shape_;
    bool alive_ = true;
};

class MovingPlatform : public Platform
{
    public:
    MovingPlatform(sf::Vector2f position, sf::Vector2f size);
    void update(float dt) override;
    private:
        float speed_;
};


