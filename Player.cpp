#include "Player.h"

Player::Player(float x, float y, sf::Texture& texture) {
	initVariables();

	player.setRadius(playerSize);
	//player.setFillColor(sf::Color::Red);
	player.setPosition(x, y);

	playerSprite.setTexture(texture);
	playerSprite.setPosition(x, y); // Background position
	playerSprite.setScale(0.65f, 0.622f);  // Background scale
}

Player::~Player() {
}

void Player::initVariables() {
	playerSize = 20.f;
	touchingGround = false;
}

void Player::move(float offset, float height) {
	// Update the velocity due to gravity
	velocity.y += gravity;

	// Update the player's position based on velocity
	player.move(sf::Vector2f(0.f, velocity.y));
	playerSprite.move(sf::Vector2f(0.f, velocity.y));

	if (velocity.y > 0 && !touchingGround)
		playerSprite.setRotation(velocity.y * 6);
	else if (velocity.y < 0 && !touchingGround)
		playerSprite.setRotation(velocity.y * 3);
	// Keep the player within the window bounds
	// Makes it so player can't go under map
	if (player.getPosition().y >= height - playerSize) {
		player.setPosition(player.getPosition().x, height - playerSize);
		playerSprite.setPosition(player.getPosition().x, height - playerSize);
		velocity.y = 0.0f; // Reset velocity when player hits the ground
		touchingGround = true;
	}
	// Makes it so player can't go above map
	else if (player.getPosition().y <= 0 - playerSize) {
		player.setPosition(player.getPosition().x, 0 - playerSize);
		playerSprite.setPosition(player.getPosition().x, 0 - playerSize);
		velocity.y = 0.0f; // Reset velocity when player hits the ground
	}
}

void Player::jump() {
	velocity.y = -3.5f; // Adjust this value for the desired jump height
}

void Player::draw(sf::RenderWindow& window) {
	//window.draw(player);
	window.draw(playerSprite);
}

sf::Vector2f Player::getPosition() {
	return player.getPosition();
}

void Player::setPosition(float x, float y) {
	player.setPosition(sf::Vector2f(x, y));
	playerSprite.setPosition(sf::Vector2f(x, y));
	touchingGround = false;
}

void Player::setSpriteRotation(float r) {
	playerSprite.setRotation(r);
}

bool Player::getTouchingGround() {
	return touchingGround;
}

bool Player::collidesWithCollider(const Collider& collider) const {
	// Calculate player's bounding box
	sf::FloatRect playerBounds = player.getGlobalBounds();

	// Calculate tower's bounding box
	sf::FloatRect colliderBounds = collider.getBoundingBox();

	// Check for intersection
	return playerBounds.intersects(colliderBounds);
}

// Inside Player class
bool Player::collidesWithTower(const Tower& tower) const {
	// Calculate player's bounding box
	sf::FloatRect playerBounds = player.getGlobalBounds();

	// Calculate tower's bounding box
	sf::FloatRect towerBounds = tower.getBoundingBox();

	// Check for intersection
	return playerBounds.intersects(towerBounds);
}
