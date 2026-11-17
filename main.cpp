#include <SFML/Graphics.hpp>
#include "Player.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({480,800}), "Toodle");
    window.setFramerateLimit(60);

    sf::Clock clock;
    Player player({220.f,400.f});
    const float floorY = 800.f;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        float dt = std::min(clock.restart().asSeconds(), 0.05f);
        player.update(dt);
        const sf::FloatRect b = player.getBounds();
        if (player.getVelocityY() > 0.f && b.position.y + b.size.y >= floorY) {
            player.bounce();
        }
        window.clear(sf::Color(30,30,40));
        player.draw(window);
        window.display();
    }
    return 0;
}
