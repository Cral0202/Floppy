#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Collider {
  private:
    sf::RectangleShape collider;
    bool hasCollided;

  public:
    Collider(float width, float height, float x, float y);
    ~Collider();

    void move(float offset);
    void collides();
    bool getHasCollided();
    sf::Vector2f getPosition();
    sf::FloatRect getBoundingBox() const;
    void draw(sf::RenderWindow &window);
};
