#pragma once
#include "actor.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "collider.h"
#include "physics_config.h"

#ifndef CAR_H
#define CAR_H


class Car : public Actor {
private:
    float m_speed;
    PhysicsConfig m_physics;
    sf::Vector2f m_velocity = { 0.f, 0.f };
    Collider m_collider;
    sf::RectangleShape m_body;
public:
    Car(const std::string& textureName, float x, float y, int sizeX, int sizeY, float speed, const std::string& type);
    sf::Vector2f getVelocity() const;
    void setVelocity(const sf::Vector2f& velocity);
    void handleInput();
    void setSpeed(const float& speed);
    Collider& getCollider();
    void updateCollider();
    void drawCollider(sf::RenderWindow& window);
    void boostPhysics(int amount);
};
#endif // CAR_H