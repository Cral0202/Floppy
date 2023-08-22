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
	playerSize = 10.f;
}

void Player::move(float offset) {
	player.move(sf::Vector2f(0.f, offset));
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(player);
}

sf::Vector2f Player::getPosition() {
	return player.getPosition();
}
