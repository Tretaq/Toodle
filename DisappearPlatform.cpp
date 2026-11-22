#include "DisappearPlatform.hpp"

DisappearPlatform::DisappearPlatform(sf::Vector2f position, sf::Vector2f size): Platform(position,size) {
  shape_.setFillColor(sf::Color(139,90,43));
}

bool DisappearPlatform::onLanded() {
  alive_ = false;
  shape_.setFillColor(sf::Color(30,30,40));
  return true;
}
