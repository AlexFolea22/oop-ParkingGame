#include "map_boundary.h"
#include "collider.h"
#include <SFML/Graphics.hpp>

MapBoundary::MapBoundary(float mapWidth, float mapHeight, float thickness) {

    sf::RectangleShape topWallShape(sf::Vector2f(mapWidth, thickness));
    topWallShape.setPosition({ 0.0f, 0.0f });
    topWallShape.setFillColor(sf::Color::Transparent);
    m_walls.emplace_back(topWallShape);

    sf::RectangleShape bottomWallShape(sf::Vector2f(mapWidth, thickness));
    bottomWallShape.setPosition({ 0.0f, mapHeight - thickness });
    bottomWallShape.setFillColor(sf::Color::Transparent);
    m_walls.emplace_back(bottomWallShape);

    sf::RectangleShape leftWallShape(sf::Vector2f(thickness, mapHeight));
    leftWallShape.setPosition({ 0.0f, 0.0f });
    leftWallShape.setFillColor(sf::Color::Transparent);
    m_walls.emplace_back(leftWallShape);

    sf::RectangleShape rightWallShape(sf::Vector2f(thickness, mapHeight));
    rightWallShape.setPosition({ mapWidth - thickness, 0.0f });
    rightWallShape.setFillColor(sf::Color::Transparent);
    m_walls.emplace_back(rightWallShape);

    sf::RectangleShape grass1(sf::Vector2f(105.0f, 900.0f));
    grass1.setPosition({ 397.0f,240.0f });
    grass1.setFillColor(sf::Color::Transparent);
    m_walls.emplace_back(grass1);

    sf::RectangleShape grass2(sf::Vector2f(105.0f, 800.0f));
    grass2.setPosition({ 1010.0f,40.0f });
    grass2.setFillColor(sf::Color::Transparent);
    m_walls.emplace_back(grass2);

    sf::RectangleShape grass3(sf::Vector2f(105.0f, 95.0f));
    grass3.setPosition({ 1117.0f,38.0f });
    grass3.setFillColor(sf::Color::Transparent);
    m_walls.emplace_back(grass3);

    sf::RectangleShape grass4(sf::Vector2f(105.0f, 95.0f));
    grass4.setPosition({ 1777.0f,38.0f });
    grass4.setFillColor(sf::Color::Transparent);
    m_walls.emplace_back(grass4);

    sf::RectangleShape grass5(sf::Vector2f(22.0f, 680.0f));
    grass5.setPosition({ 1465.0f,385.0f });
    grass5.setFillColor(sf::Color::Transparent);
    m_walls.emplace_back(grass5);

    sf::RectangleShape hut(sf::Vector2f(160.0f, 100.0f));
    hut.setPosition({ 20.0f,911.0f });
    hut.setFillColor(sf::Color::Transparent);
    m_walls.emplace_back(hut);

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