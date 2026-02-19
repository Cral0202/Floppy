#pragma once
#include <string>

struct ResolutionConfig {
    static constexpr float baseWidth = 1920.f;
    static constexpr float baseHeight = 1080.f;
};

struct UIConfig {
    static constexpr unsigned fontSize = 58;
    static constexpr float scoreTopMargin = 40.f;

    // Text
    static constexpr std::string_view jumpText = "Space to jump";
    static constexpr std::string_view restartText = "Space to restart";
};

struct GameplayConfig {
    static constexpr float gravity = 0.05f;
    static constexpr float jumpForce = 3.5f;

    static constexpr float worldScrollSpeed = 1.f;
    static constexpr float despawnOffset = 100.f;

    static constexpr float playerSpawnX = 50.f;

    static constexpr float firstTowerX = 400.f;
    static constexpr float towerSpacing = 350.f;
    static constexpr float towerSpawnOffset = 100.f;
    static constexpr float towerGap = 150.f;
};

struct PlayerConfig {
    static constexpr float radius = 27.f;
};

struct TowerConfig {
    static constexpr float width = 55.f;
    static constexpr float minHeight = 100.f;
};
