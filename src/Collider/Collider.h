#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Collider {
  private:
    sf::RectangleShape collider;
    bool hasCollided;

  public:
    Collider(float width, float height, float x, float y);

    void move(float offset);
    void collides();
    bool getHasCollided() const { return hasCollided; }

    sf::Vector2f getPosition() const { return collider.getPosition(); }
    sf::FloatRect getBoundingBox() const { return collider.getGlobalBounds(); }
};
