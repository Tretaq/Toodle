#include <SFML/Graphics.hpp>

#include "Platform.hpp"
#include "Player.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({480,800}), "Toodle");
    window.setFramerateLimit(60);
    sf::View view({240.f, 400.f},{480.f,800.f});
    sf::Clock clock;
    Player player({220.f,400.f});
    const float floorY = 800.f;
    std::vector<Platform> platforms;
    platforms.push_back({{180.f,650.f},{120.f,15.f}});
    platforms.push_back({{60.f,530.f},{100.f,15.f}});
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
        if (view.getCenter().y != player.getBounds().position.y && view.getCenter().y > player.getBounds().position.y ) {
            view.setCenter({view.getCenter().x ,player.getBounds().position.y});
        }
        float dt = std::min(clock.restart().asSeconds(), 0.05f);
        player.update(dt);
        const sf::FloatRect b = player.getBounds();

        window.clear(sf::Color(30,30,40));
        window.setView(view);
        player.draw(window);
        for (const Platform& p : platforms) {
            p.draw(window);
        }
        window.display();
    }
    return 0;
}
