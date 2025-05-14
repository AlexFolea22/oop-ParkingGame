#ifndef PARKING_SPOT_H
#define PARKING_SPOT_H

#include "actor.h"
#include <array>

class ParkingSpot : public Actor {
public:
    ParkingSpot(float x, float y);
    bool IsParked(const Actor& car);
    bool isPointInsideRect(const sf::Vector2f& point, const sf::RectangleShape& rect) const;
    std::array<sf::Vector2f, 4> getCorners(const sf::RectangleShape& rect) const;
};

#endif // PARKING_SPOT_H
