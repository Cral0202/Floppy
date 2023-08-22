#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Player {
private:
	sf::CircleShape player; // The player

	float playerSize; // The size of the player

	sf::Vector2f velocity; // Velocity of the player
	const float gravity = 0.05f; // Gravity effect

	void initVariables(); // Initializes the variables
public:
	Player(float x, float y);
	~Player();
	
	void move(float offset´, float height); // Moves the player
	void jump(); // Player jumps
	void draw(sf::RenderWindow& window); // Draws the towers to the window
	sf::Vector2f getPosition(); // Returns the position of the player
};

