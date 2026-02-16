#include "./Game/Game.h"

int main() {
  // Init game engine
  Game game;

  // The game loop
  while (game.running()) {
    // Runs while game is playing
    while (game.running()) {
      // Update game state
      game.update();

      // Render game
      game.render();
    }
  }

  return 0;
}
