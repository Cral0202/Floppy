#pragma once

#include "../Collider/Collider.h"
#include "../Config.h"
#include "../Tower/Tower.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Player : public sf::Drawable {
  private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override { target.draw(playerSprite, states); }

    sf::CircleShape player;
    sf::Vector2f velocity;
    sf::Sprite playerSprite;

    bool touchingGround = false;

  public:
    Player(float x, float y, sf::Texture &texture);

    void move(float offset, float height);
    void jump() { velocity.y = -GameplayConfig::jumpForce; }
    void setPosition(float x, float y);

    bool getTouchingGround() const { return touchingGround; }
    float getRadius() const { return player.getRadius(); }
    sf::Vector2f getPosition() const { return player.getPosition(); }
};
