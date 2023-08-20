#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game {
private:
	sf::RenderWindow* window; // The window
	sf::Event event; // The events
	sf::VideoMode videoMode; // The videomode

	void initVariables(); // Used to initialize variables
	void initWindow(); // Used to initialize the window
public:
	// Constructor & Destructor
	Game();
	~Game();

	const bool running() const; // Used to check if game/window is running
	void pollEvents(); // Used to poll events
	void update(); // Used to update game state
	void render(); // Used to render game
};

