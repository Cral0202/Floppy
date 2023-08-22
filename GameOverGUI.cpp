#include "GameOverGUI.h"

GameOverGUI::GameOverGUI(Game& game) : game(game) {
	this->game = game;
	initVariables();
    initEntities();
}

GameOverGUI::~GameOverGUI() {
}

void GameOverGUI::initVariables() {
	window = game.getWindow();
    buttonHeight = 100.f;
    buttonWidth = 250.f;
}

void GameOverGUI::initEntities() {
    button.setPosition((400.f - buttonWidth / 2), (300.f - buttonHeight / 2));
    button.setSize(sf::Vector2f(buttonWidth, buttonHeight));
    button.setFillColor(sf::Color::Blue);
}

void GameOverGUI::pollEvents() {
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

void GameOverGUI::update() {
	pollEvents();
}

void GameOverGUI::render() {
	window->clear(); // Clear old frame

    window->draw(button);

	window->display(); // Draws what has been rendered so far
}
