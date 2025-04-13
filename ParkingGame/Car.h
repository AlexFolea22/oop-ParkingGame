#pragma once

#include "Actor.h"
#include <SFML/Graphics.hpp>
#include <string>

#ifndef CAR_H
#define CAR_H

class Car : public Actor {
private:
    float speed;
    float acceleration = 0.1f;
    float maxSpeed = 8.0f;
    float friction = 0.08f;
    sf::Vector2f velocity;

public:
    Car(const std::string& textureName, float x, float y, int sizeX, int sizeY, float speed, const std::string& type);

    void update(float deltaTime);
    void handleInput();
};

#endif // CAR_H
