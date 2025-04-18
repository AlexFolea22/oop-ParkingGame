#include "map_boundary.h"
#include "collider.h"
#include <SFML/Graphics.hpp>

MapBoundary::MapBoundary(float mapWidth, float mapHeight, float thickness) {
    sf::Texture floorTexture;
    if (!floorTexture.loadFromFile("Sprites/floorTile.png")) {
        std::cerr << "Error loading texture: Sprites/floorTile.png" << std::endl;
    }

    sf::RectangleShape topWallShape(sf::Vector2f(mapWidth, thickness));
    topWallShape.setPosition({ 0.0f, 0.0f });
    topWallShape.setTexture(&floorTexture);
    m_walls.emplace_back(topWallShape);

    sf::RectangleShape bottomWallShape(sf::Vector2f(mapWidth, thickness));
    bottomWallShape.setPosition({ 0.0f, mapHeight - thickness });
    bottomWallShape.setTexture(&floorTexture);
    m_walls.emplace_back(bottomWallShape);

    sf::RectangleShape leftWallShape(sf::Vector2f(thickness, mapHeight));
    leftWallShape.setPosition({ 0.0f, 0.0f });
    leftWallShape.setTexture(&floorTexture);
    m_walls.emplace_back(leftWallShape);

    sf::RectangleShape rightWallShape(sf::Vector2f(thickness, mapHeight));
    rightWallShape.setPosition({ mapWidth - thickness, 0.0f });
    rightWallShape.setTexture(&floorTexture);
    m_walls.emplace_back(rightWallShape);
}

bool MapBoundary::checkCollisions(const Collider& other) const {
    for (const auto& wall : m_walls) {
        if (wall.checkCollision(other)) {
            return true;
        }
    }
    return false;
}

void MapBoundary::draw(sf::RenderWindow& window) {
    for (const auto& wallCollider : m_walls) {
        window.draw(wallCollider.getShape()); 
    }
}