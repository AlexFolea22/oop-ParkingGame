#include "collider.h"
#include <iostream>
#include <cmath>
#include <limits>

Collider::Collider(const sf::RectangleShape& shape) : Actor("Sprites/floorTile.png", shape.getPosition().x, shape.getPosition().y, static_cast<int>(shape.getSize().x), static_cast<int>(shape.getSize().y), "collider") {
    m_rectangle = shape;
}

sf::RectangleShape Collider::getShape() const {
    return m_rectangle;
}

std::array<sf::Vector2f, 4> Collider::getCorners() const {
    const sf::Transform& transform = m_rectangle.getTransform();
    sf::Vector2f size = m_rectangle.getSize();

    sf::Vector2f localTopLeft(0.0f, 0.0f);
    sf::Vector2f localTopRight(size.x, 0.0f);
    sf::Vector2f localBottomRight(size.x, size.y);
    sf::Vector2f localBottomLeft(0.0f, size.y);

    std::array<sf::Vector2f, 4> corners;
    corners[0] = transform.transformPoint(localTopLeft);
    corners[1] = transform.transformPoint(localTopRight);
    corners[2] = transform.transformPoint(localBottomRight);
    corners[3] = transform.transformPoint(localBottomLeft);

    return corners;
}

bool Collider::isPointInsideRect(const sf::Vector2f& point, const sf::RectangleShape& rect) const {
    const sf::Transform& transform = rect.getTransform();
    sf::Vector2f size = rect.getSize();
    sf::Vector2f origin = rect.getOrigin();
    sf::Vector2f localPoint = transform.getInverse().transformPoint(point);

    return (localPoint.x >= -origin.x &&
        localPoint.x <= (size.x - origin.x) &&
        localPoint.y >= -origin.y &&
        localPoint.y <= (size.y - origin.y));
}

// Project points onto an axis
float Collider::projectOntoAxis(const std::array<sf::Vector2f, 4>& corners, const sf::Vector2f& axis) const {
    float min = std::numeric_limits<float>::max();
    float max = std::numeric_limits<float>::lowest();

    for (const auto& corner : corners) {
        // Calculate dot product to find projection
        float projection = (corner.x * axis.x + corner.y * axis.y);

        if (projection < min) min = projection;
        if (projection > max) max = projection;
    }

    return max - min; // Return the length of the projection
}

// Calculate the distance between projections
float Collider::getOverlap(float minA, float maxA, float minB, float maxB) const {
    if (minA < minB) {
        return maxA - minB;
    }
    else {
        return maxB - minA;
    }
}

// Normalize a vector
sf::Vector2f Collider::normalize(const sf::Vector2f& vector) const {
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    if (length > 0) {
        return sf::Vector2f(vector.x / length, vector.y / length);
    }
    return vector;
}

bool Collider::checkCollision(const Collider& other) const {
    std::array<sf::Vector2f, 4> cornersA = getCorners();
    std::array<sf::Vector2f, 4> cornersB = other.getCorners();

    // Get the edges for both rectangles
    std::array<sf::Vector2f, 4> edgesA = {
        cornersA[1] - cornersA[0],
        cornersA[2] - cornersA[1],
        cornersA[3] - cornersA[2],
        cornersA[0] - cornersA[3]
    };

    std::array<sf::Vector2f, 4> edgesB = {
        cornersB[1] - cornersB[0],
        cornersB[2] - cornersB[1],
        cornersB[3] - cornersB[2],
        cornersB[0] - cornersB[3]
    };

    // Test each axis (perpendicular to edges)
    for (int i = 0; i < 4; ++i) {
        // For rectangle A
        sf::Vector2f axis = sf::Vector2f(-edgesA[i].y, edgesA[i].x); // Perpendicular
        axis = normalize(axis);

        // Project both rectangles onto the axis
        float minA = std::numeric_limits<float>::max();
        float maxA = std::numeric_limits<float>::lowest();
        float minB = std::numeric_limits<float>::max();
        float maxB = std::numeric_limits<float>::lowest();

        // Project rectangle A
        for (const auto& corner : cornersA) {
            float projection = axis.x * corner.x + axis.y * corner.y;
            minA = std::min(minA, projection);
            maxA = std::max(maxA, projection);
        }

        // Project rectangle B
        for (const auto& corner : cornersB) {
            float projection = axis.x * corner.x + axis.y * corner.y;
            minB = std::min(minB, projection);
            maxB = std::max(maxB, projection);
        }

        // Check for gap
        if (maxA < minB || maxB < minA) {
            // Found a separating axis, no collision
            return false;
        }
    }

    // Test each axis from rectangle B's edges
    for (int i = 0; i < 4; ++i) {
        sf::Vector2f axis = sf::Vector2f(-edgesB[i].y, edgesB[i].x); // Perpendicular
        axis = normalize(axis);

        // Project both rectangles onto the axis
        float minA = std::numeric_limits<float>::max();
        float maxA = std::numeric_limits<float>::lowest();
        float minB = std::numeric_limits<float>::max();
        float maxB = std::numeric_limits<float>::lowest();

        // Project rectangle A
        for (const auto& corner : cornersA) {
            float projection = axis.x * corner.x + axis.y * corner.y;
            minA = std::min(minA, projection);
            maxA = std::max(maxA, projection);
        }

        // Project rectangle B
        for (const auto& corner : cornersB) {
            float projection = axis.x * corner.x + axis.y * corner.y;
            minB = std::min(minB, projection);
            maxB = std::max(maxB, projection);
        }

        // Check for gap
        if (maxA < minB || maxB < minA) {
            // Found a separating axis, no collision
            return false;
        }
    }

    // If we get here, no separating axis was found, so the rectangles are colliding
    /*std::cout << "Collision detected using SAT\n";*/
    return true;
}

void Collider::drawCollider(sf::RenderWindow& window) const {
    // Create a copy of the rectangle for visualization
    sf::RectangleShape debugShape = m_rectangle;

    debugShape.setFillColor(sf::Color::Transparent);
    debugShape.setOutlineColor(sf::Color::Green);
    debugShape.setOutlineThickness(1.0f);

    // Draw the outline
    window.draw(debugShape);

    // Draw the corners
    std::array<sf::Vector2f, 4> corners = getCorners();
    for (const auto& corner : corners) {
        sf::CircleShape cornerPoint(2.0f);
        cornerPoint.setFillColor(sf::Color::Red);
        cornerPoint.setPosition({corner.x - 2.0f, corner.y - 2.0f});
        window.draw(cornerPoint);
    }
}