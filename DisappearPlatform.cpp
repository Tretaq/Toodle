#include "DisappearPlatform.hpp"

DisappearPlatform::DisappearPlatform(sf::Vector2f position, sf::Vector2f size): Platform(position,size) {
  shape_.setFillColor(sf::Color::White);
}

bool DisappearPlatform::onLanded() {
  alive_ = false;
  return true;
}
