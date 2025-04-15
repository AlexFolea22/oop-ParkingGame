#pragma once
#include <SFML/Graphics.hpp>
#include "collider.h"
#include <vector>

class MapBoundary {
private:
    std::vector<sf::RectangleShape> m_walls;
    std::vector<Collider> m_colliders;

public:
    MapBoundary(float mapWidth, float mapHeight, float thickness = 20.0f);

    void checkCollisions(Collider& other, float push = 1.0f);
    virtual void draw(sf::RenderWindow& window);
};
