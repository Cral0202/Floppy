#include "Game.h"
#include "GameOverGUI.h"

enum class GameState {
	Playing,
	GameOver
};

int main() {
	// Init game engine
	Game game;
	GameOverGUI gameOverGUI(game);

	// Sets the gamestate to playing
	GameState gameState = GameState::Playing;

	// The game loop
	while (game.running()) {
		// Runs while game is playing
		while (gameState == GameState::Playing && game.running()) {
			// Update game state
			game.update();

			// Render game
			game.render();

			// Sleeps the while loop
			sf::sleep(sf::milliseconds(1));

			// Changes gamestate if game is over
			if (game.gameEnded()) {
				gameOverGUI.resetState();
				gameState = GameState::GameOver;
			}
		}

		// Runs while player is dead
		while (gameState == GameState::GameOver && game.running()) {
			// Update game state
			gameOverGUI.update();

			// Render game
			gameOverGUI.render();

			// Sleeps the while loop
			sf::sleep(sf::milliseconds(1));

			if (gameOverGUI.getShouldRestart()) {
				game.resetGameState();
				gameState = GameState::Playing;
			}		
		}
	}

	return 0;
}