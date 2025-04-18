#pragma once
#include "actor.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "collider.h"

#ifndef CAR_H
#define CAR_H
class Car : public Actor {
private:
    float m_speed;
    float m_friction = 0.08f;
    float m_acceleration = 50.0f;
    float m_maxSpeed = 6.0f;
    float m_turnSpeed = 180.0f;
    float m_drag = 2.0f;
    float m_lateralFriction = 0.2f;
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
};
#endif // CAR_H