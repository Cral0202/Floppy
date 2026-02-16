#pragma once

#include "../Collider/Collider.h"
#include "../Tower/Tower.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Player {
  private:
    sf::CircleShape player;
    sf::Sprite playerSprite;

    float playerSize;
    bool touchingGround;

    sf::Vector2f velocity;
    const float gravity = 0.05f;

    void initVariables();

  public:
    Player(float x, float y, sf::Texture &texture);
    ~Player();

    void move(float offset�, float height);
    void jump();
    void draw(sf::RenderWindow &window);
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    void setSpriteRotation(float r);
    bool getTouchingGround();
    bool collidesWithTower(const Tower &tower) const;
    bool collidesWithCollider(const Collider &collider) const;
};
