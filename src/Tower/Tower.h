#pragma once

#include <SFML/Graphics.hpp>

namespace TowerConfig {
    const float DefaultWidth = 50.f;
    const float DefaultHeight = 240.f;
    const float ScaleX = 0.193f;
    const float ScaleY = 0.185f;
}

class Tower {
  private:
    sf::RectangleShape tower;
    sf::Sprite towerSprite;

    float width;
    float height;

  public:
    Tower(float x, float y, sf::Texture &texture, float h = TowerConfig::DefaultHeight);

    void move(float offset);
    void draw(sf::RenderWindow &window) const;

    float getHeight() const { return height; }
    float getWidth() const { return width; }
    sf::Vector2f getPosition() const { return tower.getPosition(); }
    sf::FloatRect getBoundingBox() const { return tower.getGlobalBounds(); }
};
