#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "Button.h"

class GameOverGUI {
private:
	sf::RenderWindow* window;
	sf::Event event;
	Game& game;

	Button restartButton;
public:
	GameOverGUI(Game& game);
	~GameOverGUI();

	void initVariables(); // Used to init variables
	void pollEvents(); // Used to poll events
	void update(); // Used to update game state
	void render(); // Used to render game
};

