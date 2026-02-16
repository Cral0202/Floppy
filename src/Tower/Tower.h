#pragma once

#include <SFML/Graphics.hpp>

class Tower {
  private:
    sf::RectangleShape tower;
    sf::Sprite towerSprite;

    float towerHeight;
    float towerWidth;

    void initVariables();

  public:
    Tower(float x, float y, sf::Texture &texture);
    Tower();
    ~Tower();

    void move(float offset);
    void draw(sf::RenderWindow &window);
    float getHeight();
    float getWidth();
    sf::Vector2f getPosition();
    sf::FloatRect getBoundingBox() const;
};
