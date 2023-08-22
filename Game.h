#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Game {
private:
	sf::RenderWindow* window; // The window
	sf::Event event; // The events
	sf::VideoMode videoMode; // The videomode

	// Game objects
	sf::RectangleShape bottomTower;
	sf::RectangleShape topTower;

	void initVariables(); // Used to initialize variables
	void initWindow(); // Used to initialize the window
	void initTowers(); // Used to initialize the towers
public:
	// Constructor & Destructor
	Game();
	~Game();

	const bool running() const; // Used to check if game/window is running
	void pollEvents(); // Used to poll events
	void update(); // Used to update game state
	void render(); // Used to render game
};

