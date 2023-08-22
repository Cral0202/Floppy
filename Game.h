#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Tower.h"
#include "Player.h"

class Game {
private:
	sf::RenderWindow* window; // The window
	sf::Event event; // The events
	sf::VideoMode videoMode; // The videomode

	// Game objects
	std::vector<Tower> towers;
	Player* player;

	// Timer variables
	int spawnTowerCounter; // Keeps track of when towers should spawn
	bool startGame; // Keeps track of if game should start

	void initVariables(); // Used to initialize variables
	void initWindow(); // Used to initialize the window
	void initEntities(); // Used to initialize the entities

	void spawnTowers(); // Used to spawn towers
	void moveGame(); // Used to move the game screen
	void endGame(); // Used to end the game
public:
	// Constructor & Destructor
	Game();
	~Game();

	const bool running() const; // Used to check if game/window is running
	void pollEvents(); // Used to poll events
	void update(); // Used to update game state
	void render(); // Used to render game
};

