#pragma once
#include <SFML/Graphics.hpp>

namespace Collision {
    bool circleVsRect(const sf::Vector2f &center, float radius, const sf::FloatRect &rect);
}
