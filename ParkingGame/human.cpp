#include "Human.h"
#include <cmath>
#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp> 

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

sf::RectangleShape humanShape(sf::Vector2f position, sf::Vector2f size) {
    sf::RectangleShape shape;
    shape.setPosition(position);
    shape.setSize(size);
    return shape;
}

Human::Human(sf::Vector2f position,
    const sf::Vector2f& mapBounds,
    float movementSpeed,
    sf::Vector2f size)
    : Collider(humanShape(position, size)),
    m_movementSpeed(movementSpeed),
    m_mapBounds(mapBounds),
    m_angleDistribution(0.f, 2.f * static_cast<float>(M_PI)),
    m_timeDistribution(1.0f, 5.0f)
{
    std::random_device rd;
    m_rng.seed(rd());

    this->getRectangle().setSize(size); 
    /*this->getRectangle().setFillColor(sf::Color(255, 222, 169));*/
    
    this->getRectangle().setOrigin({ 0,0 }); 
    this->getRectangle().setPosition(position);

    _changeDirection();
    m_timeUntilNextDirectionChange = sf::seconds(m_timeDistribution(m_rng));
    m_directionChangeClock.restart();
}

void Human::_changeDirection() {
    float angle = m_angleDistribution(m_rng);
    m_velocity.x = std::cos(angle) * m_movementSpeed;
    m_velocity.y = std::sin(angle) * m_movementSpeed;
}

void Human::update(float dt) {
    if (m_directionChangeClock.getElapsedTime() >= m_timeUntilNextDirectionChange) {
        _changeDirection();
        m_timeUntilNextDirectionChange = sf::seconds(m_timeDistribution(m_rng));
        m_directionChangeClock.restart();
    }

    this->getRectangle().move(m_velocity * dt); 

    sf::Vector2f currentPosition = this->getRectangle().getPosition(); 
    sf::Vector2f currentSize = this->getRectangle().getSize();       
    sf::Vector2f currentOrigin = this->getRectangle().getOrigin();   

    float objLeftEdge = currentPosition.x - currentOrigin.x;
    float objRightEdge = currentPosition.x - currentOrigin.x + currentSize.x;
    float objTopEdge = currentPosition.y - currentOrigin.y;
    float objBottomEdge = currentPosition.y - currentOrigin.y + currentSize.y;

    bool bounced = false;

    if (objLeftEdge < 0.f) {
        currentPosition.x = currentOrigin.x;
        m_velocity.x *= -1.f;
        bounced = true;
    }
    else if (objRightEdge > m_mapBounds.x) {
        currentPosition.x = m_mapBounds.x - currentSize.x + currentOrigin.x;
        m_velocity.x *= -1.f;
        bounced = true;
    }

    if (objTopEdge < 0.f) {
        currentPosition.y = currentOrigin.y;
        m_velocity.y *= -1.f;
        bounced = true;
    }
    else if (objBottomEdge > m_mapBounds.y) {
        currentPosition.y = m_mapBounds.y - currentSize.y + currentOrigin.y;
        m_velocity.y *= -1.f;
        bounced = true;
    }

    if (bounced) {
        _changeDirection();
        m_directionChangeClock.restart();
    }

    this->getRectangle().setPosition(currentPosition); 
}

Human::~Human() {
    std::cout << "You hit an innocent father"<<'\n';
}
