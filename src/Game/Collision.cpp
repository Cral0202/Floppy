#include "Collision.h"

namespace Collision {
    bool circleVsRect(const sf::Vector2f &center, float radius, const sf::FloatRect &rect) {
        // Find the point on the rectangle that is closest to the center of the circle
        float closestX = std::max(rect.left, std::min(center.x, rect.left + rect.width));
        float closestY = std::max(rect.top, std::min(center.y, rect.top + rect.height));

        // Calculate the distance vector between the circle's center and the closest point
        float distanceX = center.x - closestX;
        float distanceY = center.y - closestY;

        // Use Pythagorean theorem to see if the distance is less than the radius
        return (distanceX * distanceX + distanceY * distanceY) < (radius * radius);
    }
}
