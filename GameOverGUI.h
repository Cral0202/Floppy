#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"

class GameOverGUI {
private:
	sf::RenderWindow* window;
	sf::Event event;
	Game& game;

	sf::RectangleShape button;
	float buttonHeight;
	float buttonWidth;
	//sf::Text buttonText;
public:
	GameOverGUI(Game& game);
	~GameOverGUI();

	void initVariables(); // Used to init variables
	void initEntities(); // Used to initialize the entities
	void pollEvents(); // Used to poll events
	void update(); // Used to update game state
	void render(); // Used to render game
};

