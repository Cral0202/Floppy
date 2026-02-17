#include "./Game/Game.h"
#include <iostream>

int main() {
    try {
        Game game;

        while (game.isRunning()) {
            game.update();
            game.render();
        }
    } catch (const std::exception &e) {
        // TODO: Show some error message in to the user (in a window)
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
