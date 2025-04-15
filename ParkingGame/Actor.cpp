// actor.cpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "actor.h"

Actor::Actor(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& type) : m_type(type) {
    if (!m_texture.loadFromFile(textureName)) {
        std::cerr << "Error loading texture: " << textureName << std::endl;
    }
    m_rectangle.setSize(sf::Vector2f(static_cast<float>(sizeX), static_cast<float>(sizeY)));
    m_rectangle.setTexture(&m_texture);
    m_rectangle.setPosition(sf::Vector2f(x, y));
}

Actor::Actor() : m_type("") {}

sf::Texture& Actor::getTexture() {
    return m_texture;
}

const sf::RectangleShape& Actor::getRectangle() const {
    return m_rectangle;
}

const std::string& Actor::getType() const {
    return m_type;
}

//void Actor::draw(sf::RenderWindow& window) {
//    window.draw(rectangle);
//}