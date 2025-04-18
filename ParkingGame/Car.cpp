#include "car.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

Car::Car(const std::string& textureName, float x, float y, int sizeX, int sizeY, float speed, const std::string& type)
    : Actor(textureName, x, y, sizeX, sizeY, type),
    m_speed(speed),
    m_body(sf::Vector2f(static_cast<float>(sizeX), static_cast<float>(sizeY))),
    m_collider(m_body)
{
    m_rectangle.setOrigin(sf::Vector2f(sizeX / 2.0f, sizeY / 2.0f));
    m_body.setOrigin(sf::Vector2f(sizeX / 2.0f, sizeY / 2.0f));
    m_body.setPosition(m_rectangle.getPosition());
    m_body.setRotation(m_rectangle.getRotation());

    if (m_rectangle.getTexture() != nullptr) {
        m_body.setTexture(m_rectangle.getTexture());
        m_body.setTextureRect(m_rectangle.getTextureRect());
    }
}

void Car::handleInput() {
    float rotation = m_rectangle.getRotation().asRadians();
    sf::Vector2f forward(std::sin(rotation), -std::cos(rotation));
    sf::Vector2f right(forward.y, -forward.x);
    bool accelerating = false;
    float dt = 1.0f / 60.0f;
    float speed = std::sqrt(m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y);
    if (speed > 0.1f) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) {
            m_rectangle.rotate(sf::degrees(-m_turnSpeed * dt * (speed / m_maxSpeed)));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) {
            m_rectangle.rotate(sf::degrees(m_turnSpeed * dt * (speed / m_maxSpeed)));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
        m_velocity += forward * m_acceleration * dt;
        accelerating = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) {
        m_velocity -= forward * (m_acceleration * 0.1f) * dt;
        accelerating = true;
    }
    if (!accelerating) {
        m_velocity *= (1.0f - m_drag * dt);
        //lateral friction (drift reduction)
        float sideVel = m_velocity.x * right.x + m_velocity.y * right.y;
        m_velocity -= right * sideVel * m_lateralFriction * dt;
    }
    //max speed
    float magnitude = std::sqrt(m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y);
    if (magnitude > m_maxSpeed) {
        m_velocity = (m_velocity / magnitude) * m_maxSpeed;
    }
    m_rectangle.move(m_velocity);
    updateCollider();
}

void Car::updateCollider() {
    m_body.setSize(m_rectangle.getSize());
    m_body.setOrigin(m_rectangle.getOrigin());
    m_body.setPosition(m_rectangle.getPosition());
    m_body.setRotation(m_rectangle.getRotation());
    m_body.setScale(m_rectangle.getScale());

    m_collider = Collider(m_body);
}

Collider& Car::getCollider() {
    updateCollider();
    return m_collider;
}

sf::Vector2f Car::getVelocity() const {
    return m_velocity;
}

void Car::setVelocity(const sf::Vector2f& velocity) {
    m_velocity = velocity;
}

void Car::setSpeed(const float& speed) {
    m_speed = speed;
}

void Car::drawCollider(sf::RenderWindow& window) {
    m_collider.drawCollider(window);
}