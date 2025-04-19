// actor.h
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#ifndef ACTOR_H
#define ACTOR_H

class Actor {
protected:
    sf::Texture m_texture;
    sf::RectangleShape m_rectangle;
    std::string m_type;

public:
    Actor(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& type);
    Actor();
    virtual ~Actor() {};
    sf::Texture& getTexture();
    const sf::RectangleShape& getRectangle() const;
    sf::RectangleShape& getRectangle();


    const std::string& getType() const;

   /* virtual void draw(sf::RenderWindow& window);*/
    virtual void update(float deltaTime) {} 
    virtual void handleInput() {}        
};

#endif //ACTOR_H