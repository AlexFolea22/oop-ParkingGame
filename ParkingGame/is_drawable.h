#pragma once
#ifndef IS_DRAWABLE_H
#define IS_DRAWABLE_H

#include <SFML/Graphics/RenderWindow.hpp> 

class IsDrawable {
public:
	virtual void draw(sf::RenderWindow& window) const = 0;
};
#endif //IS_DRAWABLE_H