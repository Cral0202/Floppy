#include "GameOverGUI.h"

GameOverGUI::GameOverGUI(Game& game) : game(game) {
	initVariables();
}

GameOverGUI::~GameOverGUI() {
}

void GameOverGUI::initVariables() {
	window = game.getWindow();
    restartButton = Button(100.f, 250.f, (400.f - 250.f / 2), (300.f - 100.f / 2), sf::Color::Blue, "Restart");
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

    restartButton.draw(*window); // Draws the restart button

	window->display(); // Draws what has been rendered so far
}
