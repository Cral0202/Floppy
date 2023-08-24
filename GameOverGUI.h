#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "Button.h"

class GameOverGUI {
private:
	sf::RenderWindow* window; // The window
	sf::Event event; // Used for events
	Game& game; // The game instance

	Button restartButton; // The restart button
	float restartButtonWidth; // The width of the restart button
	float restartButtonHeight; // The height of the restart button

	bool shouldRestart; // If true game should restart
public:
	GameOverGUI(Game& game);
	~GameOverGUI();

	bool getShouldRestart();
	void resetState();
	void initVariables(); // Used to init variables
	void pollEvents(); // Used to poll events
	void update(); // Used to update game state
	void render(); // Used to render game
};

