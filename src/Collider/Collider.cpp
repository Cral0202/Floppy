#include "Collider.h"

Collider::Collider(float x, float y, float w, float h) {
    collider.setSize(sf::Vector2f(w, h));
    collider.setFillColor(sf::Color::Transparent);
    collider.setPosition(x, y);
}
