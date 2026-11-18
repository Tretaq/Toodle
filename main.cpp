#include <SFML/Graphics.hpp>

#include "Platform.hpp"
#include "Player.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({480,800}), "Toodle");
    window.setFramerateLimit(60);

    sf::Clock clock;
    Player player({220.f,400.f});
    const float floorY = 800.f;
    std::vector<Platform> platforms;
    platforms.push_back({{180.f,650.f},{120.f,15.f}});
    platforms.push_back({{60.f,5300.f},{100.f,15.f}});
    platforms.push_back({{300.f,410.f},{100.f,15.f}});
    platforms.push_back({{140.f,290.f},{100.f,15.f}});
    platforms.push_back({{320.f,170.f},{100.f,15.f}});
    platforms.push_back({{80.f,50.f},{100.f,15.f}});
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        for (const Platform& p : platforms) {
            if (player.isLandingOn(p.getBounds())) {
                player.bounce();
            }
        }
        float dt = std::min(clock.restart().asSeconds(), 0.05f);
        player.update(dt);
        const sf::FloatRect b = player.getBounds();

        window.clear(sf::Color(30,30,40));
        player.draw(window);
        for (const Platform& p : platforms) {
            p.draw(window);
        }
        window.display();
    }
    return 0;
}
