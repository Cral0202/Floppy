#include "Player.h"

Player::Player(float x, float y) {
	initVariables();

	player.setRadius(playerSize);
	player.setFillColor(sf::Color::Red);
	player.setPosition(x, y);
}

Player::~Player() {
}

void Player::initVariables() {
	playerSize = 20.f;
}

void Player::move(float offset, float height) {
	// Update the velocity due to gravity
	velocity.y += gravity;

	// Update the player's position based on velocity
	player.move(sf::Vector2f(0.f, velocity.y));

	// Keep the player within the window bounds
	// Makes it so player can't go under map
	if (player.getPosition().y >= height - playerSize) {
		player.setPosition(player.getPosition().x, height - playerSize);
		velocity.y = 0.0f; // Reset velocity when player hits the ground
	}
	// Makes it so player can't go above map
	else if (player.getPosition().y <= 0 - playerSize) {
		player.setPosition(player.getPosition().x, 0 - playerSize);
		velocity.y = 0.0f; // Reset velocity when player hits the ground
	}
}

void Player::jump() {
	velocity.y = -3.0f; // Adjust this value for the desired jump height
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(player);
}

sf::Vector2f Player::getPosition() {
	return player.getPosition();
}
