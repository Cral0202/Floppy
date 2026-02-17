#include "Collider.h"

Collider::Collider(float width, float height, float x, float y) {
    collider.setSize(sf::Vector2f(width, height));
    collider.setFillColor(sf::Color::Transparent);
    collider.setPosition(x, y);

    hasCollided = false;
}

void Collider::move(float offset) {
    collider.move(sf::Vector2f(offset, 0.f));
}

void Collider::collides() {
    hasCollided = true;
}

bool Collider::getHasCollided() const {
    return hasCollided;
}

void Collider::draw(sf::RenderWindow &window) const {
    window.draw(collider);
}
