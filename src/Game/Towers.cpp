#include "Towers.h"
#include "../Config.h"

namespace TowerSystem {
    void spawnTowerPair(std::vector<Tower> &towers, std::vector<Collider> &colliders, sf::Texture &towerTexture, float x) {
        towers.emplace_back(x, 0.f, TowerConfig::width, TowerConfig::height, towerTexture);                                                // Top tower
        towers.emplace_back(x, ResolutionConfig::baseHeight - TowerConfig::height, TowerConfig::width, TowerConfig::height, towerTexture); // Bottom tower
        colliders.emplace_back(x, 0.f, TowerConfig::width, ResolutionConfig::baseHeight);                                                  // Collision between towers
    }

    void spawnInitialTowers(std::vector<Tower> &towers, std::vector<Collider> &colliders, sf::Texture &towerTexture) {
        float spawnX = ResolutionConfig::baseWidth + GameplayConfig::towerSpawnOffset;

        // Fill screen
        while (spawnX > 0) {
            spawnTowerPair(towers, colliders, towerTexture, spawnX);
            spawnX -= GameplayConfig::towerSpacing;
        }
    }

    void spawnTowers(std::vector<Tower> &towers, std::vector<Collider> &colliders, sf::Texture &towerTexture) {
        float spawnX = ResolutionConfig::baseWidth + GameplayConfig::towerSpawnOffset;

        // Only spawn if the last tower is far enough away to maintain spacing
        float lastTowerX = towers.back().getPosition().x;

        if (lastTowerX + GameplayConfig::towerSpacing > spawnX) {
            return;
        }

        spawnX = lastTowerX + GameplayConfig::towerSpacing;
        spawnTowerPair(towers, colliders, towerTexture, spawnX);
    }
}
