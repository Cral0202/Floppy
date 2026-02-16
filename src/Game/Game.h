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
    sf::RenderWindow *window;
    sf::Event event;
    sf::VideoMode videoMode;

    // Game objects
    std::vector<Tower> towers;
    Tower tower;
    std::vector<Collider> colliders;
    Player *player;

    // Textures/Text
    sf::Text scoreCounterText;
    sf::Text restartText;
    std::shared_ptr<sf::Font> font;

    // Textures
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Texture towerTexture;
    sf::Texture playerTexture;

    // Timer variables
    int spawnTowerTimeCounter; // Keeps track of when towers should spawn
    int playerScoreCounter;
    bool startGame;
    bool endTheGame;

    void initVariables();
    void initWindow();
    void initEntities();

    void givePointToPlayer(Collider &collider);
    void resetGameState();

    void spawnTowers();
    void moveGame();
    void endGame();
    void pollEvents();

  public:
    Game();
    ~Game();

    const bool running() const;
    sf::RenderWindow *getWindow();

    void update();
    void render();
};
