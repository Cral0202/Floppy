#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Collider : public sf::Drawable {
  private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override { target.draw(collider, states); }

    sf::RectangleShape collider;
    bool hasCollided = false;

  public:
    Collider(float x, float y, float w, float h);

    void move(float offset) { collider.move(sf::Vector2f(offset, 0.f)); }
    void collides() { hasCollided = true; }
    bool getHasCollided() const { return hasCollided; }

    sf::Vector2f getPosition() const { return collider.getPosition(); }
    sf::FloatRect getBoundingBox() const { return collider.getGlobalBounds(); }
};
