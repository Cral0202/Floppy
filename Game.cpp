#include "Game.h"

void Game::initVariables() {
	window = nullptr;
}

void Game::initWindow() {
	videoMode.height = 600;
	videoMode.width = 800;
	window = new sf::RenderWindow (this->videoMode, "Floppy", sf::Style::Default);

    window->setFramerateLimit(144);
}

void Game::initTowers() {
    // Sets up the bottom towers
    bottomTower.setSize(sf::Vector2f(50.f, 200.f));
    bottomTower.setFillColor(sf::Color::Cyan);
    bottomTower.setPosition(600.f, (600.f - 200.f));

    // Sets up the top towers
    topTower.setSize(sf::Vector2f(50.f, 200.f));
    topTower.setFillColor(sf::Color::Cyan);
    topTower.setPosition(600.f, 0.f);
}

Game::Game() {
	initVariables();
	initWindow();
    initTowers();
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

    // Gets mouse position relative to the window
    std::cout << "Mouse pos: " << sf::Mouse::getPosition(*window).x << " " << sf::Mouse::getPosition(*window).y << std::endl;
}

void Game::render() {
    window->clear(); // Clear old frame

    // Draw game objects
    window->draw(bottomTower);
    window->draw(topTower);

    window->display(); // Draws what has been rendered so far
}
