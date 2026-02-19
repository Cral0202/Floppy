#include "Towers.h"
#include "../Config.h"

#include <random>

namespace TowerSystem {
    void spawnTowerPair(std::vector<Tower> &towers, std::vector<Collider> &colliders, sf::Texture &towerTexture, float x) {
        const float gapHeight = GameplayConfig::towerGap;
        const float minTowerHeight = TowerConfig::minHeight;
        const float maxTowerHeight = ResolutionConfig::baseHeight - gapHeight - minTowerHeight;

        // Random top tower height
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist(minTowerHeight, maxTowerHeight);

        float topTowerHeight = dist(gen);
        float bottomTowerHeight = ResolutionConfig::baseHeight - topTowerHeight - gapHeight;

        towers.emplace_back(x, 0.f, TowerConfig::width, topTowerHeight, towerTexture);                                                 // Top tower
        towers.emplace_back(x, ResolutionConfig::baseHeight - bottomTowerHeight, TowerConfig::width, bottomTowerHeight, towerTexture); // Bottom tower
        colliders.emplace_back(x, 0.f, TowerConfig::width, ResolutionConfig::baseHeight);                                              // Collider covering the gap
    }

    void spawnInitialTowers(std::vector<Tower> &towers, std::vector<Collider> &colliders, sf::Texture &towerTexture) {
        // Start from the left and move right
        float currentX = GameplayConfig::firstTowerX;
        float endX = ResolutionConfig::baseWidth + GameplayConfig::towerSpawnOffset;

        while (currentX <= endX) {
            spawnTowerPair(towers, colliders, towerTexture, currentX);
            currentX += GameplayConfig::towerSpacing;
        }
    }

    void spawnTowers(std::vector<Tower> &towers, std::vector<Collider> &colliders, sf::Texture &towerTexture) {
        float spawnX = ResolutionConfig::baseWidth + GameplayConfig::towerSpawnOffset;

        float lastTowerX = towers.back().getPosition().x;

        // Only spawn if the last tower is far enough away
        if (lastTowerX + GameplayConfig::towerSpacing > spawnX) {
            return;
        }

        spawnX = lastTowerX + GameplayConfig::towerSpacing;
        spawnTowerPair(towers, colliders, towerTexture, spawnX);
    }
}
