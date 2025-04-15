#pragma once
#include <SFML/Graphics.hpp>
#ifndef COLLIDER_H
#define COLLIDER_H

class Collider {
private:
    sf::RectangleShape& m_body;
    float m_rotation;

public:
    Collider(sf::RectangleShape& body);
    ~Collider() {};
    bool checkCollision(Collider& other, float push);
    sf::Vector2f getPosition();
    sf::Vector2f getHalfSize();
    float getRotation(); 
    void move(float dx, float dy);
    void setRotation(float rotation);
    sf::RectangleShape getBody();
};
#endif //COLLIDER_H
