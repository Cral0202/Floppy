#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <filesystem>

class Button {
private:
	sf::RectangleShape button; // The button
	float buttonHeight; // The height of the button
	float buttonWidth; // The width of the button
	float xPosition; // The x position of the button
	float yPosition; // The y position of the button
	sf::Color color; // The color of the button
	sf::Text buttonText; // The text of the button
	std::shared_ptr<sf::Font> font; // The font, which uses a shared smart pointer
public:
	Button(float height, float width, float x, float y, sf::Color color, const std::string& text);
	Button();
	~Button();

	sf::FloatRect getBoundingBox() const;
	void draw(sf::RenderWindow& window); // Draws the button to the window
};

