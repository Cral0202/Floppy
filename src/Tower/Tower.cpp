#include "Tower.h"

Tower::Tower(float x, float y, sf::Texture &texture, float h) : width(TowerConfig::DefaultWidth), height(h) {
    tower.setSize(sf::Vector2f(width, height));
    tower.setFillColor(sf::Color::Cyan);
    tower.setPosition(x, y);

    towerSprite.setTexture(texture);
    towerSprite.setPosition(x, y);
    towerSprite.setScale(TowerConfig::ScaleX, TowerConfig::ScaleY);
}

void Tower::move(float offset) {
    tower.move(sf::Vector2f(offset, 0.f));
    towerSprite.move(sf::Vector2f(offset, 0.f));
}
