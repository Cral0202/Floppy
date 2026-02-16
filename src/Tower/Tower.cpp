#include "Tower.h"

Tower::Tower(float x, float y, sf::Texture &texture) {
    initVariables();

    tower.setSize(sf::Vector2f(towerWidth, towerHeight));
    tower.setFillColor(sf::Color::Cyan);
    tower.setPosition(x, y);

    towerSprite.setTexture(texture);
    towerSprite.setPosition(x, y);
    towerSprite.setScale(0.193f, 0.185f);
}

Tower::Tower() {
    initVariables();
}

Tower::~Tower() {
}

void Tower::initVariables() {
    towerWidth = 50.f;
    towerHeight = 240.f;
}

void Tower::move(float offset) {
    tower.move(sf::Vector2f(offset, 0.f));
    towerSprite.move(sf::Vector2f(offset, 0.f));
}

void Tower::draw(sf::RenderWindow &window) {
    window.draw(towerSprite);
}

float Tower::getHeight() {
    return towerHeight;
}

float Tower::getWidth() {
    return towerWidth;
}

sf::Vector2f Tower::getPosition() {
    return tower.getPosition();
}

sf::FloatRect Tower::getBoundingBox() const {
    return tower.getGlobalBounds();
}
