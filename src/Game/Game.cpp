#include "Game.h"

Game::Game() {
    initVariables();
    initWindow();
    initEntities();
}

void Game::initVariables() {
    // Text
    std::filesystem::path fontPath = std::filesystem::current_path() / "assets" / "fonts" / "ARIAL.TTF";

    font = std::make_shared<sf::Font>();

    if (!font->loadFromFile(fontPath.string())) {
        std::cout << "can't load font" << std::endl;
    }

    scoreCounterText.setString(("Space to jump"));
    scoreCounterText.setCharacterSize(40);
    scoreCounterText.setFillColor(sf::Color::Black);
    scoreCounterText.setPosition(290, 20);
    scoreCounterText.setFont(*font);

    restartText.setString(("Space to restart"));
    restartText.setCharacterSize(40);
    restartText.setFillColor(sf::Color::Red);
    restartText.setPosition(270, 300);
    restartText.setFont(*font);

    // Background textures
    std::filesystem::path backgroundTexturePath =
        std::filesystem::current_path() / "assets" / "textures" / "game_background.png";

    if (!backgroundTexture.loadFromFile(backgroundTexturePath.string())) {
        std::cout << "No background textures!" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0.f, 0.f);
    backgroundSprite.setScale(0.417f, 0.56f);

    // Tower textures
    std::filesystem::path towerTexturePath = std::filesystem::current_path() / "assets" / "textures" / "tower.png";

    if (!towerTexture.loadFromFile(towerTexturePath.string())) {
        std::cout << "No tower textures!" << std::endl;
    }

    // Player textures
    std::filesystem::path playerTexturePath = std::filesystem::current_path() / "assets" / "textures" / "player.png";

    if (!playerTexture.loadFromFile(playerTexturePath.string())) {
        std::cout << "No player textures!" << std::endl;
    }
}

void Game::initWindow() {
    videoMode.height = 600;
    videoMode.width = 800;
    window.create(this->videoMode, "Floppy", sf::Style::Default);

    window.setFramerateLimit(144);
}

void Game::initEntities() {
    spawnTowers(true);
    player = std::make_unique<Player>(50.f, (videoMode.height / 2.f), playerTexture);
}

void Game::spawnTowers(bool force) {
    if (spawnTowerTimeCounter < 400 && !force) {
        return;
    }

    spawnTowerTimeCounter = 0;

    // Create new towers and add to the collection
    towers.emplace_back(800.f, 0.f, towerTexture);                                  // Top tower
    towers.emplace_back(800.f, (600.f - TowerConfig::DefaultHeight), towerTexture); // Bottom tower
    colliders.emplace_back(TowerConfig::DefaultWidth, 600.f, 800.f, 0.f);           // Collision between towers
}

void Game::moveGame() {
    // Moves all of the towers to the left
    for (Tower &tower : towers) {
        tower.move(-1.f);
    }

    // Moves all of the colliders to the left
    for (Collider &collider : colliders) {
        collider.move(-1.f);
    }

    // Deletes towers if they are outside of the window
    for (auto it = towers.begin(); it != towers.end();) {
        if (it->getPosition().x < -100) {
            it = towers.erase(it);
        } else {
            ++it;
        }
    }

    // Deletes colliders if they are outside of the window
    for (auto it = colliders.begin(); it != colliders.end();) {
        if (it->getPosition().x < -100) {
            it = colliders.erase(it);
        } else {
            ++it;
        }
    }

    player->move(0.0f, videoMode.height);
    spawnTowerTimeCounter++;
}

void Game::endGame() {
    endTheGame = true;
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
        // Closes the window if exit button is pressed
        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        }

        // Closes the window if escape button is pressed
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
                break;
            }
        }

        // Moves the player if the spacebar is pressed
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                if (!startGame && !endTheGame) {
                    startGame = true;
                    scoreCounterText.setString(std::to_string(playerScoreCounter));
                    scoreCounterText.setPosition(400, 20);
                }

                if (endTheGame) {
                    endTheGame = false;
                    resetGameState();
                    continue;
                }

                player->jump();
            }
        }
    }
}

void Game::update() {
    pollEvents();

    if (startGame && !endTheGame) {
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
    window.draw(scoreCounterText);

    if (endTheGame) {
        window.draw(restartText);
    }

    window.display();
}

void Game::resetGameState() {
    endTheGame = false;
    startGame = false;
    playerScoreCounter = 0;

    towers.clear();
    colliders.clear();
    spawnTowers(true);

    player->setPosition(50.f, (videoMode.height / 2)); // Resets the player to spawn position
    player->setSpriteRotation(0);

    scoreCounterText.setPosition(290, 20);
    scoreCounterText.setString(("Space to jump"));
}
