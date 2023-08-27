#include "Game.h"

void Game::initVariables() {
	window = nullptr;
    startGame = false;
    endTheGame = false;
    spawnTowerCounter = 0;
    pointCounter = 0;

    // The text for the points
    // Use std::filesystem::path to construct the font file path
    std::filesystem::path fontPath = std::filesystem::current_path() / "assets" / "fonts" / "ARIAL.TTF";

    font = std::make_shared<sf::Font>(); // Allocate the font
    //Load and check the availability of the font file
    if (!font->loadFromFile(fontPath.string())) {
        std::cout << "can't load font" << std::endl;
    }

    // Settings for the point counter text
    pointText.setString(("Space to jump")); // Set the text content
    pointText.setCharacterSize(40); // Set the character size
    pointText.setFillColor(sf::Color::Black); // Set the text color
    pointText.setPosition(290, 20);
    pointText.setFont(*font);

    // Settings for the restart text
    restartText.setString(("Space to restart")); // Set the text content
    restartText.setCharacterSize(40); // Set the character size
    restartText.setFillColor(sf::Color::Red); // Set the text color
    restartText.setPosition(270, 300);
    restartText.setFont(*font);

    // Gets the background textures
    std::filesystem::path backgroundTexturePath = std::filesystem::current_path() / "assets" / "textures" / "game_background.png";
    if (!backgroundTexture.loadFromFile(backgroundTexturePath.string())) {
        std::cout << "No background textures!" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0.f, 0.f); // Background position
    backgroundSprite.setScale(0.417f, 0.56f);  // Background scale

    // Gets the tower textures
    std::filesystem::path towerTexturePath = std::filesystem::current_path() / "assets" / "textures" / "tower.png";
    if (!towerTexture.loadFromFile(towerTexturePath.string())) {
        std::cout << "No tower textures!" << std::endl;
    }

    // Gets the player textures
    std::filesystem::path playerTexturePath = std::filesystem::current_path() / "assets" / "textures" / "player.png";
    if (!playerTexture.loadFromFile(playerTexturePath.string())) {
        std::cout << "No player textures!" << std::endl;
    }
}

void Game::initWindow() {
	videoMode.height = 600;
	videoMode.width = 800;
	window = new sf::RenderWindow (this->videoMode, "Floppy", sf::Style::Default);

    window->setFramerateLimit(144);
}

void Game::initEntities() {
    // Inits the towers
    towers.emplace_back(800.f, 0.f, towerTexture); // Top tower
    towers.emplace_back(800.f, (600.f - tower.getHeight()), towerTexture); // Bottom tower
    colliders.emplace_back(tower.getWidth(), 600.f, 800.f, 0.f); // Collision between towers

    // Inits the player
    player = new Player(50.f, (videoMode.height / 2), playerTexture);
}

void Game::spawnTowers() {
    if (spawnTowerCounter == 400) {
        spawnTowerCounter = 0;
        
        // Create new towers and add to the collection
        towers.emplace_back(800.f, 0.f, towerTexture); // Top tower
        towers.emplace_back(800.f, (600.f - tower.getHeight()), towerTexture); // Bottom tower
        colliders.emplace_back(tower.getWidth(), 600.f, 800.f, 0.f); // Collision between towers
    }
}

void Game::moveGame() {
    // Moves all of the towers to the left
    for (Tower& tower : towers) {
        tower.move(-1.f);
    }

    // Moves all of the colliders to the left
    for (Collider& collider : colliders) {
        collider.move(-1.f);
    }

    // Deletes towers if they are outside of the window
    for (auto it = towers.begin(); it != towers.end();) {
        if (it->getPosition().x < -100) {
            it = towers.erase(it); // Erase and get the next iterator
        }
        else {
            ++it;
        }
    }

    // Deletes colliders if they are outside of the window
    for (auto it = colliders.begin(); it != colliders.end();) {
        if (it->getPosition().x < -100) {
            it = colliders.erase(it); // Erase and get the next iterator
        }
        else {
            ++it;
        }
    }

    // Moves the player
    player->move(0.0f, videoMode.height);

    // Increments the spawn time counter for towers
    spawnTowerCounter++;
}

void Game::endGame() {
    endTheGame = true;
}

Game::Game() {
	initVariables();
	initWindow();
    initEntities();
}

void Game::givePoint(Collider& collider) {
    if (!collider.getHasCollided()) {
        collider.collides();
        pointCounter++;
        pointText.setString(std::to_string(pointCounter)); // Set the text content
    }
}

Game::~Game() {
	delete window;
    delete player;
}

const bool Game::running() const {
	return window->isOpen();
}

void Game::pollEvents() {
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
        // Moves the player if the spacebar is pressed
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                if (!startGame && !endTheGame) {
                    startGame = true;
                    pointText.setString(std::to_string(pointCounter)); // Set the text content
                    pointText.setPosition(400, 20);
                    
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
        for (const Tower tower : towers) {
            if (player->collidesWithTower(tower)) {
                // Collision occurred
                endGame();
            }
        }
        if (player->getTouchingGround()) {
            // Collision occurred
            endGame();
        }
        
        for (Collider& collider : colliders) {
            if (player->collidesWithCollider(collider)) {
                // Player went between towers
                givePoint(collider);
            }
        }

        // Keeps the game state flowing
        moveGame();
        spawnTowers();
    }
}

void Game::render() {
    window->clear(); // Clear old frame

    // Draw the background
    window->draw(backgroundSprite);

    // Draw all towers
    for (Tower tower : towers) {
        tower.draw(*window);
    }

    // Draws the player
    player->draw(*window);

    // Draws the point counter text
    window->draw(pointText);

    if (endTheGame) {
        window->draw(restartText);
    }

    window->display(); // Draws what has been rendered so far
}

sf::RenderWindow* Game::getWindow() {
    return window;
}

void Game::resetGameState() {
    // Resets the flags
    endTheGame = false;
    startGame = false;
    spawnTowerCounter = 0;
    pointCounter = 0;

    towers.clear(); // Removes all the towers
    towers.emplace_back(800.f, 0.f, towerTexture); // Top tower
    towers.emplace_back(800.f, (600.f - tower.getHeight()), towerTexture); // Bottom tower
    colliders.clear(); // Removes all the colliders
    colliders.emplace_back(tower.getWidth(), 600.f, 800.f, 0.f); // Collision between towers

    player->setPosition(50.f, (videoMode.height / 2)); // Resets the player to spawn position
    player->setSpriteRotation(0); // Sets the player sprite rotation back to 0

    pointText.setPosition(290, 20); // Sets the position of the point counter text
    pointText.setString(("Space to jump")); // Set the text content
}
