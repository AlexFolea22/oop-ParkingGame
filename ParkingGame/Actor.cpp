#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Actor.h"

Actor::Actor(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& type) : texture(textureName), sprite(texture) {
	texture.setSmooth(true);
	sprite.setTextureRect(sf::IntRect({ 0, 0 }, { sizeX, sizeY }));
	sprite.setPosition(sf::Vector2f(x, y));
}

sf::Texture Actor::getTexture() {
	return texture;
}

sf::Sprite Actor::getSprite() {
	return sprite;
}

std::string Actor::getType() {
	return type;
}