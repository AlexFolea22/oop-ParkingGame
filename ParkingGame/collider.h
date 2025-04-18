#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>
#include <array>
#include "actor.h" // Assuming this contains the Actor base class

class Collider : public Actor {
public:
    // Constructor
    Collider(const sf::RectangleShape& shape);

    // Getters
    sf::RectangleShape getShape() const;
    std::array<sf::Vector2f, 4> getCorners() const;

    // Collision detection
    bool checkCollision(const Collider& other) const;

    // Debug visualization
    void drawCollider(sf::RenderWindow& window) const;

private:
    sf::RectangleShape m_rectangle;

    // Helper methods
    bool isPointInsideRect(const sf::Vector2f& point, const sf::RectangleShape& rect) const;
    float projectOntoAxis(const std::array<sf::Vector2f, 4>& corners, const sf::Vector2f& axis) const;
    float getOverlap(float minA, float maxA, float minB, float maxB) const;
    sf::Vector2f normalize(const sf::Vector2f& vector) const;
};

#endif // COLLIDER_H