#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Platform.hpp"
#include "Player.hpp"
#include "World.hpp"

namespace {
    enum class GameState {Playing, GameOver};
    int loadHighScore() {
        std::ifstream in("highscore.txt");
        int hs = 0;
        in >> hs;
        return hs;
    }
    void saveHighScore(int hs) {
        std::ofstream out("highscore.txt");
        out << hs;
    }
    void centerText(sf::Text& t, float x, float y){
        sf::FloatRect b = t.getLocalBounds();
        t.setOrigin({b.position.x + b.size.x / 2.f, b.position.y + b.size.y / 2.f});
        t.setPosition({x,y});
    }
}
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
    sf::Text scoreText(font,"0",32);
    World world;
    GameState state = GameState::Playing;
    int highScore = loadHighScore();
    sf::Text gameOverText(font,"",32);
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
                if (key->code == sf::Keyboard::Key::Space && state == GameState::GameOver) {
                    player = Player({220.f,400.f});
                    world = World();
                    view.setCenter({240.f,400.f});
                    highestY = startY;
                    score = 0.f;
                    scoreText.setString("0");
                    state = GameState::Playing;
                }
            }
        }
        float dt = std::min(clock.restart().asSeconds(), 0.05f);
        if (state == GameState::Playing) {
            player.update(dt);
            world.update(view,dt);
            for (const auto& p : world.platforms()) {
                if (!p->isAlive()) continue;
                if (player.isLandingOn(p->getBounds()) && p->onLanded()) {
                    player.bounce(p->bounceStrength());
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
            const float viewBottom = view.getCenter().y + view.getSize().y / 2.f;
            if (currentY > viewBottom) {
                state = GameState::GameOver;
                const int finalScore =  static_cast<int>(score);
                if (finalScore > highScore) {
                    highScore = finalScore;
                    saveHighScore(highScore);
                }
                gameOverText.setString("GAME OVER\nScore: " + std::to_string(finalScore) + "\nBest: " + std::to_string(highScore) + "\n\n Press SPACE");
                centerText(gameOverText,240.f,300.f);
            }
        }
        window.clear(sf::Color(30,30,40));

        window.setView(view);
        world.draw(window);
        player.draw(window);
        window.setView(window.getDefaultView());
        window.draw(scoreText);
        if (state == GameState::GameOver) window.draw((gameOverText));
        window.display();
    }
    return 0;
}
