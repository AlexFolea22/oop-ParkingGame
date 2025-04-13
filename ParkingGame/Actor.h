#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#ifndef ACTOR_H
#define ACTOR_H

class Actor {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	std::string type;

public:
	Actor(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& type);
	~Actor() {};

	sf::Texture getTexture();
	sf::Sprite getSprite();
	std::string getType();
};

#endif //ACTOR_H