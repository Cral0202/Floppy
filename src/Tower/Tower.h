#pragma once

#include "../Config.h"

#include <SFML/Graphics.hpp>

class Tower : public sf::Drawable {
  private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override { target.draw(towerSprite, states); }

    sf::RectangleShape tower;
    sf::Sprite towerSprite;

    float width;
    float height;

  public:
    Tower(float x, float y, float w, float h, sf::Texture &texture);

    void move(float offset);

    float getHeight() const { return height; }
    float getWidth() const { return width; }
    sf::Vector2f getPosition() const { return tower.getPosition(); }
    sf::FloatRect getBoundingBox() const { return tower.getGlobalBounds(); }
};
