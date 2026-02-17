#include "Collider.h"

Collider::Collider(float width, float height, float x, float y) {
    collider.setSize(sf::Vector2f(width, height));
    collider.setFillColor(sf::Color::Transparent);
    collider.setPosition(x, y);
}
