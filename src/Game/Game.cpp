#include "Game.h"
#include "../Config.h"

Game::Game() {
    loadResources();
    initVariables();
    initEntities();
    initWindow();
}

void Game::loadResources() {
    if (!font.loadFromFile("assets/fonts/ARIAL.TTF")) {
        throw std::runtime_error("Font missing.");
    }

    if (!backgroundTexture.loadFromFile("assets/textures/game_background.png")) {
        throw std::runtime_error("Background texture missing.");
    }

    if (!towerTexture.loadFromFile("assets/textures/tower.png")) {
        throw std::runtime_error("Tower texture missing.");
    }

    if (!playerTexture.loadFromFile("assets/textures/player.png")) {
        throw std::runtime_error("Player texture missing.");
    }
}

void Game::initVariables() {
    // Text
    scoreCounterText.setCharacterSize(UIConfig::fontSize);
    scoreCounterText.setFillColor(sf::Color::Black);
    scoreCounterText.setFont(font);

    sf::FloatRect scoreBounds = scoreCounterText.getLocalBounds();
    scoreCounterText.setOrigin(scoreBounds.left + scoreBounds.width / 2.f, scoreBounds.top + scoreBounds.height / 2.f);
    scoreCounterText.setPosition(ResolutionConfig::baseWidth / 2.f, UIConfig::scoreTopMargin);

    jumpText.setString((UIConfig::jumpText));
    jumpText.setCharacterSize(UIConfig::fontSize);
    jumpText.setFillColor(sf::Color::Black);
    jumpText.setFont(font);

    sf::FloatRect jumpBounds = jumpText.getLocalBounds();
    jumpText.setOrigin(jumpBounds.left + jumpBounds.width / 2.f, jumpBounds.top + jumpBounds.height / 2.f);
    jumpText.setPosition(ResolutionConfig::baseWidth / 2.f, ResolutionConfig::baseHeight / 2.f);

    restartText.setString((UIConfig::restartText));
    restartText.setCharacterSize(UIConfig::fontSize);
    restartText.setFillColor(sf::Color::Red);
    restartText.setFont(font);

    sf::FloatRect restartBounds = restartText.getLocalBounds();
    restartText.setOrigin(restartBounds.left + restartBounds.width / 2.f, restartBounds.top + restartBounds.height / 2.f);
    restartText.setPosition(ResolutionConfig::baseWidth / 2.f, ResolutionConfig::baseHeight / 2.f);

    // Background texture
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0.f, 0.f);

    sf::Vector2u textureSize = backgroundTexture.getSize();
    float windowWidth = ResolutionConfig::baseWidth;
    float windowHeight = ResolutionConfig::baseHeight;

    float scaleX = windowWidth / textureSize.x;
    float scaleY = windowHeight / textureSize.y;

    backgroundSprite.setScale(scaleX, scaleY);
}

void Game::initWindow() {
    sf::VideoMode videoMode;
    videoMode.height = ResolutionConfig::baseHeight;
    videoMode.width = ResolutionConfig::baseWidth;
    window.create(videoMode, "Floppy", sf::Style::Default);

    window.setFramerateLimit(144); // TODO: Don't rely on this
}

void Game::initEntities() {
    spawnTowers(true);
    player = std::make_unique<Player>(GameplayConfig::playerSpawnX, (ResolutionConfig::baseHeight / 2.f), playerTexture);
}

void Game::spawnTowers(bool force) {
    if (spawnTowerTimeCounter < GameplayConfig::towerSpawnInterval && !force) {
        return;
    }

    spawnTowerTimeCounter = 0;

    // Create new towers and add to the collection
    towers.emplace_back(GameplayConfig::towerSpawnX, 0.f, TowerConfig::width, TowerConfig::height, towerTexture);                                                  // Top tower
    towers.emplace_back(GameplayConfig::towerSpawnX, (ResolutionConfig::baseHeight - TowerConfig::height), TowerConfig::width, TowerConfig::height, towerTexture); // Bottom tower
    colliders.emplace_back(GameplayConfig::towerSpawnX, 0.f, TowerConfig::width, ResolutionConfig::baseHeight);                                                    // Collision between towers
}

void Game::moveGame() {
    // Moves all of the towers to the left
    for (Tower &tower : towers) {
        tower.move(-GameplayConfig::worldScrollSpeed);
    }

    // Moves all of the colliders to the left
    for (Collider &collider : colliders) {
        collider.move(-GameplayConfig::worldScrollSpeed);
    }

    // Deletes towers if they are outside of the window
    for (auto it = towers.begin(); it != towers.end();) {
        if (it->getPosition().x < -GameplayConfig::despawnOffset) {
            it = towers.erase(it);
        } else {
            ++it;
        }
    }

    // Deletes colliders if they are outside of the window
    for (auto it = colliders.begin(); it != colliders.end();) {
        if (it->getPosition().x < -GameplayConfig::despawnOffset) {
            it = colliders.erase(it);
        } else {
            ++it;
        }
    }

    player->move(0.0f, ResolutionConfig::baseHeight);
    spawnTowerTimeCounter++;
}

void Game::givePointToPlayer(Collider &collider) {
    if (!collider.getHasCollided()) {
        collider.collides();
        playerScoreCounter++;
        scoreCounterText.setString(std::to_string(playerScoreCounter));
    }
}

void Game::pollEvents() {
    while (window.pollEvent(event)) {

        switch (event.type) {

        // Closes the window if exit button is pressed
        case sf::Event::Closed:
            window.close();
            break;

        // Handles keyboard input
        case sf::Event::KeyPressed:
            switch (event.key.code) {

            // Closes the window if escape button is pressed
            case sf::Keyboard::Escape:
                window.close();
                break;

            // Moves the player if the spacebar is pressed
            case sf::Keyboard::Space:

                // Starts the game if it hasn't started yet
                if (!gameStarted && !gameEnded) {
                    gameStarted = true;
                    scoreCounterText.setString(std::to_string(playerScoreCounter));
                }
                // Resets the game if it has ended
                else if (gameEnded) {
                    gameEnded = false;
                    resetGameState();
                }

                player->jump();
                break;

            default:
                break;
            }
            break;

        default:
            break;
        }
    }
}

void Game::update() {
    pollEvents();

    if (gameStarted && !gameEnded) {
        // Collision detection logic
        for (const Tower &tower : towers) {
            if (player->collidesWithTower(tower)) {
                endGame();
            }
        }

        if (player->getTouchingGround()) {
            endGame();
        }

        for (Collider &collider : colliders) {
            if (player->collidesWithCollider(collider)) {
                // Player went between towers
                givePointToPlayer(collider);
            }
        }

        moveGame();
        spawnTowers();
    }
}

void Game::render() {
    window.clear();
    window.draw(backgroundSprite);

    for (const Tower &tower : towers) {
        window.draw(tower);
    }

    window.draw(*player);

    if (gameStarted) {
        window.draw(scoreCounterText);
    } else {
        window.draw(jumpText);
    }

    if (gameEnded) {
        window.draw(restartText);
    }

    window.display();
}

void Game::resetGameState() {
    gameEnded = false;
    gameStarted = false;
    playerScoreCounter = 0;

    towers.clear();
    colliders.clear();
    spawnTowers(true);

    player->setPosition(GameplayConfig::playerSpawnX, (ResolutionConfig::baseHeight / 2)); // Reset player to spawn pos
}
