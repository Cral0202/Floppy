#include "Game.h"

void Game::initVariables() {
	window = nullptr;
}

void Game::initWindow() {
	videoMode.height = 600;
	videoMode.width = 800;
	window = new sf::RenderWindow (this->videoMode, "Floppy", sf::Style::Default);
}

Game::Game() {
	initVariables();
	initWindow();
}

Game::~Game() {
	delete window;
}

const bool Game::running() const {
	return window->isOpen();
}

void Game::pollEvents() {
    while (window->pollEvent(event)) {
        // Closes the window if exit button is pressed
        if (event.type == sf::Event::Closed) {
            window->close();
            break;
        }
        // Closes the window if escape button is pressed
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window->close();
                break;
            }
        }

    }
}

void Game::update() {
    pollEvents();
}

void Game::render() {
    window->clear(); // Clear old frame

    // Draw game objects


    window->display(); // Draws what has been rendered so far
}
