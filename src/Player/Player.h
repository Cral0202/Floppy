#pragma once

#include "../Collider/Collider.h"
#include "../Tower/Tower.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Player : public sf::Drawable {
  private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        target.draw(playerSprite, states);
    }

    sf::CircleShape player;
    sf::Vector2f velocity;

    sf::Sprite playerSprite;
    const float playerSpriteXScale = 0.65f;
    const float playerSpriteYScale = 0.622f;

    const float gravity = 0.05f;
    const float jumpHeight = -3.5f;
    const float playerSize = 20.f;

    bool touchingGround = false;

  public:
    Player(float x, float y, sf::Texture &texture);

    void move(float offset, float height);
    void jump();
    void setPosition(float x, float y);
    void setSpriteRotation(float r);
    bool collidesWithTower(const Tower &tower) const;
    bool collidesWithCollider(const Collider &collider) const;

    bool getTouchingGround() const { return touchingGround; }
    sf::Vector2f getPosition() const { return player.getPosition(); }
};
