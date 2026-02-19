#pragma once

#include "../Collider/Collider.h"
#include "../Player/Player.h"
#include "../Tower/Tower.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <filesystem>
#include <iostream>

class Game {
  private:
    sf::RenderWindow window;
    sf::Event event;

    // Game objects
    std::vector<Tower> towers;
    std::vector<Collider> colliders;
    std::unique_ptr<Player> player;

    // Text
    sf::Text scoreCounterText;
    sf::Text jumpText;
    sf::Text restartText;
    sf::Font font;

    // Textures
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Texture towerTexture;
    sf::Texture playerTexture;

    int spawnTowerTimeCounter = 0; // Keeps track of when towers should spawn
    int playerScoreCounter = 0;
    bool gameStarted = false;
    bool gameEnded = false;

    void loadResources();
    void initVariables();
    void initWindow();
    void initEntities();

    void givePointToPlayer(Collider &collider);
    void resetGameState();

    void spawnTowers(bool force = false);
    void moveGame();
    void endGame() { gameEnded = true; }
    void pollEvents();

  public:
    Game();

    void update();
    void render();

    const bool isRunning() const { return window.isOpen(); }
};
