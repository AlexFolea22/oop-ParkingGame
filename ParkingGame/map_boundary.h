#pragma once

#ifndef MAP_BOUNDARY__H
#define MAP_BOUNDARY_H


#include <SFML/Graphics.hpp>
#include "collider.h"
#include <vector>

class MapBoundary {
private:
    std::vector<Collider> m_walls;

public:
    MapBoundary(float mapWidth, float mapHeight, float thickness = 20.0f);

    bool checkCollisions(const Collider& other) const;
    virtual void draw(sf::RenderWindow& window);
};

#endif //MAP_BOUNDARY