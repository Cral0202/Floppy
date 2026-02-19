#include "Player.h"

Player::Player(float x, float y, sf::Texture &texture) {
    player.setRadius(PlayerConfig::radius);
    player.setFillColor(sf::Color::Red);
    player.setPosition(x, y);
    player.setOrigin(PlayerConfig::radius, PlayerConfig::radius);

    playerSprite.setTexture(texture);
    playerSprite.setPosition(x, y);
    playerSprite.setOrigin(PlayerConfig::radius, PlayerConfig::radius);

    float desiredWidth = PlayerConfig::radius * 2.f;
    float desiredHeight = PlayerConfig::radius * 2.f;

    sf::Vector2u textureSize = texture.getSize();
    float scaleX = desiredWidth / textureSize.x;
    float scaleY = desiredHeight / textureSize.y;

    playerSprite.setScale(scaleX, scaleY);
}

void Player::move(float offset, float height) {
    // Update the velocity due to gravity
    velocity.y += GameplayConfig::gravity;

    // Update the player's position based on velocity
    player.move(sf::Vector2f(0.f, velocity.y));
    playerSprite.move(sf::Vector2f(0.f, velocity.y));

    float radius = player.getRadius();

    // Prevent player from going under the map
    if (player.getPosition().y + radius >= height) {
        player.setPosition(player.getPosition().x, height - radius);
        playerSprite.setPosition(player.getPosition().x, height - radius);

        velocity.y = 0.0f;
        touchingGround = true;
    }
    // Prevent player from going over the map
    else if (player.getPosition().y - radius <= 0.f) {
        player.setPosition(player.getPosition().x, radius);
        playerSprite.setPosition(player.getPosition().x, radius);

        velocity.y = 0.0f;
    }
}

void Player::setPosition(float x, float y) {
    player.setPosition(sf::Vector2f(x, y));
    playerSprite.setPosition(sf::Vector2f(x, y));
    touchingGround = false;
}

bool Player::checkCollision(sf::FloatRect rect) const {
    float radius = player.getRadius();
    sf::Vector2f center = player.getPosition();

    // Find the point on the rectangle that is closest to the center of the circle
    float closestX = std::max(rect.left, std::min(center.x, rect.left + rect.width));
    float closestY = std::max(rect.top, std::min(center.y, rect.top + rect.height));

    // Calculate the distance vector between the circle's center and this closest point.
    float distanceX = center.x - closestX;
    float distanceY = center.y - closestY;

    // Use Pythagorean theorem to see if the distance is less than the radius
    return (distanceX * distanceX + distanceY * distanceY) < (radius * radius);
}
