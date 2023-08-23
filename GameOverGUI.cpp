#include "GameOverGUI.h"

GameOverGUI::GameOverGUI(Game& game) : game(game) {
	initVariables();
}

GameOverGUI::~GameOverGUI() {
}

bool GameOverGUI::getShouldRestart() {
    return shouldRestart;
}

void GameOverGUI::resetState() {
    shouldRestart = false;
}

void GameOverGUI::initVariables() {
	window = game.getWindow();
    restartButton = Button(100.f, 250.f, (400.f - 250.f / 2), (300.f - 100.f / 2), sf::Color::Blue, "Restart");
    shouldRestart = false;
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

        // Restart button pressed
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
                sf::FloatRect buttonBounds = restartButton.getBoundingBox();

                if (buttonBounds.contains(static_cast<sf::Vector2f>(mousePosition))) {
                    shouldRestart = true;
                }
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
