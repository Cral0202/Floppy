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

  void move(float offset); // Moves the collider
  void collides();
  bool getHasCollided();
  sf::Vector2f getPosition(); // Returns the position of the collider
  sf::FloatRect getBoundingBox()
      const; // Returns the bounding box, used for collision detection
  void draw(sf::RenderWindow &window); // Draws the collider to the window
};
