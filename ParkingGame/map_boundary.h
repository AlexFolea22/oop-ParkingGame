#pragma once

#ifndef MAP_BOUNDARY_H
#define MAP_BOUNDARY_H


#include <SFML/Graphics.hpp>
#include "collider.h"
#include <vector>
#include "is_drawable.h"

class MapBoundary : public IsDrawable {
private:
    std::vector<Collider> m_walls;

public:
    MapBoundary(float mapWidth, float mapHeight, float thickness = 20.0f);

    bool checkCollisions(const Collider& other) const;
    virtual void draw(sf::RenderWindow& window) const override;
};

#endif //MAP_BOUNDARY