#pragma once
#include <string>

struct ResolutionConfig {
    static constexpr float baseWidth = 1920.f;
    static constexpr float baseHeight = 1080.f;
};

struct UIConfig {
    static constexpr unsigned fontSize = 48;
    static constexpr float scoreTopMargin = 40.f;

    // Text
    static inline const std::string jumpText = "Space to jump";
    static inline const std::string restartText = "Space to restart";
};

struct GameplayConfig {
    static constexpr float gravity = 0.05f;
    static constexpr float jumpForce = 3.5f;

    static constexpr float worldScrollSpeed = 1.f;
    static constexpr float despawnOffset = 100.f;

    static constexpr float playerSpawnX = 50.f;

    static constexpr int towerSpawnInterval = 400;
    static constexpr float towerSpawnX = 800.f;
};

struct PlayerConfig {
    static constexpr float width = 64.f;
    static constexpr float height = 48.f;

    static constexpr float spriteScaleX = 0.65f;
    static constexpr float spriteScaleY = 0.622f;

    static constexpr float radius = 20.f;
};

struct TowerConfig {
    static constexpr float width = 50.f;
    static constexpr float height = 240.f;

    static constexpr float spriteScaleX = 0.193f;
    static constexpr float spriteScaleY = 0.185f;
};
