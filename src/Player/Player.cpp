#include "Player.h"

Player::Player(float x, float y, sf::Texture &texture) {
    player.setRadius(PlayerConfig::radius);
    player.setFillColor(sf::Color::Red);
    player.setPosition(x, y);

    playerSprite.setTexture(texture);
    playerSprite.setPosition(x, y);
    playerSprite.setScale(PlayerConfig::spriteScaleX, PlayerConfig::spriteScaleY);
}

void Player::move(float offset, float height) {
    // Update the velocity due to gravity
    velocity.y += GameplayConfig::gravity;

    // Update the player's position based on velocity
    player.move(sf::Vector2f(0.f, velocity.y));
    playerSprite.move(sf::Vector2f(0.f, velocity.y));

    // Prevent player from going under the map
    if (player.getPosition().y >= height - PlayerConfig::radius) {
        player.setPosition(player.getPosition().x, height - PlayerConfig::radius);
        playerSprite.setPosition(player.getPosition().x, height - PlayerConfig::radius);
        velocity.y = 0.0f;
        touchingGround = true;
    }
    // Prevent player from going over the map
    else if (player.getPosition().y <= 0 - PlayerConfig::radius) {
        player.setPosition(player.getPosition().x, 0 - PlayerConfig::radius);
        playerSprite.setPosition(player.getPosition().x, 0 - PlayerConfig::radius);
        velocity.y = 0.0f;
    }
}

void Player::setPosition(float x, float y) {
    player.setPosition(sf::Vector2f(x, y));
    playerSprite.setPosition(sf::Vector2f(x, y));
    touchingGround = false;
}

bool Player::collidesWithCollider(const Collider &collider) const {
    sf::FloatRect playerBounds = player.getGlobalBounds();
    sf::FloatRect colliderBounds = collider.getBoundingBox();
    return playerBounds.intersects(colliderBounds);
}

bool Player::collidesWithTower(const Tower &tower) const {
    sf::FloatRect playerBounds = player.getGlobalBounds();
    sf::FloatRect towerBounds = tower.getBoundingBox();
    return playerBounds.intersects(towerBounds);
}
