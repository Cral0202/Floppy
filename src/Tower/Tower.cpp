#include "Tower.h"

Tower::Tower(float x, float y, float w, float h, sf::Texture &texture) {
    tower.setSize(sf::Vector2f(w, h));
    tower.setFillColor(sf::Color::Cyan);
    tower.setPosition(x, y);

    towerSprite.setTexture(texture);
    towerSprite.setPosition(x, y);
    towerSprite.setScale(TowerConfig::spriteScaleX, TowerConfig::spriteScaleY);
}

void Tower::move(float offset) {
    tower.move(sf::Vector2f(offset, 0.f));
    towerSprite.move(sf::Vector2f(offset, 0.f));
}
