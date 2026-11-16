#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({480,800}), "Toodle");
    window.setFramerateLimit(60);

    sf::Clock clock;

    sf::RectangleShape box{{40.f, 40.f}};
    box.setFillColor(sf::Color::Green);
    box.setPosition({0.f, 380.f});
    const float speed = 200.f;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        float dt = clock.restart().asSeconds();
        box.move({speed * dt, 0.f});
        if (box.getPosition().x > 480) {
            box.setPosition({-40.f,380.f});
        }
        window.clear(sf::Color(30,30,40));
        window.draw(box);
        window.display();
    }
    return 0;
}
