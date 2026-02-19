#pragma once

#include "../Collider/Collider.h"
#include "../Tower/Tower.h"

#include <SFML/Graphics.hpp>
#include <vector>

namespace TowerSystem {
    void spawnTowerPair(std::vector<Tower> &towers, std::vector<Collider> &colliders, sf::Texture &towerTexture, float x);
    void spawnInitialTowers(std::vector<Tower> &towers, std::vector<Collider> &colliders, sf::Texture &towerTexture);
    void spawnTowers(std::vector<Tower> &towers, std::vector<Collider> &colliders, sf::Texture &towerTexture);
}
