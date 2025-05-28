#pragma once
#ifndef HUMAN_H
#define HUMAN_H

#include "Collider.h" 
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Texture.hpp> 
#include <SFML/System/Vector2.hpp> 
#include <random>
#include <string>

namespace sf {
    class RenderWindow;
}

class Human : public Collider {

private:
    void changeDirection();

    sf::Vector2f m_velocity;
    float m_movementSpeed;

    sf::Clock m_directionChangeClock;
    sf::Time m_timeUntilNextDirectionChange;

    sf::Vector2f m_mapBounds; 

    std::mt19937 m_rng;
    std::uniform_real_distribution<float> m_angleDistribution;  
    std::uniform_real_distribution<float> m_timeDistribution;    

public:
    Human(sf::Vector2f position,
        const sf::Vector2f& mapBounds,
        float movementSpeed = 50.f,
        sf::Vector2f size = sf::Vector2f(50.f, 50.f));
    virtual ~Human() {};
    void update(float dt);

};

#endif // HUMAN_H
