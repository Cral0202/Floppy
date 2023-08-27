#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Tower.h"
#include "Collider.h"

class Player {
private:
	sf::CircleShape player; // The player

	float playerSize; // The size of the player
	bool touchingGround; // Checks if the player is touching the ground

	sf::Vector2f velocity; // Velocity of the player
	const float gravity = 0.05f; // Gravity effect

	sf::Sprite playerSprite; // The player sprite

	void initVariables(); // Initializes the variables
public:
	Player(float x, float y, sf::Texture& texture);
	~Player();
	
	void move(float offset´, float height); // Moves the player
	void jump(); // Player jumps
	void draw(sf::RenderWindow& window); // Draws the player to the window
	sf::Vector2f getPosition(); // Returns the position of the player
	void setPosition(float x, float y);
	void setSpriteRotation(float r);
	bool getTouchingGround();
	bool collidesWithTower(const Tower& tower) const; // Returns wether player is colliding with any towers
	bool collidesWithCollider(const Collider& collider) const; // Returns wether player is colliding with any colliders
};

