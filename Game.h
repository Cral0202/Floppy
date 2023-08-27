#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <filesystem>
#include "Tower.h"
#include "Player.h"
#include "Collider.h"

class Game {
private:
	sf::RenderWindow* window; // The window
	sf::Event event; // The events
	sf::VideoMode videoMode; // The videomode

	// Game objects
	std::vector<Tower> towers; // A vector for the towers
	Tower tower; // Acts as a reference for a tower
	std::vector<Collider> colliders; // A vector for the colliders
	Player* player; // The player

	sf::Text pointText; // The text of the point counter
	sf::Text restartText; // The restart text
	std::shared_ptr<sf::Font> font; // The font, which uses a shared smart pointer

	sf::Texture backgroundTexture; // The background texture
	sf::Sprite backgroundSprite; // The background sprite
	sf::Texture towerTexture; // The tower texture
	sf::Texture playerTexture; // The player texture

	// Timer variables
	int spawnTowerCounter; // Keeps track of when towers should spawn
	int pointCounter; // Keeps track of the player's points
	bool startGame; // Keeps track of if game should start
	bool endTheGame; // Keeps track of if game should end

	void initVariables(); // Used to initialize variables
	void initWindow(); // Used to initialize the window
	void initEntities(); // Used to initialize the entities

	void givePoint(Collider& collider); // Used to give a point to the player
	void resetGameState(); // Used to reset the game state

	void spawnTowers(); // Used to spawn towers
	void moveGame(); // Used to move the game screen
	void endGame(); // Used to end the game
	void pollEvents(); // Used to poll events
public:
	// Constructor & Destructor
	Game();
	~Game();

	const bool running() const; // Used to check if game/window is running
	sf::RenderWindow* getWindow(); // Used to get the window
	
	void update(); // Used to update game state
	void render(); // Used to render game
};

