#include "Game.h"

void Game::initVariables() {
	window = nullptr;
    startGame = false;
    spawnTowerCounter = 0;
}

void Game::initWindow() {
	videoMode.height = 600;
	videoMode.width = 800;
	window = new sf::RenderWindow (this->videoMode, "Floppy", sf::Style::Default);

    window->setFramerateLimit(144);
}

void Game::initEntities() {
    // Inits the towers
    towers.emplace_back(800.f, 0.f); // Top tower
    towers.emplace_back(800.f, (600.f - 200.f)); // Bottom tower

    // Inits the player
    player = new Player(50.f, (videoMode.height / 2));
}

void Game::spawnTowers() {
    if (spawnTowerCounter == 600) {
        spawnTowerCounter = 0;
        
        // Create new towers and add to the collection
        towers.emplace_back(800.f, 0.f); // Top tower
        towers.emplace_back(800.f, (600.f - 200.f)); // Bottom tower
    }
}

void Game::moveGame() {
    // Moves all of the towers to the left
    for (Tower& tower : towers) {
        tower.move(-1.f);
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

    // Moves the player
    player->move(0.0f, videoMode.height);

    // Increments the spawn time counter for towers
    spawnTowerCounter++;
}

Game::Game() {
	initVariables();
	initWindow();
    initEntities();
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
                if (!startGame) {
                    startGame = true;
                }

                player->jump();              
            }
        }

    }
}

void Game::update() {
    pollEvents();

    if (startGame == true) {
        moveGame();
        spawnTowers();
    }

    // Gets mouse position relative to the window
    //std::cout << "Mouse pos: " << sf::Mouse::getPosition(*window).x << " " << sf::Mouse::getPosition(*window).y << std::endl;
    
    //std::cout << spawnTowerCounter << std::endl;
}

void Game::render() {
    window->clear(); // Clear old frame

    // Draw all towers
    for (Tower tower : towers) {
        tower.draw(*window);
    }

    // Draws the player
    player->draw(*window);

    window->display(); // Draws what has been rendered so far
}
