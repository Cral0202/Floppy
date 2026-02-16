#include "Collider.h"

Collider::Collider(float width, float height, float x, float y) {
    collider.setSize(sf::Vector2f(width, height));
    collider.setFillColor(sf::Color::Transparent);
    collider.setPosition(x, y);

    hasCollided = false;
}

Collider::~Collider() {
}

void Collider::move(float offset) {
    collider.move(sf::Vector2f(offset, 0.f));
}

void Collider::collides() {
    hasCollided = true;
}

bool Collider::getHasCollided() {
    return hasCollided;
}

sf::Vector2f Collider::getPosition() {
    return collider.getPosition();
}

sf::FloatRect Collider::getBoundingBox() const {
    return collider.getGlobalBounds();
}

void Collider::draw(sf::RenderWindow &window) {
    window.draw(collider);
}
