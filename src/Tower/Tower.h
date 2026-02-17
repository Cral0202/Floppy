#pragma once

#include <SFML/Graphics.hpp>

namespace TowerConfig {
    const float DefaultWidth = 50.f;
    const float DefaultHeight = 240.f;
    const float ScaleX = 0.193f;
    const float ScaleY = 0.185f;
}

class Tower : public sf::Drawable {
  private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(towerSprite, states);
    }

    sf::RectangleShape tower;
    sf::Sprite towerSprite;

    float width;
    float height;

  public:
    Tower(float x, float y, sf::Texture &texture, float h = TowerConfig::DefaultHeight);

    void move(float offset);

    float getHeight() const { return height; }
    float getWidth() const { return width; }
    sf::Vector2f getPosition() const { return tower.getPosition(); }
    sf::FloatRect getBoundingBox() const { return tower.getGlobalBounds(); }
};
