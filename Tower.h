#pragma once

#include <SFML/Graphics.hpp>

class Tower {
private:
	sf::RectangleShape tower;

	// The width and height of the towers
	float towerHeight;
	float towerWidth;
public:
	Tower(float x, float y);
	~Tower();

	void initVariables(); // Initializes the variables
	void move(float offset); // Moves the towers
	void draw(sf::RenderWindow& window); // Draws the towers to the window
	sf::Vector2f getPosition();
};

