#include "Game.h"

int main() {
    // Init game engine
    Game game;

    // The game loop
    while (game.running()) {

        // Update game state
        game.update();

        // Render game
        game.render();

        // Sleeps the while loop
        sf::sleep(sf::milliseconds(1));
    }

    return 0;
}