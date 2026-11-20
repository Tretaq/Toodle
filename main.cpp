#include <SFML/Graphics.hpp>

#include "Platform.hpp"
#include "Player.hpp"
#include "World.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({480,800}), "Toodle");
    window.setFramerateLimit(60);
    sf::View view({240.f, 400.f},{480.f,800.f});
    Player player({220.f,400.f});
    sf::Clock clock;
    sf::Font font;
    if (!font.openFromFile("assets/GeistPixel-Regular-VariableFont_ELSH.ttf")) return 1;
    float startY = 400.f;
    float highestY = startY;
    float score = 0.f;
    sf::Text scoreText(font,std::to_string(score),32);

    float y =  480.f;
    World world;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        float dt = std::min(clock.restart().asSeconds(), 0.05f);
        player.update(dt);
        world.update(view);
        for (const Platform& p : world.platforms()) {
            if (player.isLandingOn(p.getBounds())) {
                player.bounce();
            }
        }
        const sf::FloatRect b = player.getBounds();
        float currentY = b.position.y;
        if (currentY < highestY) {
            highestY = currentY;
            score = (startY - highestY) / 10.f;
            scoreText.setString(std::to_string(static_cast<int>(score)));
        }
        if (view.getCenter().y != player.getBounds().position.y && view.getCenter().y > player.getBounds().position.y ) {
            view.setCenter({view.getCenter().x ,player.getBounds().position.y});
        }

        window.clear(sf::Color(30,30,40));

        window.setView(view);
        player.draw(window);
        world.draw(window);
        window.setView(window.getDefaultView());
        window.draw(scoreText);
        window.display();
    }
    return 0;
}
