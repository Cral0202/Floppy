#include "./Game/Game.h"

#include <SFML/System/Clock.hpp>
#include <iostream>

int main() {
    try {
        Game game;
        sf::Clock clock;

        while (game.isRunning()) {
            float dt = clock.restart().asSeconds();

            game.update(dt);
            game.render();
        }
    } catch (const std::exception &e) {
        // TODO: Show some error message in to the user (in a window)
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
