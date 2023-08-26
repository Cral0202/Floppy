#pragma once

#include <SFML/Graphics.hpp>

class Tower {
private:
	sf::RectangleShape tower;

	// The width and height of the towers
	float towerHeight;
	float towerWidth;

	sf::Sprite towerSprite; // The tower sprite

	void initVariables(); // Initializes the variables
public:
	Tower(float x, float y, sf::Texture& texture);
	Tower();
	~Tower();
	
	void move(float offset); // Moves the towers
	void draw(sf::RenderWindow& window); // Draws the towers to the window
	float getHeight();
	float getWidth();
	sf::Vector2f getPosition(); // Returns the position of the tower
	sf::FloatRect getBoundingBox() const; // Used for collision detection
};

